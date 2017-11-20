
#pragma once
#include "particle.hpp"
class Set_particle
{
	friend class Set_whole;
protected:
	//입자 객체의 주소를 받을 동적 메모리 공간
	particle **List = nullptr;
	//메모리의 크기 저장변수
	Set_particle
		*setref = this;
	int Lsize = 0;

public:
	int setid = 0;
	Set_particle();
	~Set_particle();
	void add(particle&);
	void remove(int);
	void showmembers();
	void showid();
	particle* findparticle(int);
};