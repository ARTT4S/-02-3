#ifndef STUDENT_H
#define STUDENT_H

#include "InstituteVisitor.h"

class Student : public InstituteVisitor
{
public:
	Student();
	void SetName(char* name);
	char* GetName();
	void SetSurname(char* surname);
	char* GetSurname();
	void SetPatronymic(char* patronymic);
	char* GetPatronymic();
	void SetAge(int age);
	int GetAge();
	void print() const;
	friend ostream& operator<<(ostream& out, const Student& Stud);
	friend istream& operator>>(istream& in, Student& Stud);
	friend bool operator>(const Student& St1, const Student& St2);
	friend bool operator<(const Student& St1, const Student& St2);

	class Course 
	{
	private:
		enum constants {
			COURSENAMESIZE = 30,
			COURSEDESCRIPTIONSIZE = 30,
		};
		char* m_courseName = new char[COURSENAMESIZE] {};
		int m_courseGrade = 0;
		char* m_courseDescription = new char[COURSEDESCRIPTIONSIZE] {};

	public:
		
		Course();
		void SetCourseName(char* courseName);
		char* GetCourseName();
		void SetCourseGrade(int courseGrade);
		int GetCourseGrade();
		void SetCourseDescription(char* courseDescription);
		char* GetCourseDescription();
		void CoursePrint() const;
		friend ostream& operator<<(ostream& out, const Course& CourseSt);
		friend istream& operator>>(istream& in, Course& CourseSt);
	};
};

#endif