#include<iostream>
#include"skill.h"
#include"character.h"
using namespace std;


skill1::skill1() {
	damage = 30;
	
}
void skill1::skill( character* m) {
	m->damage(damage);
	cout << "use skill1" << endl;
}

skill2::skill2() {
	damage1 = 20;
	damage2 = 70;
	x = 2, y = 2;
}

bool skill2::skill(character* bearer,character* user,bool x) {
	cout << "use skill2" << endl;
	if (x == true) {
		user->site(x, y);
		bearer->damage(damage1);
	}
	else {
		bearer->damage(damage2);
	}
	return ~x;
}

skill3::skill3() {
	x = 1, y = 2;
	damage = 40;
	doc = 10;
}

void skill3::skill(character* bearer,character* user) {
	cout << "use skill3" << endl;
	bearer->site(x, y);
	bearer->damage(damage);
	user->doc(doc);
}