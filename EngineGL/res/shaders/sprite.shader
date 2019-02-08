#shader vertex
#version 330 core

layout(location = 0) in vec4 vertex;

out vec2 texCoords;
uniform mat4 uModel;
uniform mat4 uProjection;

void main()
{
	texCoords = vertex.zw;
	gl_Position = uProjection * uModel * vec4(vertex.xy, 0.0, 1.0);
};

#shader fragment
#version 330 core

in vec2 texCoords;
out vec4 color;

uniform sampler2D uImage;
uniform vec3 uColor;

void main()
{
	color = texture(uImage, texCoords) * vec4(uColor, 1.0);
};