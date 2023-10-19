#include "../base/ThreeCardPoker.hpp"

using namespace xel_poker;
namespace tcp = xel_poker::three_card_poker;

int main(int, char *[]) {
    auto CardNumber = Length(BaseCards);

    std::vector<tcp::xHandCard> HandCardEnumeration;

    for (size_t i = 0; i < CardNumber; ++i) {
        for (size_t j = i + 1; j < CardNumber; ++j) {
            for (size_t k = j + 1; k < CardNumber; ++k) {
                auto C = tcp::xHandCard{
                    &BaseCards[i],
                    &BaseCards[j],
                    &BaseCards[k],
                };
                HandCardEnumeration.push_back(C);
            }
        }
    }

    cout << "==============================> " << HandCardEnumeration.size() << endl;

    std::sort(HandCardEnumeration.begin(), HandCardEnumeration.end());
    for (auto & C : HandCardEnumeration) {
        cout << C.ToString() << ',' << endl;
    }

    return 0;
}