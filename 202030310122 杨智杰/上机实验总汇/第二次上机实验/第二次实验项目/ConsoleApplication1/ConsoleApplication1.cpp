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
			cout << "请输入0~100之间的数值" << endl;
		}
	cout << "max=" << max(a) << endl;
	cout << "min=" << min(a) << endl;
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单
