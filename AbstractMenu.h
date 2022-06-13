#ifndef ABSTRACTMENU_H
#define ABSTRACTMENU_H

class AbstractMenu
{
public:
	virtual int getSelect() const = 0;
	virtual size_t getCount() const = 0;
	virtual void print() = 0;
	virtual int runCommand() = 0;

protected:
	int m_select{};
	size_t m_count{};
};

#endif