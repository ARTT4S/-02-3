#include "Lecturer.h"

Lecturer::Lecturer() {
	strcpy_s(m_name, NAMESIZE, "");
	strcpy_s(m_surname, NAMESIZE, "");
	strcpy_s(m_patronymic, NAMESIZE, "");
	m_age = 0;
};

void Lecturer::SetName(char* name) {
	strcpy_s(m_name, NAMESIZE, name);
}

char* Lecturer::GetName() {
	return m_name;
}

void Lecturer::SetSurname(char* surname) {
	strcpy_s(m_surname, NAMESIZE, surname);
}

char* Lecturer::GetSurname() {
	return m_surname;
}

void Lecturer::SetPatronymic(char* patronymic) {
	strcpy_s(m_patronymic, NAMESIZE, patronymic);
}

char* Lecturer::GetPatronymic() {
	return m_patronymic;
}

void Lecturer::SetAge(int age) {
	m_age = age;
}

int Lecturer::GetAge() {
	return m_age;
}

void Lecturer::print() const{
	cout << setw(NAMESIZE - 1) << m_surname << "|" << setw(NAMESIZE - 1) << m_name << "|" << setw(NAMESIZE - 1) << m_patronymic << "|" << setw(11) << m_age << endl;
}

ostream& operator<<(ostream& out, const Lecturer& Lec) {
	Lec.print();

	return out;
}

istream& operator>>(istream& in, Lecturer& Lec) {
	cout << "¬ведите фамилию преподавател€: ";
	in >> Lec.m_surname;
	cout << "¬ведите им€ преподавател€: ";
	in >> Lec.m_name;
	cout << "¬ведите отчество преподавател€: ";
	in >> Lec.m_patronymic;
	cout << "¬ведите возраст преподавател€: ";
	in >> Lec.m_age;

	return in;
}

bool operator>(const Lecturer& Lec1, const Lecturer& Lec2) {
	int lesser = 0;
	if (Lec1.m_surname >= Lec2.m_surname) {
		lesser = strlen(Lec1.m_surname);
	}
	else {
		lesser = strlen(Lec2.m_surname);
	}
	for (int i = 0; i < lesser; ++i) {
		if (Lec1.m_surname[i] > Lec2.m_surname[i]) {
			return 1;
		}
		else {
			return 0;
		}
	}
}

bool operator<(const Lecturer& Lec1, const Lecturer& Lec2) {
	int lesser = 0;
	if (Lec1.m_surname >= Lec2.m_surname) {
		lesser = strlen(Lec1.m_surname);
	}
	else {
		lesser = strlen(Lec2.m_surname);
	}
	for (int i = 0; i < lesser; ++i) {
		if (Lec1.m_surname[i] < Lec2.m_surname[i]) {
			return 1;
		}
		else {
			return 0;
		}
	}
}