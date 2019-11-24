#ifndef SKILL_H
#define SKILL_H
#include<iostream>
class character;


//skill1 只造成少量伤害

class skill1 {
private:
	int damage;
public:
	skill1();
	void skill(character* bearer);
	void skill(character* bearer1,character* bearer2);
};
//skill2有两段，一段位移加少量伤害，一段大量伤害
class skill2 {
private:
	int damage1, damage2, x, y;
	bool choice = true;
public:
	skill2();
	bool skill(character* bearer, character* user, bool choice);
	bool skill(character* bearer1, character* bearer2, character* user, bool choice);
};
//skill3使用后使对方少量位移，并造成中量伤害,并增加少量血量
class skill3 {
private:
	int damage, doc, x, y;
public:
	skill3();
	void skill(character* bearer, character* user);
	void skill(character* bearer1,character* bearer2, character* user);
};


#endif SKILL_H