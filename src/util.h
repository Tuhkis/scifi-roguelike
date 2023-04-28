#include <inttypes.h>
#include <stdio.h>

typedef uint_fast8_t u8;
typedef uint_fast16_t u16;
typedef uint_fast32_t u32;
typedef uint_fast64_t u64;

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

#define TRACE(a) printf("%s %d: %s\n", __FILE__, __LINE__, a)

