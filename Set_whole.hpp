#pragma once
#include "Set_particle.hpp"
#include <iostream>

class Set_whole
{
	friend class UI;
private:
	int setcount = 1; // set �� (outset�� �����Ѵ�. memory ��� �ÿ��� outset����)
	int pcount = 0; //particle ��
	int fcount = 0; // force�� ��
	Set_particle** Set_of_set; //set���� set
	Set_particle* particle_outset = nullptr; //���� ���� �� �� �⺻ set
	int time = 0;
public:
	Set_whole();
	~Set_whole();
	void create_particle(string, double, double, double, double, double);
	void create_set(string);
	Set_particle* find_set(string);
	// ���ڸ� �⺻ set���� ����
	void remove_particle(string, string);
	// ���ڸ� ����
	void delete_particle(string, string);
	void print_memory();
	//�⺻set�� �ִ� ���ڸ� ���ϴ� set���� �̵�
	void add_particle(string, string);
	//�־��� �ε����� ���ڰ� �ִ��� Ȯ��
	int check(string, string);
	int t_tick = 100; // ��� �ֱ�, �ּ� ������ ms �̴�. �⺻���� 0.1��
	//set�� force ����/ ����
	void add_force(string, double, double, string);
	void delete_force(string, string);
	//�ùķ��̼� ����
	void Calculate(int,char);
	//���� �� �߷� ��ȣ�ۿ� ���
	void Gravity();
	char gravity = 1; //�߷� on/off ������, 1�� on�̴�.
};
