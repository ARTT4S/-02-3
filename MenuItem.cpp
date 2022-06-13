#include "MenuItem.h"
#include <iostream>
using namespace std;

namespace AEA {

    MenuItem::MenuItem(char* item_name, Func func) : m_item_name(item_name), m_func(func) {}

    char* MenuItem::getName() {
        return m_item_name;
    }

    void MenuItem::print() {
        cout << m_item_name;
    }

    int MenuItem::run() {
        return m_func();
    }
}
