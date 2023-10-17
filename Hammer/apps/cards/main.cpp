#include "../base/Cards.hpp"

using namespace xel_poker;

int main(int, char *[]) {
    cout << "hello cards" << endl;
    cout << "total faces: " << Length(CardFace) << endl;

    size_t Total = 0;
    for (size_t i = 0 ; i < Length(CardColor); ++i) {
        for (size_t j = 0 ; j < Length(CardFace); ++j) {
            auto C = xCard {
                uint8_t(Total++), uint8_t(j), uint8_t(i),
            };
            cout << C.ToString() << endl;
        }
    }

    return 0;
}