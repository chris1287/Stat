//============================================================================
// Name        : Statistica.cpp
// Author      : Cristiano Prato
// Version     :
// Copyright   : GPLv2
// Description : container_stat test
//============================================================================

#include <iostream>
#include <list>

#include "container_stat.hpp"

using namespace std;
using namespace crp;

int main()
{
	list<float> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	container_stat<float, list> vs1(v);

	cout
		<< "avg = " << vs1.getAvg() << endl
		<< "var = " << vs1.getStdVar() << endl
		<< "dev = " << vs1.getStdDev() << endl;

	return 0;
}
