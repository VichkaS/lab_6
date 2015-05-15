// oop6_1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Solve3.h"
//#include <stdexcept>
#include <iostream>
using namespace std;

void PrintResult(EquationRoots3 const &result)
{
	for (int i = 0; i < result.numRoots; i++)
	{
		cout << "x" << i + 1 << " = " << result.roots[i] << endl;
	}
}
int main()
{
	//double a = 1, b = 6, c = 3, d = -10; // D < 0
	//double a = 1, b = 12, c = 3, d = 4;
	double a = 2, b = -11, c = 12, d = 9; // D = 0
	EquationRoots3 result;
	result.numRoots = 0;
	result.roots[0] = 0;
	result.roots[1] = 0;
	result.roots[2] = 0;
	try
	{		
		//cin >> a >> b >> c >> d;
		result = Solve3(a, b, c, d);
		PrintResult(result);
	}
	catch (std::invalid_argument const & e) 
	{
		cout << "Error: " << e.what() << "\n";
	}
	return 0;
}

