#ifndef _GAMEC_
#define _GAMEC_

#include "Game.h"
#include "GameManager.h"

class GameC : public Game
{
public:
	GameC();
	virtual ~GameC();
	GameC(const GameC & copy);
	GameC& operator = (const GameC&equals);
	virtual void view() const;


private:
	virtual void endGame();
	GameManager *GameInstance;
};

#endif // !_GAMEC_