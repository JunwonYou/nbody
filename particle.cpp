#include "stdafx.h"
#include <string>
#include "particle.hpp"
#include <iostream>
using namespace std;
//�����ڿ� �Ҹ���


//�޼ҵ�
void particle::print_infor()
{
	cout << "particle: " << id << endl;
	cout << "	Location:(" << x << ", " << y <<")"<< endl;
	cout << "	Velocity:(" << vx << ", " << vy <<")"<< endl;
}

particle::~particle()
{
	//cout << "particle " << id << "�Ҹ���" << endl;
}