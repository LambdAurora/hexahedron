#ifndef HEXAHEDRON_LIBRARY_H
#define HEXAHEDRON_LIBRARY_H

#include "hexahedron_version.h"
#include <string>

namespace hexahedron
{
    /*
    * Integers
    */
    typedef int8_t   i8;
    typedef int16_t  i16;
    typedef int32_t  i32;
    typedef int64_t  i64;
    typedef uint8_t  u8;
    typedef uint16_t u16;
    typedef uint32_t u32;
    typedef uint64_t u64;

    /*
     * Floats
     */
    typedef float  f32;
    typedef double f64;

    void init();

    std::string get_version();
}

#endif
