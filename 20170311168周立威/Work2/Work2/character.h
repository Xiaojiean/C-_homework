#ifndef CHARACTER_H
#define CHARACTER_H
#include<iostream>
class character;
int skill(character m, int x);

class character
{
private:
	bool alive=true;

	
public:
	void died();
	void kill();

};


#endif