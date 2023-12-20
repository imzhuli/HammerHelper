#include "../base/Cards.hpp"

using namespace xel_poker;

size_t FindIndex(uint8_t F, uint8_t C) {
	size_t I = 0;
	for (auto & BC : BaseCards) {
		if (BC.Face == F && BC.Color == C) {
			return I;
		}
		++I;
	}
	return -1;
}

int main(int, char *[]) {
	cout << "hello cards" << endl;
	cout << "total faces: " << Length(CardFace) << endl;

	uint8_t Colors[] = { DIAMOND, CLUB, HEART, SPADE };
	for (auto C : Colors) {
		auto Values = std::vector<std::string>();
		for (int i = 0; i < 256; ++i) {
			Values.push_back("size_t(-1),");
		}
		for (auto F : CardFace) {
			auto I = FindIndex(F, C);
			auto BC = BaseCards[I];

			assert(BC.Index == I);
			cout << I << ": " << BC.ToString() << endl;

			char Buffer[1024];
			snprintf(Buffer, SafeLength(Buffer), "size_t(%zi),", (size_t)BC.Index);
			Values[BC.Face] = Buffer;
		}

		auto Counter = 0;
		for (auto & V : Values) {
			cout << V << " ";
			if (++Counter % 8 == 0) {
				cout << endl;
			}
		}
		cout << endl;
	}

	for (auto C : BaseCards) {
		auto ReverseCheck = xCard::GetIndex(C.Face, C.Color);
		cerr << C.ToString() << " ReverseCheck: " << ReverseCheck << endl;
		if (ReverseCheck != C.Index) {
			Fatal();
		}
		if (C.Color == JOKER_BLACK) {
			if (C.Index != C.Value && C.Index != 52) {
				Fatal();
			}
		} else if (C.Color == JOKER_RED) {
			if (C.Index != C.Value && C.Index != 53) {
				Fatal();
			}
		} else if (C.Value % 13 != (C.Index + 2) % 13) {
			Fatal();
		}
	}

	return 0;
}