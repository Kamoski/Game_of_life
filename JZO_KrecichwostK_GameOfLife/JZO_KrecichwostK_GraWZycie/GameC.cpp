#include "GameC.h"
#include <iostream>
#include <Windows.h>


GameC::GameC()
	:
	Game(GameInstance)
{
}


GameC::~GameC()
{
	delete[]GameInstance;
}

GameC::GameC(const GameC & copy)
{
	delete[]GameInstance;
	GameInstance = copy.GameInstance;
}

GameC & GameC::operator=(const GameC & equals)
{
	delete[]GameInstance;
	GameInstance = equals.GameInstance;
	return *this;
}


void GameC::endGame()
{
	Sleep(200);
	system("exit");
}

void GameC::view() const
{
	GameInstance->drawGame();
	Sleep(GameInstance->getDeltaTime());
	system("cls");
}
