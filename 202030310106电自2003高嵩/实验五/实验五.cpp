// 实验五.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<iostream>
using namespace std;
class Base {
public:
    void setx(int i)
    {
        x = i;
    }
    int getx()
    {
        return x;
    }
private:
    int x;
};
class Derived :private Base
{
public:
    void sety(int i)
    {
        y = i;
    }
    int gety()
    {
        return y;
    }
    void show()
    {
        cout << "Base::x=" << x << endl;
    }
    public:
        int y;
    };
    int main()
    {
        Derived bb;                             // 语句2
        bb.setx(16);                            // 语句3
        bb.sety(25);                            // 语句4
        bb.show();                              // 语句5
        cout << "Base::x=" << bb.x << endl;           // 语句6
        cout << "Derived::y=" << bb.y << endl;        // 语句7
        cout << "Base::x=" << bb.getx() << endl;      // 语句8
        cout << "Derived::y=" << bb.gety() << endl;   // 语句9
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
