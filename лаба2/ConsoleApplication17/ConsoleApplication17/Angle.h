#pragma once
#include "stdafx.h"
#include <iostream>
#include<locale.h>  
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;
class Angle
{

	int degree;
	int minutes;

public:

	Angle(int d, int m);
	
	Angle(int m);
	
	double ConvertToRadian();
	void Display();
	string ToString();
	void Normalize();
	void IncreaseAngle(const Angle AddAng);
	void DecreaseAngle(Angle SubAng);
	double GetSin();
	//bool CompareAngles(Angle ang2);
	static Angle create_elem();
	bool operator<(Angle ang2);
};

