#include"hero.h"
Hero::Hero()
{
	cout<<"This is a defult constructor!"<<endl;
	skill1 =0;
	skill2 =0;
	skill3 =0;
}
Hero::Hero(int x1,int x2,int x3)
{
	cout<<"This is a overloaded constructor!"<<endl;
    skill1 =x1;
	skill2 =x2;
	skill3 =x3;
}
Hero::Hero(const Hero & name)
{
	cout<<"This is a copy constructor!"<<endl;
	skill1 =name.skill1;
	skill2 =name.skill2;
	skill3 =name.skill3;
}

Hero::~Hero()      //Îö¹¹º¯Êý
{
	cout<<"This is a constructor!"<<endl;
}
Hero & Hero::operator=(const Hero &rhs)
{
	if (this ==&rhs)
	{
		return*this;
	}
	this->skill1=rhs.skill1;
	this->skill2=rhs.skill2;
	this->skill3=rhs.skill3;
	return*this;
}
void Hero::showskill()
{
	cout<<skill1<<endl;
	cout<<skill2<<endl;
    cout<<skill3<<endl;
}