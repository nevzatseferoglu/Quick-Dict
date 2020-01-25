#if !defined(_ESSENTIAL)
#define _ESSENTIAL

#include "common.h"

class Essential
{
    public:

        Essential();
        ~Essential();

        const int getWindowWidth() const;
        const int getWindowHeight() const;

        SDL_Window* getWindow() const;
        SDL_Renderer* getRenderer() const;

        void setRenderer(SDL_Renderer* renderer);
        void setWindow(SDL_Window* window);

        

    private:

    SDL_Window* window;
    SDL_Renderer* renderer;

    const int WINDOW_WIDTH = 1200;
    const int WINDOW_HEIGHT = 500;

    Uint32 initFlag;
    Uint32 rendererFlag;
    Uint32 windowFlag;
    const int rendererIndex = -1;

};


#endif