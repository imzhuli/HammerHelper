#include "./Rummy.hpp"

#include <algorithm>
#include <array>
#include <cstring>
#include <ios>
#include <sstream>
#include <stack>

using namespace std;

namespace xel_poker {

	namespace rummy {

		void foo() {}

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

		void MakeShortWinnerMelds() {
			std::vector<std::array<xMeld, 4>> WinnerMeldsByLength[10 + 1];
			size_t							  TotalFound = 0;

			xMeld	  Melds[4] = {};
			xHandCard HandCards[4] = {};
			size_t	  TotalLength[4] = {};

			struct xState {
				size_t Next;
			};
			auto LoopStack = std::stack<xState>();

			size_t Level = 1;
			size_t Start = 0;
			do {
				for (size_t j = Start; j < Length(ValidMelds); ++j) {
					// references
					auto & LastHandCards = HandCards[Level - 1];
					auto & LastTotalLength = TotalLength[Level - 1];
					auto & CurrHandCards = HandCards[Level];
					auto & CurrentTotalLength = TotalLength[Level];
					auto & CurrentMeld = Melds[Level];
					// make a copy
					CurrHandCards = LastHandCards;
					CurrentTotalLength = LastTotalLength;

					CurrentMeld = ValidMelds[j];
					CurrentTotalLength += CurrentMeld.Length;

					if (CurrentTotalLength >= Length(WinnerMeldsByLength)) {
						continue;
					}
					auto & WinnerMelds = WinnerMeldsByLength[CurrentTotalLength];
					if (!CurrHandCards.AddCards(CurrentMeld.Bits)) {
						continue;
					} else {
						// found:
						++TotalFound;

						auto WinMelds = std::array<xMeld, 4>{};
						for (int k = 1; k <= Level; ++k) {
							WinMelds[k] = Melds[k];
						}
						WinnerMelds.push_back(WinMelds);

						// if (TotalFound < 100 || TotalFound > 20700096) {
						// 	for (size_t t = 1; t <= Level; ++t) {
						// 		cout << MeldString(Meld[t]) << " ";
						// 	}
						// 	cout << endl;
						// }

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

			do {
				for (int i = 0; i < Length(WinnerMeldsByLength); ++i) {
					cout << "MeldsCount=" << i << ", total=" << WinnerMeldsByLength[i].size() << endl;
				}

			} while (false);

			cout << "TotalFound: " << TotalFound << endl;
		}

		static auto _init = xInstantRun([] {
			MakeShortWinnerMelds();
		});

	}  // namespace rummy

}  // namespace xel_poker