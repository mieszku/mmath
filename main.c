#include "mmath.h"

#include <stdio.h>
#define endl printf("\n")

int main()
{
	vec4 p = {0.5, 0.5, -0.5, 1};

	vec3 eye = {0.1, 0, 0};
	vec3 pos = {0, 0, -1};
	vec3 up = {0, 1, 0};

	mat4 m;
	mat4_push(m);
	mat4_identity();
	mat4_look_at(eye, pos, up);
	mat4_print();

	//mat4_print();

	return 0;
}
