#pragma once
#include <compare>

#include "./_.hpp"

namespace xel_poker {

    static constexpr const uint8_t SPADE = 3;
    static constexpr const uint8_t HEART = 2;
    static constexpr const uint8_t CLUB = 1;
    static constexpr const uint8_t DIAMOND = 0;
    static constexpr const char    CardFace[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K'};
    static constexpr const char*   CardColorName[] = {
        "DIAMOND",
        "CLUB",
        "HEART",
        "SPADE",
    };
    static constexpr const size_t CardIndex[4][256] = {
        {
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), 9,          size_t(-1), 1,          2,          3,          4,          5,          6,          7,          8,          size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), 0,          size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), 10,
            12,         size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), 11,         size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1),
        },
        {
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), 22,         size_t(-1), 14,         15,         16,         17,         18,         19,         20,         21,         size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), 13,         size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), 23,
            25,         size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), 24,         size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1),
        },
        {
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), 35,         size_t(-1), 27,         28,         29,         30,         31,         32,         33,         34,         size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), 26,         size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), 36,
            38,         size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), 37,         size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1),
        },
        {
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), 48,         size_t(-1), 40,         41,         42,         43,         44,         45,         46,         47,         size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), 39,         size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), 49,
            51,         size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), 50,         size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
            size_t(-1),
        },
    };

    struct xCard {
            uint8_t Index = -1;
            uint8_t Value = -1;
            uint8_t Face = -1;
            uint8_t Color = -1;

            std::strong_ordering operator<=>(const xCard& Other) const {
                if (this->Value < Other.Value) {
                    return std::strong_ordering::less;
                }
                if (this->Value > Other.Value) {
                    return std::strong_ordering::greater;
                }
                return this->Color <=> Other.Color;
            }
            string ToString() const;

            X_STATIC_INLINE size_t GetIndex(uint8_t Face, uint8_t Color) {
                assert(Color < Length(CardColorName));
                return CardIndex[Color][(size_t)Face];
            }
    };

    static constexpr const xCard BaseCards[] = {
        {0, 13, 'A', DIAMOND}, {1, 1, '2', DIAMOND}, {2, 2, '3', DIAMOND}, {3, 3, '4', DIAMOND},   {4, 4, '5', DIAMOND},   {5, 5, '6', DIAMOND},   {6, 6, '7', DIAMOND},
        {7, 7, '8', DIAMOND},  {8, 8, '9', DIAMOND}, {9, 9, '0', DIAMOND}, {10, 10, 'J', DIAMOND}, {11, 11, 'Q', DIAMOND}, {12, 12, 'K', DIAMOND},

        {13, 13, 'A', CLUB},   {14, 1, '2', CLUB},   {15, 2, '3', CLUB},   {16, 3, '4', CLUB},     {17, 4, '5', CLUB},     {18, 5, '6', CLUB},     {19, 6, '7', CLUB},
        {20, 7, '8', CLUB},    {21, 8, '9', CLUB},   {22, 9, '0', CLUB},   {23, 10, 'J', CLUB},    {24, 11, 'Q', CLUB},    {25, 12, 'K', CLUB},

        {26, 13, 'A', HEART},  {27, 1, '2', HEART},  {28, 2, '3', HEART},  {29, 3, '4', HEART},    {30, 4, '5', HEART},    {31, 5, '6', HEART},    {32, 6, '7', HEART},
        {33, 7, '8', HEART},   {34, 8, '9', HEART},  {35, 9, '0', HEART},  {36, 10, 'J', HEART},   {37, 11, 'Q', HEART},   {38, 12, 'K', HEART},

        {39, 13, 'A', SPADE},  {40, 1, '2', SPADE},  {41, 2, '3', SPADE},  {42, 3, '4', SPADE},    {43, 4, '5', SPADE},    {44, 5, '6', SPADE},    {45, 6, '7', SPADE},
        {46, 7, '8', SPADE},   {47, 8, '9', SPADE},  {48, 9, '0', SPADE},  {49, 10, 'J', SPADE},   {50, 11, 'Q', SPADE},   {51, 12, 'K', SPADE},
    };

}  // namespace xel_poker