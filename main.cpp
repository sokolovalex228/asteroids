#include <X11/X.h>
#include <X11/keysym.h>
#include <X11/extensions/Xrandr.h>
#include <GL/glut.h>
#include <stdio.h>
#include <unistd.h>
#include <jansson.h>

#include "GameAsteroids.h"

static int gWinId = 0;

typedef struct{ int x; int y; }t_size;

t_size getScreenSize()
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

				t_size size
				{
					pXRRScreenSize[indexConfig].width,
					pXRRScreenSize[indexConfig].height,
				};

				XCloseDisplay(pDisplay);

				return size;
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

	return {0, 0};
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
	(void)x;
	(void)y;

	switch (key)
	{
		case 27: // Escape key
		{
			glutDestroyWindow(gWinId);
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
#if 1
	char buff[1024];
	getcwd(buff, sizeof(buff));
	printf("getcwd(%s)\n", buff);
	fflush(stdout);
#endif

	t_size sizeScreen = getScreenSize();

	if (0 < sizeScreen.x)
	{
		glutInit(&argc, argv);

		if (0 != (gWinId = glutCreateWindow("Asteroids")))
		{
			int widthWindow = 480;
			int heightWindow = 800;

			int xWindow = (sizeScreen.x - widthWindow) / 2;
			int yWindow = (sizeScreen.y - heightWindow) / 2;

			glutInitWindowSize(widthWindow, heightWindow);
			glutInitWindowPosition(xWindow, yWindow);

			glutPositionWindow(xWindow, yWindow);
			glutKeyboardFunc(onKeyboard);
			glutMouseFunc(onMouseClick);
			glutReshapeFunc(onResize);
			//glutMotionFunc(OnMouseMove);
			glutPassiveMotionFunc(onMouseMove);
			glutReshapeWindow(widthWindow, heightWindow);

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

