#include <string>
#include "Set_whole.hpp"
using namespace std;
class UI
{
public:
	string* split(string com); // 입력받은 스트링을 분할해서 반환
	string trim(string&); // 입력받은 스트링의 앞뒤 빈칸을 삭제#pragma once
	Set_whole* whole;
	double trans_input(string*,int);
	int trans_input_decimal(string*, int);

	void Run();
};
