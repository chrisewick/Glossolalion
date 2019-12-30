#include "Phoneme.h"

Phoneme::Phoneme(Phone* phone, float weight) :
    m_Phone(phone),
    m_Weight(weight)
{
}

Phoneme::~Phoneme()
{
}

Phone* Phoneme::GetPhone()
{
    return m_Phone;
}
