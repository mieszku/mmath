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
#error mmath_mat_bits.h cannot be included directly
#endif

#if __siz == 2
# define __mat mat2
# define __mat_const mat2_const
# define __mat_ref mat2_ref
# define __mat_const_ref mat2_const_ref
# define __func(n) mat2_##n
# define __func_def(t, n) __mmath_api t __func(n)
#elif __siz == 3
# define __mat mat3
# define __mat_const mat3_const
# define __mat_ref mat3_ref
# define __mat_const_ref mat3_const_ref
# define __func(n) mat3_##n
# define __func_def(t, n) __mmath_api t __func(n)
#elif __siz == 4
# define __mat mat4
# define __mat_const mat4_const
# define __mat_ref mat4_ref
# define __mat_const_ref mat4_const_ref
# define __func(n) mat4_##n
# define __func_def(t, n) __mmath_api t __func(n)
#endif

__func_def(void, print)(__mat_const p)
{
	int y, x;
	for (y = 0; y < __siz; y++) {
		printf("| ");
		for (x = 0; x < __siz; x++)
			printf("%3f ", p[x][y]);
		printf("|\n");
	}
}

__func_def(__mat_ref, copy)(__mat dst, __mat_const src)
{
	memcpy(dst, src, sizeof(__mat));
	return dst;
}

__func_def(__mat_ref, swap)(__mat dst, __mat src)
{
	swap_mem(dst, src, sizeof(__mat), __tmp);
	return dst;
}

__func_def(__mat_ref, identity)(__mat m)
{
	int x, y;
	for (y = 0; y < __siz; y++)
		for (x = 0; x < __siz; x++)
			m[y][x] = (float)(y == x);
	return m;
}

__func_def(__mat_ref, transpose)(__mat m)
{
	__mat cp;
	__func(copy)(cp, m);
	int x, y;
	for (y = 0; y < __siz; y++)
		for (x = 0; x < __siz; x++)
			m[y][x] = cp[x][y];
	return m;
}

__func_def(__mat_ref, scale)(__mat m, float s)
{
	int x, y;
	for (y = 0; y < __siz; y++)
		for (x = 0; x < __siz; x++)
			m[y][x] *= s;
	return m;
}

__func_def(__mat_ref, add)(__mat p, __mat_const q)
{
	int x, y;
	for (y = 0; y < __siz; y++)
		for (x = 0; x < __siz; x++)
			p[y][x] += q[y][x];
	return p;
}

__func_def(__mat_ref, sub)(__mat p, __mat_const q)
{
	int x, y;
	for (y = 0; y < __siz; y++)
		for (x = 0; x < __siz; x++)
			p[y][x] -= q[y][x];
	return p;
}

__func_def(__mat_ref, sub_rev)(__mat p, __mat_const q)
{
	int x, y;
	for (y = 0; y < __siz; y++)
		for (x = 0; x < __siz; x++)
			p[y][x] = q[y][x] - p[y][x];
	return p;
}

__func_def(__mat_ref, mul)(__mat p, __mat_const q)
{
	int x, y, i;
	__mat cp;
	for (y = 0; y < __siz; y++)
	for (x = 0; x < __siz; x++) {
		float v = 0;
		for (i = 0; i < __siz; i++)
			v += p[i][x] * q[y][i];
		cp[y][x] = v;
	}
	__func(copy)(p, cp);
	return p;
}

__func_def(__mat_ref, mul_rev)(__mat p, __mat_const q)
{
	int x, y, i;
	__mat cp;
	for (y = 0; y < __siz; y++)
	for (x = 0; x < __siz; x++) {
		float v = 0;
		for (i = 0; i < __siz; i++)
			v += p[y][i] * q[i][x];
		cp[y][x] = v;
	}
	__func(copy)(p, cp);
	return p;
}

#if __siz == 4

__func_def(mat4_ref, translate_xyz)(mat4 p, vec3_const v)
{
	mat4 t;
	__func(identity)(t);
	vec3_copy(t[3], v);
	return __func(mul_rev)(t, p);
}

__func_def(mat4_ref, translate_x)(mat4 p, float t)
{
	vec3 tv = {t, 0, 0};
	return __func(translate_xyz)(p, tv);
}

