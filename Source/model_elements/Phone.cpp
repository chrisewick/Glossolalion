#include "Phone.h"

Phone::Phone(std::string ipa_glyph, PhoneType type, ObstruentSubType subtype) :
    m_IPAGlyph(ipa_glyph),
    m_PhoneType(type),
    m_Weight(0.0f),
    m_ObstruentSubType(subtype)
{
}

Phone::~Phone()
{
}

bool Phone::AddOrthography(std::string newortho)
{
    return false;
}

bool Phone::RemoveCurrentOrtho()
{
    return false;
}

bool Phone::RemoveOrtho(std::string removedortho)
{
    return false;
}

void Phone::NextOrthography()
{
    m_CurrentOrthography++;
    if (m_CurrentOrthography == m_Orthographies.end()) {
        m_CurrentOrthography = m_Orthographies.begin();
    }
}

std::string Phone::GetCurrentOrthography()
{
    return *m_CurrentOrthography;
}