#include "stdafx.h"
#include "Set_particle.hpp"
#include <iostream>
using namespace std;
//particle ��ü�� �ڱ��� �ּҸ� ��� ������ ������ ���� �ִ�.
//�� ������ �������� �迭�� ����� ���� ��ü ����Ʈ�� �����ϴ� friend Ŭ����

Set_particle::Set_particle()
{
}
Set_particle::~Set_particle()
{
	cout << "set" << setid << "�Ҹ��� ȣ��" << endl;
	delete[] List;
}

void Set_particle::add(particle& rhs)
{
	if (List != nullptr)
	{
		particle **newList = new particle*[Lsize + 1];
		for (int i = 0; i < Lsize; i++)
			newList[i] = List[i];
		delete[] List;
		newList[Lsize] = rhs.ref;
		List = newList;
	}
	else
	{
		List = new particle*[Lsize + 1];
		List[0] = rhs.ref;
	}
	Lsize++;
}
//�¿� �ִ� ���ڵ��� ����Ʈ
void Set_particle::showmembers()
{
	cout << "------------��� ���� ����Ʈ-------------" << endl;
	for (int i = 0; i < Lsize; i++)
	{
		List[i]->print_infor();
	}
}
//�¿� �ִ� ���ڵ��� ���̵� ���
void Set_particle::showid()
{
	for (int i = 0; i < Lsize; i++)
		cout << "particle: " << List[i]->id << "	";
	cout << endl;
}

//��ƼŬid�� �޾� �¿��� ����

void Set_particle::remove(int pid)
{

	particle **newList = new particle*[Lsize - 1];
	int i = 0;
	while (List[i]->id != pid)
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
//Lsize��ŭ�� for���� �ݺ��ϰ� ������ nullptr��ȯ
particle* Set_particle::findparticle(int pid)
{
	int i;
	for (i = 0; i < Lsize; i++)
		if (List[i]->id == pid)
			return List[i];
	cout << pid << "���ڰ� �����ϴ�." << endl;
	return nullptr;
}


