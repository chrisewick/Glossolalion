#include "LanguageModel.h"

#include "SoundInventory.h"
#include "Word.h"

LanguageModel::LanguageModel()
{
    m_SoundInventory = new SoundInventory();

    CreateVocabulary();
}

LanguageModel::~LanguageModel()
{
    delete m_SoundInventory;

    for (std::vector<Word*>::iterator it = m_Vocabulary.begin(); it < m_Vocabulary.end(); ++it) {
        delete (*it);
    }
}

void LanguageModel::CreateVocabulary()
{

    //TODO: Make this more sophisticated, naturally.
    //This is sufficient for now, but I'll need to consider
    //morphology as the next major concept in word construction.
    //That is, I would likely have a Morpheme class and a MorphemeInventory.
    for (uint32 i = 0; i < m_VocabularySize; i++) {
        m_Vocabulary.push_back(new Word(this, m_SoundInventory));
    }
}

uint32 LanguageModel::GetMaxSyllables()
{
    return m_MaxSyllables;
}

void LanguageModel::SetMaxSyllables(uint32 new_max)
{
    m_MaxSyllables = new_max;
}

uint32 LanguageModel::GetMinSyllables()
{
    return m_MinSyllables;
}

void LanguageModel::SetMinSyllables(uint32 new_min)
{
    m_MinSyllables = new_min;
}

SoundInventory* LanguageModel::GetSoundInventory()
{
    return m_SoundInventory;
}
