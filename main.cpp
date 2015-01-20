#include "SDL2/SDL.h"

#include "GameAsteroids.h"

int main(int argc, char* argv[])
{
//	(void)argc;
//	(void)argv;

	glutInit(&argc, argv);

	SDL_Init(SDL_INIT_VIDEO);

	int widthWindow = 480;
	int heightWindow = 800;
	bool gameRunning = true;

	uzing(SDL_Window*, pSDL_Window, SDL_CreateWindow("Asteroids", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, widthWindow, heightWindow, SDL_WINDOW_OPENGL))
	{
		uzing(SDL_GLContext, pSDL_GLContext, SDL_GL_CreateContext(pSDL_Window))
		{
			SDL_GL_MakeCurrent(pSDL_Window, pSDL_GLContext);

			gameAsteroids.resize(widthWindow, heightWindow);
			gameAsteroids.initialize();

			SDL_Event event;

			while(true == gameRunning)
			{
				while(SDL_PollEvent(&event))
				{
					switch(event.type)
					{
						case SDL_MOUSEMOTION:
						{
							gameAsteroids.mouseMove(event.motion.x, event.motion.y);
							break;
						}

						case SDL_MOUSEWHEEL:
						{
							break;
						}

						case SDL_MOUSEBUTTONDOWN:
						{
							switch(event.button.button)
							{
								case SDL_BUTTON_LEFT:
									gameAsteroids.mouseLeft(event.button.x, event.button.y, true);
									break;
							}

							break;
						}

						case SDL_MOUSEBUTTONUP:
						{
							switch(event.button.button)
							{
								case SDL_BUTTON_LEFT:
									gameAsteroids.mouseLeft(event.button.x, event.button.y, false);
									break;
							}

							break;
						}

						case SDL_WINDOWEVENT_RESIZED:
						{
							gameAsteroids.resize(event.window.data1, event.window.data2);
							break;
						}

						case SDL_KEYDOWN:
						{
							printf("Key press detected\n");
							break;
						}

						case SDL_KEYUP:
						{
							SDL_Keycode keyPressed = event.key.keysym.sym;

							switch(keyPressed)
							{
								case SDLK_ESCAPE:
								{
									gameRunning = false;
									break;
								}
							}

							break;
						}

						case SDL_QUIT:
						{
							gameAsteroids.done();
							gameRunning = false;
							break;
						}

						default:
							break;
					}
				}

				gameAsteroids.draw();

				SDL_GL_SwapWindow(pSDL_Window);

				SDL_Delay(100);
			}

			SDL_GL_DeleteContext(pSDL_GLContext);
		}
		else
		{
			printf("Error: SDL_GL_CreateContext\n");
		}

		SDL_DestroyWindow(pSDL_Window);
	}
	else
	{
		printf("Error: SDL_CreateWindow\n");
	}

	SDL_Quit();

	return true;
}

