#pragma once
#include "particle.h"
class particleset
{
	friend class whole;
protected:
	//���� ��ü�� �ּҸ� ���� ���� �޸� ����
	particle **List = nullptr;
	//�޸��� ũ�� ���庯��
	particleset *setref = this;
	int Lsize = 0;
	
public:
	int setid = 0;
	particleset();
	~particleset();
	void addparticle(particle&);
	void remove(int);
	void showmembers();
	void showid();
	particle& findparticle(int);
};