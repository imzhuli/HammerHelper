#include "./ThreeCardPoker.hpp"

#include <sstream>

namespace xel_poker {

    namespace three_card_poker {

        string xHandCard::ToString() const {
            std::stringstream ss;
            auto&             C0 = Cards[0];
            auto&             C1 = Cards[1];
            auto&             C2 = Cards[2];

            ss << "{";
            ss << char(C0->Face) << ":" << CardColorName[C0->Color];
            ss << ',';
            ss << char(C1->Face) << ":" << CardColorName[C1->Color];
            ss << ',';
            ss << char(C2->Face) << ":" << CardColorName[C2->Color];
            ss << " -> " << ePatternString[size_t(Pattern)];
            ss << "}";
            return ss.str();
        }

        void xHandCard::_Normalize() {
            auto& C0 = Cards[0];
            auto& C1 = Cards[1];
            auto& C2 = Cards[2];
            if (*C0 > *C1) {
                std::swap(C0, C1);
            }
            if (*C0 > *C2) {
                std::swap(C0, C2);
            }
            if (*C1 > *C2) {
                std::swap(C1, C2);
            }
        }

        void xHandCard::_FindPattern() {
            _Normalize();

            auto& C0 = Cards[0];
            auto& C1 = Cards[1];
            auto& C2 = Cards[2];

            if (C0->Value == C1->Value || C1->Value == C2->Value) {
                if (C0->Value == C2->Value) {
                    Pattern = ePattern::TRIPLE;
                    return;
                }
                Pattern = ePattern::PAIR;
                return;
            }

            if (C0->Value + 1 == C1->Value && C1->Value + 1 == C2->Value) {
                if (C0->Color == C1->Color && C1->Color == C2->Color) {
                    Pattern = ePattern::FLUSH_SEQ;
                    return;
                }
                Pattern = ePattern::SEQ;
                return;
            }

            if (C0->Color == C1->Color && C1->Color == C2->Color) {
                if (C0->Face == '2' && C1->Face == '3' && C2->Face == 'A') {
                    Pattern = ePattern::FLUSH_SEQ;
                    return;
                }
                Pattern = ePattern::FLUSH;
                return;
            }

            if (C0->Face == '2' && C1->Face == '3' && C2->Face == 'A') {
                Pattern = ePattern::SEQ;
                return;
            }
            Pattern = ePattern::OFFSUIT;
            return;
        }

        std::strong_ordering xHandCard::operator<=>(const xHandCard& Other) const {
            assert(Pattern != ePattern::UNDEFINED);
            assert(Other.Pattern != ePattern::UNDEFINED);

            if (Pattern < Other.Pattern) {
                return std::strong_ordering::less;
            }
            if (Other.Pattern < Pattern) {
                return std::strong_ordering::greater;
            }

            // special: 23A & QKA:
            if (Pattern == ePattern::SEQ || Pattern == ePattern::FLUSH_SEQ) {
                if (Cards[2]->Face != 'A') {
                    return *Cards[2] <=> *Other.Cards[2];
                }
                return *Cards[1] <=> *Other.Cards[1];
            }

            if (Pattern == ePattern::PAIR) {
                auto C = Cards[1];
                if (Cards[1] == Cards[2]) {
                    C = Cards[2];
                }
                auto OC = Other.Cards[1];
                if (Other.Cards[1] == Other.Cards[2]) {
                    OC = Other.Cards[2];
                }
                return *C <=> *OC;
            }
            return *Cards[2] <=> *Other.Cards[2];
        }

    }  // namespace three_card_poker

}  // namespace xel_poker
