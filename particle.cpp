#include "stdafx.h"
#include "particle.h"
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
particle::particle(const particle &rhs):m(rhs.m),x(rhs.x),y(rhs.y),v_x(rhs.v_x),v_y(rhs.v_y),f(rhs.f)
{
	//cout << "���� ������" << endl;
}
particle::~particle()
{
	//cout << "�Ҹ���" << endl;
}

//�޼ҵ�
void particle::printall()
{
	cout << "mass: " << m << endl;
	cout << "x, y: " << x << ", " << y << endl;
	cout << "v_x, v_y :" << v_x << ", " << v_y << endl;
}