#ifndef FROGPOINT

#define FROGPOINT

#include"GamePoint.h"
#include"Field.h"

class Frog {
public:
	friend class Field;
	Frog() {
		this->lives = 4;
		this->location.setPoint(13, 8, GamePoint::FROG);
		this->frogMemory.setPoint(13,8,GamePoint::SAFEPOINT);
	}
	Frog(int lives) {
		this->lives = lives;
		this->location.setPoint(13, 8, GamePoint::FROG);
		this->frogMemory.setPoint(13, 8, GamePoint::SAFEPOINT);
	}

	GamePoint getFrogLocation(){
		return location;
	}

	GamePoint getFrogMemory(){
		return frogMemory;
	}

	int getLives() {
		return lives;
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
	
	void reduceLives() {
		lives--;
	}
	void addLives() {
		lives++;
	}
	
	bool isFrogLocation(GamePoint &point) {
		if (location==point){
			return true;
		}
		else {
			return false;
		}
	}
	
	bool isDead() {
		if (frogMemory.isEnemyElement()){
			return true;
		}
		else{
			return false;
		}
	}

private:
	int lives;
	GamePoint location;
	GamePoint frogMemory;
};




#endif FROGPOINT
