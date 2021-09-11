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
	void startStage(int attempts, int gameScore) {
		
		
			while (!isStageOver()) {
				tick++;
				gameTimer.setTimer(tick);
				field.printField(tick, stageScore, gameScore, gameTimer.getStageTimer(), attempts);
				field.drivePlayingFields(tick, stageSpeed);
				field.FrogDrive();
				setScore();
			}
			system("cls");
			
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
			return true;
		}
		else {
			return false;
		}
	}

	bool isStageOver() {
		if (FrogIsDead()||gameTimer.stageTimeOver()||FrogIsHome()){
			return true;
		}
		else{
			return false;
		}
	}

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
	
	void startGame() {
		
		while (!(attemptsNumber == 0)){
			Stage *newStage = new Stage;
			newStage->startStage(attemptsNumber, gameScore);
			if (!(newStage->FrogIsHome())){
				attemptsNumber--;
			}
			gameScore += newStage->getScore();
			delete newStage;
		}
		std::cout << "Game over!\n";
		std::cout << "Your score: " << gameScore;
		std::cout << std::endl;
	}

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
