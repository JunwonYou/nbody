#include "stdafx.h"
#include "particle.hpp"
#include "particleset.hpp"
#include <iostream>
#include "whole.hpp"

using namespace std;

int main()
{
	whole a;
	a.createparticle(2, 2, 2, 2);
	a.createparticle(3, 4, 2, 4);
	a.createparticle(4, 4, 4, 4);
	a.createset();
	a.printall();
	a.addparticle(1, 0);
	a.printall();
	a.removeparticle(1, 0);
	a.printall();
	cout << "main�Լ� ��" << endl;
	return 0;
}

//addparticle�� �ű�� �͸� �����ϸ� �� �ɵ�?
//�� �ڲ� ���ڰ� ���� �ФФ