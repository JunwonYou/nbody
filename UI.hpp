#include <string>
#include "Set_whole.hpp"
using namespace std;
class UI
{
private:

public:
	string* split(string com); // �Է¹��� ��Ʈ���� �����ؼ� ��ȯ
	string trim(string&); // �Է¹��� ��Ʈ���� �յ� ��ĭ�� ����#pragma once
	Set_whole* whole;
	double trans_input(string*,int);
	int trans_input_decimal(string*, int);
	int num_parameter(string*);
	void Run();
};