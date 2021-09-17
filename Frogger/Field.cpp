#include"Field.h"

Field::Field() {

	boundary.resize(rowSize * 4);
	int k{ 0 };
	for (int i = 0; i < colSize; i++) {
		boundary[k] = GamePoint(0, i);
		k++;
	}
	for (int t = 1; t < 14; t++) {
		boundary[k] = GamePoint(t, 0);
		k++;
	}
	for (int r = 1; r < 14; r++) {
		boundary[k] = GamePoint(r, 16);
		k++;
	}
	for (int h = 0; h < colSize; h++) {
		boundary[k] = GamePoint(14, h);
		k++;
	}

	playingField.resize(rowSize);

	for (int i = 0; i < playingField[0].getSize(); i++) {
		playingField[0].setLineElement(i, GamePoint(0, i, GamePoint::BOUNDARY));
	}
	for (int i = 0; i < playingField[1].getSize(); i++) {
		if (isBoundary(GamePoint(1, i))) {
			playingField[1].setLineElement(i, GamePoint(1, i, GamePoint::BOUNDARY));
		}
		else if (i == 2 || i == 5 || i == 8 || i == 11 || i == 14) {
			playingField[1].setLineElement(i, GamePoint(1, i, GamePoint::HOME));
		}
		else {
			playingField[1].setLineElement(i, GamePoint(1, i, GamePoint::STONE));
		}
	}
	for (int i = 0; i < playingField[2].getSize(); i++) {
		if (isBoundary(GamePoint(2, i))) {
			playingField[2].setLineElement(i, GamePoint(2, i, GamePoint::BOUNDARY));
		}
		else if (i == 3 || i == 4 || i == 9 || i == 10 || i == 15) {
			playingField[2].setLineElement(i, GamePoint(2, i, GamePoint::RIVER));
		}
		else {
			playingField[2].setLineElement(i, GamePoint(2, i, GamePoint::TREE));
		}
	}
	for (int i = 0; i < playingField[3].getSize(); i++) {
		if (isBoundary(GamePoint(3, i))) {
			playingField[3].setLineElement(i, GamePoint(3, i, GamePoint::BOUNDARY));
		}
		else if (i == 2 || i == 3 || i == 8 || i == 9 || i == 12 || i == 13) {
			playingField[3].setLineElement(i, GamePoint(3, i, GamePoint::TURTLE));
		}
		else {
			playingField[3].setLineElement(i, GamePoint(3, i, GamePoint::RIVER));
		}
	}
	for (int i = 0; i < playingField[4].getSize(); i++) {
		if (isBoundary(GamePoint(4, i))) {
			playingField[4].setLineElement(i, GamePoint(4, i, GamePoint::BOUNDARY));
		}
		else if (i == 4 || i == 5 || i == 6 || i == 13 || i == 14) {
			playingField[4].setLineElement(i, GamePoint(4, i, GamePoint::RIVER));
		}
		else {
			playingField[4].setLineElement(i, GamePoint(4, i, GamePoint::TREE));
		}
	}
	for (int i = 0; i < playingField[5].getSize(); i++) {
		if (isBoundary(GamePoint(5, i))) {
			playingField[5].setLineElement(i, GamePoint(5, i, GamePoint::BOUNDARY));
		}
		else if (i == 5 || i == 6 || i == 7 || i == 11 || i == 12 || i == 13) {
			playingField[5].setLineElement(i, GamePoint(5, i, GamePoint::RIVER));
		}
		else {
			playingField[5].setLineElement(i, GamePoint(5, i, GamePoint::TREE));
		}
	}
	for (int i = 0; i < playingField[6].getSize(); i++) {
		if (isBoundary(GamePoint(6, i))) {
			playingField[6].setLineElement(i, GamePoint(6, i, GamePoint::BOUNDARY));
		}
		else if (i == 4 || i == 8 || i == 12) {
			playingField[6].setLineElement(i, GamePoint(6, i, GamePoint::RIVER));
		}
		else {
			playingField[6].setLineElement(i, GamePoint(6, i, GamePoint::TURTLE));
		}
	}
	for (int i = 0; i < playingField[7].getSize(); i++) {
		if (isBoundary(GamePoint(7, i))) {
			playingField[7].setLineElement(i, GamePoint(7, i, GamePoint::BOUNDARY));
		}
		else {
			playingField[7].setLineElement(i, GamePoint(7, i, GamePoint::SAFEPOINT));
		}
	}
	for (int i = 0; i < playingField[8].getSize(); i++) {
		if (isBoundary(GamePoint(8, i))) {
			playingField[8].setLineElement(i, GamePoint(8, i, GamePoint::BOUNDARY));
		}
		else if (i == 2 || i == 3 || i == 12 || i == 13) {
			playingField[8].setLineElement(i, GamePoint(8, i, GamePoint::CAR));
		}
		else {
			playingField[8].setLineElement(i, GamePoint(8, i, GamePoint::ROAD));
		}
	}
	for (int i = 0; i < playingField[9].getSize(); i++) {
		if (isBoundary(GamePoint(9, i))) {
			playingField[9].setLineElement(i, GamePoint(9, i, GamePoint::BOUNDARY));
		}
		else if (i == 3) {
			playingField[9].setLineElement(i, GamePoint(9, i, GamePoint::CAR));
		}
		else {
			playingField[9].setLineElement(i, GamePoint(9, i, GamePoint::ROAD));
		}
	}
	for (int i = 0; i < playingField[10].getSize(); i++) {
		if (isBoundary(GamePoint(10, i))) {
			playingField[10].setLineElement(i, GamePoint(10, i, GamePoint::BOUNDARY));
		}
		else if (i == 3 || i == 11 || i == 15) {
			playingField[10].setLineElement(i, GamePoint(10, i, GamePoint::CAR));
		}
		else {
			playingField[10].setLineElement(i, GamePoint(10, i, GamePoint::ROAD));
		}
	}
	for (int i = 0; i < playingField[11].getSize(); i++) {
		if (isBoundary(GamePoint(11, i))) {
			playingField[11].setLineElement(i, GamePoint(11, i, GamePoint::BOUNDARY));
		}
		else if (i == 1 || i == 5 || i == 10) {
			playingField[11].setLineElement(i, GamePoint(11, i, GamePoint::CAR));
		}
		else {
			playingField[11].setLineElement(i, GamePoint(11, i, GamePoint::ROAD));
		}
	}
	for (int i = 0; i < playingField[12].getSize(); i++) {
		if (isBoundary(GamePoint(12, i))) {
			playingField[12].setLineElement(i, GamePoint(12, i, GamePoint::BOUNDARY));
		}
		else if (i == 1 || i == 8 || i == 14) {
			playingField[12].setLineElement(i, GamePoint(12, i, GamePoint::CAR));
		}
		else {
			playingField[12].setLineElement(i, GamePoint(12, i, GamePoint::ROAD));
		}
	}
	for (int i = 0; i < playingField[13].getSize(); i++) {
		if (isBoundary(GamePoint(13, i))) {
			playingField[13].setLineElement(i, GamePoint(13, i, GamePoint::BOUNDARY));
		}
		else if (i == 8) {
			playingField[13].setLineElement(i, GamePoint(13, i, GamePoint::FROG));
		}
		else {
			playingField[13].setLineElement(i, GamePoint(13, i, GamePoint::SAFEPOINT));
		}
	}
	for (int i = 0; i < playingField[14].getSize(); i++) {
		playingField[14].setLineElement(i, GamePoint(14, i, GamePoint::BOUNDARY));
	}
	setLinesSpeed();

	this->strategy = nullptr;
}

