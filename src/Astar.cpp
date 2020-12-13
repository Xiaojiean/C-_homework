/* @file    Astar.cpp
 * @brief   C++ and MATLAB mixed programming of mexfunction for A-Star algorithm
 * @author  Adlexer Xu
 * @date    2020/11/24
 */

#include <mex.h>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

typedef std::pair<int, int> point;
// Fpoint: bind of a point and its F-value stored in heap
typedef std::pair<int, point> Fpoint;

// the heap storing Fpoint
static std::vector<Fpoint> openSet;

// make the min-root heap
inline bool cmp(Fpoint p1, Fpoint p2) {
    return p1.first > p2.first;
}

// return the g distance
inline int g_dis(int x1, int y1, int x2, int y2) {
    return x1 != x2 && y1 != y2 ? 14 : 10;
}

// return the h distance
inline int h_dis(int x1, int y1, int x2, int y2) {
    return (int)(10 * sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
}

/*
 *@breif    C++ mexfunction API of MATLAB that converts C++ source file to MATLAB function
 *          This function is equivalent to the main function, as a function interface in MATLAB
 *@params	nlhs    num of output params
 *@params	plhs    pointer to output params
 *@params	nrhs    num of input params
 *@params   prhs    pointer to input params
 */
void mexFunction(int nlhs, mxArray* plhs[], int nrhs, const mxArray* prhs[]) {

    //constexpr int rows = 8;
    //constexpr int cols = 8;

    double* mxInputMap = mxGetPr(prhs[0]);

    // get the number of rows(m) of the matrix
    int rows = mxGetM(prhs[0]);
    // get the number of columns(n) of the matrix
    int cols = mxGetN(prhs[0]);

    const int m[8][2] = { {-1,0},{1,0},{0,-1},{0,1},{-1,-1},{1,-1},{-1,1},{1,1} };

    // indexed pointSet for storing its F-value and f-point(father point)
    // request dynamic memory for 2d-array
    Fpoint** pointSet = new Fpoint * [rows];
    for (int i = 0; i < rows; i++) {
        pointSet[i] = new Fpoint[cols];
    }

    int** closeSet = new int* [rows];
    for (int i = 0; i < rows; i++) {
        closeSet[i] = new int[cols];
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            closeSet[i][j] = 0;
        }
    }

    int** inputMap = new int* [rows];
    for (int i = 0; i < rows; i++) {
        inputMap[i] = new int[cols];
    }

    // matlab input array to C++ 2d array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // matlab adopts column priority so we count cols first
            inputMap[i][j] = (int)mxInputMap[j * rows + i];
            //mexPrintf("%d ", inputMap[i][j]);
        }
        //mexPrintf("\n");
    }

    static int sx, sy, ex, ey;
    double* start = mxGetPr(prhs[1]);
    double* end = mxGetPr(prhs[2]);
    sx = (int)start[0] - 1, sy = (int)start[1] - 1;
    ex = (int)end[0] - 1, ey = (int)end[1] - 1;

    openSet.push_back(Fpoint(0, point(sx, sy)));
    while (!openSet.empty()) {
        int x, y, tx, ty;
        // pick out the min-F-value point from openSet
        point currentPt = openSet.front().second;

        x = currentPt.first;
        y = currentPt.second;
        pointSet[x][y].first = openSet.front().first;

        //mexPrintf("s: (%d, %d) F=%d\n", x + 1, y + 1, openSet.back().first);

        // pop heap
        pop_heap(openSet.begin(), openSet.end(), cmp);
        openSet.pop_back();

        // if find the end points
        if (x == ex && y == ey) {
            int** outputMap = new int* [rows];
            for (int i = 0; i < rows; i++) {
                outputMap[i] = new int[cols];
            }

            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    outputMap[i][j] = inputMap[i][j];
                }
            }

            while (x != sx || y != sy) {
                outputMap[x][y] = 2;

                tx = pointSet[x][y].second.first;
                ty = pointSet[x][y].second.second;
                x = tx;
                y = ty;
            }
            outputMap[x][y] = 2;

            plhs[0] = mxCreateDoubleMatrix(rows, cols, mxREAL);
            double* mxOutputMap = mxGetPr(plhs[0]);

            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    // matlab adopts column priority so we count cols first
                    mxOutputMap[j * rows + i] = outputMap[i][j];
                    //mexPrintf("%d ", outputMap[i][j]);
                }
                //mexPrintf("\n");
            }

            // finish
            return;
        }

        // search around
        for (int i = 0; i < 8; i++) {
            tx = x + m[i][0];
            ty = y + m[i][1];

            // not out of range
            if (tx >= 0 && tx < rows && ty >= 0 && ty < cols) {
                // find out the current F-value of target point
                int F = pointSet[tx][ty].first;

                // reachable && not in close set
                if (inputMap[tx][ty] == 0 && closeSet[tx][ty] == 0) {
                    // F(tartget) = g(s->current) + g(current->target) + h(target)
                    // = F(current) - h(current) + g(current->target) + h(target)
                    // weight of g-distance is greater than that of h-distance
                    // it mains that shortening total distance is greater than getting closer to the end point
                    int tF = pointSet[x][y].first - h_dis(x, y, ex, ey) + g_dis(tx, ty, x, y) + h_dis(tx, ty, ex, ey);

                    //mexPrintf("t: (%d, %d) F=%d\n", tx + 1, ty + 1, tF);

                    // if this point is not yet finded
                    // if the target F-value is greater than the current F-value
                    if (F == 0 || tF < F) {
                        Fpoint newPoint(tF, point(tx, ty));

                        // set the f-point of this target point
                        pointSet[tx][ty] = std::pair<int, point>(tF, currentPt);

                        // push heap
                        openSet.push_back(newPoint);
                        push_heap(openSet.begin(), openSet.end(), cmp);
                    }
                }
            }
        }
        // add to close set
        closeSet[x][y] = 1;
    }
    mexPrintf("the end point is unreachable, check out the map\n");
    return;
}