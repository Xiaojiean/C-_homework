#include<iostream>
using namespace std;

class Hero
{
public:
	Hero();
	Hero(int num,int hurt,string s,int hero_blood,
		float hero_orign_x,float hero_orign_y,int x1,int x2,int x3);
	Hero(const Hero & name);
	~Hero();
	void changename(string myname);
	int use_skill1(int num);
	Hero &operator=(const Hero &rhs);
	void showskill();
	int use_skill2(float hero_orign_x);
private:
	int skill1;
	int skill2;
	int skill3;
	int orign_x;
	int hurt;
	int num;
	string hero_name;
};