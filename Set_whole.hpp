#pragma once
#include "Set_particle.hpp"
#include <iostream>

class Set_whole
{
private:
	int setcount = 0; //set�� �ο��� ��ȣ
	int pcount = 0; //���ڿ� �ο��� ��ȣ
	char gravity = 0; //�߷� on/off ������
	Set_particle** Set_of_set; //set���� set
	Set_particle* particle_outset = nullptr; //���� ���� �� �� �⺻ set
public:
	Set_whole();
	~Set_whole();
	void create_particle(double, double, double, double = 0.0, double = 0.0);
	void create_set();
	Set_particle* find_set(int);
	// ���ڸ� �⺻ set���� ����
	void remove_particle(int, int);
	// ���ڸ� ����
	void delete_particle(int, int);
	void print_all();
	//�⺻set�� �ִ� ���ڸ� ���ϴ� set���� �̵�
	void add_particle(int, int);
	//�־��� �ε����� ���ڰ� �ִ��� Ȯ��
	int check(int, int);
	int t_tick = 1000; // ��� �ð� �ֱ�, ������ ms �̴�. �⺻���� 1��
	//set�� force ����/ ����
	void add_force(int, double, double, int);
	void delete_force(int, int);
	//�ùķ��̼� ����
	void Calculate(int);
	//���� �� �߷� ��ȣ�ۿ� ���
	void Gravity();
};
