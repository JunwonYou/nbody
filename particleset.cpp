#include "stdafx.h"
#include "particleset.h"
#include <iostream>
using namespace std;

particleset::particleset()
{
}
particleset::~particleset()
{
	particle *ptr = HeadNode.pNext;
	particle *pdelete = nullptr;
	while (ptr)
	{
		pdelete = ptr;
		ptr = ptr->pNext;
		//pdelete->printinfor();
		delete pdelete;
	}
	HeadNode.pNext = nullptr;
}
void particleset::createparticle(double pm, double px, double py, double pv_x, double pv_y)
{
	particle *pNode = new particle(pm, px, py, pv_x, pv_y);
	pNode->pNext = HeadNode.pNext;
	HeadNode.pNext = pNode;
}
void particleset::addparticle(particle& rhs)
{
	particle *pNode = new particle(rhs);
	pNode->pNext = HeadNode.pNext;
	HeadNode.pNext = pNode;
}
//셋에 있는 입자들을 프린트
void particleset::showmembers()
{
	cout << "showmembers()" << endl;
	particle *ptr = HeadNode.pNext;
	while (ptr)
	{
		ptr->printall();
		ptr = ptr->pNext;
	}
}
//파티클을 셋에서 제외
particle& particleset::removeparticle(particle &rhs)
{
	particle *ptr = HeadNode.pNext;
	while (ptr->pNext == &rhs)
		ptr = ptr->pNext;
	ptr->pNext = rhs.pNext;
	rhs.pNext = nullptr;
	return rhs;
}
//파티클을 삭제
void particleset::deleteparticle(particle &rhs)
{
	particle *pdelete = nullptr;
	particle *ptr = HeadNode.pNext;
	while (ptr->pNext == &rhs)
		ptr = ptr->pNext;
	pdelete = ptr->pNext;
	ptr->pNext = rhs.pNext;
	delete pdelete;
}
