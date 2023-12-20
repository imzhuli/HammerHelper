#include "./Rummy.hpp"

#include <algorithm>
#include <cstring>
#include <ios>
#include <sstream>
#include <stack>

using namespace std;

namespace xel_poker {

	namespace rummy {

		void foo() {}

		size_t PureSequenceLengths[132] = {
			3, 4, 5, 3, 4, 5, 3, 4, 5, 3, 4, 5, 3, 4, 5, 3, 4, 5, 3, 4, 5, 3, 4, 5, 3, 4, 5, 3, 4, 5, 3, 4, 3, 3, 4, 5, 3, 4, 5, 3, 4, 5, 3, 4,
			5, 3, 4, 5, 3, 4, 5, 3, 4, 5, 3, 4, 5, 3, 4, 5, 3, 4, 5, 3, 4, 3, 3, 4, 5, 3, 4, 5, 3, 4, 5, 3, 4, 5, 3, 4, 5, 3, 4, 5, 3, 4, 5, 3,
			4, 5, 3, 4, 5, 3, 4, 5, 3, 4, 3, 3, 4, 5, 3, 4, 5, 3, 4, 5, 3, 4, 5, 3, 4, 5, 3, 4, 5, 3, 4, 5, 3, 4, 5, 3, 4, 5, 3, 4, 5, 3, 4, 3,
		};

		[[maybe_unused]] static void PrintCardBits(uint64_t Bits, const char * Prefix = "") {
			auto Cards = GetCardsFromBitsSorted(Bits);
			cout << Prefix << " ";
			for (auto & C : Cards) {
				cout << C.ToMark() << " ";
			}
			cout << endl;
		}

		[[maybe_unused]] static std::string MeldString(uint64_t Bits) {
			auto SS = std::stringstream();
			SS << "[ ";
			auto Cards = GetCardsFromBitsSorted(Bits);
			for (auto & C : Cards) {
				SS << C.ToMark() << " ";
			}
			SS << ']';
			return SS.str();
		}

		void InitPureSequenceLengths() {
			// for (size_t i = 0; i < Length(PureSequenceBits); ++i) {
			// 	auto B = PureSequenceBits[i];
			// 	auto Cards = GetCardsFromBitsSorted(B);
			// 	cout << Cards.size() << "," << endl;

			// 	PureSequenceLengths[i] = Cards.size();
			// }
		}

		// uint64_t MeldBitsSorted[Length(PureSequenceBits) + Length(Sets)] = {};
		void InitMeldBitsSorted() {
			// memcpy(MeldBitsSorted, PureSequenceBits, sizeof(PureSequenceBits));
			// memcpy(MeldBitsSorted + Length(PureSequenceBits), Sets, sizeof(Sets));
			// std::sort(MeldBitsSorted, MeldBitsSorted + Length(MeldBitsSorted));

			// for (auto B : MeldBitsSorted) {
			// 	cout << "{ 0x" << std::hex << B << std::dec;
			// 	auto Cards = GetCardsFromBitsSorted(B);
			// 	cout << ", " << Cards.size() << " }," << endl;
			// 	// PrintCardBits(B);
			// }
			// // cout << "Length(MeldBitsSorted) = " << Length(MeldBitsSorted) << endl;
		}

