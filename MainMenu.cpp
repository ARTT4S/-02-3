#include "MainMenu.h"
#include <iostream>
#include <Windows.h>
using namespace std;

MainMenu::MainMenu(Menu* menus, size_t count) : m_menus(menus), m_count(count) {}

int MainMenu::getSelect() const {
    return m_select;
}

size_t MainMenu::getCount() const {
    return m_count;
}

Menu* MainMenu::getMenus() {
    return m_menus;
}

void MainMenu::print() {
    cout << "0. Выход.\n" << "1. Студенты.\n" << "2. Преподаватели." << endl;
}

int MainMenu::runCommand() {
    system("cls");
    print();
    cout << "\nСписок операций: ";
    cin >> m_select;
    Sleep(1000);
    system("cls");
    if (m_select != 0 and m_select <= m_count) {
        while (m_menus[m_select - 1].runCommand() != -1) {
            
        };
    }
    else if (m_select == 0) {
        return 0;
    }
    else {
        cout << "Вы ввели неверную комманду!\n";
    }
}