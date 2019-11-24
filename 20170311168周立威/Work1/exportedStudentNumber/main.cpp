#include<iostream>
using namespace std;
char table1[15] = { ' ','*',' ',
				    ' ','*',' ',
					' ','*',' ',
					' ','*',' ',
					' ','*',' ' };
char table2[15] = { '*','*','*',
				    ' ',' ','*',
					'*','*','*',
					'*',' ',' ',
					'*','*','*' };
char table3[15] = { '*','*','*',
					' ',' ','*',
					'*','*','*',
					' ',' ','*',
					'*','*','*' };
char table4[15] = { '*',' ','*',
					'*',' ','*',
					'*','*','*',
					' ',' ','*',
					' ',' ','*' };
char table5[15] = { '*','*','*',
					'*',' ',' ',
					'*','*','*',
					' ',' ','*',
					'*','*','*' };
char table6[15] = { '*','*','*',
					'*',' ',' ',
					'*','*','*',
					'*',' ','*',
					'*','*','*' };
char table7[15] = { '*','*','*',
					' ',' ','*',
					' ',' ','*',
					' ',' ','*',
					' ',' ','*' };
char table8[15] = { '*','*','*',
					'*',' ','*',
				    '*','*','*',
				    '*',' ','*',
					'*','*','*' };
char table9[15] = { '*','*','*',
					'*',' ','*',
					'*','*','*',
					' ',' ','*',
					'*','*','*' };		
char table0[15] = { '*','*','*',
				    '*',' ','*',
				    '*',' ','*',
			        '*',' ','*',
					'*','*','*' };

int main()
{
	auto number = new char[12];					//设定学号为12位
	/*
	cout << "main address = " << main << endl;
	cout << "table0 address = " << &table0 << endl;
	cout << "number address = " << &number << endl;
	*/
	cout << "输入你的学号" << endl;
	for (int i = 0; i < 12; i++)
		cin >> number[i];
	cout << "你的学号为：" << endl;
	char table[5][72];
	int i, j = 0, m = 0, n;
	for (; j < 5; j++)
	{
		n = 0;

		for (i = 0; i < 12; i++)
		{

			switch (number[i])
			{
			case '1':
				for (; m < 3; m++)
					table[j][n++] = table1[3 * j + m];
				table[j][n++] = ' ';
				table[j][n++] = ' ';
				table[j][n++] = ' ';
				m = 0;
				break;
			case '2':
				for (; m < 3; m++)
					table[j][n++] = table2[3 * j + m];
				table[j][n++] = ' ';
				table[j][n++] = ' ';
				table[j][n++] = ' ';
				m = 0;
				break;
			case '3':
				for (; m < 3; m++)
					table[j][n++] = table3[3 * j + m];
				table[j][n++] = ' ';
				table[j][n++] = ' ';
				table[j][n++] = ' ';
				m = 0;
				break;
			case '4':
				for (; m < 3; m++)
					table[j][n++] = table4[3 * j + m];
				table[j][n++] = ' ';
				table[j][n++] = ' ';
				table[j][n++] = ' ';
				m = 0;
				break;
			case '5':
				for (; m < 3; m++)
					table[j][n++] = table5[3 * j + m];
				table[j][n++] = ' ';
				table[j][n++] = ' ';
				table[j][n++] = ' ';
				m = 0;
				break;
			case '6':
				for (; m < 3; m++)
					table[j][n++] = table6[3 * j + m];
				table[j][n++] = ' ';
				table[j][n++] = ' ';
				table[j][n++] = ' ';
				m = 0;
				break;
			case '7':
				for (; m < 3; m++)
					table[j][n++] = table7[3 * j + m];
				table[j][n++] = ' ';
				table[j][n++] = ' ';
				table[j][n++] = ' ';
				m = 0;
				break;
			case '8':
				for (; m < 3; m++)
					table[j][n++] = table8[3 * j + m];
				table[j][n++] = ' ';
				table[j][n++] = ' ';
				table[j][n++] = ' ';
				m = 0;
				break;
			case '9':
				for (; m < 3; m++)
					table[j][n++] = table9[3 * j + m];
				table[j][n++] = ' ';
				table[j][n++] = ' ';
				table[j][n++] = ' ';
				m = 0;
				break;
			case '0':
				for (; m < 3; m++)
					table[j][n++] = table0[3 * j + m];
				table[j][n++] = ' ';
				table[j][n++] = ' ';
				table[j][n++] = ' ';
				m = 0;
				break;
			}
		}
	}
	
	for (j = 0; j < 5; j++)
	{
		for (i = 0; i < 72; i++)
			cout << table[j][i];
		cout << endl;
	}
		
	return 0;
}



