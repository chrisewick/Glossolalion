#pragma once
#include <FL/Fl_Pack.H>

class Fl_Check_Button;
class Fl_Slider;
class Fl_Value_Input;

class PhonemeWidget : public Fl_Pack {
public:
	PhonemeWidget(int x, int y, int w, int h, std::string glyph, float weight,const char *l=0);
	~PhonemeWidget();
private:
	Fl_Check_Button* m_IPAGlyph;
	Fl_Slider* m_frequencySlider;
	Fl_Value_Input* m_frequencyValue;
};