#pragma once
#include <vector>
#include <map>
#include <string>

// Constants for set sizes
const int PLOSIVES = 13;
const int NASALS = 7;
const int TRILLS = 6;
const int FRICATIVES = 22;
const int APPROXIMANTS = 8;
const int LATERALAPPROXIMANTS = 7;
const int IMPLOSIVES = 10;
const int CLICKS = 5;
const int AFFRICATIVES = 6;
const int VOWELS = 30;

class Phone;

typedef std::map<std::string, Phone*> PhoneMap;

// A universal set containing all possible sounds that can exist in the SoundInventory.
// The SoundInventory's vector of Phonemes will consist of a collection of sounds which will be a subset of this universal set.
// I have a sneaking suspicion that this should be a Singleton.
class PhoneSet {
public:
    PhoneSet();
    ~PhoneSet();

    Phone* GetPhoneByIPAGlyph(std::string glyph);

    int GetSize();
    // This function is bad because it does two things: it doesn't just get the first phone, it resets the visible iterator to the beginning.
    // Not that that's entirely bad in and of itself, but it means the function name is entirely inadequate.
    Phone* GetFirstPhone();
    Phone* GetCurrentPhone();
    Phone* GetNextPhone();
    void ResetIterator();

protected:
    PhoneMap m_AllPhones;
    PhoneMap::iterator m_AllPhonesIterator; // Okay, iterating through a map isn't my favourite. Starting to think this strategy kinda sucks.
private:


    // I'm not sure where to put this at all, but this is basically an internal inventory of all of the primary sounds in the IPA.
    // This could be more exhaustive.
    // This was copied and arrayified from https://r12a.github.io/pickers/ipa/

    // I have not included tonality markings of any kind.

    // This is also completely lacking in additional diacrits that would inform pronunciation.

    // Consonants
    std::string m_Plosives[PLOSIVES] = { u8"p", u8"b", u8"t", u8"d", u8"ʈ", u8"ɖ", u8"c", u8"ɟ", u8"k", u8"ɡ", u8"q", u8"ɢ", u8"ʔ" };
    std::string m_Nasals[NASALS] = { u8"m", u8"ɱ", u8"n", u8"ɳ", u8"ɲ", u8"ŋ", u8"ɴ" };
    std::string m_TrillsTaps[TRILLS] = { u8"ʙ", u8"ⱱ", u8"r", u8"ɾ", u8"ɽ", u8"ʀ" };
    std::string m_Fricatives[FRICATIVES] = { u8"ɸ", u8"β", u8"f", u8"v", u8"θ", u8"ð", u8"s", u8"z", u8"ʃ", u8"ʒ", u8"ʂ", u8"ʐ", u8"ç", u8"ʝ", u8"x", u8"ɣ", u8"χ", u8"ʁ", u8"ħ", u8"ʕ", u8"h", u8"ɦ" };
    std::string m_Approximants[APPROXIMANTS] = { u8"ʋ", u8"ɹ", u8"ɻ", u8"j", u8"ɰ", u8"ʍ", u8"w", u8"ɥ" };
    std::string m_LateralApproximants[LATERALAPPROXIMANTS] = { u8"ɬ", u8"ɮ", u8"u8", u8"ɭ", u8"ʎ", u8"ʟ", u8"ɫ" };
    std::string m_Implosives[IMPLOSIVES] = { u8"ƥ", u8"ɓ", u8"ƭ", u8"ɗ", u8"ƈ", u8"ʄ", u8"ƙ", u8"ɠ", u8"ʠ", u8"ʛ" };
    std::string m_Clicks[CLICKS] = { u8"ʘ", u8"ǀ", u8"ǁ", u8"ǃ", u8"ǂ" };
    std::string m_Affricatives[AFFRICATIVES] = { u8"ʦ", u8"ʣ", u8"ʧ", u8"ʤ", u8"ʨ", u8"ʥ" };
    std::string m_Null = u8"∅"; // I won't be employing this for the time being, since I don't really know what it does!

    // Vowels
    std::string m_Vowels[VOWELS] = { u8"i", u8"y", u8"ɨ", u8"ʉ", u8"ɯ", u8"u", u8"ɪ", u8"ʏ", u8"ʊ", u8"e", u8"ø", u8"ɘ", u8"ɵ", u8"ɤ", u8"o", u8"ə", u8"ɛ", u8"œ", u8"ɜ", u8"ɞ", u8"ʌ", u8"ɔ", u8"æ", u8"ɐ", u8"a", u8"ɶ", u8"ɑ", u8"ɒ", u8"ɚ", u8"ɝ" };
};