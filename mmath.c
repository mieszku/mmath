#define __MMATH_PRIVATE
#define __mmath_api extern
#include "mmath.h"
#ifdef __mmath_api
#error mmath.h has to undef __mmath_api
#endif
#define __mmath_api
#define __MMATH_PRIVATE
#include "mmath_bits.h"
#ifdef __mmath_api
#error mmath_bits.h has to undef __mmath_api
#endif
#ifdef __MMATH_PRIVATE
#error mmath_bits.h has to undef __MMATH_PRIVATE
#endif

/*

vec3_ref vec3_cross(vec3 p)
{ 
	VEC_BEGIN_BUFF(3)
	out[0] = top[1] * p[2] - top[2] * p[1];
	out[1] = top[2] * p[0] - top[0] * p[2];
	out[2] = top[0] * p[1] - top[1] * p[0];
	VEC_END(3)
}



mat4_ref mat4_translate_xyz(float x, float y, float z)
{
	mat4 m = {
		{1, 0, 0, 0},
		{0, 1, 0, 0},
		{0, 0, 1, 0},
		{x, y, z, 1}
	};
	return mat4_mul_rev(m);
}

mat4_ref mat4_translate_x(float t)
{
	return mat4_translate_xyz(t, 0, 0);
}

mat4_ref mat4_translate_y(float t)
{
	return mat4_translate_xyz(0, t, 0);
}

mat4_ref mat4_translate_z(float t)
{
	return mat4_translate_xyz(0, 0, t);
}

mat4_ref mat4_scale_xyz(float x, float y, float z)
{
	mat4 sca = {
		{ x, 0, 0, 0},
		{ 0, y, 0, 0},
		{ 0, 0, z, 0},
		{ 0, 0, 0, 1}
	};
	return mat4_mul_rev(sca);
}

mat4_ref mat4_scale_x(float s)
{
	return mat4_scale_xyz(s, 1, 1);
}

mat4_ref mat4_scale_y(float s)
{
	return mat4_scale_xyz(1, s, 1);
}

mat4_ref mat4_scale_z(float s)
{
	return mat4_scale_xyz(1, 1, s);
}

mat4_ref mat4_rotate_xyz(float x, float y, float z)
{
	mat4_rotate_x(x);
	mat4_rotate_y(y);
	return mat4_rotate_z(z);
}

mat4_ref mat4_rotate_x(float a)
{
	float c = cosf(a);
	float s = sinf(a);
	mat4 m = {
		{ 1,  0, 0, 0 },
		{ 0,  c, s, 0 },
		{ 0, -s, c, 0 },
		{ 0,  0, 0, 1 }
	};
	return mat4_mul_rev(m);
}

mat4_ref mat4_rotate_y(float a)
{
	float c = cosf(a);
	float s = sinf(a);
	mat4 m = {
		{  c, 0, s, 0 },
		{  0, 1, 0, 0 },
		{ -s, 0, c, 0 },
		{  0, 0, 0, 1 }
	};
	return mat4_mul_rev(m);
}

mat4_ref mat4_rotate_z(float a)
{
	float c = cosf(a);
	float s = sinf(a);
	mat4 m = {
		{  c, s, 0, 0 },
		{ -s, c, 0, 0 },
		{  0, 0, 1, 0 },
		{  0, 0, 0, 1 }
	};
	return mat4_mul_rev(m);
}

mat4_ref mat4_projection(float l, float r,
	float b, float t, float n, float f)
{
	float xx = 2 / (r - l);
	float zx = (r + l) / (r - l);
	float yy = 2 / (t - b);
	float zy = (t + b) / (t - b);
	float zz = - (f + n) / (f - n);
	float wz = - (2 * f * n) / (f - n);
	mat4 m = {
		{xx, 0,  0,  0 },
		{0,  yy, 0,  0 },
		{zx, zy, zz, -1},
		{0,  0,  wz, 0 }
	};
	return mat4_mul_rev(m);
}

mat4_ref mat4_look_at(vec3 eye, vec3 pos, vec3 up)
{
	mat4 mat;
	vec3_ref 
		xa = mat[0], ya = mat[1], 
		za = mat[2], wa = mat[3];

	vec3_push(za);
	vec3_write(pos);
	vec3_sub(eye);
	vec3_norm();
	vec3_scale(-1);
	
	vec3_replace(xa);
	vec3_write(up);
	vec3_cross(za);
	vec3_norm();

	vec3_replace(ya);
	vec3_write(za);
	vec3_cross(xa);

	vec3_replace(wa);
	vec3_write(eye);
	vec3_scale(-1);
	vec3_pop();

	mat[3][0] = 0;
	mat[3][1] = 0;
	mat[3][2] = 0;
	mat[3][3] = 1;

	return mat4_mul_rev(mat);
}

static void stack_push(struct stack *st, void *p)
{
	if (st->mem == NULL) {
		st->qty = 1;
		st->len = 0;
		st->mem = malloc(sizeof(p));
	} else
	if (st->len == st->qty) {
		st->qty <<= 1;
		st->mem = realloc(st->mem,
			sizeof(p) * st->qty);
	}

	st->mem[st->len++] = p;
}

static void *stack_pop(struct stack *st)
{
	if (st->mem == NULL || st->len == 0)
		return NULL;
	return st->mem[--st->len];
}

static void swap_mem(void *restrict p, 
	void *restrict q, size_t l)
{
	char b, *pc = p, *qc = q, *e = p + l;
	while (pc < e) {
		b = *pc;
		*pc = *qc;
		*qc = b;
		pc++; qc++;
	}
}
*/
