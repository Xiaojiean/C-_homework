#include<iostream>
using namespace std;

class Hero
{
public://公有
	Hero();                          //构造函数
	Hero(int x1,int x2,int x3,string s,int hero_blood,float hero_orign_x,float hero_orign_y,bool hero_movement);
	~Hero();                        //析构函数
	void showskill();
	void changename(string myname);
	void use_skill(bool hero_skill_damage,bool hero_skill_skip,int hero_skill_times,
		int current,float length_x,float length_y,int stop_time,bool stop,Hero & target);
	int blood;
	bool movement;
private://私有
	int skill1;
	int skill2;
	int skill3;
	int orign_x;
    int orign_y;
	
	string hero_name;
};
