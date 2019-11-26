#include<iostream>
#include"hero.h"
using namespace std;
Hero::Hero(int x1, int x2, int x3, string s, int hero_blood, float hero_orign_x, float hero_orign_y, bool hero_movement)
{
	cout << "This is a overloaded constructor!" << endl;
	skill1 = x1;
	skill2 = x2;
	skill3 = x3;
	hero_name = s;
	blood = hero_blood;
	orign_x = hero_orign_x;
	orign_y = hero_orign_y;
	movement = hero_movement;

}
int Hero::use_skill(bool hero_skill_damage, bool hero_skill_skip, int hero_skill_times,
	int current, float length_x, float length_y, int stop_time, bool stop, Hero & target)
{
	if(hero_skill_damage==false)
	{	return 200;
	if(hero_skill_skip==true)
		if(current<hero_skill_times)
		{
			orign_x=orign_x+length_x;
			orign_y=orign_y+length_y;
		}
}
if(stop==true)
{
	target.movement=false;
	int i =0;
	while (i<=stop)
		i++;
}
return skill1;
	}