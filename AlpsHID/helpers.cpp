#include "helpers.hpp"
#include <algorithm>  // for std::max

const char* getMatchedName(IOService* provider) {
    OSString* nameString = OSDynamicCast(OSString, provider->getProperty("name"));
    if (nameString) {
        return nameString->getCStringNoCopy(); // Safer method for getting the string
    }
    return "(null)";
}

UInt16 abs(SInt16 x) {
    // Handle edge case for smallest negative value that cannot be represented in UInt16
    if (x == std::numeric_limits<SInt16>::min()) {
        return std::numeric_limits<UInt16>::max();  // Absolute value of smallest SInt16 is out of range for UInt16
    }
    return std::max(x, static_cast<SInt16>(0)) * (x < 0 ? -1 : 1);
}
