#include <iostream>
#include <SDL.h>

SDL_Renderer* renderer = NULL;

void tahta();
void clickUp(int x1, int y1);
void clickDown(int x1,int y1);
SDL_bool done = SDL_FALSE;
int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO) == 0) {
		SDL_Window* window = NULL;

		
		if (SDL_CreateWindowAndRenderer(1280, 720, 0, &window, &renderer) == 0) {
			
			
			SDL_SetWindowTitle(window, "CHESS by Osman v2");
			//SDL_SetWindowResizable(window, SDL_TRUE);
			//SDL_CreateWindowAndRenderer(640, 480, SDL_WINDOW_OPENGL, &window, &renderer);
			SDL_Event event;
			while (!done) 
			{

				
				


					while (SDL_PollEvent(&event)) {
						
						
						if (event.button.type == SDL_MOUSEBUTTONDOWN)
						{
							clickDown(event.button.x, event.button.y);

						}
						
						if (event.button.type == SDL_MOUSEBUTTONUP)
						{
							clickUp(event.button.x, event.button.y);
						}
					
						if (event.type == SDL_QUIT) {

							done = SDL_TRUE;

						}
						



					}

					SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);


					tahta();







					SDL_RenderPresent(renderer);

					//done = SDL_TRUE;
				
			}
		}

		if (renderer) {
			SDL_DestroyRenderer(renderer);
		}
		if (window) {
			SDL_DestroyWindow(window);
		}
	}
	SDL_Quit();
	return 0;
}