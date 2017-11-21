#include "stdafx.h"
#include "particle.hpp"
#include "Set_particle.hpp"
#include <iostream>
#include "Set_whole.hpp"

using namespace std;

int main()
{
	Set_whole a;
	a.create_particle(2, 2, 2, 2);
	a.create_particle(3, 4, 2, 4);
	a.create_particle(4, 4, 4, 4);
	a.create_set();
	a.print_all();
	a.add_particle(1, 0);
	a.print_all();
	cout << "mainÇÔ¼ö ³¡" << endl;
	cout << sizeof(float) << endl;
	return 0;
}
