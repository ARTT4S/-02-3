#ifndef MENUITEM_H
#define MENUITEM_H

namespace AEA {

    class MenuItem {
    public:
        typedef int(*Func)();
        MenuItem(char*, Func);
        char* getName();
        void print();
        int run();

    private:
        Func m_func{};
        char* m_item_name{};
    };
}

#endif
