#ifndef __MMATH_H
#define __MMATH_H

#define rad(x) ((3.14159 / 180) * (x))
#define mmath(x, t, f, ...) \
	t##_push(x); \
	t##_##f(__VA_ARGS__); \
	t##_pop(x);


typedef float vec2[2];
typedef float *vec2_ref;
typedef vec2 mat2[2];
typedef vec2 *mat2_ref;

vec2_ref vec2_push(vec2 vec);
vec2_ref vec2_replace(vec2 vec);
vec2_ref vec2_pop();
vec2_ref vec2_print();
vec2_ref vec2_read(vec2 vec);
float vec2_magn(vec2 vec);
float vec2_dot(vec2 vec);
vec2_ref vec2_write(vec2 vec);
vec2_ref vec2_scale(float scale);
vec2_ref vec2_norm();
vec2_ref vec2_add(vec2 vec);
vec2_ref vec2_sub(vec2 vec);
vec2_ref vec2_sub_rev(vec2 vec);
vec2_ref vec2_mul(vec2 vec);
vec2_ref vec2_mul_mat(mat2 mat);



typedef float vec3[3];
typedef float *vec3_ref;
typedef vec3 mat3[3];
typedef vec3 *mat3_ref;

vec3_ref vec3_push(vec3 vec);
vec3_ref vec3_replace(vec3 vec);
vec3_ref vec3_pop();
vec3_ref vec3_print();
vec3_ref vec3_read(vec3 vec);
float vec3_magn(vec3 vec);
float vec3_dot(vec3 vec);
vec3_ref vec3_write(vec3 vec);
vec3_ref vec3_scale(float scale);
vec3_ref vec3_norm();
vec3_ref vec3_add(vec3 vec);
vec3_ref vec3_sub(vec3 vec);
vec3_ref vec3_sub_rev(vec3 vec);
vec3_ref vec3_mul(vec3 vec);
vec3_ref vec3_mul_mat(mat3 mat);

vec3_ref vec3_cross(vec3 vec);



typedef float vec4[4];
typedef float *vec4_ref;
typedef vec4 mat4[4];
typedef vec4 *mat4_ref;

vec4_ref vec4_push(vec4 vec);
vec4_ref vec4_replace(vec4 vec);
vec4_ref vec4_pop();
vec4_ref vec4_print();
vec4_ref vec4_read(vec4 vec);
float vec4_magn(vec4 vec);
float vec4_dot(vec4 vec);
vec4_ref vec4_write(vec4 vec);
vec4_ref vec4_scale(float scale);
vec4_ref vec4_norm();
vec4_ref vec4_add(vec4 vec);
vec4_ref vec4_sub(vec4 vec);
vec4_ref vec4_sub_rev(vec4 vec);
vec4_ref vec4_mul(vec4 vec);
vec4_ref vec4_mul_mat(mat4 mat);



mat2_ref mat2_push(mat2 mat);
mat2_ref mat2_replace(mat2 mat);
mat2_ref mat2_pop();
mat2_ref mat2_print();
mat2_ref mat2_read(mat2 mat);
mat2_ref mat2_swap(mat2 mat);
mat2_ref mat2_write(mat2 mat);
mat2_ref mat2_identity();
mat2_ref mat2_transpose();
mat2_ref mat2_scale(float scale);
mat2_ref mat2_add(mat2 mat);
mat2_ref mat2_sub(mat2 mat);
mat2_ref mat2_sub_rev(mat2 mat);
mat2_ref mat2_mul(mat2 mat);
mat2_ref mat2_mul_rev(mat2 mat);



mat3_ref mat3_push(mat3 mat);
mat3_ref mat3_replace(mat3 mat);
mat3_ref mat3_pop();
mat3_ref mat3_print();
mat3_ref mat3_read(mat3 mat);
mat3_ref mat3_swap(mat3 mat);
mat3_ref mat3_write(mat3 mat);
mat3_ref mat3_identity();
mat3_ref mat3_transpose();
mat3_ref mat3_scale(float scale);
mat3_ref mat3_add(mat3 mat);
mat3_ref mat3_sub(mat3 mat);
mat3_ref mat3_sub_rev(mat3 mat);
mat3_ref mat3_mul(mat3 mat);
mat3_ref mat3_mul_rev(mat3 mat);



mat4_ref mat4_push(mat4 mat);
mat4_ref mat4_replace(mat4 mat);
mat4_ref mat4_pop();
mat4_ref mat4_print();
mat4_ref mat4_read(mat4 mat);
mat4_ref mat4_swap(mat4 mat);
mat4_ref mat4_write(mat4 mat);
mat4_ref mat4_identity();
mat4_ref mat4_transpose();
mat4_ref mat4_scale(float scale);
mat4_ref mat4_add(mat4 mat);
mat4_ref mat4_sub(mat4 mat);
mat4_ref mat4_sub_rev(mat4 mat);
mat4_ref mat4_mul(mat4 mat);
mat4_ref mat4_mul_rev(mat4 mat);

mat4_ref mat4_translate_xyz(float x, float y, float z);
mat4_ref mat4_translate_x(float t);
mat4_ref mat4_translate_y(float t);
mat4_ref mat4_translate_z(float t);
mat4_ref mat4_scale_xyz(float x, float y, float z);
mat4_ref mat4_scale_x(float s);
mat4_ref mat4_scale_y(float s);
mat4_ref mat4_scale_z(float s);
mat4_ref mat4_rotate_xyz(float x, float y, float z);
mat4_ref mat4_rotate_x(float a);
mat4_ref mat4_rotate_y(float a);
mat4_ref mat4_rotate_z(float a);
mat4_ref mat4_projection(float l, float r,
	float b, float t, float n, float f);
mat4_ref mat4_look_at(vec3 eye, vec3 pos, vec3 up);

#endif
