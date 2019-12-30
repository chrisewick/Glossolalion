#pragma once
#include <string>
#include <vector>

class Phone;


// This is just a note to remind myself that what I'm essentially doing here is creating what's called
// a "fuzzy set", which my edition of Discrete Mathematics asserts is one of the cornerstones of
// AI programming. Neat.
// Important note: this means that all values should be weighted between 0 and 1 inclusive.
// That is to say, the set W is { x e R : x >= 0 && x <= 1.0 }
class Phoneme {
public:
	Phoneme(Phone* phone, float weight);
	~Phoneme();

    Phone* GetPhone();
    float GetWeight() {        return m_Weight;    }
    void SetWeight(float new_weight) { m_Weight = new_weight; }
private:
    Phone* m_Phone;
    float m_Weight;
};