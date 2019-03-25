#ifndef _GAME_
#define _GAME_

#include "GameManager.h"

class Game : public GameManager
{
protected:
	Game() : GameInstance(nullptr) {}
	Game(GameManager*& obj) {
		GameInstance = new GameManager();
		obj = GameInstance;
	}
	~Game() { delete[]GameInstance; }
	virtual void endGame() = 0;
	virtual void view() const = 0;
public:
	void startGame() {
		while (GameInstance->analysis()) {
			view();
		}
		endGame();
	}
private:
	GameManager *GameInstance;
};

#endif // !_GAME_