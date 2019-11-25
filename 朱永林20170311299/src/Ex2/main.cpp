//
// Created by Kratos on 2019/11/14.
//

#include <iostream>
#include "enemy.h"
#include "baseOperation.h"

using namespace std;

int main()
{
	int enemy_hp[kEnemyNum] = { 50, 100, 150, 200, 250 };
	CEnemy* enemies[kEnemyNum];
	for (auto i = 0; i < kEnemyNum; ++i)
	{
		enemies[i] = new class CEnemy(enemy_hp[i]);
	}

	while (true)
	{
		CheckRemainingEnemies(enemies);
		const auto enemy_id = SelectEnemy(enemies);
		enemies[enemy_id]->hurt(AttackWay(enemies[enemy_id]));
		if (IsDeath(enemies[enemy_id]))
		{
			delete enemies[enemy_id];
			enemies[enemy_id] = nullptr;
			if (IsPentaKill())
			{
				cout << "ÎåÁ¬¾øÊÀ!" << endl;
				break;
			}
		}
	}

	return 0;
}
