#include "stdafx.h"
#define _USE_MATH_DEFINES
#include "math.h"
#include "Solve3.h"
#include <stdexcept>

using namespace std;

EquationRoots3 GetResultWhenDLessZero(double a, double b, double p, double q, double D)
{
	EquationRoots3 result;

	double angle;
	if (q < 0)
	{
		angle = atan(sqrt(-D) / (-q / 2));
	}
	if (q > 0)
	{
		angle = atan(sqrt(-D) / (-q / 2)) + M_PI;
	}
	if (q == 0)
	{
		angle = M_PI / 2;
	}
	double y1, y2, y3;
	y1 = 2 * sqrt(-p / 3) * cos(angle / 3);
	y2 = 2 * sqrt(-p / 3) * cos((angle + 2 * M_PI) / 3);
	y3 = 2 * sqrt(-p / 3) * cos((angle + 4 * M_PI) / 3);
	result.numRoots = 3;
	result.roots[0] = y1 - (b / 3 * a);
	result.roots[1] = y2 - (b / 3 * a);
	result.roots[2] = y3 - (b / 3 * a);
	return result;
}
EquationRoots3 GetResultWhenDMoreZero(double a, double b, double q, double D)
{
	EquationRoots3 result;
	double y1;
	y1 = pow((-q / 2) + sqrt(D), 1.0 / 3.0) - pow((q / 2) + sqrt(D), 1.0 / 3.0);
	result.numRoots = 1;
	result.roots[0] = y1 - (b / 3 * a);
	return result;
}

EquationRoots3 GetResultWhenDEqualZero(double a, double b, double q, double D)
{
	EquationRoots3 result;
	double y1, y2;
	y1 = -2 * pow(q / 2, 1.0 / 3.0);
	y2 = pow(q / 2, 1.0 / 3.0);
	result.numRoots = 2;
	result.roots[0] = y1 - (b / 3 * a);
	result.roots[1] = y2 - (b / 3 * a);
	return result;
}

// ��������� ����� ����������� ��������� ax^3 + bx^2 + cx + d = 0
// ������� �������
EquationRoots3 Solve3(double a, double b, double c, double d)
{
	if (a == 0)
	{
		throw std::invalid_argument("the argument must be = 0");
	}

	EquationRoots3 result;
	double p = ((3 * a * c) - (b * b)) / 3 * a * a;
	double q = (2 * b * b * b - 9 * a * b * c + 27 * a * a * d) / 27 * a * a * a;
	double D = (q / 2) * (q / 2) + (p / 3) * (p / 3) * (p / 3);

	if (D < 0)
	{
		result = GetResultWhenDLessZero(a, b, p, q, D);
	}

	if (D > 0)
	{
		result = GetResultWhenDMoreZero(a, b, q, D);
	}
	if (D == 0)
	{
		result = GetResultWhenDEqualZero(a, b, q, D);
	}
	return result;
}