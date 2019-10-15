#include<iostream>
#include"character.h"
using namespace std;
int main() {
	character *a=new character("ChengxuyuanA",1,2);
	character *b=new character("CeshiyuanB",2,2);
	a->skill2(b);
	a->tphome();
	return 0;
}