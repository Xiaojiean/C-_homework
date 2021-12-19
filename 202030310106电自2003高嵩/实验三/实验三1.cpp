// 实验三1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include<iostream>
using namespace std;
class Coordinate
{  // 定义Coordinate类
public:
  Coordinate()
{
        times = 2;
        cout << "Coordinate construction1 called!" << endl;
  }
  Coordinate(int times1)
    
{
      times = times1;
      cout << "Coordinate construction2 called!" << endl;
  }
~Coordinate()
{
    cout << "Coordinate destruction called!" << endl;
}
void InputCoord()
{
    for (int i = 0; i < times; i++)
    {
        cout << "Please Input x:" << endl;
        cin >> Coord[i][1];
        cout << "Please Input y:" << endl;
        cin >> Coord[i][2];
    }
}
void ShowCoord()
{
    cout << "The coord is:" << endl;
    for (int i = 0; i < times; i++)
    {
        cout << "(" << Coord[i][1] << "," << Coord[i][2] << ")" << endl;
    }
}
void ShowAvgCoord()
{
    float avgx = 0;
    float avgy = 0;
    for (int i = 0; i < times; i++)
    {
        avgx = avgx + Coord[i][1];
        avgy = avgy + Coord[i][2];
    }
    avgx = avgx / times;
    avgy = avgy / times;
    cout << "The AVG coord is:" << endl;
    cout << "(" << avgx << "," << avgy << ")" << endl;
}
private:
float Coord[100][100]; // 存放输入坐标的数组
int times; // 存放输入坐标数目
};


int main()
{
    Coordinate x;
    x.InputCoord();
    x.ShowCoord();
    x.ShowAvgCoord();
    return 0;
}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
