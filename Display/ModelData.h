#ifndef MODELDATA_H
#define MODELDATA_H
//#define GLSL(src) "#version 120 \n" #src
#include "../System/lib.h"

static const GLchar* defFragShdr[] =	{
	"#version 150 compatibility\n"
    "uniform sampler2D tex;"
	"in vec2 t; "	
	"in vec4 vs;"
	"void main() { "
	"	float d = length(vs);"
	"	float fog = (gl_Fog.end - d) * gl_Fog.scale;"
	"	fog = clamp(fog, 0, 1);"
	"	vec4 image = texture2D(tex, t);"
	"	if (image.w < 0.9) discard;"
	"	vec3 color = mix(gl_Fog.color.rgb, image.rgb, fog);"
	"	gl_FragColor = vec4(color.rgb, image.a);" //image;"//
	"}"
};

void enableDraw();
void billboard();
GLuint loadTexture(char *fname, bool rep);

const GLint dummy[] = {0, 0, 0, 0};
const GLfloat dummy2[] = {0, 0, 0, 5, 5, 0, 5, 5};
const GLuint EBO1[] = {0, 1, 2, 2, 1, 3};    

const GLuint cubeEBO[] = { //crateEBO 
	0, 1, 2, 2, 1, 3, 
	4, 5, 6, 6, 5, 7,
	8, 9, 10, 10, 9, 11,
	12, 13, 14, 14, 13, 15,
	16, 17, 18, 18, 17, 19																					 
};

#endif