#ifndef SHADER_H
#define SHADER_H

#include "../ModelData.h"

//********************************* CONSTANTS *********************************


struct VAO{
	GLuint vao;
	GLuint vbo;
	GLuint ebo;
	int tri;
	glm::vec4 vid;
};

const int ERROR_SIZE = 512;

struct Quad {
	float x1;	float y1;	float z1;
	float x2;	float y2;	float z2;
	float s1;	float t1;
	float s2;	float t2;
};

struct QBox{
	float x1;	float x2;
	float z1;	float z2;
	float y1;	float y2;
	float ts;
};

Quad CQ(float x1, float y1,	float z1, float x2, float y2, float z2);
Quad CQ(float x1, float y1,	float z1, float x2, float y2, float z2,	float s1, float t1);
Quad CQ(float x1, float y1,	float z1, float x2, float y2, float z2,	float s1, float t1,	float s2, float t2);
QBox CQB(float x1, float x2, float z1, float z2, float y1, float y2, float ts); 

//********************************* INITIALIZATION *********************************
class Shader {
public:
	Shader::Shader();
	
	static void Shader::initBufferObjects();
	void Shader::activateTextures(int i, GLuint test);
	static void Shader::finalQuit();
	
	void Shader::use();
	int Shader::triangleCount(int s);
	
	void Shader::xyQuad(Quad q, GLfloat * data, int offs);
	void Shader::yzQuad(Quad q, GLfloat * data, int offs);
	void Shader::xzQuad(Quad q, GLfloat * data, int offs);
	int Shader::createQBox(QBox qb, GLfloat * data, int offs);

	virtual void Shader::build(){}
	void Shader::buildBasic();

	// draw
	void Shader::draw();	
	void Shader::draw(int vi);	
	void Shader::testDraw();
	
	void Shader::attachDummy();
	// load
	bool Shader::loadVertexShader(const GLchar ** src);
	bool Shader::loadFragmentShader(const GLchar ** src);
	bool Shader::loadShader(GLenum shdrType, GLuint &shdr, const GLchar ** src );
	bool Shader::loadProgram(GLuint progID);
	bool Shader::buildProgram(const GLchar ** vsrc, const GLchar ** fsrc, GLuint progID);
	//bool Shader::buildProgram(const GLchar ** vsrc, const GLchar ** fsrc, GLuint p);
/*/ Purpose: 
Side Effects:  
Triggers: 
/*/

//************************************************** MEMBERS ***************************************************
	
	
	
	GLuint vao; GLuint prog;
	GLuint texUni[5];

	GLint posAtt, texAtt, dumAtt;
	GLuint vbo, ebo;

	static GLuint bigebo, lilebo, dumbo;
};
#endif