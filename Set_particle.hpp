
#pragma once
#include "particle.hpp"
class Set_particle
{
	friend class Set_whole; // whole�� ���Ѿ��� �����ϵ��� ���
	//set�� ���� ���� ������ ����ü ����
	struct force_s
	{
		int fid = -1;
		double fx;
		double fy;
	};
	force_s** fList = nullptr;	//set�� �޴� force�� ���, ���߿� �� ����Ʈ�� nullptr���� �ƴ����� ���� delete[]�� ���߿� ������Ѵ�.
	int num_f = 0;	//force�� ����	
	
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
	void showforce();
	double getforce_x();
	double getforce_y();
};

