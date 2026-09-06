#include<iostream>

//#define GLEW_STATIC

#include <GL/glew.h>

#include <GLFW/glfw3.h>

// Shaders
#include "Shader.h"

void resize(GLFWwindow* window, int width, int height);

const GLint WIDTH = 800, HEIGHT = 600;


int main() {
	glfwInit();
	//Verificaci�n de compatibilidad 
	/*glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);*/

	GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "Origami Pikachu 2D", NULL, NULL);
	glfwSetFramebufferSizeCallback(window, resize);
	
	//Verificaci�n de errores de creacion  ventana
	if (window== NULL) 
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();

		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window);
	glewExperimental = GL_TRUE;

	//Verificaci�n de errores de inicializaci�n de glew

	if (GLEW_OK != glewInit()) {
		std::cout << "Failed to initialise GLEW" << std::endl;
		return EXIT_FAILURE;
	}

	// Imprimimos informacin de OpenGL del sistema
	std::cout << "> Version: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "> Vendor: " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "> Renderer: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "> SL Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;


	// Define las dimensiones del viewport
	//glViewport(0, 0, screenWidth, screenHeight);

    Shader ourShader("Shader/core.vs", "Shader/core.frag");

	// Set up vertex data (and buffer(s)) and attribute pointers
	float vertices[] = {
		// cabeza 
		0.0f, -0.6f, 0.0f,          1.0f, 0.88f, 0.2f,  // 0: Barbilla
	   -0.4f, -0.1f, 0.0f,          1.0f, 0.88f, 0.2f,  // 1: Izq Abajo
		0.4f, -0.1f, 0.0f,          1.0f, 0.88f, 0.2f,  // 2: Der Abajo
	   -0.4f,  0.2f, 0.0f,          1.0f, 0.88f, 0.2f,  // 3: Izq Arriba
		0.4f,  0.2f, 0.0f,          1.0f, 0.88f, 0.2f,  // 4: Der Arriba
		0.0f,  0.2f, 0.0f,          1.0f, 0.88f, 0.2f,  // 5: Centro Frente

		
		// Oreja Izq
		-0.2f,   0.2f,  0.0f,    1.0f,  0.88f, 0.2f,   // 6: Base izq
		-0.45f,  0.35f, 0.0f,    1.0f,  0.88f, 0.2f,   // 7: Codo inf izq
		-0.25f,  0.5f,  0.0f,    1.0f,  0.88f, 0.2f,   // 8: Codo sup izq
		-0.65f,  0.55f, 0.0f,    1.0f,  0.88f, 0.2f,   // 9: Límite amarillo inf izq
		-0.55f,  0.60f, 0.0f,    1.0f,  0.88f, 0.2f,   // 10: Límite amarillo sup izq
		-0.65f,  0.55f, 0.0f,    0.15f, 0.15f, 0.15f,  // 11: Límite NEGRO inf izq (Misma pos que 9)
		-0.55f,  0.60f, 0.0f,    0.15f, 0.15f, 0.15f,  // 12: Límite NEGRO sup izq (Misma pos que 10)
		-0.85f,  0.7f,  0.0f,    0.15f, 0.15f, 0.15f,  // 13: Punta negra izq

		// Oreja Der
		 0.2f,   0.2f,  0.0f,    1.0f,  0.88f, 0.2f,   // 14: Base der
		 0.45f,  0.35f, 0.0f,    1.0f,  0.88f, 0.2f,   // 15: Codo inf der
		 0.25f,  0.5f,  0.0f,    1.0f,  0.88f, 0.2f,   // 16: Codo sup der
		 0.65f,  0.55f, 0.0f,    1.0f,  0.88f, 0.2f,   // 17: Límite amarillo inf der
		 0.55f,  0.60f, 0.0f,    1.0f,  0.88f, 0.2f,   // 18: Límite amarillo sup der
		 0.65f,  0.55f, 0.0f,    0.15f, 0.15f, 0.15f,  // 19: Límite NEGRO inf der (Misma pos que 17)
		 0.55f,  0.60f, 0.0f,    0.15f, 0.15f, 0.15f,  // 20: Límite NEGRO sup der (Misma pos que 18)
		 0.85f,  0.7f,  0.0f,    0.15f, 0.15f, 0.15f,  // 21: Punta negra der

		 
		 // Chapita Izq
		 -0.28f, -0.20f, 0.0f,        0.9f, 0.2f, 0.2f,   // 22
		 -0.18f, -0.20f, 0.0f,        0.9f, 0.2f, 0.2f,   // 23
		 -0.18f, -0.10f, 0.0f,        0.9f, 0.2f, 0.2f,   // 24
		 -0.28f, -0.10f, 0.0f,        0.9f, 0.2f, 0.2f,   // 25

		 // Chapita Der
		  0.18f, -0.20f, 0.0f,        0.9f, 0.2f, 0.2f,   // 26
		  0.28f, -0.20f, 0.0f,        0.9f, 0.2f, 0.2f,   // 27
		  0.28f, -0.10f, 0.0f,        0.9f, 0.2f, 0.2f,   // 28
		  0.18f, -0.10f, 0.0f,        0.9f, 0.2f, 0.2f,   // 29

		  // Ojo Izq 
		  -0.25f,  0.0f, 0.0f,         0.15f, 0.15f, 0.15f,// 30
		  -0.15f,  0.0f, 0.0f,         0.15f, 0.15f, 0.15f,// 31
		  -0.15f,  0.1f, 0.0f,         0.15f, 0.15f, 0.15f,// 32
		  -0.25f,  0.1f, 0.0f,         0.15f, 0.15f, 0.15f,// 33

		  // Ojo Der 
		   0.15f,  0.0f, 0.0f,         0.15f, 0.15f, 0.15f,// 34
		   0.25f,  0.0f, 0.0f,         0.15f, 0.15f, 0.15f,// 35
		   0.25f,  0.1f, 0.0f,         0.15f, 0.15f, 0.15f,// 36
		   0.15f,  0.1f, 0.0f,         0.15f, 0.15f, 0.15f,// 37

		   // Nariz 
		   -0.02f,  0.0f, 0.0f,         0.15f, 0.15f, 0.15f,// 38
			0.02f,  0.0f, 0.0f,         0.15f, 0.15f, 0.15f,// 39
			0.0f,   0.02f, 0.0f,        0.15f, 0.15f, 0.15f // 40
	};

