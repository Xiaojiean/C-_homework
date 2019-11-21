//
// Created by Kratos on 2019/11/14.
//

#include <iostream>
#include "enemy.h"
#include "baseOperation.h"

using namespace std;

int main()
{
	int enemy_hp[kEnemyNum] = { 50 , 100, 150, 200, 250 };
	CEnemy* enemies[kEnemyNum];
	for (auto i = 0; i < kEnemyNum; ++i)
	{
		enemies[i] = new class CEnemy(enemy_hp[i]);
	}

	while (true)
	{
		CheckRemainingEnemies(enemies);
		int enemy_id[kAttackNum] = { SelectEnemy(enemies),  SelectEnemy(enemies) };
		const auto skill_kind = AttackWay(enemies[enemy_id[0]]);
		for(auto i = 0; i < kAttackNum; i++)
		{
			if (enemy_id[i] != -1)
			{
				enemies[enemy_id[i]]->hurt(skill_kind);
				if (IsDeath(enemies[enemy_id[i]]))
				{
					delete enemies[enemy_id[i]];
					enemies[enemy_id[i]] = nullptr;
					if (IsPentaKill())
					{
						cout << "ÎåÁ¬¾øÊÀ!" << endl;
						goto end;
					}
				}
			}
		}
	}

	end:
	
	return 0;
}
