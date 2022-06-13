#ifndef MAINMENU_H
#define MAINMENU_H

#include "AbstractMenu.h"
#include "Menu.h"
using namespace AEA;

class MainMenu : public AbstractMenu
{
public:
	MainMenu(Menu*, size_t);
	int getSelect() const;
	size_t getCount() const;
	Menu* getMenus();
	void print();
	int runCommand();

private:
	Menu* m_menus{};
	size_t m_count{};
};

#endif MAINMENU_H