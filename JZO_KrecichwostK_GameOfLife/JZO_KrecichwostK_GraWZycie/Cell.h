#ifndef _CELL_
#define _CELL_
class Cell
{
public:
	Cell();
	~Cell();
	void kill();
	void revive();
	bool checkIfLives();
private:
	bool isAlive;

};

#endif // !_CELL_
