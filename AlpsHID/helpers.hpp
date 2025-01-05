#ifndef helpers_hpp
#define helpers_hpp

#include <IOKit/IOService.h>
#include <IOKit/IOLib.h>

#ifndef EXPORT
#define EXPORT __attribute__((visibility("default")))
#endif

// Power management constants
#define kIOPMPowerOff                       0
#define kVoodooI2CIOPMNumberPowerStates     2

// Bitwise manipulation macro
#define BIT(nr) (1UL << (nr))

// Function declarations
UInt16 abs(SInt16 x);
const char* getMatchedName(IOService* provider);

// Safe function to set a dictionary value as an OSNumber
inline void setOSDictionaryNumber(OSDictionary* dictionary, const char * key, UInt32 number) {
    // Create a new OSNumber object with the specified number
    if (OSNumber* os_number = OSNumber::withNumber(number, 32)) {
        // Add the OSNumber to the dictionary with the specified key
        dictionary->setObject(key, os_number);
        // Safely release the object after use
        os_number->safeRelease();
    }
}

// Enum to represent the I2C state (on/off)
enum VoodooI2CState {
    kVoodooI2CStateOff = 0,  // I2C is off
    kVoodooI2CStateOn  = 1   // I2C is on
};

// Power state structure for IOPowerManagement
static IOPMPowerState VoodooI2CIOPMPowerStates[kVoodooI2CIOPMNumberPowerStates] = {
    {1, kIOPMPowerOff, kIOPMPowerOff, kIOPMPowerOff, 0, 0, 0, 0, 0, 0, 0, 0},  // Power off state
    {1, kIOPMPowerOn,  kIOPMPowerOn,  kIOPMPowerOn,  0, 0, 0, 0, 0, 0, 0, 0}   // Power on state
};

#endif /* helpers_hpp */
