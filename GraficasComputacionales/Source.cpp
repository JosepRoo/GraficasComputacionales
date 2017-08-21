#include <string>
#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>

void GameLoop() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//openGl viejito, Prohibido

	glBegin(GL_TRIANGLES);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-1.0f,-1.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(1.0f, -1.0f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.0f, 1.0f);

	glEnd();

	glutSwapBuffers();
}

int pruebaTriangulo(int argc, char* argv[]) {
	//Inicializar freeglut
	//Crea ventana para poder dibujar
	glutInit(&argc, argv);

	//Iniciar el contexto de OpenGL. El contexto se refiere a las capacidades que va atener nuestra aplicacion
	//Pipeline clasico
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

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

	//iniciar la aplicacion. El main se pausara en esta linea hasta que se cierre la ventana de OpenGl
	glutMainLoop();

		
	std::cin.get();
	return 0;
}