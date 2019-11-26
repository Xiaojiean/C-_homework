#include <iostream>
#include "4上机.h"
using namespace std;
int main()
{
	cout << "………………………………………………………" << endl;
	cout << "………………欢迎来到王者荣耀!………………" << endl;
	cout << "相比于前一阶段的天美设计经费紧张" << endl;
	cout << "拆除一座防御塔卖的钱已经不够满足天美了" << endl;
	cout << "请立刻！马上！同时击毁2座防御塔！！！" << endl;
	cout << "……………………开始游戏……………………" << endl;
	cout << "1.攻击防御塔" << endl;
	cout << "2.显示防御塔状态" << endl;
	cout << "3.结束游戏" << endl;
	Game Fangyuta1(1000, 999, 999, 1);
	Game Fangyuta2(1000, 999, 999, 1);
	int x;
	cin >> x;
	while (x != 3)
	{
		if (x == 2)
		{
			Fangyuta1.showGame();
			Fangyuta2.showGame();
		}
		else
			switch (x)
		{
			case 1: Fangyuta1.Fight(); Fangyuta1.showGame(); Fangyuta2.Fight(); Fangyuta2.showGame();
				if (Fangyuta1.g1 == 0 && Fangyuta2.g1==0)
				{
					cout << "破坏防御塔" << endl;
					Fangyuta1.~Game(); Fangyuta2.~Game();
				}break;
			default:cout << "Sorry,You are not allowed to do something else" << endl; break;
		}
		cin >> x;
	}
	return  0;
}