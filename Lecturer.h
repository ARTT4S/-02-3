#ifndef LECTURER_H
#define LECTURER_H

#include "InstituteVisitor.h"

class Lecturer : public InstituteVisitor
{
public:
	Lecturer();
	void SetName(char* name);
	char* GetName();
	void SetSurname(char* surname);
	char* GetSurname();
	void SetPatronymic(char* patronymic);
	char* GetPatronymic();
	void SetAge(int age);
	int GetAge();
	void print() const;
	friend ostream& operator<<(ostream& out, const Lecturer& Lec);
	friend istream& operator>>(istream& in, Lecturer& Lec);
	friend bool operator>(const Lecturer& Lec1, const Lecturer& Lec2);
	friend bool operator<(const Lecturer& Lec1, const Lecturer& Lec2);
};

#endif