#include "CommonHeader.h"

GLuint g_VBOSquare = 0;
GLuint g_VBOTriangle = 0;
GLuint g_VBOCircle = 0;

const int CIRCLE_SLICES = 100;
const float CIRCLE_RADIUS = 1.0f;

void GenerateTriangle()
{
    // ATM this can only be called once, so we assert if it's called again with a VBO already allocated
    assert( g_VBOTriangle == 0 );

    // vertex position info for a triangle
	float vertexattributes[] = { 0.0f, 1.0f,
								-0.7071f, -0.7071f, 
								0.7071f, -0.7071f };

    // gen and fill buffer with our attributes
    glGenBuffers( 1, &g_VBOTriangle );
    glBindBuffer( GL_ARRAY_BUFFER, g_VBOTriangle );
    glBufferData( GL_ARRAY_BUFFER, sizeof(float)*6, vertexattributes, GL_STATIC_DRAW );

    // check for errors
    CheckForGLErrors();
}

void DrawTriangle(GLuint shaderprogram)
{
    glBindBuffer( GL_ARRAY_BUFFER, g_VBOTriangle );

    GLint loc = glGetAttribLocation( shaderprogram, "a_Position" );
    if( loc != -1 )
    {
        glVertexAttribPointer( loc, 2, GL_FLOAT, GL_FALSE, sizeof(float)*2, (void*)0 );
        glEnableVertexAttribArray( loc );
    }

    // check for errors
    CheckForGLErrors();

    glDrawArrays( GL_TRIANGLES, 0, 3 );
}

void GenerateCircle()
{
	//Holds onto the values passed in for later use.
	const int Slices = CIRCLE_SLICES;
	float Convert = Slices;

	// ATM this can only be called once, so we assert if it's called again with a VBO already allocated
	assert(g_VBOCircle == 0);
	
	//Cycles between all the segments needed to generate the circle
	float vertexattributes[6*Slices];
	for (int i = 0; i < CIRCLE_SLICES; i++)
	{
		vertexattributes[1 + (i * 6) - 1] = 0;
		vertexattributes[2 + (i * 6) - 1] = 0;
	
		//Sets the positioning according to the angle to be drawn.
		vertexattributes[3 + (i * 6) - 1] = cosf((360 / Convert * (i + 1)) * PI / 180);// *CIRCLE_RADIUS;
		vertexattributes[4 + (i * 6) - 1] = sinf((360 / Convert * (i + 1)) * PI / 180);// *CIRCLE_RADIUS;
												  
		vertexattributes[5 + (i * 6) - 1] = cosf((360 / Convert * (i + 2)) * PI / 180);// *CIRCLE_RADIUS;
		vertexattributes[6 + (i * 6) - 1] = sinf((360 / Convert * (i + 2)) * PI / 180);// *CIRCLE_RADIUS;
	}

	// gen and fill buffer with our attributes
	glGenBuffers(1, &g_VBOCircle);
	glBindBuffer(GL_ARRAY_BUFFER, g_VBOCircle);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 2 * 3 * CIRCLE_SLICES , vertexattributes, GL_STATIC_DRAW);

	// check for errors
	CheckForGLErrors();
}

void DrawCircle(GLuint shaderprogram)
{
    glBindBuffer( GL_ARRAY_BUFFER, g_VBOCircle );

	GLint loc = glGetAttribLocation(shaderprogram, "a_Position");
	if (loc != -1)
	{
		glVertexAttribPointer(loc, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, (void*)0);
		glEnableVertexAttribArray(loc);
	}

    // check for errors
    CheckForGLErrors();

	glDrawArrays(GL_TRIANGLES, 0, 3 *CIRCLE_SLICES);
}

void GenerateSquare()
{
    // ATM this can only be called once, so we assert if it's called again with a VBO already allocated
    assert( g_VBOSquare == 0 );

    // vertex position info for a triangle
    float vertexattributes[] = { -1, -1, 
                                  1, -1, 
                                  1, 1,
    
                                 -1, 1,
                                  -1,-1,
                                   1,1};

    // gen and fill buffer with our attributes
    glGenBuffers( 1, &g_VBOSquare );
    glBindBuffer( GL_ARRAY_BUFFER, g_VBOSquare );
    glBufferData( GL_ARRAY_BUFFER, sizeof(float)*2*6, vertexattributes, GL_STATIC_DRAW );

    // check for errors
    CheckForGLErrors();
}

void DrawSquare(GLuint shaderprogram)
{
    glBindBuffer( GL_ARRAY_BUFFER, g_VBOSquare );

    GLint loc = glGetAttribLocation( shaderprogram, "a_Position" );
    if( loc != -1 )
    {
        glVertexAttribPointer( loc, 2, GL_FLOAT, GL_FALSE, sizeof(float)*2, (void*)0 );
        glEnableVertexAttribArray( loc );
    }

    // check for errors
    CheckForGLErrors();

    glDrawArrays( GL_TRIANGLES, 0, 6 );
}
