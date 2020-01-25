#include "Essential.h"

using namespace std;

Essential::Essential()
{
    initFlag = SDL_INIT_EVERYTHING;
    rendererFlag = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC ;
    windowFlag = SDL_WINDOW_OPENGL;

    if(SDL_Init(initFlag) < 0)
    {
        cerr << "SDL could not be initialized ! SDL Error : " << SDL_GetError();
        exit(-1); // escape statement to exit
    }

    setWindow(SDL_CreateWindow("Quick Dictionary",
                        SDL_WINDOWPOS_CENTERED,
                        SDL_WINDOWPOS_CENTERED,
                        WINDOW_WIDTH,
                        WINDOW_HEIGHT,
                        windowFlag));
                        
    if( !getWindow() )
    {
        cerr << "Window could not be initialized ! SDL Error : " << SDL_GetError() << endl;
        exit(-1); // escape statement to exit
    }
    
    setRenderer(SDL_CreateRenderer( window , rendererIndex , rendererFlag ));
    if( !getRenderer() )
    {
        cerr << "Renderer could not be initialized ! SDL Error : " << SDL_GetError() << endl;
        exit(-1);
    }

    if( TTF_Init() )
    {
        fprintf(stderr,"SDL_ttf could not be initialized! SDL_ttf Error : %s\n",TTF_GetError());
        exit(-1);
    }
}

Essential::~Essential()
{
    SDL_DestroyRenderer(getRenderer());
    SDL_DestroyWindow(getWindow());
    SDL_Quit();
}


const int Essential::getWindowWidth() const
{
    return WINDOW_WIDTH;
}

const int Essential::getWindowHeight() const
{
    return WINDOW_HEIGHT;
}

void Essential::setRenderer(SDL_Renderer* renderer)
{
    this -> renderer = renderer;
}

void Essential::setWindow(SDL_Window* window)
{
    this -> window = window;
}

SDL_Window* Essential::getWindow() const
{
    return window;
}

SDL_Renderer* Essential::getRenderer() const
{
    return renderer;
}
