#include"Stage.h"

void Stage::frogControl() {
	if (_kbhit()) {
		switch (_getch()) {
		case 'a':
		{
			this->field.setStrategy(new DriveLeft);
			this->field.FrogDrive();
			break;
		}
		case 'd':
		{
			this->field.setStrategy(new DriveRight);
			this->field.FrogDrive();
			break;
		}
		case 'w':
		{
			this->field.setStrategy(new DriveUp);
			this->field.FrogDrive();
			break;
		}
		case 's':
		{
			this->field.setStrategy(new DriveDown);
			this->field.FrogDrive();
			break;
		}
		default:
			break;
		}
	}
}

void Stage::startStage(int attempts, int gameScore) {


	while (!isStageOver()) {
		tick++;
		gameTimer.setTimer(tick);
		field.printField(tick, stageScore, gameScore, gameTimer.getStageTimer(), attempts);
		field.drivePlayingFields(tick, stageSpeed);
		frogControl();
		setScore();
	}
	system("cls");

}

bool Stage::FrogIsDead(){
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
	std::cout << "FROGGER RULES\n\n";
	std::cout << "Move the frog using 'a','d','w','s'.\n";
	std::cout << "Object is to safely maneuver frog to its home(H) in a limited time.\n";
	std::cout << "Cross the highway without hitting a car(C) and cross the river(-) without falling.\n\n";
	std::cout << "Press any key to continue.\n";
	
	do{
		Sleep(5);
	} while (!(_kbhit()));
	system("cls");
	
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