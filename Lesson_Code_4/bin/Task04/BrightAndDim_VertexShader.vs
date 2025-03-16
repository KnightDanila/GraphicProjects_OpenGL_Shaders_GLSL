#version 330 core
layout (location = 0) in vec3 aPos; // the position variable has attribute position 0

out vec4 vertexColor; // specify a color output to the fragment shader

uniform float time;
uniform vec3 rgb;
uniform mat4 modelView;
uniform mat4 modelProj;

void main()
{
    gl_Position = modelProj * modelView * vec4(aPos.x * cos(time), aPos.y * sin(time), aPos.z, 1.0); // see how we directly give a vec3 to vec4's constructor
    vertexColor = vec4(1.0, 1.0, 0.0, 1.0); // set the output variable to a dark-red color
}