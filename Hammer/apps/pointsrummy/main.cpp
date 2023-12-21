#include "../base/Cards.hpp"
#include "../base/Rummy.hpp"

#include <iostream>
#include <random>

using namespace std;
using namespace xel;
using namespace xel_poker;
using namespace rummy;

static uint8_t Deck2[] = {
	0,	1,	2,	3,	4,	5,	6,	7,	8,	9,	10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25,
	26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51,

	// 0,	1,	2,	3,	4,	5,	6,	7,	8,	9,	10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25,
	// 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51,
};

static uint8_t ShuffledDeck2[Length(Deck2)] = {};

constexpr size_t CountOnes(uint64_t I) {
	if (!I) {
		return 0;
	}
	size_t Count = 1;
	while (true) {
		uint64_t M1 = I - 1;
		uint64_t IAndM1 = I & M1;
		if (!IAndM1) {
			return Count;
		}
		++Count;
		I &= IAndM1;
	}
	return Count;
}

void Shuffle() {
	std::random_device rd;
	std::mt19937	   g(rd());
	memcpy(ShuffledDeck2, Deck2, Length(ShuffledDeck2));

	std::shuffle(ShuffledDeck2, ShuffledDeck2 + Length(ShuffledDeck2), g);
}

void PrintCardBits(uint64_t Bits, const char * Prefix = "") {
	auto Cards = GetCardsFromBitsSorted(Bits);
	cout << Prefix << " ";
	for (auto & C : Cards) {
		cout << C.ToMark() << " ";
	}
	cout << endl;
}

std::bitset<64> ToBits(uint64_t Bits) {
	auto Set = std::bitset<64>(Bits);
	return Set;
}

int main(int argc, char * argv[]) {
	//
	return 0;
}