#pragma once
#include<FL/Fl_Menu_Bar.H>

class Fl_Widget;
struct Fl_Menu_Item;

class MainMenu : public Fl_Menu_Bar {
public:
	MainMenu(int x, int y, int w, int h);
	~MainMenu();

	// all the callbacks
	static void newFileCallback(Fl_Widget*, void *v);
	static void openFileCallback(Fl_Widget*, void *v);
	static void saveFileCallback(Fl_Widget*, void *v);
	static void saveAsFileCallback(Fl_Widget*, void *v);
	static void quitCallback(Fl_Widget*, void *v);
	static void helpCallback(Fl_Widget*, void *v);
	static void aboutCallback(Fl_Widget*, void *v);
private:
	Fl_Menu_Item m_MenuContents[11];

};