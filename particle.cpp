#include "stdafx.h"
#include "particle.h"
#include <iostream>
using namespace std;

//�����ڿ� �Ҹ���
particle::particle()
{
	//cout << "�⺻������" << endl;
}

particle::particle(double mass, double px, double py, double pv_x, double pv_y)
	: m(mass), x(px), y(py), v_x(pv_x), v_y(pv_y)
{
	//cout << "���ڸ� �޴� ������" << endl;
}
particle::particle(particle &rhs) : m(rhs.m), x(rhs.x), y(rhs.y), v_x(rhs.v_x), v_y(rhs.v_y), f(rhs.f), id(rhs.id)
{
	//cout << "���� ������" << endl;
}
particle::~particle()
{
	cout << id<<"������ �Ҹ���" << endl;
}

//�޼ҵ�
void particle::printinfor()
{
	cout << "particle " << id << endl;
	cout << "mass: " << m << " x, y: " << x << ", " << y << endl;
	cout << "v_x, v_y :" << v_x << ", " << v_y << endl;
}

