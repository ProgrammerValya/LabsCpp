#include "stdafx.h"
#include "Angle.h"
#include <iostream>
#include<locale.h>  
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;
Angle::Angle(int d, int m)
{
	degree = d;
	minutes = m;
}

Angle::Angle(int m)
{
	minutes = m;
	degree = 0;
	Normalize();
}
double Angle::ConvertToRadian()
{
	double rad = degree * M_PI / 180 + minutes * M_PI / 60 / 180;
	return(rad);
}
void Angle::Display()
{

	std::cout << ToString() << endl;
}
string Angle::ToString()
{
	string str;
	str += to_string(degree) + " градус(ов) ";
	str += to_string(minutes) + " минут(ы)";
	return(str);
}
void Angle::Normalize()
{
	degree += minutes / 60;
	minutes %= 60;
	if (minutes < 0)
	{
		minutes += 60;
		degree--;
	}
	//else { minutes = minutes % 60; };

	if (degree < 0)
	{
		degree = degree % 360 + 360;
	}
	else { degree = degree % 360; };



}
void Angle::IncreaseAngle(const Angle AddAng)
{
	degree += AddAng.degree;
	minutes += AddAng.minutes;
	Normalize();
}

void Angle::DecreaseAngle(Angle SubAng)
{
	degree -= SubAng.degree;
	minutes -= SubAng.minutes;
	Normalize();
}
double Angle::GetSin()
{
	double res;
	res = sin(ConvertToRadian());
	return(res);
}

bool Angle::operator<(Angle ang2)
{
	bool res;
	ang2.Normalize();
	Normalize();
	if (degree < ang2.degree) res = true;
	else
		if (degree = ang2.degree)
			if (minutes < ang2.minutes)
				res = true;
			else
				res = false;
	return(res);
}
Angle Angle::create_elem()
{
	int deg, min;
	cout << "¬ведите градусы: ";
	cin >> deg;
	cout << "¬ведите минуты: ";
	cin >> min;
	Angle ang = Angle(deg, min);
	return(ang);
}
