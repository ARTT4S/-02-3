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
	char* itemName1 = new char[] { "Добавить студента" };
	char* itemName2 = new char[] { "Изменить данные студента" };
	char* itemName3 = new char[] { "Удалить студента" };
	char* itemName4 = new char[] { "Отсортировать список студентов по фамилии" };
	char* itemName5 = new char[] { "Вывести список студентов" };
	char* itemName6 = new char[] { "Добавить преподавателя" };
	char* itemName7 = new char[] { "Изменить данные преподавателя" };
	char* itemName8 = new char[] { "Удалить преподавателя" };
	char* itemName9 = new char[] { "Отсортировать список преподавателей по фамилии" };
	char* itemName10 = new char[] { "Вывести список преподавателей" };

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
	cout << "Добавьте запись: \n";
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
	cout << "Запись добавлена.\n";
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
	cout << "Запись о каком студентевы хотите поменять: ";
	cin >> numSt;
	numSt--;
	cout << "Выберите пункт:\n";
	cout << "0 - Возврат к меню." << endl << "1 - Изменить фамилию студента." << endl << "2 - Изменить имя студента." << endl << "3 - Изменить отчество студента." << endl << "4 - Изменить возраст студента." << endl << "5 - Изменить название курса." << endl << "6 - Изменить оценку за курс." << endl << "7 - Изменить описание курса." << endl;
	cin >> changeCommand;
	switch (changeCommand) {
	case 0:
		cout << "Возвращаем вас к меню.\n";
		break;
	case 1:
		cout << "Внесите изменения в поле Фамилия: ";
		cin >> tempName;
		tempStudents[numSt].SetName(tempName);
		break;
	case 2:
		cout << "Внесите изменения в поле Имя: ";
		cin >> tempSurname;
		tempStudents[numSt].SetSurname(tempSurname);
		break;
	case 3:
		cout << "Внесите изменения в поле Отчество: ";
		cin >> tempPatronymic;
		tempStudents[numSt].SetPatronymic(tempPatronymic);
		break;
	case 4:
		cout << "Внесите изменения в поле Возраст: ";
		cin >> tempAge;
		tempStudents[numSt].SetAge(tempAge);
		break;
	case 5:
		cout << "Внесите изменения в поле Название курса: ";
		cin >> tempCourseName;
		tempCourses[numSt].SetCourseName(tempCourseName);
		break;
	case 6:
		cout << "Внесите изменения в поле Оценка за курс: ";
		cin >> tempCourseGrade;
		tempCourses[numSt].SetCourseGrade(tempCourseGrade);
		break;
	case 7:
		cout << "Внесите изменения в поле Описание курса: ";
		cin >> tempCourseDescription;
		tempCourses[numSt].SetCourseDescription(tempCourseDescription);
		break;
	default:
		cout << "Введена неверная команда.\n";
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
	cout << "Какую по счёту запись вы хотите удалить: ";
	cin >> delstr;
	delstr--;
	system("cls");
	tempStudents = Safe.GetStudents();
	tempStudents.erase(tempStudents.begin() + delstr);
	tempCourses = Safe.GetCourse();
	tempCourses.erase(tempCourses.begin() + delstr);
	Safe.SetStudents(tempStudents);
	Safe.SetCourse(tempCourses);
	cout << "Запись удалена.\n";
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
	cout << "Список отсортирован.\n";
	system("pause");

	return 4;
}

int PrintStudents() {
	vector<Student> tempStudents = Safe.GetStudents();
	vector<Student::Course> tempCourses = Safe.GetCourse();
	cout << "Студенты:\n";
	cout << " №|" << setw(NAMESIZE) << "Фамилия|" << setw(NAMESIZE) << "Имя|" << setw(NAMESIZE) << "Отчество|" << setw(12) << "Возраст|" << setw(COURSENAMESIZE) << "Название курса|" << setw(14) << "Оценка за курс|" << setw(COURSEDESCRIPTIONSIZE) << "Описание курса" << endl;
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
	cout << "Запись добавлена.\n";
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
	cout << "Запись о каком преподавателе вы хотите поменять: ";
	cin >> numLec;
	numLec--;
	cout << "Выберите пункт:\n";
	cout << "0 - Возврат к меню." << endl << "1 - Изменить фамилию преподавателя." << endl << "2 - Изменить имя преподавателя." << endl << "3 - Изменить отчество преподавателя." << endl << "4 - Изменить возраст преподавателя." << endl;
	cin >> changeCommand;
	switch (changeCommand) {
	case 0:
		cout << "Возвращаем вас к меню сортировки.\n";
		break;
	case 1:
		cout << "Внесите изменения в поле Фамилия: ";
		cin >> tempName;
		tempLecturers[numLec].SetName(tempName);
		break;
	case 2:
		cout << "Внесите изменения в поле Имя: ";
		cin >> tempSurname;
		tempLecturers[numLec].SetSurname(tempSurname);
		break;
	case 3:
		cout << "Внесите изменения в поле Отчество: ";
		cin >> tempPatronymic;
		tempLecturers[numLec].SetPatronymic(tempPatronymic);
		break;
	case 4:
		cout << "Внесите изменения в поле Возраст: ";
		cin >> tempAge;
		tempLecturers[numLec].SetAge(tempAge);
		break;
	default:
		cout << "Введена неверная команда.\n";
	}
	Safe.SetLecturers(tempLecturers);
	system("pause");

	return 7;
}

int DelLecturer() {
	int delstr = 0, copyi = 0;
	vector<Lecturer> tempLecturers;
	PrintLecturers();
	cout << "Какую по счёту запись вы хотите удалить: ";
	cin >> delstr;
	delstr--;
	system("cls");
	tempLecturers = Safe.GetLecturers();
	tempLecturers.erase(tempLecturers.begin() + delstr);
	Safe.SetLecturers(tempLecturers);
	cout << "Запись удалена.\n";
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
	cout << "Список отсортирован.\n";
	system("pause");

	return 9;
}

int PrintLecturers() {
	vector<Lecturer> tempLecturers = Safe.GetLecturers();
	cout << "Преподаватели:\n";
	cout << " №|" << setw(NAMESIZE) << "Фамилия|" << setw(NAMESIZE) << "Имя|" << setw(NAMESIZE) << "Отчество|" << setw(12) << "Возраст" << endl;
	for (int i = 0; i < tempLecturers.size(); ++i) {
		cout << setw(2) << i + 1;
		cout << tempLecturers[i];
	}
	system("pause");

	return 10;
}

#pragma endregion