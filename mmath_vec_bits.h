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
#error mmath_vec_bits.h cannot be included directly
#endif

#if __siz == 2
# define __vec vec2
# define __vec_const vec2_const
# define __vec_ref vec2_ref
# define __mat_const mat2_const
# define __func(n) vec2_##n
# define __func_def(t, n) __mmath_api t __func(n)
#elif __siz == 3
# define __vec vec3
# define __vec_const vec3_const
# define __vec_ref vec3_ref
# define __mat_const mat3_const
# define __func(n) vec3_##n
# define __func_def(t, n) __mmath_api t __func(n)
#elif __siz == 4
# define __vec vec4
# define __vec_const vec4_const
# define __vec_ref vec4_ref
# define __mat_const mat4_const
# define __func(n) vec4_##n
# define __func_def(t, n) __mmath_api t __func(n)
#endif

__func_def(void, print)(__vec_const v)
{
	int i;
	for (i = 0; i < __siz; i++)
		printf("| %f |\n", v[i]);
}

__func_def(float, magn)(__vec_const p)
{
	float m = 0;
	int i;
	for (i = 0; i < __siz; i++)
		m += p[i] * p[i];
	return sqrtf(m);
}

__func_def(float, dot)(__vec_const p, __vec_const q)
{
	float d = 0;
	int i;
	for (i = 0; i < __siz; i++)
		d += p[i] * q[i];
	return d;
}

__func_def(vec2_ref, copy)(__vec dst, __vec_const src)
{
	memcpy(dst, src, sizeof(__vec));
	return dst;
}

__func_def(vec2_ref, swap)(__vec dst, __vec src)
{
	swap_mem(dst, src, sizeof(__vec), __tmp);
	return dst;
}

__func_def(__vec_ref, scale)(__vec p, float scale)
{
	int i;
	for (i = 0; i < __siz; i++)
		p[i] *= scale;
	return p;
}

__func_def(__vec_ref, norm)(__vec p)
{
	float r = 1 / __func(magn)(p);
	return __func(scale)(p, r);
}

__func_def(__vec_ref, add)(__vec p, __vec_const q)
{
	int i;
	for (i = 0; i < __siz; i++)
		p[i] += q[i];
	return p;
}

__func_def(__vec_ref, sub)(__vec p, __vec_const q)
{
	int i;
	for (i = 0; i < __siz; i++)
		p[i] -= q[i];
	return p;
}
__func_def(__vec_ref, sub_rev)(__vec p, __vec_const q)
{
	int i;
	for (i = 0; i < __siz; i++)
		p[i] = q[i] - p[i];
	return p;
}

__func_def(__vec_ref, mul)(__vec p, __vec_const q)
{
	int i;
	for (i = 0; i < __siz; i++)
		p[i] *= q[i];
	return p;
}

__func_def(__vec_ref, mul_mat)(__vec p, __mat_const m)
{
	__vec cp;
	__func(copy)(cp, p);
	int y, x;
	for (y = 0; y < __siz; y++) {
		float v = 0;
		for (x = 0; x < __siz; x++) {
			v += m[x][y] * cp[x];
		}
		p[y] = v;
	}
	return p;
}

#if __siz == 3

__func_def(__vec_ref, cross)(__vec p, __vec_const q)
{
	__vec cp;
	__func(copy)(cp, p);
	p[0] = cp[1] * q[2] - cp[2] * q[1];
	p[1] = cp[2] * q[0] - cp[0] * q[2];
	p[2] = cp[0] * q[1] - cp[1] * q[0];
	return p;
}

#endif

#undef __vec
#undef __vec_const
#undef __vec_ref
#undef __mat_const
#undef __func
#undef __func_def
