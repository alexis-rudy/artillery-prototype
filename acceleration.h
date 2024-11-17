/***********************************************************************
 * Header File:
 *    ACCELERATION 
 * Author:
 *    Alexis Rudy
 * Summary:
 *    Everything we need to know about acceleration
 ************************************************************************/


#pragma once

class TestAcceleration;
class TestVelocity;
class TestPosition;
class TestLander;
class Angle;


/*********************************************
 * Acceleration
 * Let's get moving
 *********************************************/
class Acceleration
{
   friend TestPosition;
   friend TestVelocity;
   friend TestAcceleration;
   friend TestLander;

public:
   // constructors
    Acceleration(); // Default constructor
    Acceleration(double ddx, double ddy); // Parameterized constructor
	
   // getters
    double getDDX() const {return ddx;} // Get ddx
    double getDDY() const {return ddy;} // Get ddy

   // setters                        
    void setDDX(double ddx) {this->ddx = ddx;} // Set ddx
    void setDDY(double ddy) {this->ddy = ddy;} // Set ddy
    void set(const Angle& angle, double magnitude);
	
	void addDDX(double ddx); // Add to ddx
	void addDDY(double ddy); // Add to ddy
	void add(const Acceleration& rhs);
private:
   double ddx;     // horizontal acceleration
   double ddy;     // vertical acceleration
};
