#pragma once

class Vector : public ActorComponent{
	int x;
	int y;

public:
	Vector(Actor* owner) : ActorComponent(owner), x(0), y(0) {}

	Cords(Actor* owner, int x, int y) : ActorComponent(owner), x(0), y(0) {}

	void plusCordX(int x) {
		this->x += x;
	}

	void plusCordY(int y) {
		this->y += y;
	}

	void minusCordX(int x) {
		this->x -= x;
	}

	void minusCordY(int y) {
		this->y -= y;
	}


};