__func_def(mat4_ref, translate_y)(mat4 p, float t)
{
	vec3 tv = {0, t, 0};
	return __func(translate_xyz)(p, tv);
}

__func_def(mat4_ref, translate_z)(mat4 p, float t)
{
	vec3 tv = {0, 0, t};
	return __func(translate_xyz)(p, tv);
}

__func_def(mat4_ref, scale_xyz)(mat4 m, vec3 scale)
{
	mat4 t;
	__func(identity)(t);
	t[0][0] = scale[0];
	t[1][1] = scale[1];
	t[2][2] = scale[2];
	return __func(mul_rev)(m, t);
}

__func_def(mat4_ref, scale_x)(mat4 m, float s)
{
	vec3 sv = {s, 0, 0};
	return __func(scale_xyz)(m, sv);
}

__func_def(mat4_ref, scale_y)(mat4 m, float s)
{
	vec3 sv = {0, s, 0};
	return __func(scale_xyz)(m, sv);
}

__func_def(mat4_ref, scale_z)(mat4 m, float s)
{
	vec3 sv = {0, 0, s};
	return __func(scale_xyz)(m, sv);
}

__func_def(mat4_ref, rotate_xyz)(mat4 m, vec3_const rot)
{
	__func(rotate_x)(m, rot[0]);
	__func(rotate_y)(m, rot[1]);
	__func(rotate_z)(m, rot[2]);
	return m;
}

__func_def(mat4_ref, rotate_x)(mat4 m, float a)
{
	float c = cosf(a);
	float s = sinf(a);
	float z = -s;
	mat4 r = {
		{1, 0, 0, 0},
		{0, c, s, 0},
		{0, z, c, 0},
		{0, 0, 0, 1}
	};
	return __func(mul_rev)(m, r);
}

__func_def(mat4_ref, rotate_y)(mat4 m, float a)
{
	float c = cosf(a);
	float s = sinf(a);
	float z = -s;
	mat4 r = {
		{c, 0, s, 0},
		{0, 1, 0, 0},
		{z, 0, c, 0},
		{0, 0, 0, 1}
	};
	return __func(mul_rev)(m, r);
}

__func_def(mat4_ref, rotate_z)(mat4 m, float a)
{
	float c = cosf(a);
	float s = sinf(a);
	float z = -s;
	mat4 r = {
		{c, s, 0, 0},
		{z, c, 0, 0},
		{0, 0, 1, 0},
		{0, 0, 0, 1}
	};
	return __func(mul_rev)(m, r);
}

__func_def(mat4_ref, projection)(mat4 m, float l, float r,
	float b, float t, float n, float f)
{
	float xx = 2 / (r - l);
	float zx = (r + l) / (r - l);
	float yy = 2 / (t - b);
	float zy = (t + b) / (t - b);
	float zz = - (f + n) / (f - n);
	float wz = - (2 * f * n) / (f - n);
	mat4 p = {
		{xx, 0,  0,  0 },
		{0,  yy, 0,  0 },
		{zx, zy, zz, -1},
		{0,  0,  wz, 0 }
	};
	return __func(mul_rev)(m, p);
}

__func_def(mat4_ref, projection_sym)(mat4 m, float w,
	float h, float n, float f)
{
	float r = w / 2, l = -r, t = h / 2, b = -t;
	return __func(projection)(m, l, r, b, t, n, f);
}

__func_def(mat4_ref, look_at)(mat4 m, vec3_const eye,
	vec3_const pos, vec3_const top)
{
	mat4 la;
	mat4_identity(la);
	vec3_ref 
		xa = la[0], 
		ya = la[1], 
		za = la[2],
		wa = la[3];

	vec3_copy(za, pos);
	vec3_sub(za, eye);
	vec3_norm(za);

	vec3_copy(xa, top);
	vec3_cross(xa, za);
	vec3_norm(xa);

	vec3_copy(ya, za);
	vec3_cross(ya, xa);

	vec3_copy(wa, eye);
	vec3_scale(wa, -1);

	return mat4_mul_rev(m, la);
}

#endif

#undef __mat
#undef __mat_const
#undef __mat_ref
#undef __mat_const_ref
#undef __func
#undef __func_def
