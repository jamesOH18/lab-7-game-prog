#include <Game.h>

bool updatable = false;

//gpp::Vector3 v3; 


Game::Game() : window(VideoMode(800, 600), "OpenGL Cube")
{
	index = glGenLists(1);

}

Game::~Game(){}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning){

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		draw();
	}

}

void Game::initialize()
{
	v3[0] = { -1.0f,-1.0f,1.0f };
	v3[1] = { 1.0f,-1.0f,1.0f };
	v3[2] = { 1.0f,1.0f,1.0f };
	v3[3] = { -1.0f,1.0f,1.0f };
	v3[4] = { -1.0f,-1.0f,-1.0f };
	v3[5] = { 1.0f,-1.0f,-1.0f };
	v3[6] = { 1.0f,1.0f,-1.0f };
	v3[7] = { -1.0f,1.0f,-1.0f };

	isRunning = true;

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
	glTranslatef(0, 0, -8);
	// glNewList(index, GL_COMPILE);
	// Creates a new Display List
	// Initalizes and Compiled to GPU
	// https://www.opengl.org/sdk/docs/man2/xhtml/glNewList.xml
	glNewList(index, GL_COMPILE);
	glBegin(GL_TRIANGLES);
	{
		//Front Face
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(v3[0].x,v3[0].y,v3[0].z);
		glVertex3f(v3[1].x, v3[1].y, v3[1].z);
		glVertex3f(v3[2].x, v3[2].y, v3[2].z);
		
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(v3[2].x, v3[2].y, v3[2].z);
		glVertex3f(v3[3].x, v3[3].y, v3[3].z);
		glVertex3f(v3[0].x, v3[0].y, v3[0].z);
		

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(v3[0].x, v3[0].y, v3[0].z);
		glVertex3f(v3[1].x, v3[1].y, v3[1].z);
		glVertex3f(v3[5].x, v3[5].y, v3[5].z);

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(v3[5].x, v3[5].y, v3[5].z);
		glVertex3f(v3[4].x, v3[4].y, v3[4].z);
		glVertex3f(v3[0].x, v3[0].y, v3[0].z);


		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(v3[1].x, v3[1].y, v3[1].z);
		glVertex3f(v3[5].x, v3[5].y, v3[5].z);
		glVertex3f(v3[6].x, v3[6].y, v3[6].z);

		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(v3[6].x, v3[6].y, v3[6].z);
		glVertex3f(v3[2].x, v3[2].y, v3[2].z);
		glVertex3f(v3[1].x, v3[1].y, v3[1].z);
		
		
		glColor3f(1.0f, 0.0f, 1.0f);
		glVertex3f(v3[3].x, v3[3].y, v3[3].z);
		glVertex3f(v3[2].x, v3[2].y, v3[2].z);
		glVertex3f(v3[6].x, v3[6].y, v3[6].z);

		glColor3f(1.0f, 0.0f, 1.0f);
		glVertex3f(v3[6].x, v3[6].y, v3[6].z);
		glVertex3f(v3[7].x, v3[7].y, v3[7].z);
		glVertex3f(v3[3].x, v3[3].y, v3[3].z);

		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(v3[3].x, v3[3].y, v3[3].z);
		glVertex3f(v3[0].x, v3[0].y, v3[0].z);
		glVertex3f(v3[4].x, v3[4].y, v3[4].z);

		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(v3[4].x, v3[4].y, v3[4].z);
		glVertex3f(v3[7].x, v3[7].y, v3[7].z);
		glVertex3f(v3[3].x, v3[3].y, v3[3].z);

		glColor3f(20.0f, 0.0f, 1.0f);
		glVertex3f(v3[4].x, v3[4].y, v3[4].z);
		glVertex3f(v3[5].x, v3[5].y, v3[5].z);
		glVertex3f(v3[6].x, v3[6].y, v3[6].z);

		glColor3f(20.0f, 0.0f, 1.0f);
		glVertex3f(v3[6].x, v3[6].y, v3[6].z);
		glVertex3f(v3[7].x, v3[7].y, v3[7].z);
		glVertex3f(v3[4].x, v3[4].y, v3[4].z);

		
	}
	glEnd();
	glEndList();
}

void Game::update()
{
	elapsed = clock.getElapsedTime();

	if (elapsed.asSeconds() >= 1.0f)
	{
		clock.restart();

		if (!updatable)
		{
			updatable = true;
		}
		else
			updatable = false;
	}

	if (updatable)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			rotationAngle += 0.005f;

			if (rotationAngle > 360.0f)
			{
				rotationAngle -= 360.0f;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			rotationAngle -= 0.005f;

			if (rotationAngle < 0.0f)
			{
				rotationAngle += 360.0f;
			}
		}
	}
	
	cout << "Update up" << endl;
}

void Game::draw()
{
	cout << "Drawing" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	cout << "Drawing Cube " << endl;
	//glLoadIdentity();
	glRotatef(rotationAngle, 0, 0, 1); // Rotates the camera on Y Axis

	glCallList(1);

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

