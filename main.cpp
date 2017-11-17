#include "stdafx.h"
#include "particle.h"
#include "particleset.h"
#include <iostream>
using namespace std;

int main()
{
	double x = 1.2;
	particle a(x, x, x);
	particle b(3, 3, 3);
	particleset s;
	s.addparticle(a);
	s.addparticle(b);
	s.removeparticle(b);
	cout << "b����Ʈ" << endl;
	b.printall();
	s.deleteparticle(a);
	cout << "a����Ʈ" << endl;
	a.printall();

	return 0;
}