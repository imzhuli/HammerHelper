#pragma once
#include "./_.hpp"

#include <compare>
#include <vector>

namespace xel_poker {

	static constexpr const uint8_t JOKER_RED = 5;
	static constexpr const uint8_t JOKER_BLACK = 4;
	static constexpr const uint8_t SPADE = 3;
	static constexpr const uint8_t HEART = 2;
	static constexpr const uint8_t CLUB = 1;
	static constexpr const uint8_t DIAMOND = 0;

	static constexpr const char CardFace[] = {
		'2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K', 'A',
	};

	static constexpr const char * CardColorName[] = {
		"DIAMOND", "CLUB", "HEART", "SPADE", "JOKER_BLACK", "JOKER_RED",
	};

	static constexpr const char * CardColorMark[] = {
		"♦️", "♣️", "♥️", "♠️", "👽", "🤡",
	};
	static constexpr const size_t TOTAL_CARDS = 54;

	static constexpr const size_t CardIndex[6][256] = {
		// CardIndex[Color][Index]
		{
			// DIAMOND
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), 8,			size_t(-1), 0,			1,
			2,			3,			4,			5,			6,			7,			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			12,			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), 9,			11,			size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), 10,			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
		},
		{
			// CLUB
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(21), size_t(-1), size_t(13), size_t(14),
			size_t(15), size_t(16), size_t(17), size_t(18), size_t(19), size_t(20), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(25), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(22), size_t(24), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(23), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
		},
		{
			// HEART
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(34), size_t(-1), size_t(26), size_t(27),
			size_t(28), size_t(29), size_t(30), size_t(31), size_t(32), size_t(33), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(38), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(35), size_t(37), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(36), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
		},
		{
			// SPADE
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(47), size_t(-1), size_t(39), size_t(40),
			size_t(41), size_t(42), size_t(43), size_t(44), size_t(45), size_t(46), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(51), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(48), size_t(50), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(49), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
		},
		{
			// BLACK_JOKER
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(52), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
		},
		{
			// RED_JOKER
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(53), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
			size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1), size_t(-1),
		}
	};

	struct xCard {
		uint8_t Index = -1;
		uint8_t Value = -1;
		uint8_t Face = -1;
		uint8_t Color = -1;

		std::strong_ordering operator<=>(const xCard & Other) const {
			if (this->Value < Other.Value) {
				return std::strong_ordering::less;
			}
			if (this->Value > Other.Value) {
				return std::strong_ordering::greater;
			}
			return this->Color <=> Other.Color;
		}

		string ToMark() const;
		string ToString() const;

		X_INLINE uint64_t GetBit() const { return uint64_t(1) << Index; }

		X_STATIC_INLINE size_t GetIndex(uint8_t Face, uint8_t Color) {
			assert(Color < Length(CardColorName));
			return CardIndex[Color][(size_t)Face];
		}
	};

	constexpr const xCard BaseCards[] = {
		{ 0, 2, '2', DIAMOND },		  { 1, 3, '3', DIAMOND },	   { 2, 4, '4', DIAMOND },		{ 3, 5, '5', DIAMOND },		{ 4, 6, '6', DIAMOND },
		{ 5, 7, '7', DIAMOND },		  { 6, 8, '8', DIAMOND },	   { 7, 9, '9', DIAMOND },		{ 8, 10, '0', DIAMOND },	{ 9, 11, 'J', DIAMOND },
		{ 10, 12, 'Q', DIAMOND },	  { 11, 13, 'K', DIAMOND },	   { 12, 14, 'A', DIAMOND },

		{ 13 + 0, 2, '2', CLUB },	  { 13 + 1, 3, '3', CLUB },	   { 13 + 2, 4, '4', CLUB },	{ 13 + 3, 5, '5', CLUB },	{ 13 + 4, 6, '6', CLUB },
		{ 13 + 5, 7, '7', CLUB },	  { 13 + 6, 8, '8', CLUB },	   { 13 + 7, 9, '9', CLUB },	{ 13 + 8, 10, '0', CLUB },	{ 13 + 9, 11, 'J', CLUB },
		{ 13 + 10, 12, 'Q', CLUB },	  { 13 + 11, 13, 'K', CLUB },  { 13 + 12, 14, 'A', CLUB },

		{ 26 + 0, 2, '2', HEART },	  { 26 + 1, 3, '3', HEART },   { 26 + 2, 4, '4', HEART },	{ 26 + 3, 5, '5', HEART },	{ 26 + 4, 6, '6', HEART },
		{ 26 + 5, 7, '7', HEART },	  { 26 + 6, 8, '8', HEART },   { 26 + 7, 9, '9', HEART },	{ 26 + 8, 10, '0', HEART }, { 26 + 9, 11, 'J', HEART },
		{ 26 + 10, 12, 'Q', HEART },  { 26 + 11, 13, 'K', HEART }, { 26 + 12, 14, 'A', HEART },

		{ 39 + 0, 2, '2', SPADE },	  { 39 + 1, 3, '3', SPADE },   { 39 + 2, 4, '4', SPADE },	{ 39 + 3, 5, '5', SPADE },	{ 39 + 4, 6, '6', SPADE },
		{ 39 + 5, 7, '7', SPADE },	  { 39 + 6, 8, '8', SPADE },   { 39 + 7, 9, '9', SPADE },	{ 39 + 8, 10, '0', SPADE }, { 39 + 9, 11, 'J', SPADE },
		{ 39 + 10, 12, 'Q', SPADE },  { 39 + 11, 13, 'K', SPADE }, { 39 + 12, 14, 'A', SPADE },

		{ 52, 52, 'B', JOKER_BLACK }, { 53, 53, 'R', JOKER_RED },
	};

	X_STATIC_INLINE std::vector<xCard> GetCardsFromBits(uint64_t Bits) {
		auto Result = std::vector<xCard>();
		for (size_t i = 0; i < TOTAL_CARDS; ++i) {
			uint64_t Mask = uint64_t(1) << i;
			if (Mask & Bits) {
				auto Card = BaseCards[i];
				Result.push_back(Card);
			}
		}
		return Result;
	}

	X_STATIC_INLINE std::vector<xCard> GetCardsFromBitsSorted(uint64_t Bits) {
		auto Result = std::vector<xCard>();
		for (size_t i = 0; i < TOTAL_CARDS; ++i) {
			uint64_t Mask = uint64_t(1) << i;
			if (Mask & Bits) {
				auto Card = BaseCards[i];
				Result.push_back(Card);
			}
		}
		sort(Result.begin(), Result.end());
		return Result;
	}
}  // namespace xel_poker
