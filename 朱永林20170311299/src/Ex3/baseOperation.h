//
// Created by Kratos on 2019/11/14.
//

#pragma once

constexpr auto kEnemyNum = 5;

int SelectEnemy(CEnemy** enemies);
int AttackWay(CEnemy* en);
bool IsDeath(CEnemy* en);
void CheckRemainingEnemies(CEnemy** enemies);
bool IsPentaKill();
