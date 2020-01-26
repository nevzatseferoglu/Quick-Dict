#include <iostream>
#include <random>

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

    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> dist_DictionarySize(0,Dictionary.game_dict.size() - 1)   ;

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
            i = dist_DictionarySize(rng);

        SDL_Delay(75);
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
