#ifndef FIELD

#define FIELD

#include "GamePoint.h"
#include"Line.h"
#include"Frog.h"

class Field
{
public:
	Field() {
		/*
		field.resize(rowSize);
		for (int i = 0; i < rowSize; i++){
			field[i].resize(colSize);
			for (int j = 0; j < colSize; j++){
				field[i][j] = GamePoint(i, j);
			}
		}
		*/
		boundary.resize(rowSize * 4);
		int k{ 0 };
		for (int i = 0; i < colSize; i++){
			boundary[k] = GamePoint(0, i);
			k++;
		}
		for (int t = 1; t < 14; t++){
			boundary[k] = GamePoint(t, 0);
			k++;
		}
		for (int r = 1; r < 14; r++) {
			boundary[k] = GamePoint(r, 16);
			k++;
		}
		for (int h = 0; h < colSize; h++){
			boundary[k] = GamePoint(14, h);
			k++;
		}
		
		playingField.resize(rowSize);
		
		for (int i = 0; i < playingField[0].getSize(); i++){
			playingField[0].setLineElement(i, GamePoint(0, i, GamePoint::BOUNDARY));
		}
		for (int i = 0; i < playingField[1].getSize(); i++) {
			if (isBoundary(GamePoint(1,i))){
				playingField[1].setLineElement(i, GamePoint(1, i, GamePoint::BOUNDARY));
			}
			else if(i==2||i==5||i==8||i==11||i==14){
				playingField[1].setLineElement(i, GamePoint(1, i, GamePoint::HOME));
			}
			else{
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
			else if (i == 2 || i == 3 || i == 8 || i == 9 || i == 12 || i==13) {
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
			else if (i == 5 || i == 6 || i == 7 || i == 11 || i == 12|| i == 13) {
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
			else{
				playingField[7].setLineElement(i, GamePoint(7, i, GamePoint::SAFEPOINT));
			}
		}
		for (int i = 0; i < playingField[8].getSize(); i++) {
			if (isBoundary(GamePoint(8, i))) {
				playingField[8].setLineElement(i, GamePoint(8, i, GamePoint::BOUNDARY));
			}
			else if (i == 2 || i == 3 || i == 12|| i == 13) {
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
		for (int i = 0; i < playingField[13].getSize(); i++){
			if (isBoundary(GamePoint(13, i))) {
				playingField[13].setLineElement(i, GamePoint(13, i, GamePoint::BOUNDARY));
			}
			else if(i == 8){
				playingField[13].setLineElement(i, GamePoint(13, i, GamePoint::FROG));
			}
			else{
				playingField[13].setLineElement(i, GamePoint(13, i, GamePoint::SAFEPOINT));
			}
		}
		for (int i = 0; i < playingField[14].getSize(); i++) {
			playingField[14].setLineElement(i, GamePoint(14, i, GamePoint::BOUNDARY));
		}
		setLinesSpeed();
	}

	void printField(unsigned int tick) {

		HANDLE hStdOut;
		COORD cPosition;
		hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		cPosition.X = 0;
		cPosition.Y = 0;

		for (int i = 0; i < rowSize; i++){
			SetConsoleCursorPosition(hStdOut, cPosition);
			cPosition.Y++;
			
			playingField[i].printLine();
			
			std::cout << "\n";
		}
		std::cout << std::endl;
		std::cout << tick;
		std::cout << std::endl;
	}

	void drivePlayingFields(unsigned int tick, int gameSpeed) {//!!!!!
		Sleep(gameSpeed);
		if (tick % playingField[5].getLineSpeed() == 0 ) {
			playingField[5].driveRight(frog);
			playingField[11].driveRight(frog);
			playingField[12].driveLeft(frog);
		}
		if (tick % playingField[2].getLineSpeed() == 0) {
			playingField[2].driveRight(frog);
			playingField[3].driveLeft(frog);
			playingField[10].driveLeft(frog);
		}
		if (tick % playingField[4].getLineSpeed() == 0) {
			playingField[4].driveRight(frog);
			playingField[8].driveLeft(frog);
		}
		if (tick % playingField[6].getLineSpeed() == 0) {
			playingField[6].driveLeft(frog);
			playingField[9].driveRight(frog);
		}
		/*
		playingField[2].driveRight();
		playingField[3].driveLeft();
		playingField[4].driveRight();
		playingField[5].driveRight();
		playingField[6].driveLeft();
		playingField[8].driveLeft();
		playingField[9].driveRight();
		playingField[10].driveLeft();
		playingField[11].driveRight();
		playingField[12].driveLeft();
		*/
	}
	
	bool isBoundary(const GamePoint &point) const {
		for (int i = 0; i < boundary.size(); i++) {
			if (boundary[i] == point) {
				return true;
			}
		}
		return false;
	}

	std::vector<Line> getPlayingField() {
		return playingField;
	}

	Frog getFrog() {
		return frog;
	}

	void FrogDrive() {
		Position FrogPositionX = frog.getFrogLocation().getPositionX();
		Position FrogPositionY = frog.getFrogLocation().getPositionY();
		GamePoint temp;
		if (_kbhit()) {
			switch (_getch()) {
			case 'a':
			{
				if (!(isBoundary(GamePoint(FrogPositionX, FrogPositionY - 1)))) {
					temp = playingField[FrogPositionX].getLineElement(FrogPositionY - 1);
					playingField[FrogPositionX].setLineElement(FrogPositionY - 1, GamePoint(FrogPositionX, FrogPositionY - 1, GamePoint::FROG));
					playingField[FrogPositionX].setLineElement(FrogPositionY, GamePoint(FrogPositionX, FrogPositionY, frog.getFrogMemory().getGameElement()));
					frog.setFrogMemory(temp);
					frog.setLocation(playingField[FrogPositionX].getLineElement(FrogPositionY - 1));//!!!!!!!!!!!!!!
				}
				else {
					break;
				}
				break;
			}
			case 'd':
			{
				if (!(isBoundary(GamePoint(FrogPositionX, FrogPositionY + 1)))) {
					temp = playingField[FrogPositionX].getLineElement(FrogPositionY + 1);
					playingField[FrogPositionX].setLineElement(FrogPositionY + 1, GamePoint(FrogPositionX, FrogPositionY + 1, GamePoint::FROG));
					playingField[FrogPositionX].setLineElement(FrogPositionY, GamePoint(FrogPositionX, FrogPositionY, frog.getFrogMemory().getGameElement()));
					frog.setFrogMemory(temp);
					frog.setLocation(playingField[FrogPositionX].getLineElement(FrogPositionY + 1));
				}
				else {
					break;
				}
				break;
			 }
			case 'w':
			{
				if (!(isBoundary(GamePoint(FrogPositionX-1, FrogPositionY)))) {
					temp = playingField[FrogPositionX-1].getLineElement(FrogPositionY);
					playingField[FrogPositionX-1].setLineElement(FrogPositionY, GamePoint(FrogPositionX-1, FrogPositionY, GamePoint::FROG));
					playingField[FrogPositionX].setLineElement(FrogPositionY, GamePoint(FrogPositionX, FrogPositionY, frog.getFrogMemory().getGameElement()));
					frog.setFrogMemory(temp);
					frog.setLocation(playingField[FrogPositionX-1].getLineElement(FrogPositionY));
					
				}
				else {
					break;
				}
				break;
			}
			case 's':
			{
				if (!(isBoundary(GamePoint(FrogPositionX + 1, FrogPositionY)))) {
					temp = playingField[FrogPositionX + 1].getLineElement(FrogPositionY);
					playingField[FrogPositionX + 1].setLineElement(FrogPositionY, GamePoint(FrogPositionX + 1, FrogPositionY, GamePoint::FROG));
					playingField[FrogPositionX].setLineElement(FrogPositionY, GamePoint(FrogPositionX, FrogPositionY, frog.getFrogMemory().getGameElement()));
					frog.setFrogMemory(temp);
					frog.setLocation(playingField[FrogPositionX + 1].getLineElement(FrogPositionY));
				}
				else {
					break;
				}
				break;
			
			}
			default:
				break;
			}
		}
		
	}
private:
	std::vector<GamePoint> boundary;
	std::vector<Line> playingField;
	//std::vector<std::vector<GamePoint>> field;
	const int rowSize = 15;
	const int colSize = 17;
	Frog frog;

	void setLinesSpeed() {
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

};

#endif FIELD