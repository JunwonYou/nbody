#include "stdafx.h"
#include "particle.hpp"
#include <iostream>
using namespace std;

//생성자와 소멸자
particle::particle()
{
	//cout << "기본생성자" << endl;
}

particle::particle(double mass, double px, double py, double pvx, double pvy)
	: m(mass), x(px), y(py), vx(pvx), vy(pvy)
{
	//cout << "인자를 받는 생성자" << endl;
}
particle::particle(particle &rhs) : m(rhs.m), x(rhs.x), y(rhs.y), vx(rhs.vx), vy(rhs.vy), f(rhs.f), id(rhs.id)
{
	//cout << "복사 생성자" << endl;
}
particle::~particle()
{
	cout << id << "입자의 소멸자" << endl;
}

//메소드
void particle::print_infor()
{
	cout << "particle " << id << endl;
	cout << "mass: " << m << " x, y: " << x << ", " << y << endl;
	cout << "vx, vy :" << vx << ", " << vy << endl;
}