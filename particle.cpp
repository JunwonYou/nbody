#include "stdafx.h"
#include <string>
#include "particle.hpp"
#include <iostream>
using namespace std;
//생성자와 소멸자


//메소드
void particle::print_infor()
{
	cout << "particle: " << id << endl;
	cout << "	Mass: " << m << "kg" << endl;
	cout << "	Location:(" << x << ", " << y <<")"<< endl;
	cout << "	Velocity:(" << vx << ", " << vy <<")"<< endl;
}

particle::~particle()
{
	//cout << "particle " << id << "소멸자" << endl;
}
