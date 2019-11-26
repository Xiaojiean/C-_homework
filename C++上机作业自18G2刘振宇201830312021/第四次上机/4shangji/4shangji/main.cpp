#include<iostream>
#include"hero.h"
using namespace std;
int main()
{
	Hero Sunwukong=Hero(0,0,200,"Sunwukong",500,0.0,0.0,true );
	Hero Libai=Hero(50,0,400,"Libai",500,0.0,0.0,true );
	int tmp_blood;
	tmp_blood = Sunwukong.use_skill(false,false,1,1,0,0,0,false,&Libai );
	Sunwukong.blood=Sunwukong.blood+tmp_blood;
	int current_Libai_skill=0;
	cout<<"Libai skill length_x and length_y:"<<endl;
	float length_x,length_y;
	cin>>length_x>>length_y;
	Libai.use_skill(true,true,3,current_Libai_skill++,length_x,length_y,20,true,&Sunwukong);
	cout<<Sunwukong.blood<<endl;
	cout<<Sunwukong.movement<<endl;
	return 0;
}