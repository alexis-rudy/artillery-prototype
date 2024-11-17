/***********************************************************************
 * Header File:
 *    ANGLE
 * Author:
 *    <your name here>
 * Summary:
 *    Everything we need to know about a direction
 ************************************************************************/

#pragma once

#define _USE_MATH_DEFINES
#include <math.h>   // for M_PI which is 3.14159

#define TWO_PI 6.28318530718

	// for the unit tests
class TestAngle;
class TestPosition;
class TestVelocity;
class TestAcceleration;
class TestHowitzer;
class TestProjectile;

/************************************
 * ANGLE
 ************************************/
class Angle
{
	public:
		// for the unit tests
	friend TestAcceleration;
	friend TestVelocity;
	friend TestAngle;
	friend TestHowitzer;
	friend TestProjectile;
	
		// Constructors
	Angle()                  : radians()         {}
	Angle(const Angle& rhs)  : radians(rhs.radians)         {}
	Angle(double degrees)    : radians(convertToRadians(normalize(degrees)))         {}
	
		// Getters
	double getDegrees() const { return convertToDegrees(radians); }
	double getRadians() const { return radians; }
	
		//         dx
		//    +-------/6
		//    |      /
		// dy |     /
		//    |    / 1.0
		//    | a /
		//    |  /
		//    | /
		// dy = cos a
		// dx = sin a
	double getDx() 			  const { return sin(radians); }
	double getDy()   		  const { return cos(radians); }
	bool   isRight()          const { return getDx() > 0.0; }
	bool   isLeft()           const { return getDx() < 0.0; }
	
	
		// Setters
	void setDegrees(double degrees) {
		radians = normalize(convertToRadians(degrees));
	}
	void setRadians(double r)       { radians = normalize(r); }
	void setUp()                    { radians = 0.0;}
	void setDown()                  { radians = M_PI; }
	void setRight()                 { radians = M_PI_2; }
	void setLeft()                  { radians = M_PI + M_PI_2; }
	void reverse()                  { radians += M_PI;}
	Angle& add(double delta)        { radians += normalize(delta); return *this; }
	
		// set based on the components
		//         dx
		//     +-------/
		//     |      /
		//  dy |     /
		//     |    /
		//     | a /
		//     |  /
		//     | /
	void setDxDy(double dx, double dy)  {radians = atan2(dx, dy);}
	Angle operator+(double degrees) const { return Angle(); }
	
	private:
	
	double normalize(double radians) const;
	double convertToDegrees(double radians) const;
	double convertToRadians(double degrees) const;
	
	double radians;   // 360 degrees equals 2 PI radians
};

#include <iostream>

/*******************************************************
 * OUTPUT ANGLE
 * place output on the screen in degrees
 *******************************************************/
inline std::ostream& operator << (std::ostream& out, const Angle& rhs)
{
	out << rhs.getDegrees() << "degree";
	return out;
}
