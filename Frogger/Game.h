#ifndef GAME

#define GAME
#include"Field.h"

class Game {
public:
	Game() { 
		this->gameSpeed = 70;
		this->tick = 0;
		this->gameScore = 0;
	}
	void startGame() {
		
		for (int i = 0; i < 4; i++)
		{
			while (!isStageOver()) {
				tick++;
				gameTimer.setTimer(tick);
				field.printField(tick, gameScore, gameTimer.getStageTimer());
				field.drivePlayingFields(tick, gameSpeed);
				field.FrogDrive();
				setScore();
			}
			//system("cls");
		}
			
	}

	
	bool FrogIsDead() {
		if (field.getFrog().isDead()){
			return true;
		}
		else{
			return false;
		}
	}

	bool FrogIsHome() {
		if (field.getFrog().getFrogMemory().isHome()){
			return true;//gameScore+300
		}
		else {
			return false;
		}
	}

	bool isStageOver() {
		if (FrogIsDead()||gameTimer.stageTimeOver()||FrogIsHome()){
			if (FrogIsHome()){
				field.getFrog().addLives();
			}
			if (FrogIsDead()){
				field.getFrog().changeFrogLocation(GamePoint(13,8));
				field.getFrog().setFrogMemory(GamePoint(13, 8,GamePoint::SAFEPOINT));
			}
			field.getFrog().reduceLives();
			tick == 0;
			gameTimer.setTimer(500);
			return true;
		}
		else{
			return false;
		}
	}

	bool isGameOver() {
		if (field.getFrog().getLives()==0) {
			return true;
		}
		else{
			return false;
		}
	}
	
	void setScore() {
		this->gameScore = field.frogInNewLine() * 100;
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
		bool stageTimeOver() {
			if (stageTimer == 0) {
				return true;
			}
			else {
				return false;
			}
		}
	private:
		int stageTimer;
	};

private:
	Field field;
	int gameSpeed;
	unsigned int tick;
	int gameScore;
	Timer gameTimer;
};

#endif GAME