		void MakeWinnerMelds() {
			constexpr const size_t MaxLength = 13;
			std::vector<xHandCard> WinnerCards;

			size_t TotalFound = 0;
			for (size_t i = 0; i < Length(PureSequenceBits); ++i) {
				uint64_t  Meld[4] = {};
				xHandCard HandCards[4] = {};
				size_t	  TotalLength[4] = {};

				auto Bits = PureSequenceBits[i];
				Meld[0] = Bits;
				HandCards[0].AddCards(Bits);
				TotalLength[0] = PureSequenceLengths[i];

				struct xState {
					size_t Next;
				};
				auto LoopStack = std::stack<xState>();

				size_t Level = 1;
				size_t Start = 0;
				do {
					for (size_t j = Start; j < Length(ValidMeldsSorted); ++j) {
						// references
						auto & LastHandCards = HandCards[Level - 1];
						auto & LastTotalLength = TotalLength[Level - 1];
						auto & CurrHandCards = HandCards[Level];
						auto & CurrentTotalLength = TotalLength[Level];
						auto & CurrentMeld = Meld[Level];
						// make a copy
						CurrHandCards = LastHandCards;
						CurrentTotalLength = LastTotalLength;

						CurrentMeld = ValidMeldsSorted[j].Bits;
						auto NewLength = ValidMeldsSorted[j].Length;
						CurrentTotalLength += NewLength;
						if (CurrentTotalLength > MaxLength || !CurrHandCards.AddCards(CurrentMeld)) {
							continue;
						}
						if (CurrentTotalLength == MaxLength) {
							// found:
							++TotalFound;
							if (TotalFound < 100) {
								for (size_t t = 0; t <= Level; ++t) {
									cout << MeldString(Meld[t]) << " ";
								}
								cout << endl;
							}

							WinnerCards.push_back(CurrHandCards);
							continue;
						} else {
							if (Level == 3) {  // no more melds
								continue;
							}
							auto NextStartState = xState{
								.Next = j + 1,
							};
							++Level;
							LoopStack.push(NextStartState);
							goto NextLoop;
						}
					}

					if (LoopStack.empty()) {
						break;
					} else {
						auto LastState = LoopStack.top();
						LoopStack.pop();
						Start = LastState.Next;
						--Level;
					}
				NextLoop:
					xel::Pass();
				} while (true);
			}
			cout << "TotalFound = " << TotalFound << endl;
		}

		static auto _init = xInstantRun([] {
			InitPureSequenceLengths();
			InitMeldBitsSorted();
			MakeWinnerMelds();

			// uint8_t Colors[] = { SPADE, HEART, CLUB, DIAMOND };
			// char	Faces[] = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K', 'A' };

			// // Generate PureSequences
			// size_t PureSequenceCount = 0;
			// for (auto C : Colors) {
			// 	for (int Start = 0; Start < Length(Faces) - 2; ++Start) {
			// 		for (int L = 3; L <= std::min(Length(Faces) - Start, size_t(5)); ++L) {
			// 			auto Bits = uint64_t(0);
			// 			for (int I = 0; I < L; I++) {
			// 				auto F = Faces[Start + I];

			// 				auto Card = BaseCards[xCard::GetIndex(F, C)];
			// 				Bits |= Card.GetBit();
			// 				// cout << F << CardColorMark[C] << " ";
			// 			}
			// 			cout << "0x" << hex << Bits << dec << ", " << endl;
			// 			assert(PureSequenceBits[PureSequenceCount] == Bits);
			// 			++PureSequenceCount;
			// 		}
			// 	}
			// }
			// cout << "PureSequenceCount: " << PureSequenceCount << endl;

			// Generate Sets
			// uint8_t ReversedColors[] = { DIAMOND, CLUB, HEART, SPADE };
			// size_t SetCount = 0;
			// for (auto Curr = 0; Curr < Length(Faces) - 1; ++Curr) {
			// 	// 3 cards:
			// 	auto F = Faces[Curr];

			// 	for (auto i : ReversedColors) {
			// 		auto Bits = uint64_t(0);
			// 		for (auto j : Colors) {
			// 			if (i == j) {
			// 				continue;
			// 			}
			// 			auto Card = BaseCards[xCard::GetIndex(F, j)];
			// 			Bits |= Card.GetBit();
			// 			// cout << F << CardColorMark[j];
			// 		}
			// 		cout << " 0x" << hex << Bits << dec << ", " << endl;
			// 		++SetCount;
			// 	}

			// 	do {
			// 		auto Bits = uint64_t(0);
			// 		for (auto i : Colors) {
			// 			auto Card = BaseCards[xCard::GetIndex(F, i)];
			// 			Bits |= Card.GetBit();
			// 			// cout << F << CardColorMark[i];
			// 		}
			// 		cout << " 0x" << hex << Bits << dec << ", " << endl;
			// 		++SetCount;
			// 	} while (false);
			// }
			// cout << "SetCount: " << SetCount << endl;
		});

	}  // namespace rummy

}  // namespace xel_poker