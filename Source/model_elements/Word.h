#pragma once

#include <vector>
#include <string>

class LanguageModel;
class SoundInventory;
class Syllable;

class Word {
public:
    Word(LanguageModel* language_model, SoundInventory* sound_inventory);
    ~Word();

    std::string ToString(bool orthographic = false);

protected:
    std::vector<Syllable*> m_Syllables;
};