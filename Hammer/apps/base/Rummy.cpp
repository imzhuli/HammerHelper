#include "./Rummy.hpp"

#include "./Rummy_WinnerHandCards.cpp.pred"

#include <algorithm>
#include <array>
#include <cstring>
#include <ios>
#include <set>
#include <sstream>
#include <stack>

using namespace std;

namespace xel_poker {

	namespace rummy {

		X_EXTERN const xHandCard WinnerHandCards_10[459964];

		bool IsWinnerHand_10(const xHandCard & HC) {
			//
			return std::binary_search(WinnerHandCards_10, WinnerHandCards_10 + Length(WinnerHandCards_10), HC);
		}

		static std::set<xHandCard> WinnerHandCards;

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
						WinnerHandCards.insert(CurrHandCards);

						// found:
						++TotalFound;

						auto WinMelds = std::array<xMeld, 4>{};
						for (int k = 1; k <= Level; ++k) {
							WinMelds[k] = Melds[k];
						}
						WinnerMelds.push_back(WinMelds);

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
			cout << "WinnerHandCards size: " << WinnerHandCards.size() << endl;

			// cout << hex;
			// for (auto HC : WinnerHandCards) {
			// 	cout << "{ 0x" << HC.Cards0 << ", 0x" << HC.Cards1 << " }, ";
			// }
			// cout << dec;
			// cout << endl;
		}

		static auto _init = xInstantRun([] {
			assert(xHandCard() != WinnerHandCards_10[SafeLength(WinnerHandCards_10)]);
			// MakeShortWinnerMelds();
		});

	}  // namespace rummy

}  // namespace xel_poker