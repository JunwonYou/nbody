#pragma once
#include "particle.h"

class particleset
{
private:
	//���� ��ü�� �ּҸ� ���� ���� �޸� ����
	particle **List = nullptr;
	//�޸��� ũ�� ���庯��
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