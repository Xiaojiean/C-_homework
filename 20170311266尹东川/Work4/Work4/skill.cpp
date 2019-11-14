#include<iostream>
#include"skill.h"
#include"character.h"
using namespace std;


skill1::skill1() {
	damage = 30;

}
void skill1::skill(character* bearer) {
	bearer->damage(damage);
	cout << "use skill1(singleobjective)" << endl;
}

void skill1::skill(character* bearer1, character* bearer2) {
	bearer1->damage(damage);
	bearer2->damage(damage);
	cout << "use skill1(multiobjective)" << endl;
}

skill2::skill2() {
	damage1 = 20;
	damage2 = 70;
	x = 2, y = 2;
}

bool skill2::skill(character* bearer, character* user, bool x) {
	cout << "use skill2(singleobjective)" << endl;
	if (x == true) {
		user->site(x, y);
		bearer->damage(damage1);
	}
	else {
		bearer->damage(damage2);
	}
	return ~x;
}

bool skill2::skill(character* bearer1, character* bearer2, character* user, bool x) {
	cout << "use skill2(multiobjective)" << endl;
	if (x == true) {
		user->site(x, y);
		bearer1->damage(damage1 / 2);
		bearer2->damage(damage1 / 2);
	}
	else {
		bearer1->damage(damage2 / 2);
		bearer2->damage(damage2 / 2);
	}
	return ~x;
}

skill3::skill3() {
	x = 1, y = 2;
	damage = 40;
	doc = 10;
}

void skill3::skill(character* bearer, character* user) {
	cout << "use skill3(singleobjective)" << endl;
	bearer->site(x, y);
	bearer->damage(damage);
	user->doc(doc);
}

void skill3::skill(character* bearer1, character* bearer2, character* user) {
	cout << "use skill3(multiobjective)" << endl;
	bearer1->site(x, y);
	bearer1->damage(damage);
	bearer2->site(x, y);
	bearer2->damage(damage);
	user->doc(doc);
}