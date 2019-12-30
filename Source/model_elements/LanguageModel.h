#pragma once

#include <vector>

typedef unsigned int uint32;

class Word;
class SoundInventory;

class LanguageModel {
public:
    LanguageModel();
    ~LanguageModel();

    bool CreateVocabulary();
    std::vector<Word*> GetVocabulary();

    uint32 GetMaxSyllables();
    uint32 GetMinSyllables();
    void SetMaxSyllables(uint32 new_max);
    void SetMinSyllables(uint32 new_min);

    SoundInventory* GetSoundInventory();

protected:
    uint32 m_MinSyllables = 0;
    uint32 m_MaxSyllables = 5;
    uint32 m_VocabularySize = 10000;
    std::vector<Word*> m_Vocabulary;
    SoundInventory* m_SoundInventory;
};