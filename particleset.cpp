#include "stdafx.h"
#include "particleset.h"
#include <iostream>
using namespace std;
//particle ��ü�� �ڱ��� �ּҸ� ��� ������ ������ ���� �ִ�.
//�� ������ �������� �迭�� ����� ���� ��ü ����Ʈ�� �����ϴ� friend Ŭ����

particleset::particleset()
{
}
particleset::~particleset()
{
	delete[] List;
}

void particleset::addparticle(particle& rhs)
{
	if (List != nullptr)
	{
		particle **newList = new particle*[size+1];
		for (int i = 0; i < size ; i++)
			newList[i] = List[i];
		delete[] List;
		newList[size] = rhs.id;
		List = newList;
	}
	else
	{
		List = new particle*[size+1];
		List[0] = rhs.id;
	}
	size++;
}
//�¿� �ִ� ���ڵ��� ����Ʈ
void particleset::showmembers()
{
	cout << "��� ���� ����Ʈ" << endl;
	for (int i = 0; i < size; i++)
	{
		List[i]->printall();
	}
}
//��ƼŬ�� �¿��� ����
void particleset::removeparticle(particle &rhs)
{	
	int i = findindex(rhs);
	removeparticle(i);
}
//�ε����� ����
void particleset::removeparticle(int i)
{
	if (i >= size)
	{
		cout << "����Ʈ�� �ε����� �ʰ��ϴ� ������ �����Ϸ� �մϴ�." << endl;
		return;
	}
	particle **newList = new particle*[size - 1];
	for (int j = 0; j < i; j++)
		newList[j] = List[j];
	for (int j = i + 1; j < size; j++)
		newList[j - 1] = List[j];
	delete[] List;
	List = newList;
	size--;
}

//��ƼŬ ��ü�� ���� (�̱���. ���ʿ� ���ڴ� ���� �Ҵ��� �ʿ䰡 ���µ�...���� �������ΰ�?)
//�ƴϴ�. ����� �Է��� �ް� �ϳ��� �����ؾ� �Ѵ�.. �� �Ӹ�����
void particleset::deleteparticle(particle &rhs)
{
	int i = findindex(rhs);
	List[i] = 0;
	removeparticle(i);
}
//�Է¹��� ������ ����Ʈ �ε��� ã��
int particleset::findindex(const particle &rhs)
{
	int i = 0;
	while (List[i] != rhs.id)
		i++;
	return i;
}