#pragma once

#include <vector>
#include <string>


// I'm not sure how valuable this will be in the end.
enum class PhoneType { Consonant, Vowel, Glide, Liquid };
enum class ObstruentSubType { Plosive, Nasal, TrillTap, Fricative, Approximant, LateralApproximant, Implosive, Click, Affricative, NA };

class Phone {
public:
    Phone(std::string ipa_glyph, PhoneType type, ObstruentSubType subtype = ObstruentSubType::NA);
    ~Phone();

    // I want these all to return results for UI purposes.
    bool AddOrthography(std::string newortho);
    bool RemoveCurrentOrtho();
    bool RemoveOrtho(std::string removedortho);

    void NextOrthography();
    std::string GetCurrentOrthography();

    std::string GetIPAGlyph() {        return m_IPAGlyph;    }
    PhoneType GetPhoneType() {        return m_PhoneType;    }
    ObstruentSubType GetObstruentSubType() { return m_ObstruentSubType;     }
    float GetWeight() {        return m_Weight;    }
    void SetWeight(float weight) {      m_Weight = weight;  }

protected:
    std::string m_IPAGlyph;
    PhoneType m_PhoneType;
    ObstruentSubType m_ObstruentSubType;
    std::vector<std::string> m_Orthographies;
    float m_Weight;
    std::vector<std::string>::iterator m_CurrentOrthography;
private:
};