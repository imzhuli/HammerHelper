#include "./Cards.hpp"

#include <sstream>

namespace xel_poker {

    string xCard::ToString() const {
        std::stringstream ss;
        ss << "{" << (int)Index << ", '" << Face << "', " << CardColor[Color] << "}";
        return ss.str();
    }

}  // namespace xel_poker