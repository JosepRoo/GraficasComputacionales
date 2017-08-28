#include <string>
#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <vector>

GLuint vao;

void Initialize() {
	std::vector<glm::vec2> positions;

	//creacion del atributo de posiciones de los vertices
	//lista de vec2
	// claramente en el cpu y ram
	positions.push_back(glm::vec2(-1.0f, -1.0f));
	positions.push_back(glm::vec2(1.0f, -1.0f));
	positions.push_back(glm::vec2(0.0f, 1.0f));

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	GLuint positionsVBO;
	glGenBuffers(1, &positionsVBO);
	glBindBuffer(GL_ARRAY_BUFFER, positionsVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec2)*positions.size(), positions.data(), GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);


}

void GameLoop() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//openGl viejito, Prohibido

	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(0);

	glutSwapBuffers();
}

int main(int argc, char* argv[]) {
	//Inicializar freeglut
	//Crea ventana para poder dibujar
	glutInit(&argc, argv);

	//solicitando una version especifica de OpenGL
	glutInitContextVersion(3, 0);

	//Iniciar el contexto de OpenGL. El contexto se refiere a las capacidades que va atener nuestra aplicacion
	//Pipeline programable
	glutInitContextProfile(GLUT_CORE_PROFILE);

	//nos permite configurar eventos que ocurren en la ventana
	//en este caso cuando alguien cierra la ventana, dejamos de renderear la escena y terminamos el programa
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

	//configuramos el framebuffer. En este caso estamos slocitando un buffer
	//true color RGBA, un buffer de profundidar y un segundo buffer para renderear
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);

	glutInitWindowSize(400, 400);

	//creamos la ventana y le damos un titulo
	glutCreateWindow("Hello World GL");

	//Asociamos una funcion de render. Esta funcion se mandara a llamar para dibujar un frame
	glutDisplayFunc(GameLoop);

	//Inicializamos GLEW, y esta libreria se encarga de obtener el API de openGL de nuestra tarjeta de video
	glewInit();

	//Configurar openGL 

	//color por default del buffer del color
	glClearColor(1.0f, 1.0f, .5f, 1.0f);

	std::cout << glGetString(GL_VERSION) << std::endl;


	Initialize();
	//iniciar la aplicacion. El main se pausara en esta linea hasta que se cierre la ventana de OpenGl
	glutMainLoop();



		
	std::cin.get();
	return 0;
}