#include "Menu.h"
#include <iostream>
#include <cmath>
#include <ctime>
#include <Windows.h>
using namespace std;

namespace AEA {

    Menu::Menu(MenuItem* items, size_t count) : m_items(items), m_count(count) {}

    int Menu::getSelect() const {
        return m_select;
    }

    size_t Menu::getCount() const {
        return m_count;
    }

    MenuItem* Menu::getItems() {
        return m_items;
    }

    void Menu::print() {
        for (size_t i{}; i < m_count; ++i) {
            cout << i + 1 << ". ";
            m_items[i].print();
            cout << endl;
        }
        cout << "0. Возврат к главному меню." << endl;
    }

    int Menu::runCommand() {
        system("cls");
        print();
            cout << "\nВведите номер команды: ";
            cin >> m_select;
            Sleep(1000);
            system("cls");
            if (m_select != 0 and m_select <= m_count) {
                return m_items[m_select - 1].run();
            }
            else if (m_select == 0) {
                return -1;
            }
            else {
                cout << "Вы ввели неверную комманду!\n";
            }
    }
}
