#version 330 core
out vec4 FragColor;

in vec2 TexCoord;

uniform sampler2D texture1;
uniform sampler2D texture2;

uniform float time;

void main()
{
	FragColor = texture(texture1, TexCoord);

	if(texture(texture2, TexCoord).g > 0.10f ){    
		FragColor = texture(texture1, TexCoord)*(1+abs(sin(time*1.3f)))/1.7;
	}
	

}