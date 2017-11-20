#pragma once
#include "particleset.hpp"
#include <iostream>

class whole
{
private:
	int setcount = 0; //set에 부여할 번호
	int pcount = 0; //입자에 부여할 번호

	particleset** BaseSet; //set들의 set
	particleset* particle_outset = nullptr; //입자 생성 시 들어갈 기본 set
public:
	whole();
	~whole();
	void createparticle(double, double, double, double = 0.0, double = 0.0);
	void createset();
	particleset* findset(int);
	// 입자를 기본 set으로 제외
	void removeparticle(int, int);
	// 입자를 삭제
	void deleteparticle(int, int);
	void printall();
	//기본set에 있는 입자를 원하는 set으로 이동
	void addparticle(int, int);
	//주어진 인덱스의 입자가 있는지 확인
	int check(int, int);

};
