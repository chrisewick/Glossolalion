#include "../Constants.h"
#include "MainMenu.h"

MainMenu::MainMenu(int x, int y, int w, int h) :
	Fl_Menu_Bar(x, y, w, h)
{
	m_MenuContents[0] = { "&File", 0, 0, 0, FL_SUBMENU };
	m_MenuContents[1] = { "&New", 0, (Fl_Callback*)newFileCallback };
	m_MenuContents[2] = { "&Open", FL_COMMAND + 'o', (Fl_Callback*)openFileCallback, 0, FL_MENU_DIVIDER };
	m_MenuContents[3] = { "&Save", FL_COMMAND + 's', (Fl_Callback*)saveFileCallback };
	m_MenuContents[4] = { "&Save as...", FL_COMMAND + FL_SHIFT + 's', (Fl_Callback*)saveAsFileCallback, 0, FL_MENU_DIVIDER };
	m_MenuContents[5] = { "E&xit", FL_COMMAND + 'q', (Fl_Callback*)quitCallback };
	m_MenuContents[6] = { 0 };
	m_MenuContents[7] = { "&Help", 0, 0, 0, FL_SUBMENU };
	m_MenuContents[8] = { "Help", 0, (Fl_Callback*)helpCallback, 0, FL_MENU_DIVIDER };
	m_MenuContents[9] = { "About", 0, (Fl_Callback*)aboutCallback };
	m_MenuContents[10] = { 0 };
	this->copy(m_MenuContents);
}

MainMenu::~MainMenu() {

}



void MainMenu::newFileCallback(Fl_Widget *, void * v)
{
}

void MainMenu::openFileCallback(Fl_Widget *, void * v)
{
}

void MainMenu::saveFileCallback(Fl_Widget *, void * v)
{
}

void MainMenu::saveAsFileCallback(Fl_Widget *, void * v)
{
}

void MainMenu::quitCallback(Fl_Widget *, void * v)
{
	exit(0);
}

void MainMenu::helpCallback(Fl_Widget *, void * v)
{
}

void MainMenu::aboutCallback(Fl_Widget *, void * v)
{
}