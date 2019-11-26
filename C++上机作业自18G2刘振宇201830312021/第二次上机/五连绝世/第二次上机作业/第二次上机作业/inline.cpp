#include <iostream>
#include"hero.h"
using namespace std;
void jishu()
{
	if (jishashu == 1) //一血
	{
		cout << "frist blood！！" << endl;
	}
	 if (jishashu == 2) //双杀
	  {
		cout << "double kill！！" << endl;
	  }
	  if (jishashu == 3) //三杀 大杀特杀
	   {
		cout << "triple kill！！" << endl;
	   }
	   if (jishashu == 4) //四杀 杀人如麻
	    {
		cout << "quatary kill！！" << endl;
	    }
	     if (jishashu >= 5) //五连绝世 势不可挡
	       {
		    cout << "penta kill！！" << endl;
		    cout << "！恭喜你成功拿到五杀！" << endl;
		    cout << "！团灭！" << endl;
		    return win();
	       }
}