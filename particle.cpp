#include "stdafx.h"
#include "particle.hpp"
#include <iostream>
using namespace std;

//�����ڿ� �Ҹ���
particle::particle()
{
	//cout << "�⺻������" << endl;
}

particle::particle(double mass, double px, double py, double pvx, double pvy)
	: m(mass), x(px), y(py), vx(pvx), vy(pvy)
{
	//cout << "���ڸ� �޴� ������" << endl;
}
particle::particle(particle &rhs) : m(rhs.m), x(rhs.x), y(rhs.y), vx(rhs.vx), vy(rhs.vy), f(rhs.f), id(rhs.id)
{
	//cout << "���� ������" << endl;
}
particle::~particle()
{
	cout << id << "������ �Ҹ���" << endl;
}

//�޼ҵ�
void particle::print_infor()
{
	cout << "particle " << id << endl;
	cout << "mass: " << m << " x, y: " << x << ", " << y << endl;
	cout << "vx, vy :" << vx << ", " << vy << endl;
}