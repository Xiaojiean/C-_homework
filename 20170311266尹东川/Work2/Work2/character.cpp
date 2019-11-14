#include<iostream>
#include"character.h"
using namespace std;

void character::died() {
	alive = ~alive;
	kill();
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

int skill(character m, int x) {
	if (x == 1) {
		cout << "first stage skill"<<endl;
		m.died();
		return 2;
	}
	if (x == 2) {
		cout << "third stage skill"<<endl;
		m.died();
		return 3;
	}
	if (x == 3) {
		cout << "finally stage skill"<<endl;
		m.died();
		return 4;
	}
}