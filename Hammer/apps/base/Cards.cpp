#include "./Cards.hpp"

#include <sstream>

namespace xel_poker {

    string xCard::ToMark() const {
        std::stringstream ss;
        ss << Face << CardColorMark[Color];
        return ss.str();
    }

    string xCard::ToString() const {
        std::stringstream ss;
        ss << "{" << (int)Index << ", '" << Face << "', " << CardColorName[Color] << "}";
        return ss.str();
    }

}  // namespace xel_poker