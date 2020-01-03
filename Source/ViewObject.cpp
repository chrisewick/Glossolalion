// Necessary so that certain FL includes which require x.h don't try to find X11 for windows.
#define WIN32

#include "ViewObject.h"
#include "Constants.h"
#include "PresenterObject.h"
#include "gui_elements/MainMenu.h"
#include "gui_elements/PhonemeWidget.h"
#include <iostream>
#include <FL/Fl_Hor_Slider.h>
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Text_Buffer.H>


ViewObject::ViewObject(PresenterObject* p) :
	Fl_Group(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, "Glossolalion")
{
	m_Presenter = p;
	// MainMenu is really crashy and I have no idea why, so let's just leave it out for now, since it isn't even important.
	// m_MainMenu = new MainMenu(0, 0, WINDOW_WIDTH, 30); // new Fl_Menu_Bar();

	// our main interface
	// declare and initialize

	m_Tabs = new Fl_Tabs(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, "Tabs");
	m_Tabs->selection_color(FL_DARK3);

        // The vocabulary tab shows the vocabulary in two scrolling and selectable text areas:
        // One shows the IPA spellings, and the other shows orthographic spellings, though these haven't het been created.
		Fl_Group* m_OutputGroup = new Fl_Group(0, 20, WINDOW_WIDTH, WINDOW_HEIGHT - 40, "Vocabulary");
            m_VocabularyTextDisplayIPA = new Fl_Text_Display(m_OutputGroup->x() + 20, m_OutputGroup->y() + 20, WINDOW_WIDTH - 40, WINDOW_HEIGHT - 364, "Complete Vocabulary (IPA)");
            m_VocabularyTextDisplayOrtho = new Fl_Text_Display(m_OutputGroup->x() + 20, m_OutputGroup->y() + WINDOW_HEIGHT - 364 + 40, WINDOW_WIDTH - 40, WINDOW_HEIGHT - 364, "Complete Vocabulary (Orthographic)");

            m_VocabularyTextDisplayIPA_Buffer = new Fl_Text_Buffer();
            m_VocabularyTextDisplayOrtho_Buffer = new Fl_Text_Buffer();

            m_VocabularyTextDisplayIPA->buffer(m_VocabularyTextDisplayIPA_Buffer);
            m_VocabularyTextDisplayOrtho->buffer(m_VocabularyTextDisplayOrtho_Buffer);

            m_GenerateVocabularyButton = new Fl_Button(240, WINDOW_HEIGHT-60, 120, 40, "Generate Vocabulary");
		m_OutputGroup->end();

        // This is a tab dedicated to word features. It's currently junk, because it was based on a bad, old model.
		Fl_Group* m_TabSyllables = new Fl_Group(0, 20, WINDOW_WIDTH, WINDOW_HEIGHT, "Word Features");
				syllableMinimumValueInput = new Fl_Value_Input(32, 24, 48, 24, "Min:");
				syllableMaximumValueInput = new Fl_Value_Input(116, 24, 48, 24, "Max:");

				// This is stupid.
				syllableIdealValueInput = new Fl_Value_Input(435, 24, 30, 24, "Most frequent syllable count:");
		m_TabSyllables->end();


        // The phones tab contains an inventory of all the phones that could possibly exist in a language, as well as showing the user
        // what phones are currently in the language (as phonemes; currently there is no distinction) and how frequently they are
        // likely to appear in words.
        //TODO: Actually make this functional.
		Fl_Group* m_PhonesGroup = new Fl_Scroll(0, 20, WINDOW_WIDTH, WINDOW_HEIGHT-20, "Phones");
        m_Presenter->ResetPhoneSetIterator();
        std::string* glyph = new std::string();
        for (int i = 0; i < m_Presenter->GetPhoneSetSize(); i++) {
            glyph->append(m_Presenter->GetIPAGlyphForCurrentPhone());
            float weight = m_Presenter->GetWeightForCurrentPhone();
            m_Presenter->GoToNextPhone();
            PhonemeWidget* pw = new PhonemeWidget(40, 40 + 20 * i, 200, 20, this, glyph->c_str(), weight);
            m_PhonemeWidgets.push_back(pw);
            m_PhonesGroup->add(pw);
            glyph->clear();
        }
        delete glyph;

        m_GenerateNewSoundInventoryButton = new Fl_Button(WINDOW_WIDTH * 0.5f, WINDOW_HEIGHT - 60, 120, 140, "Generate New Sound Inventory");

		m_PhonesGroup->end();

	m_Tabs->end();

    //TODO: These all rely on constants and don't actually poll the language, so I should change them
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
    m_GenerateVocabularyButton->callback(GenerateVocabularyButtonStaticCallback, (void*)this);
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

void ViewObject::GenerateVocabularyButtonCallback(Fl_Widget * w, void* v)
{
	m_Presenter->CreateVocabulary();
	std::string* returnString = m_Presenter->GetAllWordsAsStringPtr();
	m_VocabularyTextDisplayIPA_Buffer->text(returnString->c_str());
	std::cout << returnString;
    delete returnString;
}

void ViewObject::GenerateVocabularyButtonStaticCallback(Fl_Widget *w, void *v)
{
	((ViewObject*)v)->GenerateVocabularyButtonCallback(w, ((ViewObject*)v)->m_VocabularyTextDisplayIPA);
}
