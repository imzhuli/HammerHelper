#pragma once
#include "./_.hpp"

namespace xel_poker {

    static constexpr const char CardFace[] = {'A', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K'};

    static constexpr const char* CardColor[] = {
        "DIAMOND",
        "CLUB",
        "HEART",
        "SPADE",
    };

    struct xCard {
        uint8_t Index;
        uint8_t Face;
        uint8_t Color;

        string ToString() const;
    };

}  // namespace xel_poker