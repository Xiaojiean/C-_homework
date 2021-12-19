// 实验六.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<iostream>
#include<string>
using namespace std;
class MyArray {
public:
	MyArray(int length);
	~MyArray();
	void Input();
	void Display(string);
protected:
	int* alist;
	int length;
};

MyArray::MyArray(int leng)
{
	if (leng <= 0)
	{
		cout << "error length";
		exit(1);
	}
	length = leng;
	alist = new int[length];
	if (alist == NULL)
	{
		cout << "assign failure";
		exit(1);
	}
	cout << "MyArray类对象已创建!" << endl;
}
MyArray::~MyArray()
{
	//	delete[] alist;
	cout << "MyArray类对象已撤销!" << endl;
}

void MyArray::Display(string str)
{
	int i;
	int* p = alist;
	cout << str << length << "个整数: ";
	for (i = 0; i < length; i++, p++)
		cout << *p << " ";
	cout << endl;
}

void MyArray::Input()
{
	cout << "请从键盘输入" << length << "个整数:";
	int i;
	int* p = alist;
	for (i = 0; i < length; i++, p++)
		cin >> *p;
}

class SortArray :public MyArray
{
public:
	SortArray(int leng);
	~SortArray();
	void paixu();
};

SortArray::SortArray(int leng) :MyArray(leng)
{
	if (leng <= 0)
	{
		cout << "error length";
		exit(1);
	}
	length = leng;
	alist = new int[length];
	if (alist == NULL)
	{
		cout << "assign failure";
		exit(1);
	}
	cout << "SortArray类对象已创建!" << endl;
}

SortArray::~SortArray()
{
	delete[] alist;
	cout << "SortArray类对象已撤销!" << endl;
}


void SortArray::paixu()
{
	int i, t, j;
	int* p = alist;
	for (i = 0; i < length - 1; i++)
	{
		for (j = i + 1; j < length; j++)
		{
			if (alist[i] > alist[j])
			{
				t = p[i];
				p[i] = p[j];
				p[j] = t;
			}
		}
	}
	cout << "显示排序后以后的5个整数"  ;
	for (i = 0; i < length; i++)
		cout <<  p[i] << " ";
}
int main()
{
	//	MyArray a(5);
	SortArray b(5);
	b.Input();
	b.Display("显示排序以前的");
	b.paixu();
	cout << endl;
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
