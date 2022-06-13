#include "Student.h"



Student::Student() {
	strcpy_s(m_name, NAMESIZE, "");
	strcpy_s(m_surname, NAMESIZE, "");
	strcpy_s(m_patronymic, NAMESIZE, "");
	m_age = 0;
};

void Student::SetName(char* name) {
	strcpy_s(m_name, NAMESIZE, name);
}

char* Student::GetName() {
	return m_name;
}

void Student::SetSurname(char* surname) {
	strcpy_s(m_surname, NAMESIZE, surname);
}

char* Student::GetSurname() {
	return m_surname;
}

void Student::SetPatronymic(char* patronymic) {
	strcpy_s(m_patronymic, NAMESIZE, patronymic);
}

char* Student::GetPatronymic() {
	return m_patronymic;
}

void Student::SetAge(int age) {
	m_age = age;
}

int Student::GetAge() {
	return m_age;
}

void Student::print() const {
	cout << setw(NAMESIZE - 1) << m_surname << "|" << setw(NAMESIZE - 1) << m_name << "|" << setw(NAMESIZE - 1) << m_patronymic << "|" << setw(11) << m_age << "|";
}

ostream& operator<<(ostream& out, const Student& Stud) {
	Stud.print();

	return out;
}

istream& operator>>(istream& in, Student& Stud) {
	cout << "¬ведите фамилию студента: ";
	in >> Stud.m_surname;
	cout << "¬ведите им€ студента: ";
	in >> Stud.m_name;
	cout << "¬ведите отчество студента: ";
	in >> Stud.m_patronymic;
	cout << "¬ведите возраст студента: ";
	in >> Stud.m_age;

	return in;
}

bool operator>(const Student& St1, const Student& St2) {
	int lesser = 0;
	if (St1.m_surname >= St2.m_surname) {
		lesser = strlen(St1.m_surname);
	}
	else {
		lesser = strlen(St2.m_surname);
	}
	for (int i = 0; i < lesser; ++i) {
		if (St1.m_surname[i] > St2.m_surname[i]) {
			return 1;
		}
		else {
			return 0;
		}
	}
}

bool operator<(const Student& St1, const Student& St2) {
	int lesser = 0;
	if (St1.m_surname >= St2.m_surname) {
		lesser = strlen(St1.m_surname);
	}
	else {
		lesser = strlen(St2.m_surname);
	}
	for (int i = 0; i < lesser; ++i) {
		if (St1.m_surname[i] < St2.m_surname[i]) {
			return 1;
		}
		else {
			return 0;
		}
	}
}

Student::Course::Course() {
	strcpy_s(m_courseName, COURSENAMESIZE, "");
	m_courseGrade = 0;
	strcpy_s(m_courseDescription, COURSEDESCRIPTIONSIZE, "");
}

void Student::Course::SetCourseName(char* courseName) {
	strcpy_s(m_courseName, COURSENAMESIZE, courseName);
}

char* Student::Course::GetCourseName() {
	return m_courseName;
}

void Student::Course::SetCourseGrade(int courseGrade) {
	m_courseGrade = courseGrade;
}

int Student::Course::GetCourseGrade() {
	return m_courseGrade;
}

void Student::Course::SetCourseDescription(char* courseDescription) {
	strcpy_s(m_courseDescription, COURSEDESCRIPTIONSIZE, courseDescription);
}

char* Student::Course::GetCourseDescription() {
	return m_courseDescription;
}

void Student::Course::CoursePrint() const {
	cout << setw(COURSENAMESIZE - 1) << m_courseName << "|" << setw(14) << m_courseGrade << "|" << setw(COURSEDESCRIPTIONSIZE - 1) << m_courseDescription << endl;
}

ostream& operator<<(ostream& out, const Student::Course& CourseSt) {
	CourseSt.CoursePrint();

	return out;
}

istream& operator>>(istream& in, Student::Course& CourseSt) {
	cout << "¬ведите название курса: ";
	getchar();
	gets_s(CourseSt.m_courseName, CourseSt.COURSENAMESIZE);
	cout << "¬ведите оценку за курс: ";
	in >> CourseSt.m_courseGrade;
	cout << "¬ведите описание курса: ";
	getchar();
	gets_s(CourseSt.m_courseDescription, CourseSt.COURSEDESCRIPTIONSIZE);

	return in;
}