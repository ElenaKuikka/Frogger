#ifndef FROGPOINT

#define FROGPOINT

#include"GamePoint.h"
#include"Field.h"

class Frog {
public:
	Frog() {
		this->lives = 4;
		this->location.setPoint(13, 8, GamePoint::FROG);
		this->frogMemory.setPoint(13,8,GamePoint::SAFEPOINT);
	}

	GamePoint getFrogLocation(){
		return location;
	}

	GamePoint getFrogMemory(){
		return frogMemory;
	}

	void setLocation(GamePoint point) {
		this->location.setPoint(point.getPositionX(), point.getPositionY(), point.getGameElement());
	}

	void setFrogMemory(GamePoint point) {
		this->frogMemory.setPoint(point.getPositionX(), point.getPositionY(), point.getGameElement());
	}

	void changeFrogLocation(GamePoint point) {
		this->location.setPositionX(point.getPositionX());
		this->location.setPositionY(point.getPositionY());
	}
	void changeFrogMemory(GamePoint point) {
		this->frogMemory.setPositionX(point.getPositionX());
		this->frogMemory.setPositionY(point.getPositionY());
	}
	/*
	void setFrog(GamePoint &point) {
		point.setGameElement(GamePoint::FROG);
	}*/
	void reduceLives() {
		lives--;
		//game over
	}
	void setLives(int livesCount) {
		if (livesCount<0||livesCount>4){
			throw std::domain_error("Number of lives must be between 0 and 4");
		}
		this->lives = livesCount;
	}
	bool isFrogLocation(GamePoint &point) {
		if (location==point){
			return true;
		}
		else {
			return false;
		}
	}
	

private:
	int lives;
	GamePoint location;
	GamePoint frogMemory;
};




#endif FROGPOINT
