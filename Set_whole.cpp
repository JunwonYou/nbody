#include "stdafx.h"
#include "Set_whole.hpp"
#include <math.h>
#define G 6.673;
using namespace std;
Set_whole::Set_whole()
{
	//cout << "Set_whole()" << endl;
	Set_of_set = new Set_particle*[1];
	particle_outset = new Set_particle;
	Set_of_set[0] = particle_outset->setref;
	Set_of_set[0]->setid = "outset";
}


Set_whole::~Set_whole()
{
	//cout << "whole �Ҹ���" << endl;
	//���̽��¿� �ִ� ���� �������� �����Ͽ� ���ڸ� ����� �±��� ����
	int ss = setcount;
	for (int i = 0; i < ss; i++)
	{
		//std::cout << i << "��° �� ����" << std::endl;
		for (int j = 0; j < Set_of_set[i]->Lsize; j++)
		{
			delete Set_of_set[i]->List[j];
			pcount--;
		}
		for (int f = 0; f < Set_of_set[i]->num_f; f++)
		{
			//cout << "force<" << Set_of_set[i]->fList[f]->fid << "> ����" << endl;
			delete Set_of_set[i]->fList[f];
			fcount--;
		}
		//Set_of_set[i]->~Set_particle();
		delete Set_of_set[i];
		setcount--;
	}
	setcount++;
	cout << "All forces deleted" << endl << "All set deleted" << endl << "All particle deleted" << endl;
	// Set of Set ����
	print_memory();
	delete[] Set_of_set;
}
//���ڸ� ���� �����Ͽ� �⺻ set�� �ִ´�.
void Set_whole::create_particle(string id, double m, double x, double y, double v_x, double v_y)
{
	for (int i = 0; i < setcount; i++)
		for (int j = 0; j < Set_of_set[i]->Lsize; j++)
			if (id == Set_of_set[i]->List[j]->id)
			{
				cout << "A particle with the same name already exists" << endl;
				return;
			}
	pcount++;
	particle* a = new particle(id, m, x, y, v_x, v_y);
	particle_outset->add(*a);
	cout << "Particle " << a->id << " added" << endl;
}
//set�� �����Ͽ� Set_of_set�� �ִ´�.
void Set_whole::create_set(string setid)
{
	
	for (int i = 0; i < setcount; i++)
		if (setid == Set_of_set[i]->setid)
		{
			cout << "A set with the same name already exists" << endl;
			return;
		}
	setcount++;
	Set_particle ** nBase = new Set_particle*[setcount ];
	for (int i = 0; i< setcount-1; i++)
		nBase[i] = Set_of_set[i];
	Set_particle *ptr = new Set_particle;
	nBase[setcount-1] = ptr->setref;
	nBase[setcount-1]->setid = setid;
	delete[] Set_of_set;
	Set_of_set = nBase;
	cout << "Set " << Set_of_set[setcount-1]->setid << " added" << endl;
}
//���̽� ���� ��ȸ�Ͽ� �Էµ� setid�� ���� set�� �ּҸ� ��ȯ�Ѵ�.
Set_particle* Set_whole::find_set(string psetid)
{
	int i;
	for (i = 0; i < setcount; i++)
		if (Set_of_set[i]->setid == psetid)
			return Set_of_set[i];
	cout << psetid << "�� set�� �����ϴ�." << endl;
	return nullptr;
}

//�⺻ set���� ���ڸ� �ű��.
void Set_whole::remove_particle(string psetid, string pid)
{
	int a = check(psetid, pid);
	if (a == 0)
		cout << psetid << "set�� ���� ������ �� �����ϴ�." << endl;
	else if (a == 1)
		cout << psetid << "set�� " << pid << "���ڰ� ��� ������ �� �����ϴ�." << endl;
	else
	{
		cout << "Particle " << pid << " is deleted from set " << psetid << endl;
		particle_outset->add(*find_set(psetid)->findparticle(pid));
		find_set(psetid)->remove(pid);
	}
}
//���� ��ü�� �����Ѵ�.
void Set_whole::delete_particle(string psetid, string pid)
{
	int a = check(psetid, pid);
	if (a == 0)
		cout << psetid << "set�� ���� ������ �� �����ϴ�." << endl;
	else if (a == 1)
		cout << psetid << "set�� " << pid << "���ڰ� ��� ������ �� �����ϴ�." << endl;
	else
	{
		particle* a = find_set(psetid)->findparticle(pid)->ref;
		cout << "Particle " << pid << " is deleted" << endl;
		find_set(psetid)->remove(pid);
		delete a;
		pcount--;
	}
}
//�°� ���� ���� ������ ��ȯ
void Set_whole::print_memory()
{
	cout << "Particles: " << pcount << endl;
	cout << "Sets: " << setcount-1 << endl;
	cout << "Forces: " << fcount << endl;
}
void Set_whole::add_particle(string psetid, string pid)
{

	if (psetid == "outset")
		cout << "outset(set<0>)�� �߰��Ϸ��� ap �� �Է��ϼ���." << endl;
	else if (particle_outset->findparticle(pid) == nullptr)
		cout << pid << "outset�� �ִ� ���ڸ� �ٸ� set�� �ű� �� �ֽ��ϴ�." << endl;
	else
	{
		find_set(psetid)->add(*particle_outset->findparticle(pid));
		particle_outset->remove(pid);
		cout << "Particle " << pid << " added to set " << psetid << endl;
	}
}

