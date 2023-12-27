#include "../base/Cards.hpp"

using namespace xel_poker;

int main(int, char *[]) {
	//
	for (auto & B : BaseCards) {
		auto Mark = B.ToMark();
		auto Index = size_t(B.Index);

		cout << Mark << " --> " << Index << endl;
	}

	return 0;
}