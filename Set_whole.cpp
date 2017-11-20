#include "stdafx.h"
#include "Set_whole.hpp"
using namespace std;
Set_whole::Set_whole()
{
	Set_of_set = new Set_particle*[1];
	particle_outset = new Set_particle;
	Set_of_set[0] = particle_outset->setref;
}

Set_whole::~Set_whole()
{
	//베이스셋에 있는 셋을 역순으로 참조하여 입자를 지우고 셋까지 삭제
	for (int i = setcount; i >= 0; i--)
	{
		std::cout << i << "번째 셋 차례" << std::endl;
		for (int j = 0; j < Set_of_set[i]->Lsize; j++)
			delete Set_of_set[i]->List[j];
		//Set_of_set[i]->~Set_particle();
		delete Set_of_set[i];
	}

	//베이스 셋 삭제
	delete[] Set_of_set;
}
//입자를 동적 생성하여 기본 set에 넣는다.
void Set_whole::create_particle(double m, double x, double y, double v_x, double v_y)
{
	particle* a = new particle(m, x, y, v_x, v_y);
	a->id = pcount++;
	particle_outset->add(*a);
}
//set을 생성하여 Set_of_set에 넣는다.
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
	cout << "set" << Set_of_set[setcount]->setid << "이 추가되었습니다." << endl;
}
//베이스 셋을 조회하여 입력된 setid를 갖는 set의 주소를 반환한다.
Set_particle* Set_whole::find_set(int psetid)
{
	int i;
	for (i = 0; i <= setcount; i++)
		if (Set_of_set[i]->setid == psetid)
			return Set_of_set[i];
	cout << psetid << "인 set이 없습니다." << endl;
	return nullptr;
}

//기본 set으로 입자를 옮긴다.
void Set_whole::remove_particle(int psetid, int pid)
{
	int a = check(psetid, pid);
	if (a == 0)
		cout << psetid << "set이 없어 제외할 수 없습니다." << endl;
	else if (a == 1)
		cout << psetid << "set에 " << pid << "입자가 없어서 제외할 수 없습니다." << endl;
	else
	{
		cout << "set" << psetid << "에 있는 " << pid << "입자를 기본 set으로 제외합니다." << endl;
		particle_outset->add(*find_set(psetid)->findparticle(pid));
		find_set(psetid)->remove(pid);
	}
}
//입자 객체를 삭제한다.
void Set_whole::delete_particle(int psetid, int pid)
{
	int a = check(psetid, pid);
	if (a == 0)
		cout << psetid << "set이 없어 삭제할 수 없습니다." << endl;
	else if (a == 1)
		cout << psetid << "set에 " << pid << "입자가 없어서 삭제할 수 없습니다." << endl;
	else
	{
		particle* a = find_set(psetid)->findparticle(pid)->ref;
		cout << psetid << "set에서" << pid << "입자를 삭제합니다." << endl;
		find_set(psetid)->remove(pid);
		delete a;
	}
}
//모든 셋아이디과 그 안의 입자들의 아이디를 출력한다.
void Set_whole::print_all()
{
	cout << "*********set과 입자 목록**********" << endl;
	for (int i = 0; i <= setcount; i++)
	{
		std::cout << "SetID: " << Set_of_set[i]->setid << "  (입자의 개수: " << Set_of_set[i]->Lsize << ")" << std::endl;
		Set_of_set[i]->showid();
	}
	cout << "**********************************" << endl;
}
void Set_whole::add_particle(int psetid, int pid)
{

	if (psetid == 0)
		cout << "기본 set에 추가하려면 createparticle()함수를 호출하세요." << endl;
	else if (particle_outset->findparticle(pid) == nullptr)
		cout << pid << "기본 set에 없는 입자를 옮길 수 없습니다." << endl;
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