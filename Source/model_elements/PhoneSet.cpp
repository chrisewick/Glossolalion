#include "PhoneSet.h"
#include "Phone.h"


PhoneSet::PhoneSet()
{
    // Phone(wchar_t ipa_glyph, PhoneType type, ObstruentSubType subtype = ObstruentSubType::NA);

    // Yeah, this is a lot of for loops.
    // Yeah, maybe this should all be part of a different type of data model.
    // No, I don't know what that would look like.
    for (int i = 0; i < PLOSIVES; i++) {
        m_AllPhones[m_Plosives[i]] = new Phone(m_Plosives[i], PhoneType::Consonant, ObstruentSubType::Plosive);
        m_AllPhones[m_Plosives[i]]->AddOrthography(m_PlosivesOrthos[i]);
    }
    for (int i = 0; i < NASALS; i++) {
        m_AllPhones[m_Nasals[i]] = new Phone(m_Nasals[i], PhoneType::Consonant, ObstruentSubType::Nasal);
        m_AllPhones[m_Nasals[i]]->AddOrthography(m_NasalsOrthos[i]);
    }
    for (int i = 0; i < TRILLS; i++) {
        m_AllPhones[m_TrillsTaps[i]] = new Phone(m_TrillsTaps[i], PhoneType::Consonant, ObstruentSubType::TrillTap);
        m_AllPhones[m_TrillsTaps[i]]->AddOrthography(m_TrillsTapsOrthos[i]);
    }
    for (int i = 0; i < FRICATIVES; i++) {
        m_AllPhones[m_Fricatives[i]] = new Phone(m_Fricatives[i], PhoneType::Consonant, ObstruentSubType::Fricative);
        m_AllPhones[m_Fricatives[i]]->AddOrthography(m_FricativesOrthos[i]);
    }
    for (int i = 0; i < APPROXIMANTS; i++) {
        m_AllPhones[m_Approximants[i]] = new Phone(m_Approximants[i], PhoneType::Consonant, ObstruentSubType::Approximant);
        m_AllPhones[m_Approximants[i]]->AddOrthography(m_ApproximantsOrthos[i]);
    }
    for (int i = 0; i < LATERALAPPROXIMANTS; i++) {
        m_AllPhones[m_LateralApproximants[i]] = new Phone(m_LateralApproximants[i], PhoneType::Consonant, ObstruentSubType::LateralApproximant);
        m_AllPhones[m_LateralApproximants[i]]->AddOrthography(m_LateralApproximantsOrthos[i]);
    }
    for (int i = 0; i < IMPLOSIVES; i++) {
        m_AllPhones[m_Implosives[i]] = new Phone(m_Implosives[i], PhoneType::Consonant, ObstruentSubType::Implosive);
        m_AllPhones[m_Implosives[i]]->AddOrthography(m_ImplosivesOrthos[i]);
    }
    for (int i = 0; i < CLICKS; i++) {
        m_AllPhones[m_Clicks[i]] = new Phone(m_Clicks[i], PhoneType::Consonant, ObstruentSubType::Click);
        m_AllPhones[m_Clicks[i]]->AddOrthography(m_ClicksOrthos[i]);
    }
    for (int i = 0; i < AFFRICATIVES; i++) {
        m_AllPhones[m_Affricatives[i]] = new Phone(m_Affricatives[i], PhoneType::Consonant, ObstruentSubType::Affricative);
        m_AllPhones[m_Affricatives[i]]->AddOrthography(m_AffricativesOrthos[i]);
    }
    for (int i = 0; i < VOWELS; i++) {
        m_AllPhones[m_Vowels[i]] = new Phone(m_Vowels[i], PhoneType::Vowel);
        m_AllPhones[m_Vowels[i]]->AddOrthography(m_Vowels[i]);
    }

    m_AllPhonesIterator = m_AllPhones.begin();


    //// Consonants
    //wchar_t m_Plosives[PLOSIVES] = { 'p', 'b', 't', 'd', 'ʈ', 'ɖ', 'c', 'ɟ', 'k', 'ɡ', 'q', 'ɢ', 'ʔ' };
    //wchar_t m_Nasals[7] = { 'm', 'ɱ', 'n', 'ɳ', 'ɲ', 'ŋ',' ɴ' };
    //wchar_t m_TrillsTaps[6] = { 'ʙ', 'ⱱ', 'r', 'ɾ', 'ɽ', 'ʀ' };
    //wchar_t m_Fricatives[22] = { 'ɸ', 'β', 'f', 'v', 'θ', 'ð', 's', 'z', 'ʃ', 'ʒ', 'ʂ', 'ʐ', 'ç', 'ʝ', 'x', 'ɣ', 'χ', 'ʁ', 'ħ', 'ʕ', 'h', 'ɦ' };
    //wchar_t m_Approximants[8] = { 'ʋ', 'ɹ', 'ɻ', 'j', 'ɰ', 'ʍ', 'w', 'ɥ' };
    //wchar_t m_LateralApproximants[7] = { 'ɬ', 'ɮ', 'l', 'ɭ', 'ʎ', 'ʟ', 'ɫ' };
    //wchar_t m_Implosives[10] = { 'ƥ', 'ɓ', 'ƭ', 'ɗ', 'ƈ', 'ʄ', 'ƙ', 'ɠ', 'ʠ', 'ʛ' };
    //wchar_t m_Clicks[5] = { 'ʘ', 'ǀ', 'ǁ', 'ǃ', 'ǂ' };
    //wchar_t m_Null = '∅';
    //wchar_t m_Affricatives[6] = { 'ʦ', 'ʣ', 'ʧ', 'ʤ', 'ʨ', 'ʥ' };

    //// Vowels
    //wchar_t m_Vowels[30] = { 'i', 'y', 'ɨ', 'ʉ', 'ɯ', 'u', 'ɪ', 'ʏ', 'ʊ', 'e', 'ø', 'ɘ', 'ɵ', 'ɤ', 'o', 'ə', 'ɛ', 'œ', 'ɜ', 'ɞ', 'ʌ', 'ɔ', 'æ', 'ɐ', 'a', 'ɶ', 'ɑ', 'ɒ', 'ɚ', 'ɝ' };
}

PhoneSet::~PhoneSet()
{
    // Iterate through and clear the map of all phones.
    PhoneMap::iterator it;
    for (it = m_AllPhones.begin(); it != m_AllPhones.end(); it++) {
        delete (*it).second;
    }
}

Phone* PhoneSet::GetPhoneByIPAGlyph(std::string glyph)
{
    // This shouldn't happen, but if it does, we crash.
    assert(m_AllPhones.count(glyph) > 0);

    return m_AllPhones[glyph];
}

int PhoneSet::GetSize()
{
    return m_AllPhones.size();
}

Phone* PhoneSet::GetFirstPhone()
{
    m_AllPhonesIterator = m_AllPhones.begin();
    return (*m_AllPhonesIterator).second;
}

Phone* PhoneSet::GetCurrentPhone() {
    return (*m_AllPhonesIterator).second;
}

Phone* PhoneSet::GetNextPhone()
{
    m_AllPhonesIterator++;
    if (m_AllPhonesIterator == m_AllPhones.end()) {
        m_AllPhonesIterator = m_AllPhones.begin();
    }
    return (*m_AllPhonesIterator).second;
}

void PhoneSet::ResetIterator()
{
    m_AllPhonesIterator = m_AllPhones.begin();
}