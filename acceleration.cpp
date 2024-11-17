/***********************************************************************
 * Source File:
 *    ACCELERATION 
 * Author:
 *    Alexis Rudy
 * Summary:
 *    Everything we need to know about changing speed
 ************************************************************************/

#include "acceleration.h"
#include "angle.h"

#include <cmath>

Acceleration::Acceleration()
{
	this->ddx = 0.0;
	this->ddy = 0.0;
}

Acceleration::Acceleration(double ddx, double ddy)
{
	this->ddx = ddx;
	this->ddy = ddy;
}


/*********************************************
 * ACCELERATION : SET
 *  set from angle and direction
 *********************************************/
void Acceleration::set(const Angle & a, double magnitude)
{
    this->ddx = magnitude * sin(a.getRadians());
    this->ddy = magnitude * cos(a.getRadians());
}

	// Add to ddx
void Acceleration::addDDX(double ddx)
{
	this->ddx += ddx;
}

	// Add to ddy
void Acceleration::addDDY(double ddy)
{
	this->ddy += ddy;
}

void Acceleration::add(const Acceleration& rhs)
{
	this->ddx += rhs.ddx;
	this->ddy += rhs.ddy;
}
