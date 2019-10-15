#include<iostream>
#include"character.h"


using namespace std;

void character::died() {
	alive = ~alive;
	kill();
}

void character::damage(int number) {
	hp = hp - number;
	cout << this->name << ": hp: " << hp << endl;
}

void character::site(int x, int y) {
	this->x += x;
	this->y += y;
	cout << this->name << ": site: " << x << "," << y << endl;
}

void character::doc(int doc) {
	hp += doc;
}
void character::tphome() {
	x = 30;
	y = 30;
	cout << "use tp" << endl;
	cout << this->name << ": site: " << x << "," << y << endl;
}

void character::skill1(character* m) {
	a->skill(m);
}

void character::skill2(character* m) {
	choice=b->skill(m, this,choice);
	
}
void character::skill3(character* m) {
	c->skill(m,this);
}
character::character(string name,int x,int y){
	hp = 100;
	this->name = name;
	this->x = x;
	this->y = y;
	display();
}
void character::display() {
	cout << name << ":" << endl;
	cout << "hp: " << hp << endl;
	cout << "site: " << x << "," << y << endl;
}
character::~character() {
	cout << name << " has been shutdown" << endl;
}

void character::kill() {
	static int number;
	number++;
	switch (number) {
	case 1:
		cout << "First Blood" << endl;
		break;
	case 2:
		cout << "Double Kill" << endl;
		break;
	case 3:
		cout << "Trible Kill" << endl;
		break;
	case 4:
		cout << "Quadra Kill" << endl;
		break;
	case 5:
		cout << "Penta Kill" << endl;
		break;
	}
}

