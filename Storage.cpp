#include "Storage.h"

void Storage::SetStudents(vector<Student> Students) {
	m_Students = Students;
}

vector<Student> Storage::GetStudents() {
	return m_Students;
}

void Storage::SetCourse(vector<Student::Course> Course) {
	m_Course = Course;
}

vector<Student::Course> Storage::GetCourse() {
	return m_Course;
}

void Storage::SetLecturers(vector<Lecturer> Lecturers) {
	m_Lecturers = Lecturers;
}

vector<Lecturer> Storage::GetLecturers() {
	return m_Lecturers;
}