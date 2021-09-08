#ifndef GAME

#define GAME
#include"Field.h"

class Game {
public:
	Game() { this->gameSpeed = 70; }
	void startGame() {
		unsigned int tick{ 0 };
		while (true)//gameOver
		{
			tick++;
			field.printField(tick);
			field.drivePlayingFields(tick, gameSpeed);
		}
	}

private:
	Field field;
	int gameSpeed;
};




#endif GAME
