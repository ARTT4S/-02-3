#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <vector>
#include "MainMenu.h"
#include "Menu.h"
#include "MenuItem.h"
#include "Storage.h"
#include "InstituteVisitor.h"
#include "Student.h"
#include "Lecturer.h"

using namespace std;

#pragma region 

Storage Safe;

enum constants {
	NAMESIZE = 20,
	COURSENAMESIZE = 30,
	COURSEDESCRIPTIONSIZE = 30,
};

int AddStudent();
int ChangeStudent();
int DelStudent();
int SortStudents();
int PrintStudents();
int AddLecturer();
int ChangeLecturer();
int DelLecturer();
int SortLecturers();
int PrintLecturers();

#pragma endregion

int main() {
	const int items_number = 10, menu_number = 2;
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	char* itemName1 = new char[] { "�������� ��������" };
	char* itemName2 = new char[] { "�������� ������ ��������" };
	char* itemName3 = new char[] { "������� ��������" };
	char* itemName4 = new char[] { "������������� ������ ��������� �� �������" };
	char* itemName5 = new char[] { "������� ������ ���������" };
	char* itemName6 = new char[] { "�������� �������������" };
	char* itemName7 = new char[] { "�������� ������ �������������" };
	char* itemName8 = new char[] { "������� �������������" };
	char* itemName9 = new char[] { "������������� ������ �������������� �� �������" };
	char* itemName10 = new char[] { "������� ������ ��������������" };

    using namespace AEA;

	MenuItem StudentItems[items_number / 2]{ MenuItem(itemName1, AddStudent), MenuItem(itemName2, ChangeStudent), MenuItem(itemName3, DelStudent), MenuItem(itemName4, SortStudents), MenuItem(itemName5, PrintStudents) };
	MenuItem LecturerItems[items_number / 2]{ MenuItem(itemName6, AddLecturer), MenuItem(itemName7, ChangeLecturer), MenuItem(itemName8, DelLecturer), MenuItem(itemName9, SortLecturers), MenuItem(itemName10, PrintLecturers) };
	Menu menus[menu_number]{ Menu(StudentItems, items_number / 2), Menu(LecturerItems, items_number / 2) };
	MainMenu mainmenu(menus, menu_number);
    while (mainmenu.runCommand()) {};

    return 0;
}

#pragma region 

int AddStudent() {
	cout << "�������� ������: \n";
	vector<Student> tempStudents = Safe.GetStudents();
	vector<Student::Course> tempCourses = Safe.GetCourse();
	Student BufferSt;
	Student::Course BufferCourse;
	cin >> BufferSt;
	cin >> BufferCourse;
	tempStudents.push_back(BufferSt);
	tempCourses.push_back(BufferCourse);
	Safe.SetStudents(tempStudents);
	Safe.SetCourse(tempCourses);
	system("cls");
	cout << "������ ���������.\n";
	system("pause");

	return 1;
}

int ChangeStudent() {
	int changeCommand = 0, numSt = 0, tempAge = 0, tempCourseGrade = 0;
	char* tempName = new char[NAMESIZE];
	char* tempSurname = new char[NAMESIZE];
	char* tempPatronymic = new char[NAMESIZE];
	char* tempCourseName = new char[COURSENAMESIZE];
	char* tempCourseDescription = new char[COURSEDESCRIPTIONSIZE];
	vector<Student> tempStudents = Safe.GetStudents();
	vector<Student::Course> tempCourses = Safe.GetCourse();
	PrintStudents();
	cout << "������ � ����� ���������� ������ ��������: ";
	cin >> numSt;
	numSt--;
	cout << "�������� �����:\n";
	cout << "0 - ������� � ����." << endl << "1 - �������� ������� ��������." << endl << "2 - �������� ��� ��������." << endl << "3 - �������� �������� ��������." << endl << "4 - �������� ������� ��������." << endl << "5 - �������� �������� �����." << endl << "6 - �������� ������ �� ����." << endl << "7 - �������� �������� �����." << endl;
	cin >> changeCommand;
	switch (changeCommand) {
	case 0:
		cout << "���������� ��� � ����.\n";
		break;
	case 1:
		cout << "������� ��������� � ���� �������: ";
		cin >> tempName;
		tempStudents[numSt].SetName(tempName);
		break;
	case 2:
		cout << "������� ��������� � ���� ���: ";
		cin >> tempSurname;
		tempStudents[numSt].SetSurname(tempSurname);
		break;
	case 3:
		cout << "������� ��������� � ���� ��������: ";
		cin >> tempPatronymic;
		tempStudents[numSt].SetPatronymic(tempPatronymic);
		break;
	case 4:
		cout << "������� ��������� � ���� �������: ";
		cin >> tempAge;
		tempStudents[numSt].SetAge(tempAge);
		break;
	case 5:
		cout << "������� ��������� � ���� �������� �����: ";
		cin >> tempCourseName;
		tempCourses[numSt].SetCourseName(tempCourseName);
		break;
	case 6:
		cout << "������� ��������� � ���� ������ �� ����: ";
		cin >> tempCourseGrade;
		tempCourses[numSt].SetCourseGrade(tempCourseGrade);
		break;
	case 7:
		cout << "������� ��������� � ���� �������� �����: ";
		cin >> tempCourseDescription;
		tempCourses[numSt].SetCourseDescription(tempCourseDescription);
		break;
	default:
		cout << "������� �������� �������.\n";
	}
	Safe.SetStudents(tempStudents);
	Safe.SetCourse(tempCourses);
	system("pause");

	return 2;
}

