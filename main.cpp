#include "stdafx.h"
#include "particle.h"
#include "particleset.h"
using namespace std;

int main()
{
	double x = 1.2;
	particle a(x, x, x) ;
	particle b(3,3,3);
	particleset s;
	s.addparticle(a);
	s.addparticle(b);
	return 0;
}

