#include "stdafx.h"
#include "particle.h"
#include "particleset.h"
using namespace std;

int main()
{
	double x = 1.2;
	particle a(x, x, x);
	particle b(3,3,3);
	particleset s;
	s.addparticle(a);
	s.addparticle(b);
	s.showmembers();
	particle c= s.removeparticle(a);
	s.showmembers();
	s.addparticle(c);
	s.deleteparticle(b);
	s.showmembers();

	return 0;
}

