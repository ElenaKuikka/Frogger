#ifndef STAGE

#define STAGE
#include"Field.h"


class Stage {
public:
	Stage() { 
		this->stageSpeed = 70;
		this->tick = 0;
		this->stageScore = 0;
	}
	
	void frogControl();

	void startStage(int attempts, int gameScore);

	bool FrogIsDead();

	bool FrogIsHome();

	bool isStageOver();

	void setScore() {
		this->stageScore = field.frogInNewLine() * 100;
	}
	

	int getScore() {
		return stageScore;
	}

	class Timer {
	public:
		Timer() {
			this->stageTimer = 500;
		}
		void setTimer(unsigned int tick) {
			this->stageTimer = 500 - tick;
		}
		int getStageTimer() {
			return stageTimer;
		}
		bool stageTimeOver();
	private:
		int stageTimer;
	};

	
private:
	Field field;
	int stageSpeed;
	unsigned int tick;
	int stageScore;
	Timer gameTimer;
};

struct Game {
	Game() {
		this->gameScore = 0;
		this->attemptsNumber = 4;
	}
	
	void startGame();

	int getGameScore() {
		return gameScore;
	}
	
	void addGameScore(int score){
		this->gameScore += score;
	}
private:
	int gameScore;
	int attemptsNumber;
};


#endif STAGE
