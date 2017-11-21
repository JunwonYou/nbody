#include "stdafx.h"
#include "Set_particle.hpp"
#include <iostream>
using namespace std;
//particle 객체가 자기의 주소를 멤버 포인터 변수로 갖고 있다.
//그 포인터 변수들을 배열로 만들어 입자 객체 리스트를 관리하는 friend 클래스

Set_particle::Set_particle()
{
}
Set_particle::~Set_particle()
{
	cout << "set" << setid << "소멸자 호출" << endl;
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
//셋에 있는 입자들을 프린트
void Set_particle::showmembers()
{
	cout << "------------모든 입자 프린트-------------" << endl;
	for (int i = 0; i < Lsize; i++)
	{
		List[i]->print_infor();
	}
}
//셋에 있는 입자들의 아이디를 출력
void Set_particle::showid()
{
	for (int i = 0; i < Lsize; i++)
		cout << "particle: " << List[i]->id << "	";
	cout << endl;
}

//파티클id를 받아 셋에서 제외

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

//입력받은 id 입자를 주소로 반환
//Lsize만큼만 for문을 반복하고 없으면 nullptr반환
particle* Set_particle::findparticle(int pid)
{
	int i;
	for (i = 0; i < Lsize; i++)
		if (List[i]->id == pid)
			return List[i];
	cout << pid << "입자가 없습니다." << endl;
	return nullptr;
}


