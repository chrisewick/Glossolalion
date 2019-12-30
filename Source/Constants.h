#pragma once
enum LetterType { CONSONANT, VOWEL };
enum SyllableType { VO = 0, VC, CV, VV, CVC, CVV, VCC, CVCC, CCVC };
enum Vowel { A = 0, E, I, O, U, Y };
enum Consonant { B = 0, C, D, F, G, H, J, K, L, M, N, P, Q, R, S, T, V, W, X, Z };

const int SYLLABLE_TYPE_COUNT = 9;

const int WINDOW_HEIGHT = 540;
const int WINDOW_WIDTH = 640;

const int SYLLABLE_MINIMUM_DEFAULT = 1;
const int SYLLABLE_MAXIMUM_DEFAULT = 4;

const int WORDS_PER_SENTENCE = 10;