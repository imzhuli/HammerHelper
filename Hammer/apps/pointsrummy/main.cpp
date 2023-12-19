#include <iostream>
#include <random>

#include "../base/Cards.hpp"

using namespace std;
using namespace xel;
using namespace xel_poker;

static uint8_t Deck2[] = {
    0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25,
    26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51,

    0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25,
    26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51,
};

static uint8_t ShuffledDeck2[Length(Deck2)] = {};

void Shuffle() {
    std::random_device rd;
    std::mt19937       g(rd());
    memcpy(ShuffledDeck2, Deck2, Length(ShuffledDeck2));

    std::shuffle(ShuffledDeck2, ShuffledDeck2 + Length(ShuffledDeck2), g);
}

int main(int argc, char *argv[]) {
    auto    All = std::vector<std::vector<xCard>>();
    uint8_t Colors[] = {SPADE, HEART, CLUB, DIAMOND};
    char    Faces[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K', 'A'};

    for (auto C : Colors) {
        for (int Start = 0; Start < Length(Faces) - 2; ++Start) {
            for (int L = 3; L <= min(Length(Faces) - Start, size_t(5)); ++L) {
                for (int I = 0; I < L; I++) {
                    auto F = Faces[Start + I];
                    cout << F << CardColorMark[C] << " ";
                }
                cout << endl;
            }
        }
    }

    for (auto Curr = 0; Curr < Length(Faces) - 1; ++Curr) {
        // 3 cards:
        auto F = Faces[Curr];
        for (int i = 0; i < 4; ++i) {
            for (int j = 3; j >= 0; --j) {
                if (i == j) {
                    continue;
                }
                cout << F << CardColorMark[j];
            }
            cout << endl;
        }
        for (int i = 0; i < 4; ++i) {
            cout << F << CardColorMark[i];
        }
        cout << endl;
    }

    Shuffle();
    for (int i = 0; i < Length(ShuffledDeck2); ++i) {
        auto CardPtr = &BaseCards[ShuffledDeck2[i]];
        cout << CardPtr->ToMark() << ", ";
    }
    cout << endl;

    return 0;
}