#pragma once

#include <string>
#include <vector>

class SoundInventory;
class Phoneme;

class Syllable {
public:
    Syllable(SoundInventory* sound_inventory);
    ~Syllable();

    std::string ToString();

protected:
    Phoneme* m_Nucleus;
    std::vector<Phoneme*> m_Onset;
    std::vector<Phoneme*> m_Coda;
};