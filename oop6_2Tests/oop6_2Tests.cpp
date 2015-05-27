// oop6_2Tests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../oop6_2/Student.h"
using namespace std;

struct StudentFixture
{
	CStudent student = CStudent(16, "Petr", "Petrov");
};


BOOST_FIXTURE_TEST_SUITE(Student, StudentFixture)

BOOST_AUTO_TEST_CASE(InvalidFIO)
{
	BOOST_CHECK_THROW(CStudent(20, "P e t r", "Petrov"), invalid_argument);
	BOOST_CHECK_THROW(CStudent(20, "Petr", "P e t r o v"), invalid_argument);
	BOOST_CHECK_THROW(CStudent(20, "", "Petrov"), invalid_argument);
	BOOST_CHECK_THROW(CStudent(20, "Petr", ""), invalid_argument);
	BOOST_CHECK_THROW(CStudent(20, "Petr", "Petrov", "Pet rovich"), invalid_argument);
	
	BOOST_CHECK_NO_THROW(CStudent(20, "Petr", "Petrov", "Petrovich"));
}

BOOST_AUTO_TEST_CASE(InvalidAge)
{
	BOOST_CHECK_THROW(CStudent(13, "Petr", "Petrov"), out_of_range);
	BOOST_CHECK_NO_THROW(CStudent(30, "Petr", "Petrov", "Petrovich"));
	BOOST_CHECK_THROW(CStudent(61, "Petr", "P e t r o v"), out_of_range);
}

BOOST_AUTO_TEST_CASE(GetNameStudent)
{
	CStudent student = CStudent(21, "Petr", "Petrov", "Petrovich");
	BOOST_CHECK_EQUAL(student.GetName(), "Petr");
	BOOST_CHECK_EQUAL(student.GetSurname(), "Petrov");
	BOOST_CHECK_EQUAL(student.GetPatronymic(), "Petrovich");
	BOOST_CHECK_EQUAL(student.GetAge(), 21);
}

BOOST_AUTO_TEST_CASE(RenameStudent)
{
	CStudent student = CStudent(21, "Petr", "Petrov", "Petrovich");
	student.Rename("Ivan", "Ivanov", "Ivanovich");
	BOOST_CHECK_EQUAL(student.GetName(), "Ivan");
	BOOST_CHECK_EQUAL(student.GetSurname(), "Ivanov");
	BOOST_CHECK_EQUAL(student.GetPatronymic(), "Ivanovich");
}


BOOST_AUTO_TEST_SUITE_END()