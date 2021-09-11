#include"Stage.h"

void Stage::startStage(int attempts, int gameScore) {


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

bool Stage::FrogIsDead() {
	if (field.getFrog().isDead()) {
		return true;
	}
	else {
		return false;
	}
}

bool Stage::FrogIsHome() {
	if (field.getFrog().getFrogMemory().isHome()) {
		return true;
	}
	else {
		return false;
	}
}

bool Stage::isStageOver() {
	if (FrogIsDead() || gameTimer.stageTimeOver() || FrogIsHome()) {
		return true;
	}
	else {
		return false;
	}
}

bool Stage::Timer::stageTimeOver() {
	if (stageTimer == 0) {
		return true;
	}
	else {
		return false;
	}
}

void Game::startGame() {

	while (!(attemptsNumber == 0)) {
		Stage *newStage = new Stage;
		newStage->startStage(attemptsNumber, gameScore);
		if (!(newStage->FrogIsHome())) {
			attemptsNumber--;
		}
		gameScore += newStage->getScore();
		delete newStage;
	}
	std::cout << "Game over!\n";
	std::cout << "Your score: " << gameScore;
	std::cout << std::endl;
}