void Field::printField(unsigned int tick, int score, int gameScore, int timer, int attempts) {

	HANDLE hStdOut;
	COORD cPosition;
	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	cPosition.X = 0;
	cPosition.Y = 0;

	for (int i = 0; i < rowSize; i++) {
		SetConsoleCursorPosition(hStdOut, cPosition);
		cPosition.Y++;

		playingField[i].printLine();

		std::cout << "\n";

	}
	std::cout << std::endl;
	std::cout << "Timer: " << timer;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Score: " << gameScore + score;
	std::cout << std::endl;
	std::cout << "Attempts number: " << attempts;
}

void Field::drivePlayingFields(unsigned int tick, int gameSpeed) {
	Sleep(gameSpeed);
	if (tick % playingField[5].getLineSpeed() == 0) {
		playingField[5].driveRightRiver(frog);
		playingField[11].driveRightRoad(frog);
		playingField[12].driveLeftRoad(frog);
	}
	if (tick % playingField[2].getLineSpeed() == 0) {
		playingField[2].driveRightRiver(frog);
		playingField[3].driveLeftRiver(frog);
		playingField[10].driveLeftRoad(frog);
	}
	if (tick % playingField[4].getLineSpeed() == 0) {
		playingField[4].driveRightRiver(frog);
		playingField[8].driveLeftRoad(frog);
	}
	if (tick % playingField[6].getLineSpeed() == 0) {
		playingField[6].driveLeftRiver(frog);
		playingField[9].driveRightRoad(frog);
	}
}

bool Field::isBoundary(const GamePoint &point) const {
	for (int i = 0; i < boundary.size(); i++) {
		if (boundary[i] == point) {
			return true;
		}
	}
	return false;
}

int Field::frogInNewLine() {
	int k{ 0 };
	for (int i = 0; i < playingField.size(); i++) {
		if (playingField[i].getFrogInLine()) {
			k++;
		}
	}
	if (frog.getFrogMemory().isHome()) {
		k += 2;
	}
	return k;
}

void Field::setStrategy(DriveStrategy *strategy) {
	if (!(this->strategy)) {
		delete this->strategy;
	}
	this->strategy = strategy;
}

void Field::setLinesSpeed() {
	playingField[5].setLineSpeed(Line::FIRST);
	playingField[11].setLineSpeed(Line::FIRST);
	playingField[12].setLineSpeed(Line::FIRST);

	playingField[2].setLineSpeed(Line::SECOND);
	playingField[3].setLineSpeed(Line::SECOND);
	playingField[10].setLineSpeed(Line::SECOND);

	playingField[4].setLineSpeed(Line::THIRD);
	playingField[8].setLineSpeed(Line::THIRD);

	playingField[6].setLineSpeed(Line::FOURTH);
	playingField[9].setLineSpeed(Line::FOURTH);
}