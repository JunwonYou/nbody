#include <string>
#pragma once
#include "particle.hpp"
using namespace std;
class Set_particle
{
	friend class Set_whole; // whole�� ���Ѿ��� �����ϵ��� ���
	friend class UI;
	//set�� ���� ���� ������ ����ü ����
	struct force_s
	{
		string fid = "None";
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
	string setid;
	Set_particle();
	~Set_particle();
	void add(particle&);
	void remove(string);
	void showmembers();
	void showid();
	particle* findparticle(string);
	void showforce();
	double getforce_x();
	double getforce_y();
};

