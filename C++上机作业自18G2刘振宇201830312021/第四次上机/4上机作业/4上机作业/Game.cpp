#include <iostream>
#include "4上机.h"
using namespace std;
Game::Game(int LP, int PhysicResistance, int MagicResistance, int AttackFrequency)
{
	g1 = LP; g2 = PhysicResistance; g3 = MagicResistance; g4 = AttackFrequency;
}
void Game::showGame()
{
	cout << "防御塔的血量:" << g1 << endl;
	cout << "防御塔的物理抗性:" << g2 << endl;
	cout << "防御塔的魔法抗性:" << g3 << endl;
	cout << "防御塔的攻击频率:" << g4 << endl;
}
void Game::Fight()
{
	g1 = g1 - 500;
}
Game::~Game()
{
	cout << "防御塔被拆除！！！" << endl;
	cout << "该防御塔析构函数已启动" << endl;
	cout << "该防御塔析构函数已启动" << endl;
	cout << "该防御塔析构函数已启动（重要的事情说三遍）" << endl;
};