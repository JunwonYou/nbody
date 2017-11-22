#include "stdafx.h"
#include "Set_whole.hpp"
using namespace std;
Set_whole::Set_whole()
{
	cout << "Set_whole()" << endl;
	Set_of_set = new Set_particle*[1];
	particle_outset = new Set_particle;
	Set_of_set[0] = particle_outset->setref;
}

Set_whole::~Set_whole()
{
	cout << "whole �Ҹ���" << endl;
	//���̽��¿� �ִ� ���� �������� �����Ͽ� ���ڸ� ����� �±��� ����
	for (int i = setcount; i >= 0; i--)
	{
		std::cout << i << "��° �� ����" << std::endl;
		for (int j = 0; j < Set_of_set[i]->Lsize; j++)
			delete Set_of_set[i]->List[j];
		//Set_of_set[i]->~Set_particle();
		delete Set_of_set[i];
	}
	cout << "Set of Set ����" << endl;
	// Set of Set ����
	delete[] Set_of_set;
}
//���ڸ� ���� �����Ͽ� �⺻ set�� �ִ´�.
void Set_whole::create_particle(double m, double x, double y, double v_x, double v_y)
{
	particle* a = new particle(m, x, y, v_x, v_y);
	a->id = pcount++;
	particle_outset->add(*a);
	cout << "outset(set0)�� particle" << a->id << "�� �߰��Ǿ����ϴ�." << endl;
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
		std::cout << "Set: " << Set_of_set[i]->setid << "  (������ ����: " << Set_of_set[i]->Lsize << " ���� ����: "<<Set_of_set[i]->num_f <<")" << std::endl;
		cout << "force: ";
		Set_of_set[i]->showforce();
		cout << "particle: ";
		Set_of_set[i]->showid();
	}
	cout << "**********************************" << endl;
}
void Set_whole::add_particle(int psetid, int pid)
{

	if (psetid == 0)
		cout << "outset�� �߰��Ϸ��� createparticle()�Լ��� ȣ���ϼ���." << endl;
	else if (particle_outset->findparticle(pid) == nullptr)
		cout << pid << "outset�� ���� ���ڸ� �ű� �� �����ϴ�." << endl;
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

void Set_whole::add_force(int pfid, double pfx, double pfy, int psetid)
{
	Set_particle* rhs = find_set(psetid);
	if (rhs == nullptr)
	{
		cout << "set" << psetid << "�� ��� force �߰��� �����߽��ϴ�." << endl;
		return;
	}
	Set_particle::force_s* newforce = new Set_particle::force_s;
	newforce->fid = pfid;
	newforce->fx = pfx;
	newforce->fy = pfy;
	rhs->num_f++;
	if (rhs->fList != nullptr)
	{
		Set_particle::force_s** nfList = new Set_particle::force_s*[rhs->num_f];
		for (int i = 0; i < rhs->num_f-1; ++i)
			nfList[i] = rhs->fList[i];
		nfList[rhs->num_f - 1] = newforce;
		delete[] rhs->fList;
		rhs->fList = nfList;
	}
	else
	{
		rhs->fList = new Set_particle::force_s*[1];
		rhs->fList[0] = newforce;
	}
	cout << "set"<<psetid << "�� force" << pfid << "�� �߰��Ͽ����ϴ�." << endl;
}

void Set_whole::delete_force(int pfid, int psetid)
{
	Set_particle* rhs = find_set(psetid);
	if (rhs == nullptr)
	{
		cout << "set" << psetid << "�� ��� force ���ſ� �����߽��ϴ�." << endl;
		return;
	}
	for (int i = 0; i < rhs->num_f; i++)
		if (rhs->fList[i]->fid == pfid)
		{
			rhs->num_f--;
			Set_particle::force_s** nfList = new Set_particle::force_s*[rhs->num_f];
			for (int j = 0; j < i; j++)
				nfList[j] = rhs->fList[j];
			for (int j = i + 1; j < rhs->num_f; j++)
				nfList[j - 1] = rhs->fList[j];
			delete[] rhs->fList[i];
			delete[] rhs->fList;
			rhs->fList = nfList;
			cout << "set" << psetid << "�� force" << pfid << "�� �����Ͽ����ϴ�." << endl;
			return;
		}
	cout << "set" << rhs->setid << "�� force" << pfid << "�� �����ϴ�." << endl;
}

void Set_whole::Calculate(int duration)
{
	for (int t = 0; t < duration; t++)
	{
		Gravity();
		for (int s = 0; s <= setcount; s++)
		{
			double fxs = Set_of_set[s]->getforce_x();
			double fys = Set_of_set[s]->getforce_y();
			for (int p = 0; p < Set_of_set[s]->Lsize; p++)
			{
				//���� ���� üũ
				if (Set_of_set[s]->List[p]->fixation == 0)
				{
					//x,y ��ǥ ��ȭ
					Set_of_set[s]->List[p]->x += Set_of_set[s]->List[p]->vx + 2 * (Set_of_set[s]->List[p]->force_p[0] + fxs) / Set_of_set[s]->List[p]->m;
					Set_of_set[s]->List[p]->y += Set_of_set[s]->List[p]->vy + 2 * (Set_of_set[s]->List[p]->force_p[1] + fys) / Set_of_set[s]->List[p]->m;
				}
				//vx, vy ��ȭ
				Set_of_set[s]->List[p]->vx += (Set_of_set[s]->List[p]->force_p[0] + fxs) / Set_of_set[s]->List[p]->m;
				Set_of_set[s]->List[p]->vy += (Set_of_set[s]->List[p]->force_p[1] + fys) / Set_of_set[s]->List[p]->m;
			}
		}
		if (t%t_tick == 0)
		{
			cout << "�ùķ��̼� t= " << t << "�� ���� ��� ���" << endl;
			for (int s = 0; s <= setcount; s++)
			{
				cout << "set" << Set_of_set[s]->setid << endl;
				for (int p = 0; p < Set_of_set[s]->Lsize; p++)
					Set_of_set[s]->List[p]->print_infor();
			}
		}
	}
}


void Set_whole::Gravity()
{
	//�� ���ڵ��� force_p�� 0���� �ʱ�ȭ
	for (int s = 0; s <= setcount; s++)
		for (int p = 0; p < Set_of_set[s]->Lsize; p++)
		{
			Set_of_set[s]->List[p]->force_p[0] = 0.0;
			Set_of_set[s]->List[p]->force_p[1] = 0.0;
		}

	//�߷� ������ ���� ���� �ߴ�.
	if (gravity == 0)
		return;
	//�������� ���� ��ȣ�ۿ� ���

}
