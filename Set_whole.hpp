#pragma once
#include "Set_particle.hpp"
#include <iostream>

class Set_whole
{
	friend class UI;
private:
	int setcount = 1; // set 수 (outset도 포함한다. memory 출력 시에만 outset제외)
	int pcount = 0; //particle 수
	int fcount = 0; // force의 수
	Set_particle** Set_of_set; //set들의 set
	Set_particle* particle_outset = nullptr; //입자 생성 시 들어갈 기본 set
	double time = 0; //단위 second
	int t_tick = 100; // 계산 주기, 최소 단위는 1ms 이다. 기본값은 0.1초
	
public:
	Set_whole();
	~Set_whole();
	void create_particle(string, double, double, double, double, double);
	void create_set(string);
	Set_particle* find_set(string);
	// 입자를 기본 set으로 제외
	void remove_particle(string, string);
	// 입자를 삭제
	void delete_particle(string, string);
	void print_memory();
	//기본set에 있는 입자를 원하는 set으로 이동
	void add_particle(string, string);
	//주어진 인덱스의 입자가 있는지 확인
	int check(string, string);
	//set에 force 생성/ 삭제
	void add_force(string, double, double, string);
	void delete_force(string, string);
	//시뮬레이션 연산
	void Calculate(int,char);
	//입자 간 중력 상호작용 계산
	void Gravity();
	char gravity = 1; //중력 on/off 설정값, 1이 on이다.
};
