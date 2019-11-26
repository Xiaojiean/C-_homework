#include<iostream>                  
#include"hero.h"
using namespace std;

int main()
{
	Hero Libai;
	Hero Sunwukong=Hero(10,10,10);
	Hero hanxin(Sunwukong);
	Libai=Sunwukong;
	return 0;
}