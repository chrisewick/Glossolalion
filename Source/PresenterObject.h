#pragma once
#include <string>

class ViewObject;
class LanguageModel;
class Phoneme;

class PresenterObject {
public:
    PresenterObject(ViewObject* v, LanguageModel* lm);
	~PresenterObject();

    void GenerateRandomLanguageModel();
    void CreateVocabulary();
    void SaveLanguageModel();
    void LoadLanguageModel(const char* filename);

    // Word behaviour
    std::string* GetAllWordsAsStringPtr(bool orthographic = false); // orthographic is a flag for whether or not we want the string returned to be ortho or ipa.

    // Syllable behaviour
    int GetMaxSyllables();
    int GetMinSyllables();
    void SetMaxSyllables(int new_max);
    void SetMinSyllables(int new_min);

    // PhoneSet behaviour
    void ResetPhoneSetIterator();
    void GoToNextPhone();
    size_t GetPhoneSetSize();
    std::string GetIPAGlyphForCurrentPhone();
    float GetWeightForCurrentPhone();

    // Phoneme behaviour
    void AddPhonemeToLanguageModel(std::string identifier);
    void RemovePhonemeFromLanguageModel(std::string identifier);
    float GetPhonemeWeight(std::string identifier);
    void SetPhonemeWeight(std::string identifier, float new_weight);

    //Phone Behaviour
    float GetWeightForPhone(std::string phoneglyph);
    void SetWeightForPhone(std::string phoneglyph, float weight);
    bool GetIsActiveForPhone(std::string phoneglyph);
    void SetIsActiveForPhone(std::string phoneglyph, bool value);
    void RandomizeWeightsForAllActivePhones();

private:
	ViewObject* m_ViewObject;
    LanguageModel* m_LanguageModel;
};