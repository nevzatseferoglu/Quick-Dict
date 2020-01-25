#include <iostream>

#include "common.h"
#include "SDL_Dictionary.h"
#include "Essential.h"
#include "cstdlib"

using namespace std;

SDL_Event event;
bool quit = false; /* Game Loop Control bool */

void loadMedia(SDL_Dictionary& Dict , const Essential& Tools);

int main(int argc , const char* argv[])
{
    Essential Tools;
    SDL_Dictionary Dictionary;

    int i = 0;
    bool flag = false;

    loadMedia(Dictionary,Tools);

    while( !quit )
    {
        
        while(SDL_PollEvent( &event )) 
        {
            switch ( event.type )
            {
                case SDL_QUIT:
                    Dictionary.close_TTF();
                    Tools.~Essential();
                    exit(1);
                break;

                case SDL_KEYDOWN:
                    if( !flag )
                        flag = true;
                    else
                        flag = false;
                break;
            }
        }

        SDL_SetRenderDrawColor( Tools.getRenderer(), 249, 235, 174, 0xFF );
        SDL_RenderClear(Tools.getRenderer());

        Dictionary.render(Tools,i);
        SDL_RenderPresent( Tools.getRenderer() );

        if( flag == true )
        {
            if( i == Dictionary.game_dict.size() -1 )
                i = 0;
            else
                ++i;
        }

        SDL_Delay(50);
    }

    Dictionary.close_TTF();

    return 0;
}
void loadMedia(SDL_Dictionary& Dict , const Essential& Tools)
{
    Dict.open_TTF();

    for(int i = 0 ; i < Dict.game_dict.size() ; ++i  )
    {
        if( !Dict.loadFromRenderedText( Dict.game_dict[i].get_word() , Dict.getColor(), Tools , i , 0 ) )
        {
            fprintf( stderr , "Failed to render text texture , getWord !\n");
            exit(-1);
        }

        if( !Dict.loadFromRenderedText( Dict.game_dict[i].get_origin() , Dict.getColor() , Tools , i , 1 ) )
        {
            fprintf( stderr , "Failed to render text texture , getOrigin !\n");
            exit(-1);
        }

        if( !Dict.loadFromRenderedText( Dict.game_dict[i].get_definition() , Dict.getColor() , Tools , i , 2 ) )
        {
            fprintf( stderr , "Failed to render text texture , getDefinition !\n");
            exit(-1);
        }
    }
    
}