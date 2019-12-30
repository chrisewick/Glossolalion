#include "Syllable.h"
#include "SoundInventory.h"
#include "Phoneme.h"
#include "Phone.h"

Syllable::Syllable(SoundInventory* sound_inventory)
{
    // For now, every syllable will have CV at the very least.
    m_Onset.push_back(sound_inventory->GetRandomPhoneme(PhoneType::Consonant));

    // By definition, every syllable has a vowel.
    m_Nucleus = sound_inventory->GetRandomPhoneme(PhoneType::Vowel);


    // Codas are common, but for now, we'll say there's a 50% chance a syllable has one.
    int has_coda = rand() % 2;

    if (has_coda == 1) {
        m_Coda.push_back(sound_inventory->GetRandomPhoneme(PhoneType::Consonant));
    }
    
}

Syllable::~Syllable()
{
}

std::string Syllable::ToString()
{
    return std::string();
}
