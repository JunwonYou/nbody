#include "particleset.h"
#include <iostream>
using namespace std;
//particle 객체가 자기의 주소를 멤버 포인터 변수로 갖고 있다.
//그 포인터 변수들을 배열로 만들어 입자 객체 리스트를 관리하는 friend 클래스

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
//셋에 있는 입자들을 프린트
void particleset::showmembers()
{
	cout << "모든 입자 프린트" << endl;
	for (int i = 0; i < size; i++)
	{
		List[i]->printall();
	}
}
//파티클을 셋에서 제외
void particleset::removeparticle(particle &rhs)
{	
	int i = findindex(rhs);
	removeparticle(i);
}
//인덱스로 제외
void particleset::removeparticle(int i)
{
	if (i >= size)
	{
		cout << "리스트의 인덱스를 초과하는 값으로 제외하려 합니다." << endl;
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

//파티클 객체를 삭제 (미구현. 애초에 입자는 동적 할당할 필요가 없는데...
//아니다. 사용자 입력을 받고 하나씩 생성해야 한다.. 아 머리아파
void particleset::deleteparticle(particle &rhs)
{
	int i = findindex(rhs);
	List[i] = 0;
	removeparticle(i);
}
//입력받은 입자의 리스트 인덱스 찾기
int particleset::findindex(const particle &rhs)
{
	int i = 0;
	while (List[i] != rhs.id)
		i++;
	return i;
}
