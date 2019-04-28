

//Handles Object's positioning and scaling uniforms
uniform vec2 u_ChangePosition;
uniform vec2 u_ObjectScale;

//Handles Camera scale and position uniforms
uniform vec2 u_CameraPosition;
uniform vec2 u_CameraScale;

attribute vec2 a_Position;

void main()
{
vec2 finalpos = a_Position;

//This is where we are handling object related translations
finalpos *= u_ObjectScale; // apply object scale
finalpos += u_ChangePosition; // apply object translation

//Handles camera translations
finalpos += vec2(u_CameraPosition.x, u_CameraPosition.y); // apply camera translation
finalpos *= vec2( 1/u_CameraScale.x, 1/u_CameraScale.y ); // apply projection scale



    gl_Position = vec4( finalpos, 0, 1 );
}
