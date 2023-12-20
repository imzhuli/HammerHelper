#include "./Rummy.hpp"

#include <ios>

using namespace std;

namespace xel_poker {

	namespace rummy {

		void foo() {}

		static auto _init = xInstantRun([] {
			// uint8_t Colors[] = { SPADE, HEART, CLUB, DIAMOND };
			// char	Faces[] = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K', 'A' };

			/* Generate PureSequences */
			// size_t PureSequenceCount = 0;
			// for (auto C : Colors) {
			// 	for (int Start = 0; Start < Length(Faces) - 2; ++Start) {
			// 		for (int L = 3; L <= std::min(Length(Faces) - Start, size_t(5)); ++L) {
			// 			auto Bits = uint64_t(0);
			// 			for (int I = 0; I < L; I++) {
			// 				auto F = Faces[Start + I];

			// 				auto Card = BaseCards[xCard::GetIndex(F, C)];
			// 				Bits |= Card.ToBitmask();
			// 				cout << F << CardColorMark[C] << " ";
			// 			}
			// 			cout << "0x" << hex << Bits << dec << ", " << endl;
			// 			assert(PureSequenceBits[PureSequenceCount] == Bits);
			// 			++PureSequenceCount;
			// 		}
			// 	}
			// }
			// cout << "PureSequenceCount: " << PureSequenceCount << endl;

			/* Generate Sets */
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
			// 			Bits |= Card.ToBitmask();
			// 			// cout << F << CardColorMark[j];
			// 		}
			// 		cout << " 0x" << hex << Bits << dec << ", " << endl;
			// 		++SetCount;
			// 	}

			// 	do {
			// 		auto Bits = uint64_t(0);
			// 		for (auto i : Colors) {
			// 			auto Card = BaseCards[xCard::GetIndex(F, i)];
			// 			Bits |= Card.ToBitmask();
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