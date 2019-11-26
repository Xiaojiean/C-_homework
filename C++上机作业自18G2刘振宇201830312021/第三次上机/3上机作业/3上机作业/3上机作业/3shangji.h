#include <iostream>
using namespace std;
class Game
{
public:
	Game();
	Game(int LP, int PhysicResistance, int MagicResistance, int AttackFrequency);
	int g1, g2, g3, g4, g5;
	void showGame();
	void Fight();
	~Game();
};