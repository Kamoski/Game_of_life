#ifndef _GAMEMANAGER_
#define _GAMEMANAGER_

#include "Cell.h"

class GameManager
{
public:
	GameManager();
	virtual ~GameManager();
	GameManager(const GameManager&copy);
	GameManager& operator=( const GameManager & equals);

	bool analysis();
	void drawGame();

	int getDeltaTime();
private:
	Cell **gameField;
	Cell **gameFieldTemporary;

	int rows, cols;
	bool gameRunning;
	int deltaTime;
	bool CellAnalysis(int i, int j);
	int NeighboursNum(int i, int j);

};

#endif // !_GAMEMANAGER_