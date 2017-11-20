#include "stdafx.h"
#include "particle.h"
#include <iostream>
using namespace std;

//생성자와 소멸자
particle::particle()
{
	//cout << "기본생성자" << endl;
}

particle::particle(double mass, double px, double py, double pv_x, double pv_y)
	: m(mass), x(px), y(py), v_x(pv_x), v_y(pv_y)
{
	//cout << "인자를 받는 생성자" << endl;
}
particle::particle(particle &rhs) : m(rhs.m), x(rhs.x), y(rhs.y), v_x(rhs.v_x), v_y(rhs.v_y), f(rhs.f), id(rhs.id)
{
	//cout << "복사 생성자" << endl;
}
particle::~particle()
{
	cout << id<<"입자의 소멸자" << endl;
}

//메소드
void particle::printinfor()
{
	cout << "particle " << id << endl;
	cout << "mass: " << m << " x, y: " << x << ", " << y << endl;
	cout << "v_x, v_y :" << v_x << ", " << v_y << endl;
}

