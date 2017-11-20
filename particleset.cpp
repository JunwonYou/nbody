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
	cout << "set" << setid << "�Ҹ��� ȣ��" << endl;
	delete[] List;
}

void particleset::addparticle(particle& rhs)
{
	if (List != nullptr)
	{
		particle **newList = new particle*[Lsize+1];
		for (int i = 0; i < Lsize ; i++)
			newList[i] = List[i];
		delete[] List;
		newList[Lsize] = rhs.ref;
		List = newList;
	}
	else
	{
		List = new particle*[Lsize+1];
		List[0] = rhs.ref;
	}
	Lsize++;
}
//�¿� �ִ� ���ڵ��� ����Ʈ
void particleset::showmembers()
{
	cout << "------------��� ���� ����Ʈ-------------" << endl;
	for (int i = 0; i < Lsize; i++)
	{
		List[i]->printinfor();
	}
}
//�¿� �ִ� ���ڵ��� ���̵� ���
void particleset::showid()
{
	for (int i = 0; i < Lsize; i++)
		cout << List[i]->id << " ";
	cout << endl;
}

//��ƼŬid�� �޾� �¿��� ����

void particleset::remove(int id)
{

	particle **newList = new particle*[Lsize - 1];
	int i = 0;
	while (List[i]->id != id)
		i++;
	for (int j = 0; j < i; j++)
		newList[j] = List[j];
	for (int j = i + 1; j < Lsize; j++)
		newList[j - 1] = List[j];
	delete[] List;
	List = newList;
	Lsize--;
}


//�Է¹��� id ���ڸ� �ּҷ� ��ȯ
particle& particleset::findparticle(int pid)
{
	int i = 0;
	while (List[i]->id != pid)
		i++;
	return *List[i];
}