#pragma once
#include "particle.h"

class particleset
{
private:
	particle HeadNode;
public:
	particleset();
	~particleset();
	void createparticle(double, double, double, double = 0, double = 0);
	void addparticle(particle&);
	void removeparticle(particle&);
	void deleteparticle(particle&);
};
