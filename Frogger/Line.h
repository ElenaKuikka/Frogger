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

	void driveLeft(Frog &frog) {
		std::vector<GamePoint> tempLine(line);
		for (int i = 1; i < lineSize-2; i++){//!!!!!!!!!Frog memory
			if (tempLine[i + 1].isFrog()){
				line[i] = tempLine[i + 1];
				frog.setLocation(line[i]);
			}
			else{
				line[i] = tempLine[i + 1];
			}
		}
		if (tempLine[1].isFrog()){
			line[lineSize - 2] = tempLine[1];
			frog.setLocation(line[lineSize - 2]);
		}
		else{
			line[lineSize - 2] = tempLine[1];
		}
		
	}

	void driveRight(Frog &frog) {
		std::vector<GamePoint> tempLine(line);
		if (tempLine[lineSize - 2].isFrog()){
			line[1] = tempLine[lineSize - 2];
			frog.setLocation(line[1]);
		}
		else{
			line[1] = tempLine[lineSize - 2];
		}
		
		for (int i = 2; i < lineSize - 1; i++) {
			if (tempLine[i-1].isFrog()){
				line[i] = tempLine[i - 1];
				frog.setLocation(line[i]);
			}
			else{
				line[i] = tempLine[i - 1];
			}
		}
	}

	
private:
	std::vector<GamePoint> line;
	const int lineSize = 17;
	LineSpeed lineSpeed;
};




#endif LINE

