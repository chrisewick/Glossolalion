#include "ViewObject.h"
#include "Constants.h"
#include "PresenterObject.h"
#include "gui_elements/MainMenu.h"
#include "gui_elements/PhonemeWidget.h"
#include <iostream>
#include <FL/Fl_Hor_Slider.h>
#include <FL/Fl_Scroll.H>


ViewObject::ViewObject(PresenterObject* p) :
	Fl_Group(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, "Glossolalion")
{
	m_Presenter = p;
	// MainMenu is really crashy and I have no idea why, so let's just leave it out for now, since it isn't even important.
	// m_MainMenu = new MainMenu(0, 0, WINDOW_WIDTH, 30); // new Fl_Menu_Bar();


	// our main interface
	// declare and initialize

	// This can appear in the Orthography tab
	// diacritCheckButton = new Fl_Check_Button(34, 48, 12, 12, "Use diacritical marks");

	// This can appear in the phones tab
	// glottalstopCheckButton = new Fl_Check_Button(34, 72, 12, 12, "Include glottal stops");

	m_Tabs = new Fl_Tabs(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, "Tabs");
	m_Tabs->selection_color(FL_DARK3);

		Fl_Group* m_OutputGroup = new Fl_Group(0, 20, WINDOW_WIDTH, WINDOW_HEIGHT - 40, "Output");
			generatedMultilineOutput = new Fl_Multiline_Output(m_OutputGroup->x()+20, m_OutputGroup->y()+20, WINDOW_WIDTH-40, WINDOW_HEIGHT-364, "Generated text");
			generatedMultilineOutput->align(FL_ALIGN_TOP);
			generatedMultilineOutput->labelsize(12);

			/*m_IPABuffer = new Fl_Text_Buffer();
			m_IPADisplay = new Fl_Text_Display(m_OutputGroup->x() + 20, m_OutputGroup->y() + 20 + 200, WINDOW_WIDTH - 40, 200, "Generated text");
			m_IPADisplay->buffer(m_IPABuffer);
			m_IPABuffer->text(u8"This string is encoded in UTF-8. See? ŋ");
			m_IPABuffer->append("This should also be UTF-8 encoded. Right? ŋ");*/
	
			generateButton = new Fl_Button(240, WINDOW_HEIGHT-60, 120, 40, "Generate Words");
		m_OutputGroup->end();

		Fl_Group* m_TabSyllables = new Fl_Group(0, 20, WINDOW_WIDTH, WINDOW_HEIGHT, "Syllables");
				syllableMinimumValueInput = new Fl_Value_Input(32, 24, 48, 24, "Min:");
				syllableMaximumValueInput = new Fl_Value_Input(116, 24, 48, 24, "Max:");

				// This is stupid.
				syllableIdealValueInput = new Fl_Value_Input(435, 24, 30, 24, "Most frequent syllable count:");
		m_TabSyllables->end();

		Fl_Group* m_PhonesGroup = new Fl_Scroll(0, 20, WINDOW_WIDTH, WINDOW_HEIGHT-80, "Phones");
        m_Presenter->ResetPhoneSetIterator();
        for (int i = 0; i < m_Presenter->GetPhoneSetSize(); i++) {
            std::string glyph = m_Presenter->GetIPAGlyphForCurrentPhone();
            float weight = m_Presenter->GetWeightForCurrentPhone();
            m_Presenter->GoToNextPhone();
            PhonemeWidget* pw = new PhonemeWidget(40, 40 + 20 * i, 200, 20, glyph, weight);
            m_PhonemeWidgets.push_back(pw);
            m_PhonesGroup->add(pw);
        }
            // Previous version:
			// m_PhonemeWidgets.push_back(new PhonemeWidget(40,40,200,20, u8"ʣ"));
			// m_PhonesGroup->add(m_PhonemeWidgets.at(0));
			/*
			Fl_Check_Button* m_GlideW = new Fl_Check_Button(20, 40, 20, 20, u8"ʣ"); // vd postalveolar affricate 02A4 ʣ \x02\xA4
			Fl_Hor_Slider* m_GlideWSlider = new Fl_Hor_Slider(60, 40, 200, 20);
			Fl_Value_Input* m_GlideWValueInput = new Fl_Value_Input(280, 40, 40, 20);
			m_GlideW->value(true);
			Fl_Check_Button* m_GlideY = new Fl_Check_Button(20, 60, 20, 20, u8"ʃ");
			m_GlideY->labelfont(FL_COURIER);
			Fl_Check_Button* m_GlideL = new Fl_Check_Button(20, 80, 20, 20, u8"ɪ");
			Fl_Check_Button* m_GlideR = new Fl_Check_Button(20, 100, 20, 20, u8"ŋ"); */
		m_PhonesGroup->end();

	m_Tabs->end();

	syllableMinimumValueInput->value(SYLLABLE_MINIMUM_DEFAULT);
	syllableMaximumValueInput->value(SYLLABLE_MAXIMUM_DEFAULT);
	syllableIdealValueInput->value(1);

	syllableMinimumValueInput->minimum(SYLLABLE_MINIMUM_DEFAULT);
	syllableMinimumValueInput->maximum(SYLLABLE_MAXIMUM_DEFAULT);
	syllableMaximumValueInput->minimum(SYLLABLE_MINIMUM_DEFAULT);
	syllableMaximumValueInput->maximum(SYLLABLE_MAXIMUM_DEFAULT);
	syllableIdealValueInput->minimum(SYLLABLE_MINIMUM_DEFAULT);
	syllableIdealValueInput->maximum(SYLLABLE_MAXIMUM_DEFAULT);

	// define callback functions and their triggering behaviours for each widget
	syllableMinimumValueInput->callback(syllableMinimumCallback, syllableIdealValueInput);
	syllableMaximumValueInput->callback(syllableMaximumCallback, syllableIdealValueInput);
	generateButton->callback(static_cb, (void*)this);
}

ViewObject::~ViewObject()
{
}

void ViewObject::syllableMinimumCallback(Fl_Widget * w, void * v)
{
	Fl_Value_Input* minInput = (Fl_Value_Input*)w;
	Fl_Value_Input* idealValueInput = (Fl_Value_Input*)v;
	if (minInput->value() > idealValueInput->value()) {
		idealValueInput->value(minInput->value());
	}
}

void ViewObject::syllableMaximumCallback(Fl_Widget * w, void * v)
{
	Fl_Value_Input* maxInput = (Fl_Value_Input*)w;
	Fl_Value_Input* idealValueInput = (Fl_Value_Input*)v;
	if (maxInput->value() < idealValueInput->value()) {
		idealValueInput->value(maxInput->value());
	}
}

void ViewObject::generateButtonCallback(Fl_Widget * w, void* v)
{
	Fl_Multiline_Output* outputBox = (Fl_Multiline_Output*)v;
	//m_Presenter->CreateSentence(syllableMinimumValueInput->value(), syllableMaximumValueInput->value());
	std::string returnString = outputBox->value();
	//returnString += m_Presenter->GetSentenceAsStringAt(m_Presenter->SentenceCount()-1) + "\n";
	//outputBox->value(returnString.c_str());
	//std::cout << returnString;
}

void ViewObject::static_cb(Fl_Widget *w, void *v)
{
	((ViewObject*)v)->generateButtonCallback(w, ((ViewObject*)v)->generatedMultilineOutput );
}
