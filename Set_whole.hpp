#pragma once
#include "Set_particle.hpp"
#include <iostream>

class Set_whole
{
private:
	int setcount = 0; //set에 부여할 번호
	int pcount = 0; //입자에 부여할 번호

	Set_particle** Set_of_set; //set들의 set
	Set_particle* particle_outset = nullptr; //입자 생성 시 들어갈 기본 set
public:
	Set_whole();
	~Set_whole();
	void create_particle(double, double, double, double = 0.0, double = 0.0);
	void create_set();
	Set_particle* find_set(int);
	// 입자를 기본 set으로 제외
	void remove_particle(int, int);
	// 입자를 삭제
	void delete_particle(int, int);
	void print_all();
	//기본set에 있는 입자를 원하는 set으로 이동
	void add_particle(int, int);
	//주어진 인덱스의 입자가 있는지 확인
	int check(int, int);

};
