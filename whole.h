#pragma once
#include "particleset.h"
#include <iostream>

class whole
{
public:
	int setcount = 0; //set�� �ο��� ��ȣ
	int pcount = 0; //���ڿ� �ο��� ��ȣ

	particleset** BaseSet; //set���� set
	particleset* remainSet = nullptr; //���� ���� �� �� �⺻ set
public:
	whole();
	~whole();
	void createparticle(double, double, double, double=0.0, double=0.0);
	void createset();
	particleset& findset(int);
	// ���ڸ� �⺻ set���� ����
	void removeparticle(int, int);
	// ���ڸ� ����
	void deleteparticle(int, int);
	void printall();
};

