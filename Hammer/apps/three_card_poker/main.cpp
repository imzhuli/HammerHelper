#include <map>

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

    std::sort(HandCardEnumeration.begin(), HandCardEnumeration.end());
    for (auto & C : HandCardEnumeration) {
        cout << C.ToString() << ',' << endl;
    }

    [[maybe_unused]] auto Map = std::map<uint64_t, tcp::xHandCard>{};
    for (auto &C : HandCardEnumeration) {
        Map[C.GetBitMask()] = C;
    }

    // auto L = Map[0x10000000006];
    // auto R = Map[0x8000006];

    // auto Max = std::max(L, R);
    // auto Min = std::min(L, R);

    // cout << "Max: " << Max.ToString() << endl;
    // cout << "Min: " << Min.ToString() << endl;

    // [[maybe_unused]] auto S3 = BaseCards + CardIndex[SPADE][uint8_t('3')];
    // [[maybe_unused]] auto H3 = BaseCards + CardIndex[HEART][uint8_t('3')];
    // [[maybe_unused]] auto C3 = BaseCards + CardIndex[CLUB][uint8_t('3')];
    // [[maybe_unused]] auto D3 = BaseCards + CardIndex[DIAMOND][uint8_t('3')];

    // [[maybe_unused]] auto S2 = BaseCards + CardIndex[SPADE][uint8_t('2')];
    // [[maybe_unused]] auto H2 = BaseCards + CardIndex[HEART][uint8_t('2')];
    // [[maybe_unused]] auto C2 = BaseCards + CardIndex[CLUB][uint8_t('2')];
    // [[maybe_unused]] auto D2 = BaseCards + CardIndex[DIAMOND][uint8_t('2')];

    // auto HC1 = tcp::xHandCard(S2, H2, D3);
    // auto HC2 = tcp::xHandCard(C2, D2, C3);

    // auto Max12 = std::max(HC1, HC2);
    // auto Min12 = std::min(HC1, HC2);

    // cout << "Max12: " << Max12.ToString() << endl;
    // cout << "Min12: " << Min12.ToString() << endl;

    // auto HC3 = tcp::xHandCard(S3, H3, D2);
    // auto HC4 = tcp::xHandCard(C3, D3, C2);

    // auto Max34 = std::max(HC3, HC4);
    // auto Min34 = std::min(HC3, HC4);

    // cout << "Max34: " << Max34.ToString() << endl;
    // cout << "Min34: " << Min34.ToString() << endl;

    return 0;
}