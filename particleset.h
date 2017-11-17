#pragma once
#include "particle.h"

class particleset
{
private:
	//입자 객체의 주소를 받을 동적 메모리 공간
	particle **List = nullptr;
	//메모리의 크기 저장변수
	int size = 0;
public:

	particleset();
	~particleset();
	void addparticle(particle&);
	void removeparticle(particle&);
	void removeparticle(int);
	void deleteparticle(particle&);
	void showmembers();
	int findindex(const particle&);
};