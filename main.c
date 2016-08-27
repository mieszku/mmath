#include "mmath_inline.h"

#include <stdio.h>
#define endl printf("\n")

int main()
{
	mat4 m;
	vec3 eye = {0, 0, -0.5};
	vec3 pos = {0, 0, 0};
	vec3 up = {0, 1, -0.5};

	vec4 v = {0.5, 0.5, -3, 1};

	mat4_identity(m);
	//mat4_look_at(m, eye, pos, up);
	mat4_projection(m, -1, 1, -1, 1, 1, 5);
	mat4_print(m);

	vec4_mul_mat(v, m);
	vec4_print(v);
	return 0;
}
