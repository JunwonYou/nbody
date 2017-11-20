#include "stdafx.h"
#include "Set_whole.hpp"
using namespace std;
Set_whole::Set_whole()
{
	Set_of_set = new Set_particle*[1];
	particle_outset = new Set_particle;
	Set_of_set[0] = particle_outset->setref;
}

Set_whole::~Set_whole()
{
	//���̽��¿� �ִ� ���� �������� �����Ͽ� ���ڸ� ����� �±��� ����
	for (int i = setcount; i >= 0; i--)
	{
		std::cout << i << "��° �� ����" << std::endl;
		for (int j = 0; j < Set_of_set[i]->Lsize; j++)
			delete Set_of_set[i]->List[j];
		//Set_of_set[i]->~Set_particle();
		delete Set_of_set[i];
	}

	//���̽� �� ����
	delete[] Set_of_set;
}
//���ڸ� ���� �����Ͽ� �⺻ set�� �ִ´�.
void Set_whole::create_particle(double m, double x, double y, double v_x, double v_y)
{
	particle* a = new particle(m, x, y, v_x, v_y);
	a->id = pcount++;
	particle_outset->add(*a);
}
//set�� �����Ͽ� Set_of_set�� �ִ´�.
void Set_whole::create_set()
{
	setcount++;
	Set_particle ** nBase = new Set_particle*[setcount + 1];
	for (int i = 0; i< setcount; i++)
		nBase[i] = Set_of_set[i];
	Set_particle *ptr = new Set_particle;
	nBase[setcount] = ptr->setref;
	nBase[setcount]->setid = setcount;
	delete[] Set_of_set;
	Set_of_set = nBase;
	cout << "set" << Set_of_set[setcount]->setid << "�� �߰��Ǿ����ϴ�." << endl;
}
//���̽� ���� ��ȸ�Ͽ� �Էµ� setid�� ���� set�� �ּҸ� ��ȯ�Ѵ�.
Set_particle* Set_whole::find_set(int psetid)
{
	int i;
	for (i = 0; i <= setcount; i++)
		if (Set_of_set[i]->setid == psetid)
			return Set_of_set[i];
	cout << psetid << "�� set�� �����ϴ�." << endl;
	return nullptr;
}

//�⺻ set���� ���ڸ� �ű��.
void Set_whole::remove_particle(int psetid, int pid)
{
	int a = check(psetid, pid);
	if (a == 0)
		cout << psetid << "set�� ���� ������ �� �����ϴ�." << endl;
	else if (a == 1)
		cout << psetid << "set�� " << pid << "���ڰ� ��� ������ �� �����ϴ�." << endl;
	else
	{
		cout << "set" << psetid << "�� �ִ� " << pid << "���ڸ� �⺻ set���� �����մϴ�." << endl;
		particle_outset->add(*find_set(psetid)->findparticle(pid));
		find_set(psetid)->remove(pid);
	}
}
//���� ��ü�� �����Ѵ�.
void Set_whole::delete_particle(int psetid, int pid)
{
	int a = check(psetid, pid);
	if (a == 0)
		cout << psetid << "set�� ���� ������ �� �����ϴ�." << endl;
	else if (a == 1)
		cout << psetid << "set�� " << pid << "���ڰ� ��� ������ �� �����ϴ�." << endl;
	else
	{
		particle* a = find_set(psetid)->findparticle(pid)->ref;
		cout << psetid << "set����" << pid << "���ڸ� �����մϴ�." << endl;
		find_set(psetid)->remove(pid);
		delete a;
	}
}
//��� �¾��̵�� �� ���� ���ڵ��� ���̵� ����Ѵ�.
void Set_whole::print_all()
{
	cout << "*********set�� ���� ���**********" << endl;
	for (int i = 0; i <= setcount; i++)
	{
		std::cout << "SetID: " << Set_of_set[i]->setid << "  (������ ����: " << Set_of_set[i]->Lsize << ")" << std::endl;
		Set_of_set[i]->showid();
	}
	cout << "**********************************" << endl;
}
void Set_whole::add_particle(int psetid, int pid)
{

	if (psetid == 0)
		cout << "�⺻ set�� �߰��Ϸ��� createparticle()�Լ��� ȣ���ϼ���." << endl;
	else if (particle_outset->findparticle(pid) == nullptr)
		cout << pid << "�⺻ set�� ���� ���ڸ� �ű� �� �����ϴ�." << endl;
	else
	{
		find_set(psetid)->add(*find_set(0)->findparticle(pid));
		particle_outset->remove(pid);
	}
}

int Set_whole::check(int psetid, int pid)
{
	if (find_set(psetid) == nullptr)
		return 0;
	else if (find_set(psetid)->findparticle(pid) == nullptr)
		return 1;
	else
		return 2;
}