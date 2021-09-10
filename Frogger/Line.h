#ifndef LINE

#define LINE

#include"Frog.h"

class Line {
public:
	enum LineSpeed {
		FIRST = 17,
		SECOND = 13,
		THIRD = 11,
		FOURTH = 7
	};
	Line() {
		line.resize(lineSize);
		lineSpeed = FIRST;
	}
	/*
	Line(const Line &lineL) {
		for (int i = 0; i < lineSize; i++){
			this->line[i].setPoint(lineL.line[i].getPositionX(), lineL.line[i].getPositionY(), lineL.line[i].getGameElement());
		}
	}
	*/
	const int getSize() {
		return lineSize;
	}
	LineSpeed getLineSpeed() const {
		return this->lineSpeed;
	}
	GamePoint getLineElement(int index) {
		return line[index];
	}
	void setLineElement(int index, GamePoint point) {
		line[index] = point;
	}
	void setLineSpeed(LineSpeed speed) {
		this->lineSpeed = speed;
	}

	void printLine() {
		for (int i = 0; i < lineSize; i++){
			line[i].printPoint();
		}
	}

	friend class Frog;

	void driveRightRoad(Frog &frogObj) {
		std::vector<GamePoint> tempLine(line);
		
		if (tempLine[lineSize - 2].isFrog()) {
			line[1].setGameElement(frogObj.getFrogMemory().getGameElement());
			frogObj.setFrogMemory(tempLine[lineSize - 3]);
		}
		else if (!(tempLine[1].isFrog())) {
			line[1].setGameElement(tempLine[lineSize - 2].getGameElement());
		}

		for (int i = lineSize-2; i > 3; i--) {
			if (tempLine[i - 1].isFrog()){
				line[i].setGameElement(frogObj.getFrogMemory().getGameElement());
				frogObj.setFrogMemory(tempLine[i - 2]);
				i--;
			}
			else if(!(tempLine[i].isFrog())){
				line[i].setGameElement(tempLine[i - 1].getGameElement());
			}
		}

		if (tempLine[2].isFrog()) {
			line[3].setGameElement(frogObj.getFrogMemory().getGameElement());
			frogObj.setFrogMemory(tempLine[1]);
		}
		else if (!(tempLine[3].isFrog())) {
			line[3].setGameElement(tempLine[2].getGameElement());
		}

		if (tempLine[1].isFrog()) {
			line[2].setGameElement(frogObj.getFrogMemory().getGameElement());
			frogObj.setFrogMemory(tempLine[lineSize - 2]);
		}
		else if (!(tempLine[2].isFrog())) {
			line[2].setGameElement(tempLine[1].getGameElement());
		}

		checkFrogsNumber(frogObj);

	}

	void driveLeftRoad(Frog &frogObj) {

		std::vector<GamePoint> tempLine(line);

		if (tempLine[2].isFrog()) {
			line[1].setGameElement(frogObj.getFrogMemory().getGameElement());
			frogObj.setFrogMemory(tempLine[3]);
		}
		else if (!(tempLine[1].isFrog())) {
			line[1].setGameElement(tempLine[2].getGameElement());
		}

		for (int i = 2; i < lineSize - 3; i++) {
			if (tempLine[i + 1].isFrog()) {
				line[i].setGameElement(frogObj.getFrogMemory().getGameElement());
				frogObj.setFrogMemory(tempLine[i + 2]);
				i++;
			}
			else {
				line[i].setGameElement(tempLine[i + 1].getGameElement());
			}
		}

		if (tempLine[lineSize - 2].isFrog()) {
			line[lineSize - 3].setGameElement(frogObj.getFrogMemory().getGameElement());
			frogObj.setFrogMemory(tempLine[1]);
		}
		else if (!(tempLine[lineSize - 3].isFrog())) {
			line[lineSize - 3].setGameElement(tempLine[lineSize - 2].getGameElement());
		}

		if (tempLine[1].isFrog()) {
			line[lineSize - 2].setGameElement(frogObj.getFrogMemory().getGameElement());
			frogObj.setFrogMemory(tempLine[2]);
		}
		else if (!(tempLine[lineSize - 2].isFrog())) {
			line[lineSize - 2].setGameElement(tempLine[1].getGameElement());
		}

		checkFrogsNumber(frogObj);

	}

	void driveLeftRiver(Frog &frog) {
		
		std::vector<GamePoint> tempLine(line);
		for (int i = 1; i < lineSize - 2; i++) {
			if (tempLine[i + 1].isFrog()){
				line[i].setGameElement(tempLine[i + 1].getGameElement());
				frog.changeFrogLocation(line[i]);
			}
			else{
				line[i].setGameElement(tempLine[i + 1].getGameElement());
			}
		}
		if (tempLine[1].isFrog()){
			line[lineSize - 2].setGameElement(tempLine[1].getGameElement());
			frog.changeFrogLocation(line[lineSize - 2]);
		}
		else{
			line[lineSize - 2].setGameElement(tempLine[1].getGameElement());
		}

		checkFrogsNumber(frog);
		
	}

	void driveRightRiver(Frog &frog) {

		std::vector<GamePoint> tempLine(line);
		if (tempLine[lineSize - 2].isFrog()){
			line[1].setGameElement(tempLine[lineSize - 2].getGameElement());
			frog.changeFrogLocation(line[1]);
		}
		else{
			line[1].setGameElement(tempLine[lineSize - 2].getGameElement());
		}
		for (int i = 2; i < lineSize - 1; i++) {
			if (tempLine[i - 1].isFrog()){
				line[i].setGameElement(tempLine[i - 1].getGameElement());
				frog.changeFrogLocation(line[i]);
			}
			else{
				line[i].setGameElement(tempLine[i - 1].getGameElement());
			}
		}

		checkFrogsNumber(frog);
		
	}

	
private:
	std::vector<GamePoint> line;
	const int lineSize = 17;
	LineSpeed lineSpeed;

	void checkFrogsNumber(Frog &frog) {
		int frogCheck{ 0 };
		for (int j = 0; j < lineSize; j++) {
			if (line[j].isFrog()) {
				frogCheck++;
			}
		}
		if (frogCheck > 1) {
			for (int k = 0; k < lineSize; k++) {
				if ((line[k].isFrog()) && !(frog.isFrogLocation(line[k]))) {
					line[k].setGameElement(frog.getFrogMemory().getGameElement());
				}
			}
		}
	}
};




#endif LINE

