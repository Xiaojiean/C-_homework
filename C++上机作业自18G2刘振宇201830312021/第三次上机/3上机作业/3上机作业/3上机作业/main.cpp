#include <iostream>
#include "3shangji.h"
using namespace std;
int main()
{
	cout << "¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­" << endl;
	cout << "¡­¡­¡­¡­¡­¡­»¶Ó­À´µ½ÍõÕßÈÙÒ«!¡­¡­¡­¡­¡­¡­" << endl;
	cout << "ÓÉÓÚÌìÃÀÉè¼Æ¾­·Ñ½ôÕÅ" << endl;
	cout << "¼±Ðè²ð³ý·ÀÓùËþÂôÇ®" << endl;
	cout << "Çë¾¡¿ì»÷»ÙÒ»×ù·ÀÓùËþ" << endl;
	cout << "¡­¡­¡­¡­¡­¡­¡­¡­¿ªÊ¼ÓÎÏ·¡­¡­¡­¡­¡­¡­¡­¡­" << endl;
	cout << "1.¹¥»÷·ÀÓùËþ" << endl;
	cout << "2.ÏÔÊ¾·ÀÓùËþ×´Ì¬" << endl;
	cout << "3.½áÊøÓÎÏ·" << endl;
	Game Fangyuta(1000, 999, 999, 1);
	int x;
	cin >> x;
	while (x != 3)
	{
		if (x == 2)
		  {Fangyuta.showGame();}
		else
			switch (x)
		{case 1: Fangyuta.Fight(); Fangyuta.showGame();
				if (Fangyuta.g1 == 0)
				{
					cout << "ÆÆ»µ·ÀÓùËþ" << endl;
					Fangyuta.~Game();
				}break;
			default:cout << "Sorry,You are not allowed to do something else" << endl; break;}
		cin >> x;
     }
return  0;
}