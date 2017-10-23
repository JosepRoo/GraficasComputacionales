//Examen Practico 2 parcial
//Alumno: Josep Romagosa Llorden A01374637
//Fecha: 23/Octubre/2017


#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <glm/glm.hpp>
#include <vector>
#include "Mesh.h"
#include "ShaderProgram.h"
#include "Transform.h"
#include "Camera.h"

Mesh _mesh;
ShaderProgram _shaderProgram;
Transform _transform;
Transform _transform2;
Camera _camera;
//Grados para el giro de la geometria 1
float deg = 0;
int direccion = 1.0f;

void Initialize()
{
	// Creando toda la memoria que el programa va a utilizar.

	// CreaciÛn del atributo de posiciones de los vÈrtices.
	// Lista de vec2
	// Claramente en el CPU y RAM
	std::vector<glm::vec3> positions;
	std::vector<unsigned int> indices;
	std::vector<glm::vec3> colors;
	
	//Posiciones de la pir·mide
	positions.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	positions.push_back(glm::vec3(1.0f, -1.0f, 1.0f));
	positions.push_back(glm::vec3(1.0f, -1.0f, -1.0f));
	positions.push_back(glm::vec3(-1.0f, -1.0f, -1.0f));
	positions.push_back(glm::vec3(-1.0f, -1.0f, 1.0f));

	//Indices de la pir·mide

	//Cara triangular 1
	indices.push_back(0);
	indices.push_back(1);
	indices.push_back(2);

	//Cara triangular 2
	indices.push_back(0);
	indices.push_back(2);
	indices.push_back(3);

	//Cara triangular 3
	indices.push_back(0);
	indices.push_back(3);
	indices.push_back(4);

	//Cara triangular 1
	indices.push_back(0);
	indices.push_back(4);
	indices.push_back(1);

	//Base cuadrada
	indices.push_back(1);
	indices.push_back(3);
	indices.push_back(2);
	indices.push_back(4);
	indices.push_back(3);
	indices.push_back(1);
	


	//Colores por vÈrtice
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));

	_mesh.CreateMesh(5);
	_mesh.SetPositionAttribute(positions, GL_STATIC_DRAW, 0);
	_mesh.setIndices(indices, GL_STATIC_DRAW);
	_mesh.SetColorAttribute(colors, GL_STATIC_DRAW, 1);

	_shaderProgram.createProgram();
	_shaderProgram.attachShader("Default.vert", GL_VERTEX_SHADER);
	_shaderProgram.attachShader("Default.frag", GL_FRAGMENT_SHADER);
	_shaderProgram.setAttribute(0, "VertexPosition");
	_shaderProgram.setAttribute(1, "VertexColor");
	_shaderProgram.linkProgram();
	_camera.setPosition(0,0,25);
	_transform.setScale(3, 3, 3);

	_transform2.SetPosition(0.0f, 0.0f, 0.0f);
	_transform2.SetScale(0.5f, 0.5f, 0.5f);
}

void GameLoop()
{
	// Limpiamos el buffer de color y el buffer de profunidad.
	// Siempre hacerlo al inicio del frame
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	_shaderProgram.Activate();
	_shaderProgram.SetUniformMatrix("mvpMatrix",_camera.getViewProjection() * _transform.getModelMatrix());
	_mesh.Draw(GL_TRIANGLES);
	deg += .3f;
	//RotaciÛn de la geometrÌa 1
	_transform.setPosition(5 * glm::cos(glm::radians(deg)), 5 * glm::sin(glm::radians(deg)), 0.0f);
	_transform.rotate(.3f, .3f, .3f, true);
	_shaderProgram.deactivate();

	// Escala de la segunda gemoetria
	_transform2.Rotate(-0.3f, -0.3f, -0.3f, true);

	if (direccion == 0) {

		if (_transform2.GetScale().x <= 0.25f) {
			direccion = 1;
		}
		_transform2.SetScale(_transform2.GetScale().x - 0.1f,_transform2.GetScale().y - 0.1f,_transform2.GetScale().z - 0.1f);

	} else {

		if (_transform2.GetScale().x >= 1.0f) {
			direccion = 0;
		}
		_transform2.SetScale(_transform2.GetScale().x + 0.1f,_transform2.GetScale().y + 0.1f,_transform2.GetScale().z + 0.1f);

	}

	_shaderProgram.Activate();
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform2.GetModelMatrix());
	_mesh.Draw(GL_TRIANGLES);
	_shaderProgram.Deactivate();

	// Cuando terminamos de renderear, cambiamos los buffers.
	glutSwapBuffers();
}

