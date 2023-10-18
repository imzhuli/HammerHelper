#pragma once
#include "./_.hpp"

namespace xel_poker {

    static constexpr const uint8_t SPADE = 3;
    static constexpr const uint8_t HEART = 2;
    static constexpr const uint8_t CLUB = 1;
    static constexpr const uint8_t DIAMOND = 0;
    static constexpr const char    CardFace[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K'};
    static constexpr const char*   CardColor[] = {
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
        uint8_t Index;
        uint8_t Face;
        uint8_t Color;

        string ToString() const;

        X_STATIC_INLINE size_t GetIndex(uint8_t Face, uint8_t Color) {
            assert(Color < Length(CardColor));
            return CardIndex[Color][(size_t)Face];
        }
    };

    static constexpr const xCard BaseCards[] = {
        {0, 'A', DIAMOND}, {1, '2', DIAMOND},  {2, '3', DIAMOND},  {3, '4', DIAMOND},  {4, '5', DIAMOND}, {5, '6', DIAMOND}, {6, '7', DIAMOND}, {7, '8', DIAMOND}, {8, '9', DIAMOND},
        {9, '0', DIAMOND}, {10, 'J', DIAMOND}, {11, 'Q', DIAMOND}, {12, 'K', DIAMOND}, {13, 'A', CLUB},   {14, '2', CLUB},   {15, '3', CLUB},   {16, '4', CLUB},   {17, '5', CLUB},
        {18, '6', CLUB},   {19, '7', CLUB},    {20, '8', CLUB},    {21, '9', CLUB},    {22, '0', CLUB},   {23, 'J', CLUB},   {24, 'Q', CLUB},   {25, 'K', CLUB},   {26, 'A', HEART},
        {27, '2', HEART},  {28, '3', HEART},   {29, '4', HEART},   {30, '5', HEART},   {31, '6', HEART},  {32, '7', HEART},  {33, '8', HEART},  {34, '9', HEART},  {35, '0', HEART},
        {36, 'J', HEART},  {37, 'Q', HEART},   {38, 'K', HEART},   {39, 'A', SPADE},   {40, '2', SPADE},  {41, '3', SPADE},  {42, '4', SPADE},  {43, '5', SPADE},  {44, '6', SPADE},
        {45, '7', SPADE},  {46, '8', SPADE},   {47, '9', SPADE},   {48, '0', SPADE},   {49, 'J', SPADE},  {50, 'Q', SPADE},  {51, 'K', SPADE},
    };

}  // namespace xel_poker