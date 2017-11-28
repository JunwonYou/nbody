#include "stdafx.h"
#include <iostream>
#include <string>
#include "UI.hpp"
using namespace std;

double UI::trans_input(string* com_arr, int index)
{
	if (com_arr[index].length() == 0)
		throw 1;
	double num = 0;
	char sign = 1;
	for (int i = 0; i < com_arr[index].length(); i++)
	{
		int a = static_cast<int>(com_arr[index][i]);
		if (i==0 && a == 45)
			sign = -1;
		else if (47 < a && a < 58)
		{
			num += a - 48;
			num *= 10;
		}
		else if (a == 46)
			continue;
		else if (a == 101 || a == 69 || a == 43 || a == 45)
			continue;
		else
			throw 1;
	}
	int deg = trans_input_decimal(com_arr, index) - 1;
	if (deg > 0)
	{
		while (deg > 0)
		{
			num *= 10.0;
			deg--;
		}
	}
	else if (deg < 0)
	{
		while (deg < 0)
		{
			num /= 10.0;
			deg++;
		}
	}
	return sign*num;

}
int UI::trans_input_decimal(string* com_arr, int index)
{
	int deg = 0;
	char decimal = 0;
	int exponent = 0;
	char sign = 0;
	for (int i = 0; i < com_arr[index].length(); i++)
	{
		int a = static_cast<int>(com_arr[index][i]);
		if (47 < a && a < 58)
		{
			if (decimal)
				deg--;
		}
		else if (a == 45)
			continue;
		else if (a == 46)
			if (decimal == 0)
				decimal = 1;
			else
				throw 2;
		else if (a == 101 || a == 69)
		{
			cout << "지수 부분 처리" << endl;
			for (int k = i + 1; k < com_arr[index].length(); k++)
			{
				int b = static_cast<int>(com_arr[index][k]);
				if (k == i + 1)
				{
					if (b == 43)
					{
						sign = 1;
						continue;
					}
					else if (b == 45)
					{
						sign = 2;
						continue;
					}
					else if (47 < b && b < 58)
					{
						exponent += b - 48;
						exponent *= 10;
						cout << exponent << endl;
					}

				}
				else if (47 < b && b < 58)
				{
					exponent += b - 48;
					exponent *= 10;
					cout << exponent << endl;
				}
				
				else
					throw 2;
			}
			exponent /= 10;
			if (sign == 2)
				exponent *= -1;
			cout << "지수: " << exponent << endl;
			deg += exponent;
			return deg;
		}
		else
			throw 2;
	}
	return deg;
}
int UI::num_parameter(string* com_arr)
{
	string str = com_arr[0];
	if (str == "@")
		return 0;
	else if (str == "A")
		return 1;
	else if (str == "B")
		return 2;
	else if (str == "C")
		return 3;
	else if (str == "D")
		return 4;
	else if (str == "E")
		return 5;
	else if (str == "F")
		return 6;
	else if (str == "G")
		return 7;
	else
		return -1;
}

