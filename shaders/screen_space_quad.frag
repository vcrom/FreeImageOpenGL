#version 330 core
layout(location=0) out vec4 vFColor;

uniform sampler2D color_texture;
smooth in vec2 vUV;

void main(void)
{
	vec4 color = texture(color_texture, vUV).rgba;
	vFColor = color;
}
