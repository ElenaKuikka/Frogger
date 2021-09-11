#ifndef FROGPOINT

#define FROGPOINT

#include"GamePoint.h"
#include"Field.h"



class Frog {
public:
	friend class Field;
	Frog() {
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

	//static constexpr int lives = 4;
private:
	GamePoint location;
	GamePoint frogMemory;
};




#endif FROGPOINT
