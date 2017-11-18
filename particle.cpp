#include "particle.hpp"
#include <iostream>
using namespace std;

//생성자와 소멸자
particle::particle()
{
	//cout << "기본생성자" << endl;
	//wholeset count 호출필요
}

particle::particle(double mass, double x, double y, double vx, double vy)
	: m(mass), x(x), y(y), vx(vx), vy(vy)
{
	//cout << "인자를 받는 생성자" << endl;
	//wholeset count 호출필요
}
particle::particle(particle &rhs) : m(rhs.m), x(rhs.x), y(rhs.y), v_x(rhs.vx), v_y(rhs.vy), f(rhs.f), id(rhs.id)
{
	//cout << "복사 생성자" << endl;
}
particle::~particle()
{
	cout << "소멸자" << endl;
}

//메소드
void particle::printall()
{
	cout << "mass: " << m << endl;
	cout << "x, y: " << x << ", " << y << endl;
	cout << "v_x, v_y :" << vx << ", " << vy << endl;
}
