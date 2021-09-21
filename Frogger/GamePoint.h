#ifndef GAMEPOINT

#define GAMEPOINT

#include<iostream>
#include<vector>
#include<Windows.h>
#include<conio.h>

using Position = unsigned short;

class GamePoint
{
public:
	enum GameElement {
		BOUNDARY = '#',
		SAFEPOINT = '=',
		HOME = 'H',
		STONE = '#',
		ROAD = ' ',
		CAR = 'C',
		RIVER = '-',
		TREE = 'T',
		TURTLE = 'O',
		FROG = 'F'
	};
	GamePoint() :x(0), y(0), gameElement(BOUNDARY) {}
	GamePoint(Position x, Position y);
	GamePoint(Position x, Position y, GameElement elemName);
	Position getPositionX() const{
		return this->x;
	}
	Position getPositionY() const {
		return this->y;
	}
	GameElement getGameElement() const {
		return this->gameElement;
	}
	
	void setPositionX(Position x) {
		this->x = x;
	}
	void setPositionY(Position y) {
		this->y = y;
	}
	void setGameElement(GameElement elemName) {
		this->gameElement = elemName;
	}
	void setPoint(Position x, Position y, GameElement elemName);

	void printPoint() const {
		std::cout << " " << static_cast<char>(gameElement) << " ";
	}
	
	GamePoint &operator=(const GamePoint &object);
	
	bool isFrog();
	
	bool isEnemyElement();

	bool isHome();

	friend bool operator==(const GamePoint &first, const GamePoint &second);
	
private:
	Position x = 0;
	Position y = 0;
	GameElement gameElement;
};

#endif GAMEPOINT