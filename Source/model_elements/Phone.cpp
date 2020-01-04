#include "Phone.h"

Phone::Phone(std::string ipa_glyph, PhoneType type, ObstruentSubType subtype) :
    m_IPAGlyph(ipa_glyph),
    m_PhoneType(type),
    m_Weight(0.0f),
    m_ObstruentSubType(subtype),
    m_IsActive(false)
{
}

Phone::~Phone()
{
}

bool Phone::AddOrthography(std::string newortho, bool makecurrent)
{
    //TODO: makecurrent is currently ignored, because I'm just building a test.
    m_Orthographies.push_back(newortho);
    m_CurrentOrthography = m_Orthographies.begin();
    return true;
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

bool Phone::GetIsActive()
{
    return m_IsActive;
}

void Phone::SetIsActive(bool value)
{
    m_IsActive = value;
}
