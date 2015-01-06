#include <X11/X.h>
#include <X11/keysym.h>
#include <X11/extensions/Xrandr.h>
#include <GL/glut.h>
#include <stdio.h>
#include <unistd.h>
#include <jansson.h>

#include "GameAsteroids.h"

static int g_win_id = 0;

bool getScreenSize(int* pWidth, int* pHeight)
{
	uzing(Display*, pDisplay, XOpenDisplay(NULL))
	{
		int numScreens;

		uzing(XRRScreenSize*, pXRRScreenSize, XRRSizes(pDisplay, 0, &numScreens))
		{
			Window aWindowDesktop = RootWindow(pDisplay, 0);

			uzing(XRRScreenConfiguration*, pXRRScreenConfiguration, XRRGetScreenInfo(pDisplay, aWindowDesktop))
			{
				Rotation aRotation;
				SizeID indexConfig = XRRConfigCurrentConfiguration(pXRRScreenConfiguration, &aRotation);

				*pWidth = pXRRScreenSize[indexConfig].width;
				*pHeight = pXRRScreenSize[indexConfig].height;

				XCloseDisplay(pDisplay);

				return true;
			}
			else
			{
				printf("Error: XRRGetScreenInfo\n");
				XCloseDisplay(pDisplay);
			}
		}
		else
		{
			printf("Error: XRRSizes\n");
			XCloseDisplay(pDisplay);
		}
	}
	else
	{
		printf("Error: XOpenDisplay\n");
	}

	return false;
}

void onDisplay()
{
	gameAsteroids.render();

	glClearColor((float) rand() / RAND_MAX, (float) rand() / RAND_MAX, (float) rand() / RAND_MAX, 1.0);
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

	usleep(100 * 1000);

	glutSwapBuffers();
}

void onKeyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 27: // Escape key
		{
			glutDestroyWindow(g_win_id);
			printf("exit\n");

			exit(0);
			break;
		}
	}

	glutPostRedisplay();
}

void onMouseMove(int x, int y)
{
	gameAsteroids.mouseMove(x, y);
}

void onMouseClick(int button, int state, int x, int y)
{
	switch (button)
	{
		case GLUT_LEFT_BUTTON:
		{
			if (GLUT_UP == state)
			{
				gameAsteroids.mouseLeft(x, y, false);
			}
			else if (GLUT_DOWN == state)
			{
				gameAsteroids.mouseLeft(x, y, true);
			}

			break;
		}
	}
}

void onResize(int width, int height)
{
	gameAsteroids.resize(width, height);
}

int main(int argc, char** argv)
{
	int width = 480;
	int height = 800;
	int widthScreen;
	int heightScreen;

	char buff[1024];
	getcwd(buff, sizeof(buff));

	printf("==%s\n", buff);

	if (true == getScreenSize(&widthScreen, &heightScreen))
	{
		int x = (widthScreen - width) / 2;
		int y = (heightScreen - height) / 2;

		printf("cwd:");
		fflush(stdout);
		system("pwd");

		glutInit(&argc, argv);

		if (0 != (g_win_id = glutCreateWindow("Asteroids")))
		{
			glutInitWindowSize(width, height);
			glutInitWindowPosition(x, y);

			glutPositionWindow(x, y);
			glutKeyboardFunc(onKeyboard);
			glutMouseFunc(onMouseClick);
			glutReshapeFunc(onResize);
			//glutMotionFunc(OnMouseMove);
			glutPassiveMotionFunc(onMouseMove);
			glutReshapeWindow(width, height);

			glutIdleFunc(onDisplay);
			glutDisplayFunc(onDisplay);

			gameAsteroids.initialize();

			glutMainLoop();
		}
		else
		{
			printf("Error: 0=glutCreateWindow\n");
		}
	}
	else
	{
		printf("Error: getScreenSize\n");
	}

	return 0;
}

