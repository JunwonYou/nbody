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
	//베이스셋에 있는 셋을 역순으로 참조하여 입자를 지우고 셋까지 삭제
	for (int i = setcount; i >= 0; i--)
	{
		std::cout << i << "번째 셋 차례" << std::endl;
		for (int j = 0; j < BaseSet[i]->Lsize; j++)
			deleteparticle(i, j);
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
	remainSet->addparticle(*a);
}
//set을 생성하여 baseSet에 넣는다.
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
//베이스 셋을 조회하여 입력된 setid를 갖는 set의 주소를 반환한다.
particleset& whole::findset(int psetid)
{
	int i=0;
	while (BaseSet[i]->setid != psetid) 
		i++;
	return *BaseSet[i];

}

//기본 set으로 입자를 옮긴다.
void whole::removeparticle(int psetid, int pid)
{
	remainSet->addparticle(findset(psetid).findparticle(pid));
	findset(psetid).remove(pid);
}
//입자 객체를 삭제한다.
void whole::deleteparticle(int psetid, int pid)
{
	particle* a = findset(psetid).findparticle(pid).ref;
	findset(psetid).remove(pid);
	delete a;
}
//모든 셋아이디과 그 안의 입자들의 아이디를 출력한다.
void whole::printall()
{
	for (int i = 0; i <= setcount; i++)
	{
		std::cout << "SetID: " << BaseSet[i]->setid << std::endl << "	";
		BaseSet[i]->showid();
	}
}