#pragma once
#include <utility>

#include "./Cards.hpp"

namespace xel_poker {

    namespace three_card_poker {

        struct HandCard {
            const xCard* Cards[3];

            X_INLINE bool IsNormalized() const { return *Cards[0] < *Cards[1] && *Cards[1] < *Cards[2]; }

            X_INLINE void Normalize() {
                auto& C0 = Cards[0];
                auto& C1 = Cards[1];
                auto& C2 = Cards[2];
                if(*C0 < *C1) {
                    std::swap(C0, C1);
                }
                if(*C0 < *C2) {
                    std::swap(C0, C2);
                }
                if(*C1 < *C2) {
                    std::swap(C1, C2);
                }
            }
        };

    }  // namespace three_card_poker

}  // namespace xel_poker