void Idle()
{
	// Cuando OpenGL entra en modo de reposo 
	// (para guardar bateria, por ejemplo)
	// le decimos que vuelva a dibujar ->
	// Vuelve a mandar a llamar GameLoop
	glutPostRedisplay();
}

void ReshapeWindow(int width, int height)
{
	glViewport(0, 0, width, height);
}

int main(int argc, char* argv[])
{
	// Inicializar freeglut
	// Freeglut se encarga de crear una ventana
	// en donde podemos dibujar
	glutInit(&argc, argv);
	// Solicitando una versiÛn especÌfica de OpenGL.
	glutInitContextVersion(4, 4);
	// Iniciar el contexto de OpenGL. El contexto se refiere
	// a las capacidades que va a tener nuestra aplicaciÛn
	// gr·fica.
	// En este caso estamos trabajando con el pipeline programable.
	glutInitContextProfile(GLUT_CORE_PROFILE);
	// Freeglut nos permite configurar eventos que ocurren en la ventana.
	// Un evento que nos interesa es cuando alguien cierra la ventana.
	// En este caso, simplemente dejamos de renderear la esscena y terminamos el programa.
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	// Configuramos el framebuffer. En este caso estamos solicitando un buffer
	// true color RGBA, un buffer de profundidad y un segundo buffer para renderear.
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	// Iniciar las dimensiones de la ventana (en pixeles)
	glutInitWindowSize(400, 400);
	// Creamos la ventana y le damos un tÌtulo.
	glutCreateWindow("Hello World GL");
	// Asociamos una funciÛn de render.
	//Esta funciÛn se mandar· a llamar para dibujar un frame.
	glutDisplayFunc(GameLoop);
	// Asociamos una funciÛn para el cambio de resoluciÛn
	// de la ventana. Freeglut la va a mandar a llamar
	// cuando alguien cambie el tamaÒo de la venta.
	glutReshapeFunc(ReshapeWindow);
	// Asociamos la funciÛn que se mandar· a llamar
	// cuando OpenGL entre en modo de reposo.
	glutIdleFunc(Idle);

	// Inicializar GLEW. Esta librerÌa se encarga de obtener el API de OpenGL de
	// nuestra tarjeta de video. SHAME ON YOU MICROSOFT.
	glewInit();

	// Configurar OpenGL. Este es el color por default del buffer de color
	// en el framebuffer.
	glClearColor(1.0f, 1.0f, 0.5f, 1.0f);
	// Ademas de solicitar el buffer de profundidad, tenemos
	// que decirle a OpenGL que lo queremos activo
	glEnable(GL_DEPTH_TEST);
	// Activamos el borrado de caras traseras.
	// Ahora todos los triangulos que dibujemos deben estar en CCW
	glEnable(GL_CULL_FACE);
	// No dibujar las caras traseras de las geometrÌas.
	glCullFace(GL_BACK);

	std::cout << glGetString(GL_VERSION) << std::endl;

	// ConfiguraciÛn inicial de nuestro programa.
	Initialize();

	// Iniciar la aplicaciÛn. El main se pausar· en esta lÌnea hasta que se cierre
	// la venta de OpenGL.
	glutMainLoop();

	return 0;
}
