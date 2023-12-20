#include "./Rummy.hpp"

#include <ios>

using namespace std;

namespace xel_poker {

	namespace rummy {

		void foo() {}

		static auto _init = xInstantRun([] {
			uint8_t Colors[] = { SPADE, HEART, CLUB, DIAMOND };
			char	Faces[] = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K', 'A' };

			size_t PureSequenceCount = 0;
			for (auto C : Colors) {
				for (int Start = 0; Start < Length(Faces) - 2; ++Start) {
					for (int L = 3; L <= std::min(Length(Faces) - Start, size_t(5)); ++L) {
						for (int I = 0; I < L; I++) {
							auto F = Faces[Start + I];

							auto Card = BaseCards[xCard::GetIndex(F, C)];
							auto Bits = Card.ToBitmask();
							cout << F << CardColorMark[C] << " " << hex << Bits << dec << " ";
						}
						cout << endl;
						++PureSequenceCount;
					}
				}
			}

			size_t SetCount = 0;
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
					++SetCount;
				}
				for (int i = 0; i < 4; ++i) {
					cout << F << CardColorMark[i];
				}
				++SetCount;
				cout << endl;
			}

			cout << "PureSequenceCount: " << PureSequenceCount << endl;
			cout << "SetCount: " << SetCount << endl;
		});

	}  // namespace rummy

}  // namespace xel_poker