//版权声明
//Copyright 2021-2099 ZhantengZhang.
//202030310284 张展腾  

#include <iostream>
using namespace std;
int add(int, int);
int main()
{
	int x, y, sum;
	cout << "Enter two numbers:" << endl;
	cin >> x>>y;
	sum = add(x,y);
	cout << sum << endl;
	int i=5000000000;
	for(;i>=1;i--);
	return 0;
}
int add(int a, int b)
{
	return a + b;
}

