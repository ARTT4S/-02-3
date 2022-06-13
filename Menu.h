#ifndef MENU_H
#define MENU_H
#include "AbstractMenu.h"
#include "MenuItem.h"
#include <cstddef>

namespace AEA {

    class Menu : public AbstractMenu {
    public:
        Menu(MenuItem*, size_t);
        int getSelect() const;
        size_t getCount() const;
        MenuItem* getItems();
        void print();
        int runCommand();

    private:
        MenuItem* m_items{};
        size_t m_count{};
    };
}

#endif