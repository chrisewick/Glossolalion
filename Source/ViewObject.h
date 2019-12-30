#pragma once

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Multiline_Output.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Menu_Item.H>
#include <FL/Fl_Tabs.H>
#include <vector>
// #include <FL/Fl_Radio_Button.H>
// #include <FL/Fl_Text_Display.H>

class PresenterObject;
class MainMenu;
class PhonemeWidget;
class Fl_Text_Display;
class Fl_Text_Buffer;

class ViewObject : public Fl_Group {
public:
	ViewObject(PresenterObject* p);
	~ViewObject();

	static void syllableMinimumCallback(Fl_Widget* w, void *v);
	static void syllableMaximumCallback(Fl_Widget* w, void *v);
	void GenerateVocabularyButtonCallback(Fl_Widget* w, void *v);

	static void GenerateVocabularyButtonStaticCallback(Fl_Widget* w, void *v);
private:
	PresenterObject* m_Presenter;
	// MainMenu* m_MainMenu;

	std::vector<Fl_Check_Button*> vowelCheckButtons;
	std::vector<Fl_Check_Button*> consonantCheckButtons;
	std::vector<Fl_Check_Button*> consonantTypesCheckButtons;
	Fl_Check_Button* diacritCheckButton;
	Fl_Check_Button* glottalstopCheckButton;
	Fl_Group* syllableCountGroup;
	Fl_Value_Input* syllableMinimumValueInput;
	Fl_Value_Input* syllableMaximumValueInput;
	Fl_Value_Input* syllableIdealValueInput;
	Fl_Multiline_Output* generatedMultilineOutput;

	Fl_Text_Buffer* m_TextBuffer;
	Fl_Text_Display* m_VocabularyTextDisplayIPA;
    Fl_Text_Display* m_VocabularyTextDisplayOrtho;

	Fl_Button* m_GenerateVocabularyButton;
	Fl_Tabs* m_Tabs;

	std::vector<PhonemeWidget*> m_PhonemeWidgets;
};