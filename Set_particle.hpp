#include <string>
#pragma once
#include "particle.hpp"
using namespace std;
class Set_particle
{
	friend class Set_whole; // whole이 제한없이 접근하도록 허용
	friend class UI;
	//set이 가질 힘을 저장할 구조체 선언
	struct force_s
	{
		string fid = "None";
		double fx;
		double fy;
	};
	force_s** fList = nullptr;	//set이 받는 force의 목록, 나중에 이 리스트가 nullptr인지 아닌지에 따라 delete[]를 나중에 해줘야한다.
	int num_f = 0;	//force의 개수	
	
	//입자 객체의 주소를 받을 동적 메모리 공간
	particle **List = nullptr;
	//메모리의 크기 저장변수
	Set_particle
		*setref = this;
	int Lsize = 0;

public:
	string setid;
	Set_particle();
	~Set_particle();
	void add(particle&);
	void remove(string);
	void showmembers();
	void showid();
	particle* findparticle(string);
	void showforce();
	double getforce_x();
	double getforce_y();
};

