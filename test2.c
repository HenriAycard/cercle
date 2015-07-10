 #include <SDL2/SDL.h>
 #include <stdlib.h>
 #include <stdio.h>
 #include <math.h>
SDL_Window* fenetre; // Les Variables déclarées en dehors des fonctions sont accesibles depuis tout le fichier
SDL_Renderer* renderer; // Ne pas en abuser non plus ...


int Draw_Cercle(SDL_Renderer* renderer)
{
  int an = 0;
  float ra = 1;
  int x = 0;
  int y = 0;
  int ray = 250;

  while (an < 360){
    ra = (M_PI*(float)an/180.0);
    x =ray * cos(ra) + 500;
    y =ray * sin(ra) + 500;
    SDL_RenderDrawPoint(renderer, x, y);
    an++;
  }
  SDL_RenderPresent(renderer);
}
     
int init()
{
  if(SDL_VideoInit(NULL) < 0)
    return EXIT_FAILURE;
  fenetre = SDL_CreateWindow("TABLE" , SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED , 1000 , 800 , SDL_WINDOW_RESIZABLE);
  if(fenetre == NULL)
    return EXIT_FAILURE;
  renderer = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if(renderer == NULL)
    return EXIT_FAILURE;
}
     
int clean()
{
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(fenetre);
  SDL_Quit();
}
     
int main()
{
  if (init() == EXIT_FAILURE)
    return (EXIT_FAILURE); // Appeler au début;
     
  int terminer = 0;
  SDL_Event evenements;
  SDL_RenderClear(renderer);   
  // Appeler votre fonction de dessin ici;
  while(!terminer)
    {
      Draw_Cercle(renderer);
      if (SDL_PollEvent(&evenements) == 1)
	{
	  if(evenements.window.event == SDL_WINDOWEVENT_CLOSE
	     || evenements.key.keysym.sym == SDLK_ESCAPE)
	    terminer = 1;
	};
    }
     
  clean(); // Appeler a la fin !;
  return (EXIT_SUCCESS);
}

