#ifndef INSTITUTEVISITOR_H
#define INSTITUTEVISITOR_H

#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std;

class InstituteVisitor 
{
protected:
	enum constants {
		NAMESIZE = 20,
	};
	char* m_name = new char[NAMESIZE]{};
	char* m_surname = new char[NAMESIZE] {};
	char* m_patronymic = new char[NAMESIZE] {};
	int m_age{};

public:
	virtual void SetName(char* name) = 0;
	virtual char* GetName() = 0;
	virtual void SetSurname(char* surname) = 0;
	virtual char* GetSurname() = 0;
	virtual void SetPatronymic(char* patronymic) = 0;
	virtual char* GetPatronymic() = 0;
	virtual void SetAge(int age) = 0;
	virtual int GetAge() = 0;
	virtual void print() const = 0;
};

#endif