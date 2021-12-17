#include<iostream>
using namespace std;
void showavg(int time,float[])
{
	float a=0; float b=0; float c=0; float cj[100][100];
	for (int i = 0; i < time; ++i)
	{
		a = a + cj[i][1];
	}
	a = a / time;
	for (int i = 0; i < time; ++i)
	{
		b = b + cj[i][2];
	}
	b = b / time;
	for (int i = 0; i < time; ++i)
	{
		c = c + cj[i][3];
	}
	c = c / time;

	cout << "cj1的平均成绩为" << endl;
	cout << "cj2的平均成绩为" << endl;
	cout << "cj3的平均成绩为" << endl;

	float  temp;    	               
	if (a > b) {	
		temp = a;
		a = b;
		b = temp;
	}
	if (a > c) {	
		temp = a;
		a = c;
		c = temp;
	}
	if (b > c) {
		temp = b;
		b = c;
		c = temp;
	}
	cout << "排序结果如下：" << endl;
	cout << a << " " << b << " " << c << endl;
}

