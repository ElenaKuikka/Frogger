#include"GamePoint.h"

GamePoint::GamePoint(Position x, Position y) {
	this->x = x;
	this->y = y;
	this->gameElement = BOUNDARY;
}

GamePoint::GamePoint(Position x, Position y, GameElement elemName) {
	this->x = x;
	this->y = y;
	this->gameElement = elemName;
}

void GamePoint::setPoint(Position x, Position y, GameElement elemName) {
	this->x = x;
	this->y = y;
	this->gameElement = elemName;
}

GamePoint& GamePoint::operator=(const GamePoint &object) {
	if (this == &object) {
		return *this;
	}
	this->x = object.x;
	this->y = object.y;
	this->gameElement = object.gameElement;
	return *this;
}

bool GamePoint::isFrog() {
	if (gameElement == FROG) {
		return true;
	}
	else {
		return false;
	}
}

bool GamePoint::isEnemyElement() {
	if (gameElement == STONE || gameElement == CAR || gameElement == RIVER) {
		return true;
	}
	else {
		return false;
	}
}

bool GamePoint::isHome() {
	if (gameElement == HOME) {
		return true;
	}
	else {
		return false;
	}
}

bool operator==(const GamePoint &first, const GamePoint &second) {
	return(first.x == second.x && first.y == second.y);
}