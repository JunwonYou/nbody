
#pragma once
#include "particle.hpp"
class Set_particle
{
	friend class Set_whole;
protected:
	//���� ��ü�� �ּҸ� ���� ���� �޸� ����
	particle **List = nullptr;
	//�޸��� ũ�� ���庯��
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