void UI::Run()
{
	whole = new Set_whole;
start:
	try {
		while (1)
		{
			string commend;
			cout << endl << "Enter a command: ";
			getline(cin, commend);
			string* com_arr = split(commend);
			if (com_arr[1].length() != 2)
				throw 3;
			else if (com_arr[1][0] == 'q' && com_arr[1][1] == 'q')
			{
				delete[] com_arr;
				delete whole;
				cout << "Done" << endl;
				return;
			}
			else
			{
				switch (com_arr[1][0])
				{
				case 'p':
					switch (com_arr[1][1])
					{
					case  'a':
					{
						if (num_parameter(com_arr) != 1)
							throw 6;
						if (whole->pcount == 0)
						{
							cout << "No particle" << endl;
							goto start;
						}
						for (int s = 0; s < whole->setcount; s++)
							for (int p = 0; p < whole->Set_of_set[s]->Lsize; p++)
								whole->Set_of_set[s]->List[p]->print_infor();
						break;
					}
					case  'p':
					{
						if(num_parameter(com_arr) != 2)
							throw 6;
						string id = com_arr[2];
						for (int s = 0; s < whole->setcount; s++)
							for (int p = 0; p < whole->Set_of_set[s]->Lsize; p++)
								if (whole->Set_of_set[s]->List[p]->get_id() == id)
								{
									whole->Set_of_set[s]->List[p]->print_infor();
									goto start;
								}
						cout << "There is no particle " << id << endl;
						break;
						
					}
					case  's':
					{
						if (num_parameter(com_arr) != 2)
							throw 6;
						string setid = com_arr[2];
						if (whole->find_set(setid))
							whole->find_set(setid)->showmembers();
						else
							cout << "There is no set " << setid << endl;
						break;
					}
					case  'f':
					{
						if (num_parameter(com_arr) != 2)
							throw 6;
						string setid = com_arr[2];
						if (whole->find_set(setid))
							whole->find_set(setid)->showforce();
						break;
					}
					case  't':
					{
						if (num_parameter(com_arr) != 1)
							throw 6;
						cout << "print current time" << endl;
						cout << whole->time << "s" << endl;
						break;
					}
					case  'm':
					{
						if (num_parameter(com_arr) != 1)
							throw 6;
						whole->print_memory();
						break;
					}
					case  'g':
					{
						if (num_parameter(com_arr) != 1)
							throw 6;
						if (whole->gravity == 1)
							cout << "Gravity is active now" << endl;
						else
							cout << "Gravity is inactive now" << endl;
						break;
					}

					}
					break;
				case 'a':
					switch (com_arr[1][1])
					{
					case 'p':
					{
						if (num_parameter(com_arr) != 7)
							throw 6;
						string id = com_arr[2];
						double result[5];
						for (int i = 0; i < 5; i++)
							result[i] = trans_input(com_arr, i + 3);
						if (result[0] <= 0)
							throw 7;
						whole->create_particle(id, result[0], result[1], result[2], result[3], result[4]);
						break;
					}
					case 's':
					{
						if (num_parameter(com_arr) != 2)
							throw 6;
						if (com_arr[2].length() == 0)
							throw 5;
						string setid = com_arr[2];
						whole->create_set(setid);
						break;
					}
					case 'e':
					{
						if (num_parameter(com_arr) != 3)
							throw 6;
						string setid = com_arr[2];
						string id = com_arr[3];
						whole->add_particle(setid, id);
						break;
					}
					case 'f':
					{
						if (num_parameter(com_arr) != 5)
							throw 6;
						string pfid = com_arr[2];
						string setid = com_arr[3];
						double result[2];
						for (int i = 0; i < 2; i++)
							result[i] = trans_input(com_arr, i + 4);
						whole->add_force(pfid, result[0], result[1], setid);
						break;
					}
					}

					break;
				case 'd':
					switch (com_arr[1][1])
					{
					case 'p':
					{
						if (num_parameter(com_arr) != 2)
							throw 6;
						string id = com_arr[2];
						int s, p;
						for (s = 0; s < whole->setcount; s++)
							for (p = 0; p < whole->Set_of_set[s]->Lsize; p++)
								if (whole->Set_of_set[s]->List[p]->get_id() == id)
								{
									whole->delete_particle(whole->Set_of_set[s]->setid, id);
									goto start;
								}
						break;
					}
					case 'e':
					{
						if (num_parameter(com_arr) != 3)
							throw 6;
						string setid = com_arr[2];
						string id = com_arr[3];
						whole->remove_particle(setid, id);
						break;
					}
					case 'f':
					{
						if (num_parameter(com_arr) != 2)
							throw 6;
						string pfid = com_arr[2];
						for (int s = 0; s < whole->setcount; s++)
						{
							int numf = whole->Set_of_set[s]->num_f;
							for (int f = 0; f < numf; f++)
							{
								if (whole->Set_of_set[s]->fList[f]->fid == pfid)
								{
									whole->delete_force(pfid, whole->Set_of_set[s]->setid);
									goto start;
								}
							}
						}
						cout << "There is no force " << pfid << endl;
						break;
					}
					case 'a':
					{
						if (num_parameter(com_arr) != 1)
							throw 6;
						//모든 정보 삭제 -> whole 객체를 지우고 새로 만듦. 시간만 유지
						int temp = whole->time;
						delete whole;
						whole = new Set_whole;
						whole->time = temp;
						break;
					}
					}
					break;

				case 'c':
					switch (com_arr[1][1])
					{
					case 't':
					{
						if (num_parameter(com_arr) != 2)
							throw 6;
						int deg = trans_input_decimal(com_arr, 2);
						if (deg < -3)
							throw 4;
						double input = trans_input(com_arr, 2);
						if (input <= 0)
							throw 7;
						cout << "time tick is changed to " << input << "s" << endl;
						whole->t_tick = static_cast<int>(input * 1000);
						break;
					}
					case 'g':
					{
						if (num_parameter(com_arr) != 2)
							throw 6;
						string input = com_arr[2];
						if (input == "true")
						{
							whole->gravity = 1;
							cout << "Gravity enabled" << endl;
						}
						else if (input == "false")
						{
							whole->gravity = 0;
							cout << "Gravity disabled" << endl;
						}
						else
							throw static_cast<string>("bool");
						break;
					}
					case 'p':
					{
						if (num_parameter(com_arr) != 3)
							throw 6;
						string pid = com_arr[2];
						string boo = com_arr[3];
						int s, p;
						for (s = 0; s < whole->setcount; s++)
							for (p = 0; p < whole->Set_of_set[s]->Lsize; p++)
								if (whole->Set_of_set[s]->List[p]->get_id() == pid)
								{
									if (boo == "true")
									{
										cout << "particle " << pid << " is set to fixed" << endl;
										whole->Set_of_set[s]->List[p]->fixation = 1;
									}
									else if (boo == "false")
									{
										cout << "particle " << pid << " is set to movable" << endl;
										whole->Set_of_set[s]->List[p]->fixation = 0;
									}
									else
										throw static_cast<string>("bool");
									goto start;
								}
						cout << "There is no particle " << pid << endl;
						break;
					}
					case 'l':
						cout << "명령어 목록 출력" << endl;
					}
					break;
				case 'r':
					if (num_parameter(com_arr) != 2)
						throw 6;
                        			int time_in_second = static_cast<int>(trans_input(com_arr, 2));
                        			int numof_tick = (time_in_second * 1000 / whole->t_tick);
                        			cout << time_in_second << "초 동안을 계산합니다." << endl;
					switch (com_arr[1][1])
					{
					case  'u':
					{
						whole->Calculate(numof_tick, 0);
						break;
					}
					case  'v':
					{
						whole->Calculate(numof_tick, 1);
						break;
					}
					default:
						throw commend;
					}
					delete[] com_arr;
				}
			}
		}
	}
	catch (int n)
	{
		switch (n)
		{
		case 1:
		{
			cout << "입력 인수가 없거나 정상적이지 않습니다. 다시 입력해주세요." << endl;
			goto start;
		}
		case 2:
		{
			cout << "올바른 소수를 입력해주세요." << endl;
			goto start;
		}
		case 3:
		{
			cout << "커맨드는 두글자로만 입력해주세요. cl 을 입력하면 커맨드 목록을 확인할 수 있습니다." << endl;
			goto start;
		}
		case 4:
		{
			cout << "time tick은 0.001 이상으로만 설정할 수 없습니다." << endl;
			goto start;
		}
		case 5:
		{
			cout << "id를 입력해야 합니다." << endl;
			goto start;
		}
		case 6:
		{
			cout << "커맨드가 필요로 하는 인수와 개수가 맞지 않습니다." << endl;
			goto start;
		}
		case 7:
		{
			cout << "양수로만 받을 수 있는 인수입니다." << endl;
		}
		}
	}
	catch (string str)
	{
		if (str == "bool")
			cout << "true 혹은 false로 설정을 입력하세요" << endl;
		else
		{
			cout << "알 수 없는 오류입니다. 입력을 확인하세요." << endl;
			cout << "잘못된 입력: " << str << endl;

		}
		goto start;
	}
}


string* UI::split(string com)
{

	com = trim(com);

	string* result = new string[8];
	char buffer[64];
	int i;
	int j = 0;
	int index = 1;
	for (i = 0; i < com.length(); i++)
	{
		if (index == 8)
			break;
		else if (i == com.length() - 1)
		{
			buffer[j] = com[i];
			buffer[j + 1] = '\0';
			result[index] = buffer;
			buffer[0] = 0;
		}

		if (com[i] != ' ')
		{
			buffer[j] = com[i];
			j++;
		}

		else
		{
			buffer[j] = '\0';
			result[index] = buffer;
			buffer[0] = 0;
			j = 0;
			index++;

		}
	}
	result[0] = index + 64;
	return result;
}

string UI::trim(string& com)
{

	for (int i = 0; i < com.length(); i++)
	{
		if (com[0] != ' ')
			break;

		if (com[0] == ' ')
		{
			com.erase(0, 1);
		}
	}

	for (int i = com.length() - 1; i > -1; i--)
	{
		if (com[i] != ' ')
			break;

		if (com[i] == ' ')
		{
			com.erase(i, 1);
		}
	}
	return com;
}
