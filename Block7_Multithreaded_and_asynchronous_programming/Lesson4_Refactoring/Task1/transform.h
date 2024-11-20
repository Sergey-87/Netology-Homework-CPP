#pragma once
#include"shape.h"

template <class T>
class Transform {
public:
	Transform() {};
	Transform(T& figure) {
		Figure = figure;
	}

	T shift(int shiftX, int shiftY, int shiftZ) {
		for (auto& point : Figure.getPoints()) {
			point.x += shiftX;
			point.y += shiftY;
			point.z += shiftZ;
		}
		return Figure;
	}

	T scaleX(int scaleX) {
		for (auto& point : Figure.getPoints()) {
			point.x *= scaleX;
		}
		return Figure;
	}

	T scaleY(int scaleY) {
		for (auto& point : Figure.getPoints()) {
			point.y *= scaleY;
		}
		return Figure;
	}

	T scaleZ(int scaleZ) {
		for (auto& point : Figure.getPoints()) {
			point.z *= scaleZ;
		}
		return Figure;
	}

	T scale(int scale) {
		for (auto& point : Figure.getPoints()) {
			point.x /= scale;
			point.y /= scale;
			point.z /= scale;
		}
		return Figure;
	}

private:
	T Figure{};
};