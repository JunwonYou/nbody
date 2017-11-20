#include "stdafx.h"
#include "whole.h"

whole::whole()
{
	BaseSet = new particleset*[1];
	remainSet = new particleset;
	BaseSet[0] = remainSet->setref;
}


whole::~whole()
{	
	//���̽��¿� �ִ� ���� �������� �����Ͽ� ���ڸ� ����� �±��� ����
	for (int i = setcount; i >= 0; i--)
	{
		std::cout << i << "��° �� ����" << std::endl;
		for (int j = 0; j < BaseSet[i]->Lsize; j++)
			deleteparticle(i, j);
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
	remainSet->addparticle(*a);
}
//set�� �����Ͽ� baseSet�� �ִ´�.
void whole::createset()
{	
	setcount++;
	particleset ** nBase = new particleset*[setcount+1];
	for(int i=0; i< setcount ; i++)
		nBase[i] = BaseSet[i];
	particleset *ptr = new particleset;
	nBase[setcount] = ptr->setref;
	nBase[setcount]->setid = setcount;
	delete[] BaseSet;
	BaseSet=nBase;

}
//���̽� ���� ��ȸ�Ͽ� �Էµ� setid�� ���� set�� �ּҸ� ��ȯ�Ѵ�.
particleset& whole::findset(int psetid)
{
	int i=0;
	while (BaseSet[i]->setid != psetid) 
		i++;
	return *BaseSet[i];

}

//�⺻ set���� ���ڸ� �ű��.
void whole::removeparticle(int psetid, int pid)
{
	remainSet->addparticle(findset(psetid).findparticle(pid));
	findset(psetid).remove(pid);
}
//���� ��ü�� �����Ѵ�.
void whole::deleteparticle(int psetid, int pid)
{
	particle* a = findset(psetid).findparticle(pid).ref;
	findset(psetid).remove(pid);
	delete a;
}
//��� �¾��̵�� �� ���� ���ڵ��� ���̵� ����Ѵ�.
void whole::printall()
{
	for (int i = 0; i <= setcount; i++)
	{
		std::cout << "SetID: " << BaseSet[i]->setid << std::endl << "	";
		BaseSet[i]->showid();
	}
}