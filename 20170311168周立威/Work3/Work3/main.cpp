#include<iostream>
#include"character.h"
using namespace std;
int main() {
	character *a=new character("Àî°×",1,2);
	character *b=new character("ÏîÓð",2,2);
	a->skill2(b);
	a->tphome();
	return 0;
}