int DelStudent() {
	int delstr = 0, copyi = 0;
	vector<Student> tempStudents = Safe.GetStudents();
	vector<Student::Course> tempCourses = Safe.GetCourse();
	PrintStudents();
	cout << "����� �� ����� ������ �� ������ �������: ";
	cin >> delstr;
	delstr--;
	system("cls");
	tempStudents = Safe.GetStudents();
	tempStudents.erase(tempStudents.begin() + delstr);
	tempCourses = Safe.GetCourse();
	tempCourses.erase(tempCourses.begin() + delstr);
	Safe.SetStudents(tempStudents);
	Safe.SetCourse(tempCourses);
	cout << "������ �������.\n";
	system("pause");

	return 3;
}

int SortStudents() {
	vector<Student> tempStudents = Safe.GetStudents();
	vector<Student::Course> tempCourses = Safe.GetCourse();
	Student BufferSt;
	Student::Course BufferCourse;
	for (int i = 0; i < tempStudents.size() - 1; ++i) {
		for (int j = 0; j < tempStudents.size() - i - 1; ++j) {
			if (tempStudents[j] > tempStudents[j + 1]) {
				swap(tempStudents[j], tempStudents[j + 1]);
				swap(tempCourses[j], tempCourses[j + 1]);

			}
		}
	}
	Safe.SetStudents(tempStudents);
	Safe.SetCourse(tempCourses);
	cout << "������ ������������.\n";
	system("pause");

	return 4;
}

int PrintStudents() {
	vector<Student> tempStudents = Safe.GetStudents();
	vector<Student::Course> tempCourses = Safe.GetCourse();
	cout << "��������:\n";
	cout << " �|" << setw(NAMESIZE) << "�������|" << setw(NAMESIZE) << "���|" << setw(NAMESIZE) << "��������|" << setw(12) << "�������|" << setw(COURSENAMESIZE) << "�������� �����|" << setw(14) << "������ �� ����|" << setw(COURSEDESCRIPTIONSIZE) << "�������� �����" << endl;
	for (int i = 0; i < tempStudents.size(); ++i) {
		cout << setw(2) << i + 1 << "|";
		cout << tempStudents[i];
		cout << tempCourses[i];
	}
	system("pause");

	return 5;
}

int AddLecturer() {
	vector<Lecturer> tempLecturers = Safe.GetLecturers();
	Lecturer BufferLec;
	cin >> BufferLec;
	tempLecturers.push_back(BufferLec);
	Safe.SetLecturers(tempLecturers);
	system("cls");
	cout << "������ ���������.\n";
	system("pause");

	return 6;
}

int ChangeLecturer() {
	int changeCommand = 0, numLec = 0, tempAge = 0;
	char* tempName = new char[NAMESIZE];
	char* tempSurname = new char[NAMESIZE];
	char* tempPatronymic = new char[NAMESIZE];
	PrintLecturers();
	vector<Lecturer> tempLecturers = Safe.GetLecturers();
	cout << "������ � ����� ������������� �� ������ ��������: ";
	cin >> numLec;
	numLec--;
	cout << "�������� �����:\n";
	cout << "0 - ������� � ����." << endl << "1 - �������� ������� �������������." << endl << "2 - �������� ��� �������������." << endl << "3 - �������� �������� �������������." << endl << "4 - �������� ������� �������������." << endl;
	cin >> changeCommand;
	switch (changeCommand) {
	case 0:
		cout << "���������� ��� � ���� ����������.\n";
		break;
	case 1:
		cout << "������� ��������� � ���� �������: ";
		cin >> tempName;
		tempLecturers[numLec].SetName(tempName);
		break;
	case 2:
		cout << "������� ��������� � ���� ���: ";
		cin >> tempSurname;
		tempLecturers[numLec].SetSurname(tempSurname);
		break;
	case 3:
		cout << "������� ��������� � ���� ��������: ";
		cin >> tempPatronymic;
		tempLecturers[numLec].SetPatronymic(tempPatronymic);
		break;
	case 4:
		cout << "������� ��������� � ���� �������: ";
		cin >> tempAge;
		tempLecturers[numLec].SetAge(tempAge);
		break;
	default:
		cout << "������� �������� �������.\n";
	}
	Safe.SetLecturers(tempLecturers);
	system("pause");

	return 7;
}

int DelLecturer() {
	int delstr = 0, copyi = 0;
	vector<Lecturer> tempLecturers;
	PrintLecturers();
	cout << "����� �� ����� ������ �� ������ �������: ";
	cin >> delstr;
	delstr--;
	system("cls");
	tempLecturers = Safe.GetLecturers();
	tempLecturers.erase(tempLecturers.begin() + delstr);
	Safe.SetLecturers(tempLecturers);
	cout << "������ �������.\n";
	system("pause");

	return 8;
}

int SortLecturers() {
	vector<Lecturer> tempLecturers = Safe.GetLecturers();
	Lecturer BufferLec;
	for (int i = 0; i < tempLecturers.size() - 1; ++i) {
		for (int j = 0; j < tempLecturers.size() - i - 1; ++j) {
			if (tempLecturers[j] > tempLecturers[j + 1]) {
				swap(tempLecturers[j], tempLecturers[j + 1]);

			}
		}
	}
	Safe.SetLecturers(tempLecturers);
	cout << "������ ������������.\n";
	system("pause");

	return 9;
}

int PrintLecturers() {
	vector<Lecturer> tempLecturers = Safe.GetLecturers();
	cout << "�������������:\n";
	cout << " �|" << setw(NAMESIZE) << "�������|" << setw(NAMESIZE) << "���|" << setw(NAMESIZE) << "��������|" << setw(12) << "�������" << endl;
	for (int i = 0; i < tempLecturers.size(); ++i) {
		cout << setw(2) << i + 1;
		cout << tempLecturers[i];
	}
	system("pause");

	return 10;
}

#pragma endregion