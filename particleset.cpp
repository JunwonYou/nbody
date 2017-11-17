#include "stdafx.h"
#include "particleset.h"


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
		pdelete->printinfor();
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
//��ƼŬ�� �¿��� ����
void particleset::removeparticle(particle &rhs)
{

}
//��ƼŬ�� ����
void particleset::deleteparticle(particle &rhs)
{

}