#include <string>

#include "../ViewObject.h"
#include "../PresenterObject.h"
#include "PhonemeWidget.h"
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Hor_Slider.H>
#include <FL/Fl_Value_Input.H>

PhonemeWidget::PhonemeWidget(int x, int y, int w, int h, ViewObject* parent, const char* l, float weight)
    : Fl_Pack(x, y, w, h, nullptr)
    , m_Parent(parent)
{
    // Stores the IPA glyph this specific PhonemeWidget is responsible for.
    m_Glyph = new std::string(l);
	// Sets the type for the pack.
    type(HORIZONTAL);

    // A check button, with label
    m_GlyphButton = new Fl_Check_Button(x, y, 40, 20, m_Glyph->c_str()); // u8"ʣ");
    m_GlyphButton->value(m_Parent->GetPresenter()->GetIsActiveForPhone(l));

    // The frequency at which the letter is likely to appear, ranging from 0-1.
	m_frequencySlider = new Fl_Hor_Slider(x, y, 200, 20, m_Glyph->c_str());
    m_frequencySlider->bounds(0, 1.0);
	m_frequencySlider->value(m_Parent->GetPresenter()->GetWeightForPhone(*m_Glyph));

    // Ties to the slider. I should change this so that it just shows the value as a number rather than allow it to be editable.
	m_frequencyValue = new Fl_Value_Input(x, y, 120, 20);
    m_frequencyValue->bounds(0, 1.0);

    
    // Set up callbacks
    m_frequencySlider->callback(SetWeightSliderCallback, this);
    m_GlyphButton->callback(SetIsActiveCheckboxCallback, this);
}

PhonemeWidget::~PhonemeWidget()
{
    delete m_Glyph;
    delete m_GlyphButton;
    delete m_frequencySlider;
    delete m_frequencyValue;
}

void PhonemeWidget::SetWeightSliderCallback(Fl_Widget* w, void* v)
{
    // So much casting.
    // Sets the value for the slider and the Fl_Value_Input box.
    PhonemeWidget* pw = (PhonemeWidget*)v;
    ViewObject* vo = pw->GetParent();
    Fl_Hor_Slider* slider = (Fl_Hor_Slider*)w;
    vo->GetPresenter()->SetPhonemeWeight(*(pw->GetIPAGlyph()), slider->value());
    Fl_Value_Input* valueinput = pw->GetValueInput();
    valueinput->value(slider->value());
}

void PhonemeWidget::SetIsActiveCheckboxCallback(Fl_Widget* w, void* v)
{
    PhonemeWidget* pw = (PhonemeWidget*)v;
    ViewObject* vo = pw->GetParent();
    Fl_Check_Button* button = (Fl_Check_Button*)w;
    //TODO: This has to do more than just set the active phone. It has to add the phone to, or remove it from, the phoneme pool in the Language Model.
    vo->GetPresenter()->SetIsActiveForPhone(*(pw->GetIPAGlyph()), button->value());
}

ViewObject* PhonemeWidget::GetParent()
{
    return m_Parent;
}

std::string* PhonemeWidget::GetIPAGlyph()
{
    return m_Glyph;
}

Fl_Value_Input* PhonemeWidget::GetValueInput()
{
    return m_frequencyValue;
}
