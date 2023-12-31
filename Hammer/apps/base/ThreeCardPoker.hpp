#pragma once
#include <utility>

#include "./Cards.hpp"

namespace xel_poker {

    namespace three_card_poker {

        enum struct ePattern : uint8_t {
            OFFSUIT,
            PAIR,
            FLUSH,
            SEQ,
            FLUSH_SEQ,
            TRIPLE,

            UNDEFINED = uint8_t(-1),
        };

        static constexpr const char* ePatternString[] = {
            "OFFSUIT", "PAIR", "FLUSH", "SEQ", "FLUSH_SEQ", "TRIPLE",
        };

        class xHandCard {
            private:
                const xCard* Cards[3];
                uint64_t     BitMask;
                ePattern     Pattern;

            public:
                X_INLINE xHandCard() : Cards{}, BitMask{}, Pattern{ePattern::UNDEFINED} {};
                X_INLINE xHandCard(const xCard* C0, const xCard* C1, const xCard* C2) : Cards{C0, C1, C2}, Pattern(ePattern::UNDEFINED) {
                    _FindPattern();
                    _SetupBitMask();
                }

                X_INLINE            xHandCard(const xHandCard& Other) = default;
                X_INLINE xHandCard& operator=(const xHandCard& Other) = default;

                string               ToString() const;
                uint64_t             GetBitMask() const { return BitMask; }
                ePattern             GetPattern() const { return Pattern; }
                bool                 operator==(const xHandCard& Other) const { return BitMask == Other.BitMask; }
                std::strong_ordering operator<=>(const xHandCard& Other) const;

            private:
                void _Normalize();
                void _FindPattern();
                void _SetupBitMask();
        };

    }  // namespace three_card_poker

}  // namespace xel_poker
