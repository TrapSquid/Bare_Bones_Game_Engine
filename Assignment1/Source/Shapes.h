#ifndef __Shapes_H__
#define __Shapes_H__

extern GLuint g_VBOSquare;
extern GLuint g_VBOTriangle;
extern GLuint g_VBOCircle;

void GenerateTriangle();
void DrawTriangle(GLuint shaderprogram);

void GenerateCircle();
void DrawCircle(GLuint shaderprogram);

void GenerateSquare();
void DrawSquare(GLuint shaderprogram);

#endif //__Game_H__
