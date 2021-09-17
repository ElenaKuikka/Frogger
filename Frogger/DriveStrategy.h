#ifndef DRIVESTRATEGY

#define DRIVESTRATEGY

#include"Field.h"

class DriveStrategy {
public:
	virtual GamePoint checkNextStep(Frog &frog) = 0;
	virtual void Drive(Frog &frog, std::vector<Line> &playingField, bool isBoundary) = 0;
	virtual ~DriveStrategy() {}
};

class DriveLeft :public DriveStrategy {
	GamePoint checkNextStep(Frog &frog) override {
		return GamePoint(frog.getFrogLocation().getPositionX(), frog.getFrogLocation().getPositionY() - 1);
	}
	
	virtual void Drive(Frog &frog, std::vector<Line> &playingField, bool isBoundary) override {
		Position FrogPositionX = frog.getFrogLocation().getPositionX();
		Position FrogPositionY = frog.getFrogLocation().getPositionY();
		GamePoint temp;
		if (!isBoundary) {
			temp = playingField[FrogPositionX].getLineElement(FrogPositionY - 1);
			playingField[FrogPositionX].setLineElement(FrogPositionY - 1, GamePoint(FrogPositionX, FrogPositionY - 1, GamePoint::FROG));
			frog.changeFrogLocation(playingField[FrogPositionX].getLineElement(FrogPositionY - 1));
			playingField[FrogPositionX].setLineElement(FrogPositionY, GamePoint(FrogPositionX, FrogPositionY, frog.getFrogMemory().getGameElement()));
			frog.setFrogMemory(temp);
		}
	}

};

class DriveRight :public DriveStrategy {
	GamePoint checkNextStep(Frog &frog) override {
		return GamePoint(frog.getFrogLocation().getPositionX(), frog.getFrogLocation().getPositionY() + 1);
	}

	virtual void Drive(Frog &frog, std::vector<Line> &playingField, bool isBoundary) override {
		Position FrogPositionX = frog.getFrogLocation().getPositionX();
		Position FrogPositionY = frog.getFrogLocation().getPositionY();
		GamePoint temp;
		if (!isBoundary) {
			temp = playingField[FrogPositionX].getLineElement(FrogPositionY + 1);
			playingField[FrogPositionX].setLineElement(FrogPositionY + 1, GamePoint(FrogPositionX, FrogPositionY + 1, GamePoint::FROG));
			frog.changeFrogLocation(playingField[FrogPositionX].getLineElement(FrogPositionY + 1));
			playingField[FrogPositionX].setLineElement(FrogPositionY, GamePoint(FrogPositionX, FrogPositionY, frog.getFrogMemory().getGameElement()));
			frog.setFrogMemory(temp);
		}
	}

};

class DriveUp :public DriveStrategy {
	GamePoint checkNextStep(Frog &frog) override {
		return GamePoint(frog.getFrogLocation().getPositionX() - 1, frog.getFrogLocation().getPositionY());
	}

	virtual void Drive(Frog &frog, std::vector<Line> &playingField, bool isBoundary) override {
		Position FrogPositionX = frog.getFrogLocation().getPositionX();
		Position FrogPositionY = frog.getFrogLocation().getPositionY();
		GamePoint temp;
		if (!isBoundary) {
			temp = playingField[FrogPositionX - 1].getLineElement(FrogPositionY);
			playingField[FrogPositionX - 1].setLineElement(FrogPositionY, GamePoint(FrogPositionX - 1, FrogPositionY, GamePoint::FROG));
			frog.changeFrogLocation(playingField[FrogPositionX - 1].getLineElement(FrogPositionY));
			playingField[FrogPositionX].setLineElement(FrogPositionY, GamePoint(FrogPositionX, FrogPositionY, frog.getFrogMemory().getGameElement()));
			playingField[FrogPositionX].setFrogInLine();
			frog.setFrogMemory(temp);
		}
	}

};

class DriveDown :public DriveStrategy {
	GamePoint checkNextStep(Frog &frog) override {
		return GamePoint(frog.getFrogLocation().getPositionX() + 1, frog.getFrogLocation().getPositionY());
	}

	virtual void Drive(Frog &frog, std::vector<Line> &playingField, bool isBoundary) override {
		Position FrogPositionX = frog.getFrogLocation().getPositionX();
		Position FrogPositionY = frog.getFrogLocation().getPositionY();
		GamePoint temp;
		if (!isBoundary) {
			temp = playingField[FrogPositionX + 1].getLineElement(FrogPositionY);
			playingField[FrogPositionX + 1].setLineElement(FrogPositionY, GamePoint(FrogPositionX + 1, FrogPositionY, GamePoint::FROG));
			frog.changeFrogLocation(playingField[FrogPositionX + 1].getLineElement(FrogPositionY));
			playingField[FrogPositionX].setLineElement(FrogPositionY, GamePoint(FrogPositionX, FrogPositionY, frog.getFrogMemory().getGameElement()));
			frog.setFrogMemory(temp);
		}
	}

};

#endif DRIVESTRATEGY
