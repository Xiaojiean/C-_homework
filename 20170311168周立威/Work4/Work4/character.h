#ifndef CHARACTER_H
#define CHARACTER_H
#include"skill.h"
#include<iostream>
using namespace std;

class character {
private:
	bool alive = true, choice = true;
	int hp, x, y;
	skill1 m_a, * a = &m_a;
	skill2 m_b, * b = &m_b;
	skill3 m_c, * c = &m_c;
	string  name;
public:
	void died();
	void kill();
	void skill1(character* m);
	void skill1(character* m, character* n);
	void skill2(character* m);
	void skill2(character* m, character* n);
	void skill3(character* m);
	void skill3(character* m, character* n);
	character(string name, int x, int y);
	~character();
	void damage(int number);
	void doc(int doc);
	void tphome();
	void display();
	void site(int x, int y);
};



#endif CHARACTER_H