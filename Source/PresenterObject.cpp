#include "PresenterObject.h"
#include "ViewObject.h"
#include "model_elements/LanguageModel.h"
#include "model_elements/SoundInventory.h"
#include "model_elements/Phoneme.h"
#include "model_elements/PhoneSet.h"
#include "model_elements/Word.h"

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
    //TODO: do I flush the current language model, or store the old one and generate a new one? Seems like a broader design question.
}

void PresenterObject::CreateVocabulary()
{
    //TODO: Report on failure.
    m_LanguageModel->CreateVocabulary();
}

void PresenterObject::SaveLanguageModel()
{
    //TODO: 
}

void PresenterObject::LoadLanguageModel(const char* filename)
{
    //TODO:
}

std::string* PresenterObject::GetAllWordsAsStringPtr(bool orthographic)
{
    // Our return string.
    std::string* output = new std::string();
    // The vocabulary.
    std::vector<Word*> vocab;
    vocab = m_LanguageModel->GetVocabulary();

    // Do this just so we aren't calling .size() an unknowably large amount of times; just a microoptimization
    int vocab_size = (int)vocab.size();

    for (int i = 0; i < vocab_size; i++) {
        output->append(vocab[i]->ToString(orthographic));
        output->append("\n");
    }
    return output;
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

void PresenterObject::RemovePhonemeFromLanguageModel(std::string identifier) {
    m_LanguageModel->GetSoundInventory()->RemovePhonemeByIdentifier(identifier);
}

float PresenterObject::GetPhonemeWeight(std::string identifier) {
    return m_LanguageModel->GetSoundInventory()->GetPhonemeByIdentifier(identifier)->GetWeight();
}

void PresenterObject::SetPhonemeWeight(std::string identifier, float new_weight) {
    m_LanguageModel->GetSoundInventory()->GetPhonemeByIdentifier(identifier)->SetWeight(new_weight);
}

float PresenterObject::GetWeightForPhone(std::string phoneglyph) {
    return m_LanguageModel->GetSoundInventory()->GetPhoneSet()->GetPhoneByIPAGlyph(phoneglyph)->GetWeight();
}

void PresenterObject::SetWeightForPhone(std::string phoneglyph, float weight) {
    m_LanguageModel->GetSoundInventory()->GetPhoneSet()->GetPhoneByIPAGlyph(phoneglyph)->SetWeight(weight);
}

bool PresenterObject::GetIsActiveForPhone(std::string phoneglyph) {
    return m_LanguageModel->GetSoundInventory()->GetPhoneSet()->GetPhoneByIPAGlyph(phoneglyph)->GetIsActive();
}

void PresenterObject::SetIsActiveForPhone(std::string phoneglyph, bool value) {
    Phone* phone = m_LanguageModel->GetSoundInventory()->GetPhoneSet()->GetPhoneByIPAGlyph(phoneglyph);
    if (phone != nullptr) {
        phone->SetIsActive(value);
        if (value == true) {
            AddPhonemeToLanguageModel(phoneglyph);
        } else {
            RemovePhonemeFromLanguageModel(phoneglyph);
        }
    }
}

void PresenterObject::RandomizeWeightsForAllActivePhones()
{
    //TODO: Build this.
}