float verticesBoca[] = {
	
	-0.08f, -0.08f, 0.0f,       0.15f, 0.15f, 0.15f, 
	-0.04f, -0.12f, 0.0f,       0.15f, 0.15f, 0.15f, 
	 0.0f,  -0.08f, 0.0f,       0.15f, 0.15f, 0.15f, 
	 0.04f, -0.12f, 0.0f,       0.15f, 0.15f, 0.15f, 
	 0.08f, -0.08f, 0.0f,       0.15f, 0.15f, 0.15f,  
};

	unsigned int indices[] = {  
		// Estos son los indices utilizados para formar las poligonales (triangulos y cuadrados) que dan la forma a nuestro personaje
		// Barbilla
		0, 1, 2,
		// Centro cara
		1, 2, 4,
		1, 4, 3,

		// Oreja Izq
		3, 6, 7,
		6, 7, 8,
		7, 8, 9,
		8, 9, 10,       
		11, 12, 13,     

		// Oreja Der
		4, 14, 15,
		14, 15, 16,
		15, 16, 17,
		16, 17, 18,     
		19, 20, 21,

		// Chapita Izq
		22, 23, 24, 
		22, 24, 25,
		// Chapita Der
		26, 27, 28,
		26, 28, 29,
		// Ojo Izq
		30, 31, 32, 
		30, 32, 33,
		// Ojo Der
		34, 35, 36, 
		34, 36, 37,
		// Nariz
		38, 39, 40,
		
	};



	GLuint VBO, VAO,EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	// Enlazar  Vertex Array Object
	glBindVertexArray(VAO);

	//2.- Copiamos nuestros arreglo de vertices en un buffer de vertices para que OpenGL lo use
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	// 3.Copiamos nuestro arreglo de indices en  un elemento del buffer para que OpenGL lo use
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// 4. Despues colocamos las caracteristicas de los vertices
	// Configuración VAO / VBO para la cabeza
	//Posicion
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)0);
	glEnableVertexAttribArray(0);

	//Color
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)(3*sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);


	glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)

	// Configuración VAO / VBO para la Boca
	GLuint VAOBoca, VBOBoca;
	glGenVertexArrays(1, &VAOBoca);
	glGenBuffers(1, &VBOBoca);

	glBindVertexArray(VAOBoca);
	glBindBuffer(GL_ARRAY_BUFFER, VBOBoca);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesBoca), verticesBoca, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);


	//Ciclo de renderizado
	while (!glfwWindowShouldClose(window))
	{
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();

		// Render
		// Clear the colorbuffer - Fondo claro
		glClearColor(0.98f, 0.95f, 0.82f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);


		// Draw our first triangle
        ourShader.Use();

		// Rellenos de la figura
        glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(unsigned int), GL_UNSIGNED_INT, 0);

		// Boca al estilo Line Strip
		glBindVertexArray(VAOBoca);
		glLineWidth(3.0f); // Grosor de línea
		glDrawArrays(GL_LINE_STRIP, 0, 5);
        //glPointSize(10);
        //glDrawArrays(GL_POINTS,0,1);
        
        //glDrawArrays(GL_LINES,0,2);
        //glDrawArrays(GL_LINE_LOOP,0,4);
        
        //glDrawArrays(GL_TRIANGLES,0,3);
        //glDrawElements(GL_TRIANGLES, 3,GL_UNSIGNED_INT,0);

        
        
        glBindVertexArray(0);
    
		// Swap the screen buffers
		glfwSwapBuffers(window);
	}



	glfwTerminate();
	return EXIT_SUCCESS;
}

void resize(GLFWwindow* window, int width, int height)
{
	// Set the Viewport to the size of the created window
	glViewport(0, 0, width, height);
	//glViewport(0, 0, screenWidth, screenHeight);
}