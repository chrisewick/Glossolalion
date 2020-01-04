#pragma once
#include <FL/Fl_Pack.H>

class ViewObject;
class Fl_Check_Button;
class Fl_Slider;
class Fl_Value_Input;


//TODO: Rename to PhoneWidget.
// It's worth noting that this widget, as it functions, now controls Phones more than it does Phonemes.
// I will need a PhonemeWidget at some point, which will be responsible for which of the Phones actually
// have a distinct meaning in the language, and which might simply be phonological 'side effects'.
class PhonemeWidget : public Fl_Pack {
public:
	PhonemeWidget(int x, int y, int w, int h, ViewObject* parent, const char* l, float weight);
	~PhonemeWidget();

    // Callbacks
    static void SetWeightSliderCallback(Fl_Widget *w, void *v);
    static void SetIsActiveCheckboxCallback(Fl_Widget* w, void* v);

    ViewObject* GetParent();
    std::string* GetIPAGlyph();

    Fl_Value_Input* GetValueInput();
private:
    ViewObject* m_Parent; //TODO: I think 'parent' is already built into the library, test this later to see if m_Parent is redundant.
    std::string* m_Glyph;
	Fl_Check_Button* m_GlyphButton;
	Fl_Slider* m_frequencySlider;
	Fl_Value_Input* m_frequencyValue;
};