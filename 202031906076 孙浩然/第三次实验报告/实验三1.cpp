﻿#include<iostream>
#include<string>
using namespace std;
class Score{
public:
Score()
{  times=2; }
Score(int times1)
{  times=times1; }
void InputNameAndScore()
{  for(int i=0;i<times;i++)
  {
       cout<<"请输入学生姓名:"<<endl;
       cin>>Name[i];
       cout<<"请输入科目A成绩:"<<endl;
       cin>>SScore[i][1];
       cout<<"请输入科目B成绩:"<<endl;
       cin>>SScore[i][2];
       cout<<"请输入科目C成绩:"<<endl;
       cin>>SScore[i][3];
   }
}
void ShowNameAndScore()
{      for(int i=0;i<times;i++)
    {
      cout<<"姓名: "<<Name[i]<<" 科目A成绩: "<<SScore[i][1]<<" 科目B成绩 "<<SScore[i][2]<<" 科目C成绩: "<<SScore[i][3]<<endl;
     }
                  }
void ShowStdentAvgScore(int Sid)
{    float avg = 0;
    avg = (SScore[Sid][1]+SScore[Sid][2]+SScore[Sid][3])/3;
    cout<<"姓名: "<<Name[Sid]<<" 平均成绩: "<<avg<<endl;
      }
void ShowClassAvgScore(string ClassName)
{       int Cid;
   float avg = 0;
   if(ClassName == "A") Cid = 1;
   if(ClassName == "B") Cid = 2;
   if(ClassName == "C") Cid = 3;
   for(int i=0;i<times;i++)
   {  avg = avg + SScore[i][Cid]; }
   avg = avg/times;
   cout<<"课程名称: "<<ClassName<<"平均成绩: "<<avg<<endl;
    }

void OrderScore(string ClassName)
{
         int Cid;
  if(ClassName == "A") Cid = 1;
  if(ClassName == "B") Cid = 2;
  if(ClassName == "C") Cid = 3;
  for(int i=0;i<times;i++)
  { SScore1[i] = SScore[i][Cid]; }
  for(int i=0;i<times;i++)
  {  Name1[i] = Name[i];  }
  for(int i=1;i<times;i++)
  {  if(SScore1[i] > SScore1[i-1])
      {  float temp = SScore1[i-1];
         SScore1[i-1] = SScore1[i];
         SScore1[i] = temp;
         string temp1;
         temp1 = Name1[i-1];
         Name1[i-1] = Name1[i];
         Name1[i]= temp1;
       }
    }

    cout<<"课程名称: "<<ClassName<<endl;
    for(int i=0;i<times;i++)
    {
       cout<<"姓名: "<<Name1[i]<<" 成绩: "<<SScore1[i]<<endl;
     }

}
private:
float SScore[100][3],SScore1[100];
string Name[100],Name1[100];
int times;
};
int main()
{  Score x;
   x.InputNameAndScore();
   x.ShowNameAndScore();
   x.ShowStdentAvgScore(1);
   x.ShowClassAvgScore("A");
   x.OrderScore("B");
   return 0;
}
//Copyright ©2021-2099 HaoranSun. All rights reserved