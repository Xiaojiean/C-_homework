#include<iostream>
using namespace std;

void showcjavg(int time,float[])
{
	float cj[100][100];
	cout << "The cj is:" << endl;
	for (int i = 0; i < time; i++)
	{
		cout << "(" <<cj[i][1] << "," << cj[i][2] <<","<<cj[i][3]<< ")" << endl;
		cout << "平均分为" << (cj[i][1] + cj[i][2] + cj[i][3]) / 3 << endl;
	}

}