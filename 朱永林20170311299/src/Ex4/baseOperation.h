//
// Created by Kratos on 2019/11/14.
//

#pragma once

constexpr auto kEnemyNum = 5;
constexpr auto kAttackNum = 2;

int SelectEnemy(CEnemy** enemies);
int AttackWay(CEnemy* en);
bool IsDeath(CEnemy* en);
int CheckRemainingEnemies(CEnemy** enemies);
bool IsPentaKill();
