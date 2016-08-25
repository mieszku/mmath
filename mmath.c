#include "mmath.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

#ifndef __unused
#	define __unused __attribute__((unused))
#endif

#define VEC_RESULT_REQUIRED(n) \
	assert(vec##n##_used); \
	vec##n##_ref top __unused = vec##n##_used;

#define VEC_BEGIN(n) \
	VEC_RESULT_REQUIRED(n) \
	vec##n##_ref out __unused = top;

#define VEC_BEGIN_BUFF(n) \
	VEC_RESULT_REQUIRED(n) \
	vec##n __out_memory__; \
	vec##n##_ref out = __out_memory__;

#define VEC_END_NO_RETURN(n) \
	if (out != top) \
	memcpy(top, out, sizeof(vec##n));

#define VEC_END(n) \
	VEC_END_NO_RETURN(n) \
	return top;


#define MAT_RESULT_REQUIRED(n) \
	assert(mat##n##_used); \
	mat##n##_ref top __unused = mat##n##_used;

#define MAT_BEGIN(n) \
	MAT_RESULT_REQUIRED(n) \
	mat##n##_ref out __unused = top;

#define MAT_BEGIN_BUFF(n) \
	MAT_RESULT_REQUIRED(n) \
	mat##n __out_memory__; \
	mat##n##_ref out __unused = __out_memory__;

#define MAT_END_NO_RETURN(n) \
	if (out != top) \
	memcpy(top, out, sizeof(mat##n));

#define MAT_END(n) \
	MAT_END_NO_RETURN(n) \
	return top;


struct stack {
	void **mem;
	size_t len;
	size_t qty;
};

static void stack_push(struct stack *st, void *p);
static void *stack_pop(struct stack *st);
static void swap_mem(void *restrict p, 
	void *restrict q, size_t l);


#define VEC_BASE(n) \
	static struct stack vec##n##_used_stack; \
	static vec##n##_ref vec##n##_used; \
	vec##n##_ref vec##n##_push(vec##n p) \
	{ \
		stack_push(&vec##n##_used_stack, vec##n##_used); \
		return vec##n##_replace(p); \
	} \
	\
	vec##n##_ref vec##n##_replace(vec##n p) \
	{ \
		vec##n##_used = p; \
		return p; \
	} \
	\
	vec##n##_ref vec##n##_pop() \
	{ \
		vec##n##_ref out = vec##n##_used; \
		vec##n##_used = stack_pop(&vec##n##_used_stack); \
		return out; \
	} \
	\
	vec##n##_ref vec##n##_print() \
	{ \
		for (int x = 0; x < n; x++) \
			printf("| %3f |\n", vec##n##_used[x]); \
		return vec##n##_used; \
	} \
	\
	vec##n##_ref vec##n##_read(vec##n p) \
	{ \
		memcpy(p, vec##n##_used, sizeof(vec##n)); \
		return vec##n##_used; \
	}\
	\
	float vec##n##_magn(vec##n p) \
	{ \
		float m = 0; \
		for (int x = 0; x < n; x++) \
			m += p[x] * p[x]; \
		return sqrtf(m); \
	} \
	\
	float vec##n##_dot(vec##n p) \
	{ \
		float d = 0; \
		VEC_BEGIN(n) \
		for (int x = 0; x < n; x++) \
			d += p[x] * top[x]; \
		VEC_END_NO_RETURN(n) \
		return d; \
	} \
	vec##n##_ref vec##n##_write(vec##n p) \
	{ \
		memcpy(vec##n##_used, p, sizeof(vec##n)); \
		return vec##n##_used; \
	} \
	\
	vec##n##_ref vec##n##_scale(float s) \
	{ \
		VEC_BEGIN(n) \
		for (int x = 0; x < n; x++) \
			out[x] = top[x] * s; \
		VEC_END(n) \
	} \
	\
	vec##n##_ref vec##n##_norm() \
	{ \
		VEC_BEGIN(n) \
		float r = 1 / vec##n##_magn(top); \
		vec##n##_scale(r); \
		VEC_END(n) \
	} \
	\
	vec##n##_ref vec##n##_add(vec##n p) \
	{ \
		VEC_BEGIN(n) \
		for (int x = 0; x < n; x++) \
			out[x] = top[x] + p[x]; \
		VEC_END(n) \
	} \
	\
	vec##n##_ref vec##n##_sub(vec##n p) \
	{ \
		VEC_BEGIN(n) \
		for (int x = 0; x < n; x++) \
			out[x] = top[x] - p[x]; \
		VEC_END(n) \
	} \
	\
	vec##n##_ref vec##n##_sub_rev(vec##n p) \
	{ \
		VEC_BEGIN(n) \
		for (int x = 0; x < n; x++) \
			out[x] = p[x] - top[x]; \
		VEC_END(n) \
	} \
	\
	vec##n##_ref vec##n##_mul(vec##n p) \
	{ \
		VEC_BEGIN(n) \
		for (int x = 0; x < n; x++) \
			out[x] = top[x] * p[x]; \
		VEC_END(n) \
	} \
	\
	vec##n##_ref vec##n##_mul_mat##n(mat##n m) \
	{ \
		VEC_BEGIN_BUFF(n) \
		for (int y = 0; y < n; y++) { \
			float v = 0; \
			for (int x = 0; x < n; x++) \
				v += m[x][y] * top[x]; \
			out[y] = v; \
		} \
		VEC_END(n) \
	} \


VEC_BASE(2)
VEC_BASE(3)
VEC_BASE(4)

vec3_ref vec3_cross(vec3 p)
{ 
	VEC_BEGIN_BUFF(3)
	out[0] = top[1] * p[2] - top[2] * p[1];
	out[1] = top[2] * p[0] - top[0] * p[2];
	out[2] = top[0] * p[1] - top[1] * p[0];
	VEC_END(3)
}

#define MAT_BASE(n) \
	static struct stack mat##n##_used_stack; \
	static mat##n##_ref mat##n##_used; \
	\
	mat##n##_ref mat##n##_push(mat##n p) \
	{ \
		stack_push(&mat##n##_used_stack, mat##n##_used); \
		mat##n##_used = p; \
		return p; \
	} \
	\
	mat##n##_ref mat##n##_replace(mat##n p) \
	{ \
		mat##n##_used = p; \
		return p; \
	} \
	\
	mat##n##_ref mat##n##_pop() \
	{ \
		mat##n##_ref out = mat##n##_used; \
		mat##n##_used = stack_pop(&mat##n##_used_stack); \
		return out; \
	} \
	\
	mat##n##_ref mat##n##_print() \
	{ \
		for (int x = 0; x < n; x++) { \
			printf("| "); \
			for (int y = 0; y < n; y++) \
				printf("%3f ", mat##n##_used[y][x]); \
			printf("|\n"); \
		} \
		return mat##n##_used; \
	} \
	\
	mat##n##_ref mat##n##_read(mat##n p) \
	{ \
		memcpy(p, mat##n##_used, sizeof(mat##n)); \
		return mat##n##_used; \
	} \
	\
	mat##n##_ref mat##n##_swap(mat##n p) \
	{ \
		swap_mem(mat##n##_used, p, sizeof(mat##n)); \
		return mat##n##_used; \
	} \
	\
	mat##n##_ref mat##n##_write(mat##n p) \
	{ \
		memcpy(mat##n##_used, p, sizeof(mat##n)); \
		return mat##n##_used; \
	} \
	\
	mat##n##_ref mat##n##_identity() \
	{ \
		MAT_BEGIN(n) \
		for (int y = 0; y < n; y++) \
			for (int x = 0; x < n; x++) \
				out[y][x] = (float)(x == y); \
		MAT_END(n) \
	} \
	\
	mat##n##_ref mat##n##_transpose() \
	{ \
		MAT_BEGIN_BUFF(n) \
		for (int y = 0; y < n; y++) \
			for (int x = 0; x < n; x++) \
				out[x][y] = top[y][x]; \
		MAT_END(n) \
	} \
	\
	mat##n##_ref mat##n##_scale(float scale) \
	{ \
		MAT_BEGIN(n) \
		for (int y = 0; y < n; y++) \
			for (int x = 0; x < n; x++) \
				out[y][x] = top[y][x] * scale; \
		MAT_END(n) \
	} \
	\
	mat##n##_ref mat##n##_add(mat##n p) \
	{ \
		MAT_BEGIN(n) \
		for (int y = 0; y < n; y++) \
			for (int x = 0; x < n; x++) \
				out[y][x] = top[y][x] + p[y][x]; \
		MAT_END(n) \
	}\
	\
	mat##n##_ref mat##n##_sub(mat##n p) \
	{ \
		MAT_BEGIN(n) \
		for (int y = 0; y < n; y++) \
			for (int x = 0; x < n; x++) \
				out[y][x] = top[y][x] - p[y][x]; \
		MAT_END(n) \
	}\
	\
	mat##n##_ref mat##n##_sub_rev(mat##n p) \
	{ \
		MAT_BEGIN(n) \
		for (int y = 0; y < n; y++) \
			for (int x = 0; x < n; x++) \
				out[y][x] = p[y][x] - top[y][x]; \
		MAT_END(n) \
	}\
	\
	mat##n##_ref mat##n##_mul(mat##n p) \
	{ \
		MAT_BEGIN_BUFF(n) \
		for (int y = 0; y < n; y++) \
		for (int x = 0; x < n; x++) { \
			float v = 0; \
			for (int i = 0; i < n; i++) \
				v += top[i][x] * p[y][i]; \
			out[y][x] = v; \
		} \
		MAT_END(n) \
	} \
	\
	mat##n##_ref mat##n##_mul_rev(mat##n p) \
	{ \
		MAT_BEGIN_BUFF(n) \
		for (int y = 0; y < n; y++) \
		for (int x = 0; x < n; x++) { \
			float v = 0; \
			for (int i = 0; i < n; i++) \
				v += top[y][i] * p[i][x]; \
			out[y][x] = v; \
		} \
		MAT_END(n) \
	}


MAT_BASE(2)
MAT_BASE(4)
MAT_BASE(3)


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

/*
 * internal 
 */

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
