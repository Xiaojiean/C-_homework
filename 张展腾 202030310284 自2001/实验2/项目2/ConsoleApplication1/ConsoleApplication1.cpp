//��Ȩ����
//Copyright 2021-2099 ZhantengZhang.
//202030310284 ��չ��

#include <iostream>
using namespace std;
int max(int p[]);
int min(int p[]);
int main()
{
	int a[5];

	for (int i = 0; i <= 4; i++)
		if (cin >> a[i] && a[i] >= 0 && a[i] <= 100)
			;
		else
		{
			i--;
			cout << "������0~100֮�����ֵ" << endl;
		}
	cout << "max=" << max(a) << endl;
	cout << "min=" << min(a) << endl;
	return 0;
}



