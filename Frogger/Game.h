#ifndef GAME

#define GAME
#include"Field.h"

class Game {
public:
	Game() { 
		this->gameSpeed = 70;
		this->tick = 0;
	
	}
	void startGame() {
		
		while (field.gameNotOver())//gameOver
		{
			tick++;
			field.printField(tick);
			field.drivePlayingFields(tick, gameSpeed);
			field.FrogDrive();
		}
	}

	bool GameOver() {
		
	}

	bool isNextStage() {

	}
private:
	Field field;
	int gameSpeed;
	unsigned int tick;
};




#endif GAME
