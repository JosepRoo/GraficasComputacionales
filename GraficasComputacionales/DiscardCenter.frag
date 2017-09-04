#version 330

in vec3 InterpolatedColor;
in vec4 gl_FragCoord;

out vec4 FragColor;

void main()
{
	FragColor = vec4(InterpolatedColor, 1.0f);
}