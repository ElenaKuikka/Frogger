#ifndef LINE

#define LINE

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

	/*
	Line &operator=(const Line &firstLine) {
		if (this == &firstLine){
			return *this;
		}
		line = firstLine.line;
		return *this;
	}
	*/
	void driveLeft() {
		std::vector<GamePoint> tempLine(line);
		for (int i = 1; i < lineSize-2; i++){
			line[i].setGameElement(tempLine[i + 1].getGameElement());
		}
		line[lineSize - 2].setGameElement(tempLine[1].getGameElement());
	}

	void driveRight() {
		std::vector<GamePoint> tempLine(line);
		line[1].setGameElement(tempLine[lineSize-2].getGameElement());
		for (int i = 2; i < lineSize - 1; i++) {
			line[i].setGameElement(tempLine[i - 1].getGameElement());
		}
	}
private:
	std::vector<GamePoint> line;
	const int lineSize = 17;
	LineSpeed lineSpeed;
};




#endif LINE

