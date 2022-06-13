#ifndef STORAGE_H
#define STORAGE_H

#include "InstituteVisitor.h"
#include "Student.h"
#include "Lecturer.h"
#include <iostream>
#include <vector>
using namespace std;

class Storage
{
private:
	vector<Student> m_Students;
	vector<Student::Course> m_Course;
	vector<Lecturer> m_Lecturers;

public:
	void SetStudents(vector<Student> Students);
	vector<Student> GetStudents();
	void SetCourse(vector<Student::Course> Course);
	vector<Student::Course> GetCourse();
	void SetLecturers(vector<Lecturer> Lecturers);
	vector<Lecturer> GetLecturers();

};

#endif STORAGE_H