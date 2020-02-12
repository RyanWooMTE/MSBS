#include "LGMode_lct.h"

real_T LGMode_lct(uint8_T LGLeftLock, uint8_T LGRightLock)
{
    LandingGearMode_U.misc.LGLeftLock = LGLeftLock;
    LandingGearMode_U.misc.LGRightLock = LGRightLock;
    LandingGearMode_step();
    return LandingGearMode_Y.LGMode;
}