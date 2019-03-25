#include "GameManager.h"
#include <fstream>
#include <iostream>


GameManager::GameManager()
	:
	gameField(nullptr)
	, gameFieldTemporary(nullptr)
	, rows(1)
	, cols(1)
	, gameRunning(0)
	, deltaTime(200)
{
	std::fstream file;
	file.open("data.ini", std::ios::in);
	file >> rows;
	file >> cols;

	
	gameField = new Cell* [rows];
	for (int i = 0; i < rows; i++) {
		gameField[i] = new Cell[cols];
	}

	gameFieldTemporary = new Cell* [rows];
	for (int i = 0; i < rows; i++) {
		gameFieldTemporary[i] = new Cell[cols];
	}
	
	
	int InitCells;
	int x, y;
	file >> InitCells;

	for (int i = 0; i < InitCells; i++) {
		file >> x;
		file >> y;
		gameField[x][y].revive();
	}


}


GameManager::~GameManager()
{
	for (int i = 0; i < rows; i++) {
		delete[]gameField[i];
	}
	delete[]gameField;

	for (int i = 0; i < rows; i++) {
		delete[]gameFieldTemporary[i];
	}
	delete[]gameFieldTemporary;
}

GameManager::GameManager(const GameManager & copy)
	:
	rows(copy.rows)
	, cols(copy.cols)
	, gameRunning(copy.gameRunning)
	, deltaTime(copy.deltaTime)
{
	delete[]this->gameField;
	gameField = new Cell*[copy.cols];
	for (int i = 0; i < copy.cols; i++) {
		gameField[i] = new Cell[copy.rows];
	}

	delete[]this->gameFieldTemporary;
	gameFieldTemporary = new Cell*[copy.cols];
	for (int i = 0; i < copy.cols; i++) {
		gameFieldTemporary[i] = new Cell[copy.rows];
	}
}

GameManager & GameManager::operator=(const GameManager & equals)
{
	rows = equals.rows;
	cols = equals.cols;
	gameRunning = equals.gameRunning;
	deltaTime = equals.deltaTime;
	for (int i = 0; i < cols; i++) {
		delete[]gameField[i];
	}
	delete[]gameField;
	gameField = new Cell*[equals.cols];
	for (int i = 0; i < equals.cols; i++) {
		gameField[i] = new Cell[equals.rows];
	}

	for (int i = 0; i < cols; i++) {
		delete[]gameFieldTemporary[i];
	}
	delete[]gameFieldTemporary;
	gameFieldTemporary = new Cell*[equals.cols];
	for (int i = 0; i < equals.cols; i++) {
		gameFieldTemporary[i] = new Cell[equals.rows];
	}
	return *this;
}

bool GameManager::analysis()
{
	int check = 0;
	for (int i = 1; i < rows-1; i++) {
		for (int j = 1; j < cols-1; j++) {
			if (CellAnalysis(i, j)) {
				gameFieldTemporary[i][j].revive();
				++check;
			}
			else
				gameFieldTemporary[i][j].kill();
		}
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			gameField[i][j] = gameFieldTemporary[i][j];
			gameFieldTemporary[i][j].kill();
		}
	}


	if (check != 0)
		return true;
	else
		return false;
}

void GameManager::drawGame()
{
	for (int i = 1; i < rows - 1; i++) {
		for (int j = 1; j < cols - 1; j++) {
			if (gameField[i][j].checkIfLives())
				std::cout << "X";
			else
				std::cout << " ";
		}
		std::cout << std::endl;
	}
	
}

int GameManager::getDeltaTime()
{
	return deltaTime;
}

bool GameManager::CellAnalysis(int i, int j)
{
	int value = NeighboursNum(i,j);

	bool cellSatus = gameField[i][j].checkIfLives();

	if (value == 3) 
		return true;

	if ( value == 2 && cellSatus )
		return true;

	if ((value == 2) && (cellSatus == false)) 
		return false;

	if ( (value < 2) || (value > 3) )
		return false;

	return false;
}

int GameManager::NeighboursNum(int i, int j)
{
	int num = 0;

	for (int i_ = -1; i_ < 2; ++i_) {
		for (int j_ = -1; j_ < 2; ++j_) {
		if ((i_ == 0) && (j_ == 0)) {

		}
			else if (gameField[i + i_][j + j_].checkIfLives()) {
				++num;
			}
		}
	}
	return num;
}