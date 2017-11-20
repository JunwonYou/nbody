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
	cout << "main함수 끝" << endl;
	return 0;
}

//addparticle로 옮기는 것만 성공하면 다 될듯?
//왜 자꾸 입자가 없대 ㅠㅠㅜ