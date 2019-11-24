#include<iostream>
#include"character.h"
using namespace std;

int main() {
	character* a = new character("user", 2, 3);
	character* b = new character("enemy1", 3, 3);
	character* c = new character("enemy2", 2, 2);
	a->skill2(b, c);
	a->skill2(b);
	a->skill3(b, c);
	return 0;

}