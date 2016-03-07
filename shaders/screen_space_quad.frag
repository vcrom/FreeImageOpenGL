#version 330 core

layout(location=0) out vec4 vFColor;

uniform sampler2D color_texture;
smooth in vec2 vUV;

void main(void)
{
	vec4 color = texture(color_texture, vUV).rgba;
	vFColor = color;

	// vec2 uv = (vUV-vec2(0.5));//*vec2(2);
	// float r = 0.2+0.05*cos(atan(uv.x, uv.y)*10 + 20.0*length(uv));
	// float f = smoothstep(r, r+0.4, length(uv));
	// vFColor = mix(vec4(0), vec4(1), f);
}
