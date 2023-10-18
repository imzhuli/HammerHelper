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
                ePattern     Pattern;

            public:
                // X_INLINE xHandCard() : Cards{nullptr, nullptr, nullptr}, Pattern(ePattern::UNDEFINED) {}
                X_INLINE xHandCard() = delete;
                X_INLINE xHandCard(const xCard* C0, const xCard* C1, const xCard* C2) : Cards{C0, C1, C2}, Pattern(ePattern::UNDEFINED) { _FindPattern(); }

                X_INLINE xHandCard(const xHandCard& Other) = default;
                X_INLINE xHandCard& operator=(const xHandCard& Other) = default;

                string               ToString() const;
                ePattern             GetPattern() const { return Pattern; }
                std::strong_ordering operator<=>(const xHandCard& Other) const;

            private:
                void _Normalize();
                void _FindPattern();
        };

    }  // namespace three_card_poker

}  // namespace xel_poker
