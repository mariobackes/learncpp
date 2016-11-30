#pragma once
#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace myConstants
{
    const double k_gravity_earth    = 9.807;
    const double k_gravity_mars     = 3.711;
    const double k_gravity_moon     = 1.622;
    const double k_gravity_jupiter  = 24.79;
    const double k_gravity_pluto    = 0.62;
}

#endif // !CONSTANTS_H

#ifndef PLANET_IDS
#define PLANET_IDS

namespace planet_id
{
    const int k_earth_id    = 56100;  // 0x800FFFD 
    const int k_jupiter_id  = 56101;
    const int k_mars_id     = 56102;
    const int k_moon_id     = 56103;
    const int k_pluto_id    = 56104;
}

#endif // !PLANET_IDS

#ifndef GENERAL_IDS
#define GENERAL_IDS

namespace error_ids
{
    const int general_error         = 62000;
    const int value_out_of_reach    = 62001;
    const int no_identifier         = 62002;
}

#endif // !GENERAL_IDS