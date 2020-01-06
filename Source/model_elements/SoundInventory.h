#pragma once

#include <map>
#include <vector>

#include "Phone.h"

class PhoneSet;
class Phoneme;



class SoundInventory {
public:
    SoundInventory(int phonemepoolsize = 15, int vowelpoolsize = 3);
    ~SoundInventory();

    int GetVowelPoolSize();
    int GetPhonemePoolSize();

    void IncrementVowelPoolSize();
    void IncrementPhonemePoolSize();
    void DecrementVowelPoolSize();
    void DecrementPhonemePoolSize();

    Phoneme* GetRandomPhoneme(PhoneType type);

    PhoneSet* GetPhoneSet();

    void AddPhonemeByIdentifier(std::string identifier);
    void RemovePhonemeByIdentifier(std::string identifier);
    Phoneme* GetPhonemeByIdentifier(std::string identifier);

protected:
    PhoneSet* m_PhoneSet; // A collection of every "possible" phone (possible within the program, not within all human languages).
    std::vector<Phoneme*> m_PhonemePool;
    std::vector<Phoneme*> m_ConsonantClusters; // Here, Phoneme* should refer to a dynamic array pointer.
    int m_VowelPoolSize; // Vowel should be determined first, and the rest of the phonemes can then be consonants, liquids, or glides
    int m_PhonemePoolSize; // I have doubts about how necessary it is to store either of these values. This might be totally useless.

private:
    void PickRandomVowels();
    void PickRandomConsonants();

    // Perhaps a more appropriate name would be MakeRandomPhoneme...
    Phoneme* MakeRandomPhoneme(std::vector<Phone*> phone_mini_pool);

    bool CheckIsUniquePhoneme(Phoneme* phoneme);
};