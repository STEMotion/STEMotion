//
// Created by mdgaziur001 on 3/28/25.
//

#pragma once

#include <cstdint>
#include <cstddef>

typedef int8_t i8;
typedef uint8_t u8;
typedef int16_t i16;
typedef uint16_t u16;
typedef int32_t i32;
typedef uint32_t u32;
typedef int64_t i64;
typedef uint64_t u64;
typedef float f32;
typedef double f64;
typedef size_t usize;

#ifdef _WIN32
typedef long isize;
#else
#include <unistd.h>
typedef ssize_t isize;
#endif
