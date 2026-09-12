//Práctica 4: Modelado Geométrico
//Hernández Irineo Jorge Manuel
//Fecha: 11 - septiembre - 2026
//No.de cuenta : 423045291
#include<iostream>

//#define GLEW_STATIC

#include <GL/glew.h>

#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>



// Shaders
#include "Shader.h"

void Inputs(GLFWwindow *window);


const GLint WIDTH = 800, HEIGHT = 600;
//PARA MANIPULAR LA VISTA SIN TENER QUE ANDAR COMPILANDO
float movX=0.0f;
float movY=0.0f;
float movZ=-5.0f;
float rot = 0.0f;
int main() {
	glfwInit();
	//Verificación de compatibilidad 
	// Set all the required options for GLFW
	/*glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);*/

	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "Hernandez Irineo Jorge Manuel Modelado geometrico", nullptr, nullptr);

	int screenWidth, screenHeight;

	glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

	//Verificación de errores de creacion  ventana
	if (nullptr == window)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();

		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window);
	glewExperimental = GL_TRUE;

	//Verificación de errores de inicialización de glew

	if (GLEW_OK != glewInit()) {
		std::cout << "Failed to initialise GLEW" << std::endl;
		return EXIT_FAILURE;
	}


	// Define las dimensiones del viewport
	glViewport(0, 0, screenWidth, screenHeight);


	// Setup OpenGL options
	glEnable(GL_DEPTH_TEST);

	// enable alpha support
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


	// Build and compile our shader program
	Shader ourShader("Shader/core.vs", "Shader/core.frag");


	// Set up vertex data (and buffer(s)) and attribute pointers

	

	// use with Perspective Projection
	float vertices[] = {
		-0.5f, -0.5f, 0.5f, 1.0f, 0.0f,0.0f,//Front
		0.5f, -0.5f, 0.5f,  1.0f, 0.0f,0.0f,
		0.5f,  0.5f, 0.5f,  1.0f, 0.0f,0.0f,
		0.5f,  0.5f, 0.5f,  1.0f, 0.0f,0.0f,
		-0.5f,  0.5f, 0.5f, 1.0f, 0.0f,0.0f,
		-0.5f, -0.5f, 0.5f, 1.0f, 0.0f,0.0f,
		
	    -0.5f, -0.5f,-0.5f, 1.0f, 0.0f,0.0f,//Back
		 0.5f, -0.5f,-0.5f, 1.0f, 0.0f,0.0f,
		 0.5f,  0.5f,-0.5f, 1.0f, 0.0f,0.0f,
		 0.5f,  0.5f,-0.5f, 1.0f, 0.0f,0.0f,
	    -0.5f,  0.5f,-0.5f, 1.0f, 0.0f,0.0f,
	    -0.5f, -0.5f,-0.5f, 1.0f, 0.0f,0.0f,
		
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,0.0f,
		 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 0.0f,0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 0.0f,0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,0.0f,
		 0.5f,  -0.5f, 0.5f,  1.0f, 0.0f,0.0f,
      
		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,0.0f,
		-0.5f,  0.5f, -0.5f,  1.0f, 0.0f,0.0f,
		-0.5f, -0.5f, -0.5f,  1.0f, 0.0f,0.0f,
		-0.5f, -0.5f, -0.5f,  1.0f, 0.0f,0.0f,
		-0.5f, -0.5f,  0.5f,  1.0f, 0.0f,0.0f,
		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,0.0f,
		
		-0.5f, -0.5f, -0.5f, 1.0f, 0.0f,0.0f,
		0.5f, -0.5f, -0.5f,  1.0f, 0.0f,0.0f,
		0.5f, -0.5f,  0.5f,  1.0f, 0.0f,0.0f,
		0.5f, -0.5f,  0.5f,  1.0f, 0.0f,0.0f,
		-0.5f, -0.5f,  0.5f, 1.0f, 0.0f,0.0f,
		-0.5f, -0.5f, -0.5f, 1.0f, 0.0f,0.0f,
		
		-0.5f,  0.5f, -0.5f, 1.0f, 0.0f,0.0f,
		0.5f,  0.5f, -0.5f,  1.0f, 0.0f,0.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,0.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,0.0f,
		-0.5f,  0.5f,  0.5f, 1.0f, 0.0f,0.0f,
		-0.5f,  0.5f, -0.5f, 1.0f, 0.0f,0.0f,
	};




	GLuint VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	//glGenBuffers(1, &EBO);

	// Enlazar  Vertex Array Object
	glBindVertexArray(VAO);

	//2.- Copiamos nuestros arreglo de vertices en un buffer de vertices para que OpenGL lo use
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	// 3.Copiamos nuestro arreglo de indices en  un elemento del buffer para que OpenGL lo use
	/*glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);*/

	// 4. Despues colocamos las caracteristicas de los vertices

	//Posicion
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)0);
	glEnableVertexAttribArray(0);

	//Color
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);


	glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)

	
	glm::mat4 projection=glm::mat4(1);

	projection = glm::perspective(glm::radians(45.0f), (GLfloat)screenWidth / (GLfloat)screenHeight, 0.1f, 100.0f);//FOV, Radio de aspecto,znear,zfar
	//projection = glm::ortho(0.0f, (GLfloat)screenWidth, 0.0f, (GLfloat)screenHeight, 0.1f, 1000.0f);//Izq,Der,Fondo,Alto,Cercania,Lejania
	while (!glfwWindowShouldClose(window))
	{
		
		Inputs(window);
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();

		// Render
		// Clear the colorbuffer
		glClearColor(0.98f, 0.94f, 0.82f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);


		// Draw our first triangle
		ourShader.Use();
		glm::mat4 model=glm::mat4(1);
		glm::mat4 view=glm::mat4(1);
	

		view = glm::translate(view, glm::vec3(movX,movY, movZ));
		view = glm::rotate(view, glm::radians(rot), glm::vec3(0.0f, 1.0f, 0.0f));

		GLint modelLoc = glGetUniformLocation(ourShader.Program, "model");
		GLint viewLoc = glGetUniformLocation(ourShader.Program, "view");
		GLint projecLoc = glGetUniformLocation(ourShader.Program, "projection");


		glUniformMatrix4fv(projecLoc, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
	

		glBindVertexArray(VAO);
		// Obtener la ubicación del uniform de color
		GLint colorLoc = glGetUniformLocation(ourShader.Program, "objectColor");

		
		//  TORSO
		glUniform3f(colorLoc, 0.8f, 0.1f, 0.1f); // COLOR DE LA CAJA ROJO
		glm::mat4 torsoMatrix = glm::mat4(1.0f);
		torsoMatrix = glm::scale(torsoMatrix, glm::vec3(2.4f, 1.0f, 1.0f)); // ANCHO, ALTO, PROFUNDIDAD
		torsoMatrix = glm::translate(torsoMatrix, glm::vec3(0.0f, 1.5f, 0.0f));

		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(torsoMatrix));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//  ABDOMEN
		glUniform3f(colorLoc, 0.4f, 0.4f, 0.4f); // CAJA GRIS
		glm::mat4 abdomenMatrix = glm::mat4(1.0f);
		abdomenMatrix = glm::translate(abdomenMatrix, glm::vec3(0.0f, 0.65f, 0.0f));
		abdomenMatrix = glm::scale(abdomenMatrix, glm::vec3(1.5f, 0.6f, 0.8f));
		

		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(abdomenMatrix));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		
		//  CABEZA
		glUniform3f(colorLoc, 0.0f, 0.3f, 0.8f); // AZUL
		glm::mat4 cabezaMatrix = glm::mat4(1.0f);
		cabezaMatrix = glm::translate(cabezaMatrix, glm::vec3(0.0f, 2.4f, 0.0f));
		cabezaMatrix = glm::scale(cabezaMatrix, glm::vec3(0.8f, 0.8f, 0.8f));

		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(cabezaMatrix));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		// ANTENAS 
		glUniform3f(colorLoc, 0.0f, 0.3f, 0.8f);

		// IZQUIERDA
		glm::mat4 antIzq = glm::mat4(1.0f);
		antIzq = glm::translate(antIzq, glm::vec3(-0.45f, 2.85f, 0.0f));
		antIzq = glm::scale(antIzq, glm::vec3(0.12f, 0.4f, 0.12f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(antIzq));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		// DERECHA
		glm::mat4 antDer = glm::mat4(1.0f);
		antDer = glm::translate(antDer, glm::vec3(0.45f, 2.85f, 0.0f));
		antDer = glm::scale(antDer, glm::vec3(0.12f, 0.4f, 0.12f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(antDer));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//  OJOS
		glUniform3f(colorLoc, 1.0f, 0.85f, 0.0f); // Amarillo 

		// IZQUIERDO
		glm::mat4 ojoIzq = glm::mat4(1.0f);
		ojoIzq = glm::translate(ojoIzq, glm::vec3(-0.2f, 2.5f, 0.41f));
		ojoIzq = glm::scale(ojoIzq, glm::vec3(0.2f, 0.1f, 0.05f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(ojoIzq));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		// DERECHO
		glm::mat4 ojoDer = glm::mat4(1.0f);
		ojoDer = glm::translate(ojoDer, glm::vec3(0.2f, 2.5f, 0.41f));
		ojoDer = glm::scale(ojoDer, glm::vec3(0.2f, 0.1f, 0.05f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(ojoDer));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		// CADERA
		glUniform3f(colorLoc, 0.0f, 0.3f, 0.8f);
		glm::mat4 caderaMatrix = glm::mat4(1.0f);
		caderaMatrix = glm::translate(caderaMatrix, glm::vec3(0.0f, 0.2f, 0.0f));
		caderaMatrix = glm::scale(caderaMatrix, glm::vec3(1.75f, 0.4f, 0.9f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(caderaMatrix));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		// BRAZOS
		glUniform3f(colorLoc, 0.8f, 0.1f, 0.1f); //ROJO
		// IZQUIERDO
		glm::mat4 brazoIzq = glm::mat4(1.0f);
		brazoIzq = glm::translate(brazoIzq, glm::vec3(-1.4f, 1.2f, 0.0f));
		brazoIzq = glm::scale(brazoIzq, glm::vec3(0.5f, 1.4f, 0.6f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(brazoIzq));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		// DERECHO
		glm::mat4 brazoDer = glm::mat4(1.0f);
		brazoDer = glm::translate(brazoDer, glm::vec3(1.4f, 1.2f, 0.0f));
		brazoDer = glm::scale(brazoDer, glm::vec3(0.5f, 1.4f, 0.6f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(brazoDer));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//PUÑOS CERRADOS
		glUniform3f(colorLoc, 0.3f, 0.3f, 0.3f); //GRIS

		glm::mat4 punoIzq = glm::mat4(1.0f);
		punoIzq = glm::translate(punoIzq, glm::vec3(-1.4f, 0.3f, 0.0f));
		punoIzq = glm::scale(punoIzq, glm::vec3(0.4f, 0.4f, 0.4f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(punoIzq));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		glm::mat4 punoDer = glm::mat4(1.0f);
		punoDer = glm::translate(punoDer, glm::vec3(1.4f, 0.3f, 0.0f));
		punoDer = glm::scale(punoDer, glm::vec3(0.4f, 0.4f, 0.4f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(punoDer));
		glDrawArrays(GL_TRIANGLES, 0, 36);


		// MUSLOS
		glUniform3f(colorLoc, 0.5f, 0.5f, 0.5f);

		glm::mat4 musloIzq = glm::mat4(1.0f);
		musloIzq = glm::translate(musloIzq, glm::vec3(-0.45f, -0.3f, 0.0f));
		musloIzq = glm::scale(musloIzq, glm::vec3(0.6f, 0.8f, 0.6f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(musloIzq));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		glm::mat4 musloDer = glm::mat4(1.0f);
		musloDer = glm::translate(musloDer, glm::vec3(0.45f, -0.3f, 0.0f));
		musloDer = glm::scale(musloDer, glm::vec3(0.6f, 0.8f, 0.6f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(musloDer));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//PIERNAS
		glUniform3f(colorLoc, 0.0f, 0.3f, 0.8f);

		glm::mat4 botaIzq = glm::mat4(1.0f);
		botaIzq = glm::translate(botaIzq, glm::vec3(-0.45f, -1.0f, 0.0f));
		botaIzq = glm::scale(botaIzq, glm::vec3(0.55f, 1.0f, 0.65f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(botaIzq));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		glm::mat4 botaDer = glm::mat4(1.0f);
		botaDer = glm::translate(botaDer, glm::vec3(0.45f, -1.0f, 0.0f));
		botaDer = glm::scale(botaDer, glm::vec3(0.55f, 1.0f, 0.65f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(botaDer));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		// PIES
		glUniform3f(colorLoc, 0.2f, 0.2f, 0.2f);

		glm::mat4 pieIzq = glm::mat4(1.0f);
		pieIzq = glm::translate(pieIzq, glm::vec3(-0.45f, -1.65f, 0.2f));
		pieIzq = glm::scale(pieIzq, glm::vec3(0.6f, 0.3f, 1.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(pieIzq));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		glm::mat4 pieDer = glm::mat4(1.0f);
		pieDer = glm::translate(pieDer, glm::vec3(0.45f, -1.65f, 0.2f));
		pieDer = glm::scale(pieDer, glm::vec3(0.6f, 0.3f, 1.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(pieDer));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		glBindVertexArray(0);
		// Swap the screen buffers
		glfwSwapBuffers(window);
	
	}
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);


	glfwTerminate();
	return EXIT_SUCCESS;
 }

 void Inputs(GLFWwindow *window) {
	 if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)  //GLFW_RELEASE
		 glfwSetWindowShouldClose(window, true);
	 if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		 movX += 0.04f;
	 if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		 movX -= 0.04f;
	 if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS)
		 movY += 0.04f;
	 if (glfwGetKey(window, GLFW_KEY_V) == GLFW_PRESS)
		 movY -= 0.04f;
	 if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		 movZ -= 0.04f;
	 if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		 movZ += 0.04f;
	 if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
		 rot += 0.04f;
	 if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
		 rot -= 0.04f;
 }


