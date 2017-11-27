#include "stdafx.h"
#include <string>
#include "particle.hpp"
#include <iostream>
using namespace std;
//持失切人 社瑚切


//五社球
void particle::print_infor()
{
	cout << "particle: " << id << endl;
	cout << "	Location:(" << x << ", " << y <<")"<< endl;
	cout << "	Velocity:(" << vx << ", " << vy <<")"<< endl;
}

particle::~particle()
{
	//cout << "particle " << id << "社瑚切" << endl;
}