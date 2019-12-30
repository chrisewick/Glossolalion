#include "Word.h"
#include "Syllable.h"
#include "LanguageModel.h"

Word::Word(LanguageModel* language_model, SoundInventory* sound_inventory)
{
    int syllableCount = (rand() % language_model->GetMaxSyllables()) + language_model->GetMinSyllables();

    for (int i = 0; i < syllableCount; i++) {
        m_Syllables.push_back(new Syllable(sound_inventory));
    }
}

Word::~Word()
{
}

std::string Word::ToString()
{
    return std::string();
}
