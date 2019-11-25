#include<iostream>
#include"Hero.h"
using namespace std;
string sunwukong;
int skill;
int num=2;
int aim1=5000;
int aim2=3000;
int dis = 30;
int main()
{
	int times = 3;
	Hero Zhugeliang;
	Zhugeliang.showskill();
	cout << "回合开始" << endl;
	cout << "1：技能一 2：技能二 3：技能三" << endl;
	cout << "当前距离目标30" << endl;
	cin >>skill;
	if (skill == 1)
	{
		aim1=aim1-Zhugeliang.use_skill1(num);
		aim2 = aim2- Zhugeliang.use_skill1(num);
		cout << "目标一生命值" << aim1;
		cout << "目标二生命值" << aim2 << endl;
	}
	if (skill == 2)
	{
		dis = Zhugeliang.use_skill2(dis);
		times--;
		cout << "当前距离目标:" <<dis;
		cout << "  剩余次数:" <<times<<endl;
	}
	while (1)
	{
		cin >> skill;
		if (skill == 2)
		{
			dis = Zhugeliang.use_skill2(dis);
			times--;
			cout << "当前距离目标:" << dis;
			cout << "  剩余次数:" <<times<<endl;
		}
		if (times <= 0)
		{
			cout << "技能进入冷却" << endl;
			break;
		}
	}
	while (1)
	{
		cout << "按1释放技能:东风破" << endl;
		cin >> skill;
		aim1 = aim1 - Zhugeliang.use_skill1(num);
		aim2 = aim2 - Zhugeliang.use_skill1(num);
		cout << "目标一生命值" << aim1;
		cout << "  目标二生命值" << aim2 << endl;
		if (aim2 <= 0)
		{
			cout << "你击杀了一名敌人" << endl;
			break;
		}
	}
	while(1)
	{
		cout << "按1继续释放技能" << endl;
		cin >> skill;
		aim1 = aim1 - Zhugeliang.use_skill1(1);
		cout << "  目标二生命值" << aim1 << endl;
		if (aim1 <= 0)
		{
			cout << "来犯之敌已尽数诛灭！" << endl;
			break;
		}
	}
	return 0;
}