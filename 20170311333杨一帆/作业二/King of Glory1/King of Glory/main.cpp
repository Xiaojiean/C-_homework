#include<iostream>
#include"Sword_ruling.h"

using namespace std;
inline int ping_a(int &a);
int E1 = 2000, E2 = 2000;
int main ()
{
	int x,y;
	int i = 1000;
	cout<<"王者荣耀五连绝世播报程序"<<endl;
	cout<<"选择初始英雄：1 亚瑟 2 妲己"<<endl;
	cin>>x;
	if (x ==1) {
		cout << "您选择的英雄：亚瑟"<< endl;
	}
	if(x==2) {
		cout << "您选择的英雄：妲己" << endl;
	}
	cout << "基础生命值：1000" << endl;
	cout << "  攻击：100  防御：50" << endl;
	cout << "第一个敌人出现，发起进攻" << endl;
	while (1)
	{
		cout << "请选者攻击方式：0：普通攻击；1：大招" << endl;
		cin >> y;
		switch (y) {
		case 0:cout << "敌人-100，剩余生命值：" << ping_a(E1) << endl; break;
		case 1:cout << "敌人-200，剩余生命值：" << Sword_ruling(E1) << endl; break;
		}
		if (E1<= 0) {
			cout << "First blood" << endl;
			break;
		}
	}
	cout << "前方发现四个落单的敌人，发起进攻" << endl;
	while (1)
	{
		
		cout << "请选者攻击方式：0：普通攻击；1：大招" << endl;
		cin >> y;
		switch (y) {
		case 0:cout << "敌人-100，剩余生命值：" << ping_a(E2) << endl; break;
		case 1:cout << "敌人-200，剩余生命值：" << Sword_ruling(E2) << endl; break;
		}
		if (E2 <= 0) {
			cout << "Double kill" << endl;
			break;
		}
		
	}
	cout << "对方回合：致命打击-300 您的生命值：" << i - 300 << endl;
	while (1)
	{
		
		cout << "您的回合，请选者攻击方式：0：普通攻击；1：大招" << endl;
		cin >> y;
		switch (y) {
		case 0:cout << "敌人-100，剩余生命值：" << ping_a(E2) << endl; break;
		case 1:cout << "敌人-200，剩余生命值：" << Sword_ruling(E2) << endl; break;
		}
		cout << "对方回合：普通攻击 您的生命值：" << i - 10 << endl;
		if (E2 <= 0) {
			cout << "Triple kill" << endl;
			break;
		}

	}
	cout << "有两个残血要逃了，快，上去收割" << endl;
	while (1)
	{

		cout << "请选者攻击方式：0：普通攻击；1：终结" << endl;
		cin >> y;
		switch (y) {
		case 0:cout << "敌人-100，剩余生命值：" << ping_a(E2) << endl; break;
		case 1:cout << "敌人-200，剩余生命值：" << Sword_ruling(E2) << endl; break;
		}
		if (E2 <= 0) {
			cout << "Quadra kill" << endl;
			cout << "Penta kill" << endl;
			cout << "Ace" << endl;
			break;
		}

	}
	cout << "Victory" << endl;
	return 0;
}
inline int ping_a(int &a)
{
	a -= 100;
	return a;
}