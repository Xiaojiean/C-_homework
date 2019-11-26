#include <iostream>
#include"hero.h"
using namespace std;
void duikanglu()//对抗路
{
	int duikangluxuanze;//你选择去对抗路
	cout << "到了对抗路发现对线橘右京在打河道蟹" << endl;
	cout << "1.不怂！硬刚！ 强杀橘右京！" << endl;
	cout << "2.支援发育路" << endl;
	cout << "3.支援中路" << endl;
	cout << "别问，问就是拿五杀，五杀他不香吗" << endl;
	cin >> duikangluxuanze;
	while (duikangluxuanze != 4)
	{
		switch (duikangluxuanze)
		{
		case 1: up(); break; //不怂！硬刚！ 强杀橘右京！
		case 2: fayulu(); break; //支援发育路
		case 3: zhonglu(); break; //支援中路
		default: cout << "Sorry召唤师，由于游戏研发经费不足，您目前不能做别的事情！" << endl; break; //deafult 超出选项范围
		}
	}
}
void zhonglu()//中路
{
	int zhongluxuanze;//你选择去中路
	cout << "通过小地图看到中路武则天走位太过深入" << endl;
	cout << "1.走位躲开武则天二技能和强化一技能 一炮带走" << endl;
	cout << "2.支援对抗路" << endl;
	cout << "3.支援发育路" << endl;
	cout << "别问，问就是拿五杀，五杀他不香吗" << endl;
	cin >> zhongluxuanze;
	while (zhongluxuanze != 4)
	{
		switch (zhongluxuanze)
		{
		case 1:cout << "1" << endl;  middle(); break; //走位躲开武则天二技能和强化一技能 一炮带走
		case 2: duikanglu(); break; //支援对抗路
		case 3: fayulu(); break; //支援发育路
		default: cout << "Sorry召唤师，由于游戏研发经费不足，您目前不能做别的事情！" << endl; break; //deafult 超出选项范围
		}
	}
}
void fayulu()//发育路
{
	int xialuxuanze;//

	cout << "火速赶到了发育路，兵线很差，对面刘禅和刘备要拆塔了！！" << endl;
	cout << "1.勾引两人越塔强杀你，打算利用防御塔反杀父子二人" << endl;
	cout << "2.去发育路带兵线" << endl;
	cout << "3.返回中路防守防御塔" << endl;
	cout << "别问，问就是拿五杀，五杀他不香吗" << endl;
	cin >> xialuxuanze;
	while (xialuxuanze != 4)
	{
		switch (xialuxuanze)
		{
		case 1: down(); break; //勾引两人越塔强杀你，打算利用防御塔反杀父子二人
		case 2: duikanglu(); break; //去发育路带兵线
		case 3: zhonglu(); break; //返回中路防守防御塔
		default: cout << "Sorry召唤师，由于游戏研发经费不足，您目前不能做别的事情！" << endl; break; //deafult 超出选项范围
		}
	}
}
void middle() //在中路操作一番
{
	int caozuo1;
	cout << "1.一技能减速" << endl;
	cout << "2.平a" << endl;
	cin >> caozuo1;
	while (caozuo1 != 3)
	{
		switch (caozuo1)
		{
		case 1:jishashu = jishashu + 1; break;
		case 2:inline void a(); break;
		default: cout << "Sorry召唤师，由于游戏研发经费不足，您目前不能做别的事情！" << endl; break; //deafult 超出选项范围
		}
		jishu(); break;
	}
	if (jishashu>5)
		return win();
	else
	{
		return  zhonglu();
	}
}
void up()//上单的细节操作
{
	int caozuo2;
	cout << "1.反向二闪将橘右京打回塔下" << endl;
	cout << "2.平a" << endl;
	cin >> caozuo2;
	while (caozuo2 != 3)
	{
		switch (caozuo2)
		{
		case 1:jishashu = jishashu + 1; break;
		case 2:inline void a(); break;
		default: cout << "Sorry召唤师，由于游戏研发经费不足，您目前不能做别的事情！" << endl; break; //deafult 超出选项范围
		}
		jishu(); break;
	}
	if (jishashu>5)
		return win();
	else
	{
		return duikanglu();
	}
}
void down() //下路直接双杀
{
	int caozuo3;//下路小团战一打二
	cout << "1.刘备扛塔来杀你，你反手大招收掉刘备\n刘禅发现大势已去，转身想跑，但最终遗恨塔下" << endl;
	cin >> caozuo3;
	while (caozuo3 != 2)
	{
		switch (caozuo3)
		{
		case 1:jishashu = jishashu + 2; break;
		default: cout << "Sorry召唤师，由于游戏研发经费不足，您目前不能做别的事情！" << endl; break; //deafult 超出选项范围
		}
		jishu(); break;
	}
	if (jishashu>5)
		return win();
	else
	{
		return  fayulu();
	}
}
void win()//拿到五杀
{
	cout << "！五连绝世！" << endl;
	cout << "！五连绝世！" << endl;
	cout << "！干得漂亮！" << endl;
	cout << "！干得漂亮！" << endl;
}