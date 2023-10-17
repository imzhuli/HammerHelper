#include "../base/Cards.hpp"

using namespace xel_poker;

int main(int, char *[]) {
    cout << "hello cards" << endl;
    cout << "total faces: " << Length(CardFace) << endl;

    for(auto C : BaseCards) {
        auto ReverseCheck = xCard::GetIndex(C.Face, C.Color);
        cerr << C.ToString() << " ReverseCheck: " << ReverseCheck << endl;
        if(ReverseCheck != C.Index) {
            Fatal();
        }
    }

    return 0;
}