#pragma once
#include <string>

class Rectangle {

public:
	Rectangle();
	Rectangle(float w, float h);

	float getWidth();
	float getHeight();
	void setWidth(float w);
	void setHeight(float h);
	float getArea();
	float getPerimeter();

private:
	float _width;
	float _height;

};