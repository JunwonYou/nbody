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
	//베이스셋에 있는 셋을 역순으로 참조하여 입자를 지우고 셋까지 삭제
	for (int i = setcount; i >= 0; i--)
	{
		std::cout << i << "번째 셋 차례" << std::endl;
		for (int j = 0; j < BaseSet[i]->Lsize; j++)
			delete BaseSet[i]->List[j];
		//BaseSet[i]->~particleset();
		delete BaseSet[i];
	}

	//베이스 셋 삭제
	delete[] BaseSet;
}
//입자를 동적 생성하여 기본 set에 넣는다.
void whole::createparticle(double m, double x, double y, double v_x, double v_y)
{
	particle* a = new particle(m, x, y, v_x, v_y);
	a->id = pcount++;
	particle_outset->add(*a);
}
//set을 생성하여 baseSet에 넣는다.
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
	cout << "set" << BaseSet[setcount]->setid << "이 추가되었습니다." << endl;
}
//베이스 셋을 조회하여 입력된 setid를 갖는 set의 주소를 반환한다.
particleset* whole::findset(int psetid)
{
	int i;
	for (i = 0; i <= setcount; i++)
		if (BaseSet[i]->setid == psetid)
			return BaseSet[i];
	cout << psetid << "인 set이 없습니다." << endl;
	return nullptr;
}

//기본 set으로 입자를 옮긴다.
void whole::removeparticle(int psetid, int pid)
{
	int a = check(psetid, pid);
	if (a == 0)
		cout << psetid << "set이 없어 제외할 수 없습니다." << endl;
	else if (a == 1)
		cout << psetid << "set에 " << pid << "입자가 없어서 제외할 수 없습니다." << endl;
	else
	{
		cout << "set" << psetid << "에 있는 " << pid << "입자를 기본 set으로 제외합니다." << endl;
		particle_outset->add(*findset(psetid)->findparticle(pid));
		findset(psetid)->remove(pid);
	}
}
//입자 객체를 삭제한다.
void whole::deleteparticle(int psetid, int pid)
{
	int a = check(psetid, pid);
	if (a == 0)
		cout << psetid << "set이 없어 삭제할 수 없습니다." << endl;
	else if (a == 1)
		cout << psetid << "set에 " << pid << "입자가 없어서 삭제할 수 없습니다." << endl;
	else
	{
		particle* a = findset(psetid)->findparticle(pid)->ref;
		cout << psetid << "set에서" << pid << "입자를 삭제합니다." << endl;
		findset(psetid)->remove(pid);
		delete a;
	}
}
//모든 셋아이디과 그 안의 입자들의 아이디를 출력한다.
void whole::printall()
{
	cout << "*********set과 입자 목록**********" << endl;
	for (int i = 0; i <= setcount; i++)
	{
		std::cout << "SetID: " << BaseSet[i]->setid << "  (입자의 개수: " << BaseSet[i]->Lsize << ")" << std::endl;
		BaseSet[i]->showid();
	}
	cout << "**********************************" << endl;
}
void whole::addparticle(int psetid, int pid)
{

	if (psetid == 0)
		cout << "기본 set에 추가하려면 createparticle()함수를 호출하세요." << endl;
	else if (particle_outset->findparticle(pid) == nullptr)
		cout << pid << "기본 set에 없는 입자를 옮길 수 없습니다." << endl;
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