#include <string>


#include "PhonemeWidget.h"
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Hor_Slider.H>
#include <FL/Fl_Value_Input.H>

PhonemeWidget::PhonemeWidget(int x, int y, int w, int h, std::string glyph, float weight, const char* l)
    : Fl_Pack(x, y, w, h, nullptr)
{
	type(HORIZONTAL);
    m_IPAGlyph = new Fl_Check_Button(x, y, 40, 20, glyph.c_str()); // u8"ʣ");
	m_frequencySlider = new Fl_Hor_Slider(x, y, 200, 20);
	m_frequencySlider->value(true);
	m_frequencyValue = new Fl_Value_Input(x, y, 40, 20);

	m_frequencySlider->bounds(0, 20);
	m_frequencyValue->bounds(0, 20);
}

PhonemeWidget::~PhonemeWidget()
{
}