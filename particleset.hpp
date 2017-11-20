
#pragma once
#include "particle.hpp"
class particleset
{
	friend class whole;
protected:
	//입자 객체의 주소를 받을 동적 메모리 공간
	particle **List = nullptr;
	//메모리의 크기 저장변수
	particleset *setref = this;
	int Lsize = 0;

public:
	int setid = 0;
	particleset();
	~particleset();
	void add(particle&);
	void remove(int);
	void showmembers();
	void showid();
	particle* findparticle(int);
};