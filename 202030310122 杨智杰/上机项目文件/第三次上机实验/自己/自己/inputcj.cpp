#include<iostream>
using namespace std;
void Inputcj(int time)
{
	float cj[100][100];
	for (int i = 0; i < time; i++)
	{
		cout << "Please Input cj1:" << endl;
		cin >> cj[i][1];
		cout << "Please Input cj2:" << endl;
		cin >> cj[i][2];
		cout << "Please Input cj3:" << endl;
		cin >> cj[i][3];
	}

}