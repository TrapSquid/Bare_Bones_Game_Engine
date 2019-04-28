#ifndef __CommonHeader_H__
#define __CommonHeader_H__

#include <windows.h>
#include <stdio.h>
#include <map>
#include <string.h>
#define assert myassert

#include <gl/GL.h>
#include <gl/GLU.h>

#include "GL/GLExtensions.h"

#include "Utility/Helpers.h"

#include "Math/Utility.h"
#include "Math/Vector.h"
#include "Math/MyMatrix.h"

#include "lodepng/lodepng.h"
#include "Utility/ShaderProgram.h"

extern bool g_KeyStates[256];

#include "Shapes.h"

#include "GameObject.h"
#include "Target.h"
#include "Player.h"
#include "Enemy.h"
#include "LevelTile.h"

#include "Game.h"

#include "Camera.h"

#include "RandomCodeFiles\RandomNumberGenerator.h"
#include "RandomCodeFiles\functions.h"

#endif //__CommonHeader_H__
