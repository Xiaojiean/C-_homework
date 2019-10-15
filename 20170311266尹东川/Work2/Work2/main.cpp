#include<iostream>
#include"character.h"
using namespace std;
inline void attack(character m);
int main() {
	int x = 1;
	character hero[5];
	attack(hero[0]);
	x = skill(hero[1], x);
	x = skill(hero[2], x);
	x = skill(hero[3], x);
	attack(hero[4]);
}

inline void attack(character m) {
	cout << "normal attack" << endl;
	m.died();
}