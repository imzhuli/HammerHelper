#include "./ThreeCardPoker.hpp"

#include <cassert>
#include <sstream>

#define LESS std::strong_ordering::less
#define EQUAL std::strong_ordering::equal
#define GREATER std::strong_ordering::greater

namespace xel_poker {

    namespace three_card_poker {

        string xHandCard::ToString() const {
            std::stringstream ss;
            auto&             C0 = Cards[0];
            auto&             C1 = Cards[1];
            auto&             C2 = Cards[2];

            ss << "{";
            ss << "C0:XCard{Face:'" << char(C0->Face) << "', Color:" << CardColorName[C0->Color] << "},";
            ss << "C1:XCard{Face:'" << char(C1->Face) << "', Color:" << CardColorName[C1->Color] << "},";
            ss << "C2:XCard{Face:'" << char(C2->Face) << "', Color:" << CardColorName[C2->Color] << "},";
            ss << "Pattern: " << ePatternString[size_t(Pattern)] << ",";
            ss << "BitMask:0x" << std::hex << BitMask << std::dec;
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

        void xHandCard::_SetupBitMask() {
            auto C0 = Cards[0];
            auto C1 = Cards[1];
            auto C2 = Cards[2];
            auto Index0 = xCard::GetIndex(C0->Face, C0->Color);
            auto Index1 = xCard::GetIndex(C1->Face, C1->Color);
            auto Index2 = xCard::GetIndex(C2->Face, C2->Color);
            BitMask = (uint64_t(1) << Index0) | (uint64_t(1) << Index1) | (uint64_t(1) << Index2);
        }

        std::strong_ordering xHandCard::operator<=>(const xHandCard& Other) const {
            assert(Pattern != ePattern::UNDEFINED);
            assert(Other.Pattern != ePattern::UNDEFINED);

            if (Pattern < Other.Pattern) {
                return LESS;
            }
            if (Other.Pattern < Pattern) {
                return GREATER;
            }

            auto C2 = Cards[2];
            auto C1 = Cards[1];
            auto C0 = Cards[0];

            auto OC2 = Other.Cards[2];
            auto OC1 = Other.Cards[1];
            auto OC0 = Other.Cards[0];

            if (Pattern == ePattern::FLUSH_SEQ || Pattern == ePattern::SEQ) {
                if (C2->Value < OC2->Value) {
                    return LESS;
                }
                if (C2->Value > OC2->Value) {
                    return GREATER;
                }
                if (C1->Value < OC1->Value) {
                    return LESS;
                }
                if (C1->Value > OC1->Value) {
                    return GREATER;
                }
                // passthrough
            }

            if (Pattern == ePattern::PAIR) {
                if (C0->Value == C1->Value) {
                    C2 = Cards[1];
                    C1 = Cards[0];
                    C0 = Cards[2];
                }
                if (OC0->Value == OC1->Value) {
                    OC2 = Other.Cards[1];
                    OC1 = Other.Cards[0];
                    OC0 = Other.Cards[2];
                }

                if (C2->Value < OC2->Value) {
                    return LESS;
                }
                if (C2->Value > OC2->Value) {
                    return GREATER;
                }

                if (C0->Value < OC0->Value) {
                    return LESS;
                }
                if (C0->Value > OC0->Value) {
                    return GREATER;
                }

                assert(C0->Value == OC0->Value);
                assert(C1->Value == OC1->Value);
                assert(C2->Value == OC2->Value);

                if (C2->Value < C0->Value) {
                    auto Temp = C0;
                    C0 = C1;
                    C1 = C2;
                    C2 = Temp;

                    auto OTemp = OC0;
                    OC0 = OC1;
                    OC1 = OC2;
                    OC2 = OTemp;
                }
            }

            auto Order = *C2 <=> *OC2;
            if (Order != EQUAL) {
                return Order;
            }
            Order = *C1 <=> *OC1;
            if (Order != EQUAL) {
                return Order;
            }
            return *C0 <=> *OC0;
        }

    }  // namespace three_card_poker

}  // namespace xel_poker
