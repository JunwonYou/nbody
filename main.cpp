#include "stdafx.h"
#include "particle.h"
#include "particleset.h"
#include <iostream>
#include "whole.h"
#include <string>
#include "UI.h"
using namespace std;

int main()
{
	whole a;
	a.createparticle(2, 2, 2, 2);
	a.createset();
	a.BaseSet[0]->showmembers();
	cout << "mainÇÔ¼ö ³¡" << endl;
	return 0;
}