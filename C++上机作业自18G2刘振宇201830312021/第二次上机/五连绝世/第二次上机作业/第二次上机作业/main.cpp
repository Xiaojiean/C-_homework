#include <iostream> 
#include"hero.h"
using namespace std;
int jishashu = 0;

inline void A()//  内联函数
{
	int A1;
	cout << "1.平a" << endl;
	cin >> A1;
	switch (A1)
	{
	case 1:jishashu = jishashu + 1; break;
	default: cout << "Sorry召唤师，由于游戏研发经费不足，您目前不能做别的事情！" << endl; break;
	}
}

int main()  //主函数描绘一下王者峡谷环境
{
	cout << "……………………………………………………………………" << endl;
	cout << "……………………………………………………………………" << endl;
	cout << "欢迎来到王者荣耀！敌军还有三秒到达战场！全军出击！！" << endl;//王者峡谷开场白
	cout << "VR时代，Final Fantasy！" << endl;//电玩鲁班语音
	cout << "主播上线，开始直播冒险！" << endl;//电玩鲁班语音
	cout << "换人秘籍，上上下下，左右左右，BABA！" << endl;//电玩鲁班语音
	cout << "游戏开始，你是智商250的鲁班七号，请问你想去哪路发育？" << endl;
	cout << "……………………………………………………………………" << endl;
	cout << "……………………………………………………………………" << endl;
	int WZXG;
	cout << "1.对抗路（回血包 续航无压力）" << endl;
	cout << "2.发育路（money大大滴啊）" << endl;
	cout << "3.中路" << endl;
	cout << "4.挂机" << endl;
	cin >> WZXG;
	while (WZXG != 4)  //挂机还想拿五杀？？游戏直接结束！
	{
		switch (WZXG)
		{
		case 1:duikanglu(); break;
		case 2: fayulu(); break;
		case 3: zhonglu(); break;
		case 4: cout << "Game over" << endl;
		default: cout << "Sorry召唤师，由于游戏研发经费不足，您目前不能做别的事情！" << endl; break;
		}
		jishu();

	}
}