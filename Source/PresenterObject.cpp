#include "PresenterObject.h"
#include "ViewObject.h"
#include "Constants.h"
#include "model_elements/LanguageModel.h"
#include "model_elements/SoundInventory.h"
#include "model_elements/Phoneme.h"
#include "model_elements/PhoneSet.h"

PresenterObject::PresenterObject(ViewObject * v, LanguageModel* lm)
{
	m_ViewObject = v;
    m_LanguageModel = lm;
}

PresenterObject::~PresenterObject()
{
}

void PresenterObject::GenerateRandomLanguageModel()
{
}

void PresenterObject::CreateVocabulary()
{
}

void PresenterObject::SaveLanguageModel()
{
}

void PresenterObject::LoadLanguageModel(const char* filename)
{
}

int PresenterObject::GetMaxSyllables()
{
    return m_LanguageModel->GetMaxSyllables();
}

int PresenterObject::GetMinSyllables()
{
    return m_LanguageModel->GetMinSyllables();
}

void PresenterObject::SetMaxSyllables(int new_max)
{
    m_LanguageModel->SetMaxSyllables(new_max);
}

void PresenterObject::SetMinSyllables(int new_min)
{
    m_LanguageModel->SetMinSyllables(new_min);
}

void PresenterObject::ResetPhoneSetIterator()
{
    m_LanguageModel->GetSoundInventory()->GetPhoneSet()->ResetIterator();
}

void PresenterObject::GoToNextPhone()
{
    m_LanguageModel->GetSoundInventory()->GetPhoneSet()->GetNextPhone();
}

size_t PresenterObject::GetPhoneSetSize()
{
    return m_LanguageModel->GetSoundInventory()->GetPhoneSet()->GetSize();
}

std::string PresenterObject::GetIPAGlyphForCurrentPhone()
{
    return m_LanguageModel->GetSoundInventory()->GetPhoneSet()->GetCurrentPhone()->GetIPAGlyph();
}

float PresenterObject::GetWeightForCurrentPhone()
{
    return m_LanguageModel->GetSoundInventory()->GetPhoneSet()->GetCurrentPhone()->GetWeight();
}

void PresenterObject::AddPhonemeToLanguageModel(std::string identifier)
{
    m_LanguageModel->GetSoundInventory()->AddPhonemeByIdentifier(identifier);
}

void PresenterObject::RemovePhonemeFromLanguageModel(std::string identifier)
{
    m_LanguageModel->GetSoundInventory()->RemovePhonemeByIdentifier(identifier);
}

float PresenterObject::GetPhonemeWeight(std::string identifier)
{
    return m_LanguageModel->GetSoundInventory()->GetPhonemeByIdentifier(identifier)->GetWeight();
}

void PresenterObject::SetPhonemeWeight(std::string identifier, float new_weight)
{
    m_LanguageModel->GetSoundInventory()->GetPhonemeByIdentifier(identifier)->SetWeight(new_weight);
}