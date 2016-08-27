/*
 * DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
 * Version 2, December 2004
 * Copyright (C) 2016 Mieszko Mazurek <mieszko392@yahoo.com>
 * Everyone is permitted to copy and distribute verbatim or modified
 * copies of this license document, and changing it is allowed as long
 * as the name is changed.
 * DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
 * TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION
 * 0. You just DO WHAT THE FUCK YOU WANT TO.
 */

#ifndef __MMATH_INLINE_H
#define __MMATH_INLINE_H

#ifdef __MMATH_H
#error mmath.h cannot be included before mmath_inline.h
#else

#define __mmath_api static inline
#include "mmath.h"

#define __mmath_api static inline
#define __MMATH_PRIVATE
#include "mmath_bits.h"

#endif

#endif
