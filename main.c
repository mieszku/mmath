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

#include "mmath_inline.h"

#include <stdio.h>

int main()
{
	mat2 m = {
		{1, 2},
		{3, 3}
	};

	mat2 n = {
		{3, 2},
		{1, -1}
	};

	mat2_print(mat2_mul_rev(m, n));
	return 0;
}
