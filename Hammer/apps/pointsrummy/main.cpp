#include "../base/Cards.hpp"
#include "../base/Rummy.hpp"

#include <cstdlib>
#include <iostream>
#include <random>

using namespace std;
using namespace xel;
using namespace xel_poker;
using namespace rummy;

static uint8_t PlainDeck[] = {
	0,	1,	2,	3,	4,	5,	6,	7,	8,	9,	10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25,
	26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51,

	// 0,	1,	2,	3,	4,	5,	6,	7,	8,	9,	10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25,
	// 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51,
};

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

enum eGameState {
	GS_Init,
	GS_Shuffle,
	GS_Discard,
	GS_PlayerRound,
	GS_CheckRound,
	GS_FinishRound,
	GS_End,
};

eGameState		   State;
uint8_t			   Deck[Length(PlainDeck)];
size_t			   DeckCardCount;
const size_t	   PlayerBaseCardCount = 13;
std::random_device RandomDevice;
std::mt19937	   RandomGenerator(RandomDevice());
uint8_t			   PlayerCards[14];
xHandCard		   PlayerHandCard;

void Shuffle() {
	memcpy(Deck, PlainDeck, Length(PlainDeck));
	std::shuffle(Deck, Deck + Length(Deck), RandomGenerator);
}

void GameInit() {
	State = GS_Shuffle;
	return;
}

void GameShuffle() {
	Shuffle();
	DeckCardCount = sizeof(Deck);

	State = GS_Discard;
}

void GameDiscard() {
	memcpy(PlayerCards, Deck, PlayerBaseCardCount * sizeof(*PlayerCards));
	DeckCardCount -= PlayerBaseCardCount;

	PlayerHandCard.Reset();
	for (size_t i = 0; i < PlayerBaseCardCount; ++i) {
		auto CardPtr = &BaseCards[PlayerCards[i]];
		PlayerHandCard.AddCards(CardPtr->GetBit());
	}

	State = GS_PlayerRound;
	return;
}

void PrintPlayerCard() {
	for (size_t i = 0; i < 14; ++i) {
		auto CardPtr = &BaseCards[PlayerCards[i]];
		printf(" %s   ", CardPtr->ToMark().c_str());
	}
	printf("\n");
	for (size_t i = 0; i < 14; ++i) {
		printf("[%02zi]  ", i);
	}
	printf("\n");

	auto Cards0 = PlayerHandCard.Cards0;
	// PrintHints:
	for (auto M : SequencesMelds) {
		if ((M.Bits & Cards0) == M.Bits) {
			PrintCardBits(M.Bits, "<Sequence>");
		}
	}

	// Sets:
	for (auto M : SetMelds) {
		if ((M.Bits & Cards0) == M.Bits) {
			PrintCardBits(M.Bits, "<Set>");
		}
	}
}

bool PickPlayerCard() {
	if (!DeckCardCount) {
		return false;
	}
	auto NewCard = Deck[Length(Deck) - DeckCardCount--];
	PlayerCards[PlayerBaseCardCount] = NewCard;
	std::sort(PlayerCards, PlayerCards + Length(PlayerCards));

	auto CardPtr = &BaseCards[NewCard];
	PlayerHandCard.AddCards(CardPtr->GetBit());
	return true;
}

bool PlayerDiscard() {
	int InputIndex = 0;
	cin >> InputIndex;
	cout << "UserInputIndex: " << InputIndex << endl;
	if (InputIndex < 0 || InputIndex > PlayerBaseCardCount) {
		cout << "Invalid input, enter index above" << endl;
		return false;
	}

	auto CardIndex = PlayerCards[InputIndex];
	auto CardPtr = &BaseCards[CardIndex];
	PlayerHandCard.RemoveCards(CardPtr->GetBit());

	memmove(PlayerCards + InputIndex, PlayerCards + InputIndex + 1, PlayerBaseCardCount - InputIndex);
	return true;
}

void GamePlayerRound() {
	// Pick a card:
	if (!PickPlayerCard()) {
		State = GS_CheckRound;
		return;
	}

	PrintPlayerCard();
	while (!PlayerDiscard()) {
		Pass();
	}

	State = GS_CheckRound;
	return;
}

void GameCheckRound() {
	if (0 == DeckCardCount) {
		cout << "No winner" << endl;
		State = GS_FinishRound;
		return;
	}

	for (auto PS : SequencesMelds) {
		if ((PS.Bits & PlayerHandCard.Cards0) != PS.Bits) {
			continue;
		}
		auto Copy = PlayerHandCard;
		Copy.RemoveCards(PS.Bits);

		if (IsWinnerHand_10(Copy)) {
			cout << "Winner" << endl;
			State = GS_FinishRound;
			return;
		}
	}

	State = GS_PlayerRound;
	return;
}

void GameFinish() {
	cout << "Game finish" << endl;
	State = GS_End;
	return;
}

void GameEnd() {
	State = GS_Init;
	return;
}

int main(int argc, char * argv[]) {

	// foo();

	while (true) {
		switch (State) {
			case GS_Init:
				GameInit();
				break;

			case GS_Shuffle:
				GameShuffle();
				break;

			case GS_Discard:
				GameDiscard();
				break;

			case GS_PlayerRound:
				GamePlayerRound();
				break;

			case GS_CheckRound:
				GameCheckRound();
				break;

			case GS_FinishRound:
				GameFinish();
				break;

			case GS_End:
				GameEnd();
				break;

			default:
				Pass();
				break;
		}
	}

	return 0;
}