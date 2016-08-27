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

#ifndef __MMATH_PRIVATE
#error mmath_bits.h cannot be included directly
#endif

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#ifndef __mmath_api
#error __mmath_api undefined
#endif

#define swap_mem(p, q, l, tmp) \
	char tmp[l]; \
	memcpy(tmp, p, l); \
	memcpy(p, q, l); \
	memcpy(q, tmp, l); 

#define __siz 2
#include "mmath_vec_bits.h"
#include "mmath_mat_bits.h"
#undef __siz
#define __siz 3
#include "mmath_vec_bits.h"
#include "mmath_mat_bits.h"
#undef __siz
#define __siz 4
#include "mmath_vec_bits.h"
#include "mmath_mat_bits.h"
#undef __siz

#undef swap_mem
#undef __mmath_api
#undef __MMATH_PRIVATE
