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

#ifndef __MMATH_H
#define __MMATH_H

#ifndef __mmath_api
#define __mmath_api extern
#endif

#define rad(x) ((3.14159 / 180) * (x))
#define const

typedef float vec2[2];
typedef const vec2 vec2_const;
typedef float *vec2_ref;
typedef const float * vec2_const_ref;
typedef vec2 mat2[2];
typedef const mat2 mat2_const;
typedef vec2 * mat2_ref;
typedef vec2_const * mat2_const_ref;

__mmath_api void vec2_print(vec2_const v);
__mmath_api float vec2_magn(vec2_const v);
__mmath_api float vec2_dot(vec2_const v1, vec2_const v2);
__mmath_api vec2_ref vec2_copy(vec2 dst, vec2_const src);
__mmath_api vec2_ref vec2_swap(vec2 dst, vec2 src);
__mmath_api vec2_ref vec2_scale(vec2 v, float scale);
__mmath_api vec2_ref vec2_norm(vec2 v);
__mmath_api vec2_ref vec2_add(vec2 v, vec2_const w);
__mmath_api vec2_ref vec2_sub(vec2 v, vec2_const w);
__mmath_api vec2_ref vec2_sub_rev(vec2 v, vec2_const w);
__mmath_api vec2_ref vec2_mul(vec2 vec, vec2_const w);
__mmath_api vec2_ref vec2_mul_mat(vec2 vec, mat2_const m);

__mmath_api void mat2_print(mat2_const m);
__mmath_api mat2_ref mat2_copy(mat2 dst, mat2_const src);
__mmath_api mat2_ref mat2_swap(mat2 dst, mat2 src);
__mmath_api mat2_ref mat2_identity(mat2 m);
__mmath_api mat2_ref mat2_transpose(mat2 m);
__mmath_api mat2_ref mat2_scale(mat2 m, float scale);
__mmath_api mat2_ref mat2_add(mat2 m, mat2_const w);
__mmath_api mat2_ref mat2_sub(mat2 m, mat2_const w);
__mmath_api mat2_ref mat2_sub_rev(mat2 m, mat2_const w);
__mmath_api mat2_ref mat2_mul(mat2 m, mat2_const w);
__mmath_api mat2_ref mat2_mul_rev(mat2 m, mat2_const w);



typedef float vec3[3];
typedef const vec3 vec3_const;
typedef float *vec3_ref;
typedef const float * vec3_const_ref;
typedef vec3 mat3[3];
typedef const mat3 mat3_const;
typedef vec3 * mat3_ref;
typedef vec3_const * mat3_const_ref;

__mmath_api void vec3_print(vec3_const v);
__mmath_api float vec3_magn(vec3_const v);
__mmath_api float vec3_dot(vec3_const v1, vec3_const v3);
__mmath_api vec3_ref vec3_copy(vec3 dst, vec3_const src);
__mmath_api vec3_ref vec3_swap(vec3 dst, vec3 src);
__mmath_api vec3_ref vec3_scale(vec3 v, float scale);
__mmath_api vec3_ref vec3_norm(vec3 v);
__mmath_api vec3_ref vec3_add(vec3 v, vec3_const w);
__mmath_api vec3_ref vec3_sub(vec3 v, vec3_const w);
__mmath_api vec3_ref vec3_sub_rev(vec3 v, vec3_const w);
__mmath_api vec3_ref vec3_mul(vec3 vec, vec3_const w);
__mmath_api vec3_ref vec3_mul_mat(vec3 vec, mat3_const m);

__mmath_api vec3_ref vec3_cross(vec3 v, vec3_const w);

