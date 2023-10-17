#include "./Cards.hpp"
#include <sstream>

namespace xel_poker {

    string xCard::ToString() const {
        std::stringstream ss;
        ss << "[" << (int)Index << ", " << CardFace[Face] << ", "  << CardColor[Color] << "]";
        return ss.str();
    }

}