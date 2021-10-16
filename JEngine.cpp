#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include "JEngine.hpp"

using namespace std;

JEngine::JEngine() {
    init();
}

JEngine::~JEngine() {
    close();
}

void JEngine::init() {
    cout << "Init" << endl;
    
    quit=false;
    
    //Initialize SDL
  if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_JOYSTICK ) < 0 )
  {
    printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
    exit(-1);
  }
  
  //Set texture filtering to linear
  if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
  {
    printf( "Warning: Linear texture filtering not enabled!" );
    exit(-1);
  }
  
  //Check for joysticks 
  if( SDL_NumJoysticks() < 1 ) 
  { 
    printf( "Warning: No joysticks connected!\n" ); 
  } 
  else 
  {
    printf("%d joysticks connected\n", SDL_NumJoysticks());
    for(int i=0; i<SDL_NumJoysticks(); i++)
    {
      //Load joystick 
      sdl_gamepads[i] = SDL_JoystickOpen(i); 
      if(sdl_gamepads[i] == NULL ) 
      { 
	printf( "Warning: Unable to open game controller %d! SDL Error: %s\n", i, SDL_GetError() ); 
	
      }
    }
    
  }
  
  
    // Get display mode
    if (SDL_GetDesktopDisplayMode(0, &sdl_display_mode) != 0) {
      printf("SDL_GetDesktopDisplayMode failed: %s", SDL_GetError());
      exit(-1);
    }
    SCREEN_WIDTH=sdl_display_mode.w;
    SCREEN_HEIGHT=sdl_display_mode.h;
    
    //Create window
    sdl_window = SDL_CreateWindow("Duck_hunter", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN);
    if( sdl_window == NULL )
    {
      printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
      exit(-1);
    }
  
  
  //Create renderer for window
  sdl_renderer = SDL_CreateRenderer( sdl_window, -1, SDL_RENDERER_ACCELERATED );
  if( sdl_renderer == NULL )
  {
    printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
    exit(-1);
  }
  
  //Initialize SDL_ttf 
  if(TTF_Init()<0) 
  {
    printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() ); 
    exit(-1);
  }
  
  //Initialize PNG loading
  if( !( IMG_Init( IMG_INIT_PNG ) & IMG_INIT_PNG ) )
  {
    printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
    exit(-1);
  }
  
  //Initialize SDL_mixer 
  if(Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 512 )<0) 
  { 
    printf( "SDL_mixer could not initialize!\n");
    exit(-1);
  }
  
}

void JEngine::close() {
    cout << "Close" << endl;
    
    
  
  //Destroy renderer  
  if(sdl_renderer!=NULL)
  {
    SDL_DestroyRenderer( sdl_renderer );
    sdl_renderer=NULL;
  }
  
  if(sdl_window != NULL)
  {
    // Destroy window
    SDL_DestroyWindow( sdl_window );
    sdl_window=NULL;
  }
  
  // Close gamepads
  for(int i=0; i<SDL_NumJoysticks(); i++)
  {
    SDL_JoystickClose(sdl_gamepads[i]);
    sdl_gamepads[i]=NULL;
  }
  
  // Exit SDL
  Mix_CloseAudio();
  TTF_Quit();
  IMG_Quit();
  SDL_Quit();
}

void JEngine::process_input(SDL_Event *e)
{
  //User requests quit
  if(e->type == SDL_QUIT 
    // User press ESC or q
    || (e->type == SDL_KEYDOWN && (e->key.keysym.sym=='q' || e->key.keysym.sym == 27))
  )
  {
    quit = 1;
  }
}

void JEngine::sync_render()
{
  unsigned int start, end, render_time; 
  
  start = SDL_GetTicks();
  
  // Count frames
  frames++;
  // Update game data
  update_game();
  
  // Render screen
  render();  
  
  
  end = SDL_GetTicks();
  render_time = end - start;
  
  // 60 fps -> 16ms
  // 30 fps -> 32ms
  // 50 fps -> 20ms
  // 100 fps -> 10ms
  
  if(render_time < 20)
  {
    //remaining = 1;
    SDL_Delay(20 - render_time);
  }
  else
  {
    printf("Render time: %ud !!!!\n", render_time);
  }  
}

void JEngine::run()
{
  //Event handler
  SDL_Event e;
  
  // Init quit flag
  quit=0;
      
  // Main game loop
  while(!quit)
  {
    //Handle events on queue
    while( SDL_PollEvent( &e ) != 0 )
    {
      process_input(&e);
    }
    
    // Update & Render
    sync_render();
  }
}

void JEngine::render() {
    //Clear screen
  SDL_SetRenderDrawColor( sdl_renderer, 0x00, 0x00, 0x00, 0xFF );
  SDL_RenderClear( sdl_renderer );
  
  // Actual rendering
  render_game();
  
  //Update screen
  SDL_RenderPresent(sdl_renderer);
}

void JEngine::update_game() {
}

void JEngine::render_game() {
}


