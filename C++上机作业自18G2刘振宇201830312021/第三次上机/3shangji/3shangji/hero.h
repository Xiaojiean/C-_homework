#include<iostream>
using namespace std;

class Hero
{
public://公有
	Hero();                          //构造函数
	Hero(int x1,int x2,int x3);
	Hero(const Hero & name);
	~Hero();                        //析构函数
	Hero &operator=(const Hero&rhs);//等号运算符重载   右等
	void showskill();
private://私有
	int skill1;
	int skill2;
	int skill3;
};
