#include "stdafx.h"
#include "whole.hpp"
using namespace std;
whole::whole()
{
	BaseSet = new particleset*[1];
	particle_outset = new particleset;
	BaseSet[0] = particle_outset->setref;
}

whole::~whole()
{
	//���̽��¿� �ִ� ���� �������� �����Ͽ� ���ڸ� ����� �±��� ����
	for (int i = setcount; i >= 0; i--)
	{
		std::cout << i << "��° �� ����" << std::endl;
		for (int j = 0; j < BaseSet[i]->Lsize; j++)
			delete BaseSet[i]->List[j];
		//BaseSet[i]->~particleset();
		delete BaseSet[i];
	}

	//���̽� �� ����
	delete[] BaseSet;
}
//���ڸ� ���� �����Ͽ� �⺻ set�� �ִ´�.
void whole::createparticle(double m, double x, double y, double v_x, double v_y)
{
	particle* a = new particle(m, x, y, v_x, v_y);
	a->id = pcount++;
	particle_outset->add(*a);
}
//set�� �����Ͽ� baseSet�� �ִ´�.
void whole::createset()
{
	setcount++;
	particleset ** nBase = new particleset*[setcount + 1];
	for (int i = 0; i< setcount; i++)
		nBase[i] = BaseSet[i];
	particleset *ptr = new particleset;
	nBase[setcount] = ptr->setref;
	nBase[setcount]->setid = setcount;
	delete[] BaseSet;
	BaseSet = nBase;
	cout << "set" << BaseSet[setcount]->setid << "�� �߰��Ǿ����ϴ�." << endl;
}
//���̽� ���� ��ȸ�Ͽ� �Էµ� setid�� ���� set�� �ּҸ� ��ȯ�Ѵ�.
particleset* whole::findset(int psetid)
{
	int i;
	for (i = 0; i <= setcount; i++)
		if (BaseSet[i]->setid == psetid)
			return BaseSet[i];
	cout << psetid << "�� set�� �����ϴ�." << endl;
	return nullptr;
}

//�⺻ set���� ���ڸ� �ű��.
void whole::removeparticle(int psetid, int pid)
{
	int a = check(psetid, pid);
	if (a == 0)
		cout << psetid << "set�� ���� ������ �� �����ϴ�." << endl;
	else if (a == 1)
		cout << psetid << "set�� " << pid << "���ڰ� ��� ������ �� �����ϴ�." << endl;
	else
	{
		cout << "set" << psetid << "�� �ִ� " << pid << "���ڸ� �⺻ set���� �����մϴ�." << endl;
		particle_outset->add(*findset(psetid)->findparticle(pid));
		findset(psetid)->remove(pid);
	}
}
//���� ��ü�� �����Ѵ�.
void whole::deleteparticle(int psetid, int pid)
{
	int a = check(psetid, pid);
	if (a == 0)
		cout << psetid << "set�� ���� ������ �� �����ϴ�." << endl;
	else if (a == 1)
		cout << psetid << "set�� " << pid << "���ڰ� ��� ������ �� �����ϴ�." << endl;
	else
	{
		particle* a = findset(psetid)->findparticle(pid)->ref;
		cout << psetid << "set����" << pid << "���ڸ� �����մϴ�." << endl;
		findset(psetid)->remove(pid);
		delete a;
	}
}
//��� �¾��̵�� �� ���� ���ڵ��� ���̵� ����Ѵ�.
void whole::printall()
{
	cout << "*********set�� ���� ���**********" << endl;
	for (int i = 0; i <= setcount; i++)
	{
		std::cout << "SetID: " << BaseSet[i]->setid << "  (������ ����: " << BaseSet[i]->Lsize << ")" << std::endl;
		BaseSet[i]->showid();
	}
	cout << "**********************************" << endl;
}
void whole::addparticle(int psetid, int pid)
{

	if (psetid == 0)
		cout << "�⺻ set�� �߰��Ϸ��� createparticle()�Լ��� ȣ���ϼ���." << endl;
	else if (particle_outset->findparticle(pid) == nullptr)
		cout << pid << "�⺻ set�� ���� ���ڸ� �ű� �� �����ϴ�." << endl;
	else
	{
		findset(psetid)->add(*findset(0)->findparticle(pid));
		particle_outset->remove(pid);
	}
}

int whole::check(int psetid, int pid)
{
	if (findset(psetid) == nullptr)
		return 0;
	else if (findset(psetid)->findparticle(pid) == nullptr)
		return 1;
	else
		return 2;
}