#ifndef FIELD

#define FIELD

#include "GamePoint.h"
#include"Line.h"
#include"Frog.h"


class Field
{
public:
	
	Field();
	
	void printField(unsigned int tick, int score, int gameScore, int timer, int attempts);

	void drivePlayingFields(unsigned int tick, int gameSpeed);
	
	bool isBoundary(const GamePoint &point) const;

	std::vector<Line> getPlayingField() {
		return playingField;
	}

	Frog getFrog() {
		return frog;
	}

	void FrogDrive();

	int frogInNewLine();
	
private:
	std::vector<GamePoint> boundary;
	std::vector<Line> playingField;
	const int rowSize = 15;
	const int colSize = 17;
	Frog frog;

	void setLinesSpeed();

};

#endif FIELD