int Set_whole::check(string psetid, string pid)
{
	if (find_set(psetid) == nullptr)
		return 0;
	else if (find_set(psetid)->findparticle(pid) == nullptr)
		return 1;
	else
		return 2;
}

void Set_whole::add_force(string pfid, double pfx, double pfy, string psetid)
{
	Set_particle* rhs = find_set(psetid);
	if (rhs == nullptr)
	{
		cout <<"There is no set "<< psetid << endl;
		return;
	}
	Set_particle::force_s* newforce = new Set_particle::force_s;
	newforce->fid=pfid;
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
	fcount++;
	cout << "Force " << pfid << " is addad to set " << psetid << endl;
}

void Set_whole::delete_force(string pfid, string psetid)
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
			
			Set_particle::force_s** nfList = new Set_particle::force_s*[rhs->num_f-1];
			for (int j = 0; j < i; j++)
				nfList[j] = rhs->fList[j];
			for (int j = i + 1; j < rhs->num_f; j++)
				nfList[j - 1] = rhs->fList[j];
			delete rhs->fList[i];
			delete[] rhs->fList;
			rhs->fList = nfList;
			cout << "Force " << pfid << " deleted from set " << psetid << endl;
			rhs->num_f--;
			fcount--;
			return;
		}
	cout << "set" << rhs->setid << "�� force" << pfid << "�� �����ϴ�." << endl;
}

void Set_whole::Calculate(int duration, char print)
{
	for (int t = 0; t < duration; t++)
	{
		Gravity();
		if (print)
		{
			cout << "�ùķ��̼� t= " << time / 1000.0 << "s" << endl;
			for (int s = 0; s < setcount; s++)
				for (int p = 0; p < Set_of_set[s]->Lsize; p++)
					Set_of_set[s]->List[p]->print_infor();
		}
		for (int s = 0; s < setcount; s++)
		{
			double fxs = Set_of_set[s]->getforce_x();
			double fys = Set_of_set[s]->getforce_y();
			for (int p = 0; p < Set_of_set[s]->Lsize; p++)
			{
				//���� ���� üũ
				if (Set_of_set[s]->List[p]->fixation == 0)
				{
					//x,y ��ǥ ��ȭ
					Set_of_set[s]->List[p]->x += Set_of_set[s]->List[p]->vx + (Set_of_set[s]->List[p]->force_p[0] + fxs) / (2 * Set_of_set[s]->List[p]->m);
					Set_of_set[s]->List[p]->y += Set_of_set[s]->List[p]->vy + (Set_of_set[s]->List[p]->force_p[1] + fys) / (2 * Set_of_set[s]->List[p]->m);
				}
				//vx, vy ��ȭ
				Set_of_set[s]->List[p]->vx += (Set_of_set[s]->List[p]->force_p[0] + fxs) / Set_of_set[s]->List[p]->m;
				Set_of_set[s]->List[p]->vy += (Set_of_set[s]->List[p]->force_p[1] + fys) / Set_of_set[s]->List[p]->m;
			}
			
		}
		time += t_tick;
	}
	if (print)
	{
		cout << "�ùķ��̼� t= " << time / 1000.0 << "s" << endl;
		for (int s = 0; s < setcount; s++)
			for (int p = 0; p < Set_of_set[s]->Lsize; p++)
				Set_of_set[s]->List[p]->print_infor();
	}
}


void Set_whole::Gravity()
{
	//�߷� ������ ���� ���� �ߴ�.
	if (gravity == 0)
		return;
	//�� ���ڵ��� force_p�� 0���� �ʱ�ȭ
	for (int s = 0; s < setcount; s++)
		for (int p = 0; p < Set_of_set[s]->Lsize; p++)
		{
			Set_of_set[s]->List[p]->force_p[0] = 0.0;
			Set_of_set[s]->List[p]->force_p[1] = 0.0;
		}



	// ���� ��ȣ�ۿ� ��� �� force_p�� ����
	for (int s = 0; s < setcount; s++)
		for (int p = 0; p < Set_of_set[s]->Lsize; p++)
		{
			double fx = 0; double fy = 0;
			for (int ss = 0; ss < setcount; ss++)
				for (int pp = 0; pp < Set_of_set[s]->Lsize; pp++)
				{
					if (pp == p)
						continue;
					double rx = Set_of_set[ss]->List[pp]->x - Set_of_set[s]->List[p]->x;
					double ry = Set_of_set[ss]->List[pp]->y - Set_of_set[s]->List[p]->y;
					fx += (Set_of_set[ss]->List[pp]->m)*(Set_of_set[s]->List[p]->m) / (sqrt(rx*rx + ry*ry)*(rx*rx + ry*ry))*rx*G;
					fy += (Set_of_set[ss]->List[pp]->m)*(Set_of_set[s]->List[p]->m) / (sqrt(rx*rx + ry*ry)*(rx*rx + ry*ry))*ry*G;
				}
			Set_of_set[s]->List[p]->force_p[0] = fx;
			Set_of_set[s]->List[p]->force_p[1] = fy;

		}
}
