#include "SoundInventory.h"

#include "../helpers/Helpers.h"

#include "PhoneSet.h"
#include "Phoneme.h"

SoundInventory::SoundInventory(int phonemepoolsize, int vowelpoolsize) :
    m_PhonemePoolSize(phonemepoolsize),
    m_VowelPoolSize(vowelpoolsize)
{
    m_PhoneSet = new PhoneSet();
    
    PickRandomVowels();
    PickRandomConsonants();

    //TODO: From the phoneme pool, create a list of 10-20 consonant clusters of 2-3 characters in length
}

SoundInventory::~SoundInventory()
{
}

int SoundInventory::GetVowelPoolSize()
{
    return m_VowelPoolSize;
}

int SoundInventory::GetPhonemePoolSize()
{
    return m_PhonemePoolSize;
}

void SoundInventory::IncrementVowelPoolSize()
{
    m_VowelPoolSize++;
    m_PhonemePoolSize++; // because our vowel pool is a subset of our phoneme pool.
}

void SoundInventory::IncrementPhonemePoolSize()
{
    m_PhonemePoolSize++;
}

void SoundInventory::DecrementVowelPoolSize()
{
    m_VowelPoolSize--;
    m_PhonemePoolSize--; // because our vowel pool is a subset of our phoneme pool.
}

void SoundInventory::DecrementPhonemePoolSize()
{
    m_PhonemePoolSize--;
}

Phoneme* SoundInventory::GetRandomPhoneme(PhoneType type)
{
    Phoneme* phoneme = nullptr;

    float searchsize = GetRandomNormal() * (float)m_PhonemePool.size();

    // Loop through the phoneme pool.
    while (searchsize >= 0.f) {
        for (auto p : m_PhonemePool) {
            // Make sure our phoneme is actually of the right type before we modify the search
            if (p->GetPhone()->GetPhoneType() == type) {
                searchsize -= p->GetWeight();
                // If we've gone below zero, we've got our phoneme!
                if (searchsize <= 0.f) {
                    phoneme = p;
                    break;
                }
            }
        }
    }

    return phoneme;
}

PhoneSet* SoundInventory::GetPhoneSet()
{
    return m_PhoneSet;
}

void SoundInventory::AddPhonemeByIdentifier(std::string identifier)
{
    Phone* phone = m_PhoneSet->GetPhoneByIPAGlyph(identifier);
    for (auto phoneme : m_PhonemePool) {
        if (phoneme->GetPhone() == phone) {
            return;
        }
    }
    m_PhonemePool.push_back(new Phoneme(phone, 1.f));
}

void SoundInventory::RemovePhonemeByIdentifier(std::string identifier)
{
    Phone* phone = m_PhoneSet->GetPhoneByIPAGlyph(identifier);
    for (int i = 0; i < m_PhonemePool.size(); i++) {
        if (m_PhonemePool[i]->GetPhone() == phone) {
            delete m_PhonemePool[i];
            m_PhonemePool.erase(m_PhonemePool.begin() + i);
            return;
        }
    }
}

Phoneme* SoundInventory::GetPhonemeByIdentifier(std::string identifier)
{
    Phone* phone = m_PhoneSet->GetPhoneByIPAGlyph(identifier);
    for (auto phoneme : m_PhonemePool) {
        if (phoneme->GetPhone() == phone) {
            return phoneme;
        }
    }
}

void SoundInventory::PickRandomVowels()
{
    // Retreive all vowels from the PhoneSet.
    std::vector<Phone*> vowel_phones;
    for (int i = 0; i < m_PhoneSet->GetSize(); i++) {
        Phone* p;
        if (i == 0) {
            p = m_PhoneSet->GetFirstPhone();
        } else {
            p = m_PhoneSet->GetNextPhone();
        }

        if (p->GetPhoneType() == PhoneType::Vowel) {
            vowel_phones.push_back(p);
        }
    }

    for (auto p : vowel_phones) {
        p->SetWeight(GetRandomNormal());
    }

    // Add all of our vowels to the phoneme pool.
    for (int i = 0; i < m_VowelPoolSize; i++) {
        Phoneme* phoneme;
        do {
            phoneme = GetRandomPhone(vowel_phones);
        } while(CheckIsUniquePhoneme(phoneme) == false);
        phoneme->GetPhone()->SetIsActive(true); // Activate the phone.
        m_PhonemePool.push_back(phoneme);
    }
}

void SoundInventory::PickRandomConsonants()
{
    // Retreive all consonants from the PhoneSet.
    std::vector<Phone*> consonant_phones;
    for (int i = 0; i < m_PhoneSet->GetSize(); i++) {
        Phone* p;
        if (i == 0) {
            p = m_PhoneSet->GetFirstPhone();
        }
        else {
            p = m_PhoneSet->GetNextPhone();
        }

        if (p->GetPhoneType() != PhoneType::Vowel) {
            consonant_phones.push_back(p);
        }
    }

    for (auto p : consonant_phones) {
        p->SetWeight(GetRandomNormal());
    }

    // Add all of our consonantss to the phoneme pool.
    for (int i = 0; i < m_PhonemePoolSize - m_VowelPoolSize; i++) {
        Phoneme* phoneme;
        do {
            phoneme = GetRandomPhone(consonant_phones);
        } while (CheckIsUniquePhoneme(phoneme) == false);
        phoneme->GetPhone()->SetIsActive(true); // Activate the phone.
        m_PhonemePool.push_back(phoneme);
    }
}

Phoneme* SoundInventory::GetRandomPhone(std::vector<Phone*> phone_mini_pool)
{
    float searchsize = GetRandomNormal() * (float)phone_mini_pool.size();
    Phoneme* newphoneme = nullptr;
    while (searchsize > 0.f) {
        for (auto p : phone_mini_pool) {
            searchsize -= p->GetWeight();
            if (searchsize <= 0.f) {
                newphoneme = new Phoneme(p, p->GetWeight());
                return newphoneme;
            }
        }
    }
}

bool SoundInventory::CheckIsUniquePhoneme(Phoneme* phoneme)
{
    // O[n] complexity...?
    for (size_t i = 0; i < m_PhonemePool.size(); i++) {
        if (phoneme->GetPhone() == m_PhonemePool[i]->GetPhone()) {
            return false;
        }
    }
    return true;
}