__mmath_api void mat3_print(mat3_const m);
__mmath_api mat3_ref mat3_copy(mat3 dst, mat3_const src);
__mmath_api mat3_ref mat3_swap(mat3 dst, mat3 src);
__mmath_api mat3_ref mat3_identity(mat3 m);
__mmath_api mat3_ref mat3_transpose(mat3 m);
__mmath_api mat3_ref mat3_scale(mat3 m, float scale);
__mmath_api mat3_ref mat3_add(mat3 m, mat3_const w);
__mmath_api mat3_ref mat3_sub(mat3 m, mat3_const w);
__mmath_api mat3_ref mat3_sub_rev(mat3 m, mat3_const w);
__mmath_api mat3_ref mat3_mul(mat3 m, mat3_const w);
__mmath_api mat3_ref mat3_mul_rev(mat3 m, mat3_const w);



typedef float vec4[4];
typedef const vec4 vec4_const;
typedef float *vec4_ref;
typedef const float * vec4_const_ref;
typedef vec4 mat4[4];
typedef const mat4 mat4_const;
typedef vec4 * mat4_ref;
typedef vec4_const * mat4_const_ref;

__mmath_api void vec4_print(vec4_const v);
__mmath_api float vec4_magn(vec4_const v);
__mmath_api float vec4_dot(vec4_const v1, vec4_const v4);
__mmath_api vec4_ref vec4_copy(vec4 dst, vec4_const src);
__mmath_api vec4_ref vec4_swap(vec4 dst, vec4 src);
__mmath_api vec4_ref vec4_scale(vec4 v, float scale);
__mmath_api vec4_ref vec4_norm(vec4 v);
__mmath_api vec4_ref vec4_add(vec4 v, vec4_const w);
__mmath_api vec4_ref vec4_sub_rev(vec4 v, vec4_const w);
__mmath_api vec4_ref vec4_mul(vec4 vec, vec4_const w);
__mmath_api vec4_ref vec4_mul_mat(vec4 vec, mat4_const m);

__mmath_api void mat4_print(mat4_const m);
__mmath_api mat4_ref mat4_copy(mat4 dst, mat4_const src);
__mmath_api mat4_ref mat4_swap(mat4 dst, mat4 src);
__mmath_api mat4_ref mat4_identity(mat4 m);
__mmath_api mat4_ref mat4_transpose(mat4 m);
__mmath_api mat4_ref mat4_scale(mat4 m, float scale);
__mmath_api mat4_ref mat4_add(mat4 m, mat4_const w);
__mmath_api mat4_ref mat4_sub(mat4 m, mat4_const w);
__mmath_api mat4_ref mat4_sub_rev(mat4 m, mat4_const w);
__mmath_api mat4_ref mat4_mul(mat4 m, mat4_const w);
__mmath_api mat4_ref mat4_mul_rev(mat4 m, mat4_const w);

__mmath_api mat4_ref mat4_translate_xyz(mat4 m, vec3_const v);
__mmath_api mat4_ref mat4_translate_x(mat4 m, float t);
__mmath_api mat4_ref mat4_translate_y(mat4 m, float t);
__mmath_api mat4_ref mat4_translate_z(mat4 m, float t);
__mmath_api mat4_ref mat4_scale_xyz(mat4 m, vec3 scale);
__mmath_api mat4_ref mat4_scale_x(mat4 m, float t);
__mmath_api mat4_ref mat4_scale_y(mat4 m, float t);
__mmath_api mat4_ref mat4_scale_z(mat4 m, float t);
__mmath_api mat4_ref mat4_rotate_xyz(mat4 m, vec3_const rot);
__mmath_api mat4_ref mat4_rotate_x(mat4 m, float a);
__mmath_api mat4_ref mat4_rotate_y(mat4 m, float a);
__mmath_api mat4_ref mat4_rotate_z(mat4 m, float a);
__mmath_api mat4_ref mat4_projection(mat4 m, float l, float r,
	float b, float t, float n, float f);
__mmath_api mat4_ref mat4_projection_sym(mat4 m, float w,
	float h, float n, float f);
__mmath_api mat4_ref mat4_look_at(mat4 m, vec3_const eye, 
	vec3_const pos, vec3_const top);

#undef __mmath_api

#endif
