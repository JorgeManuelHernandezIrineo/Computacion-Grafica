#version 330 core
//in vec3 ourColor;

//Solo recibe la posicion del color de cada pieza, no es necesario recibir el color de cada vertice
out vec4 color;

uniform vec3 objectColor; // Uniform para cambiar de color por pieza

void main()
{
	//color = vec4(ourColor, 1.0f);
	color = vec4(objectColor, 1.0f);
}