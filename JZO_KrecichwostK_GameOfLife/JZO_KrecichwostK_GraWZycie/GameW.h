#ifndef _GAMEW_
#define _GAMEW_

#include "Game.h"
#include "GameManager.h"

class GameW : public virtual Game
{
public:
	GameW();
	virtual ~GameW();
	GameW(const GameW & copy);
	GameW& operator = (const GameW & equals);

	virtual void endGame();
	virtual void view();

private:
	GameManager *GameInstance;
};

#endif // !_GAMEW_