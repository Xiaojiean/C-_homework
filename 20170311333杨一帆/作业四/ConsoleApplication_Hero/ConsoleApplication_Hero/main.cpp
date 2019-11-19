#include<iostream>
#include"Hero.h"
using namespace std;
string sunwukong;
int skill;
int num=2;
int aim1=5000;
int aim2=3000;
int main()
{
	Hero Zhugeliang;
	Zhugeliang.showskill();
	cout << "回合开始" << endl;
	cout << "1：技能一 2：技能二 3：技能三" << endl;
	cin >>skill;
	if (skill == 1)
	{
		aim1=aim1-Zhugeliang.use_skill1(num);
		aim2 = aim2- Zhugeliang.use_skill1(num);
		cout << "目标一生命值" << aim1;
		cout << "目标二生命值" << aim2 << endl;
	}
	while (1)
	{
		cout << "按1继续释放技能：东风破" << endl;
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