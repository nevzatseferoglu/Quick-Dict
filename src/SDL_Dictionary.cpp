#include "SDL_Dictionary.h"
#include "SDL2/SDL_ttf.h"

using std::cout;
using std::cin;
using std::cerr;
using std::string;
using std::endl;

using namespace Dictionarys;

SDL_Dictionary::SDL_Dictionary()
{
    game_dict.set_filename("Dictionary.txt");
    game_dict.read_from_file();

    texture = new SDL_Texture** [game_dict.size()];
    for( int i =0 ; i < game_dict.size() ; ++i )
        texture[i] = new SDL_Texture* [3];

    textColor.r = 15;
    textColor.g = 20;
    textColor.b = 40;
    textColor.a = 255;
}

SDL_Dictionary::~SDL_Dictionary()
{
    close_TTF();
    destroyTexture(game_dict.size() , 3 );
}

void SDL_Dictionary::setColor(Uint8 r , Uint8 g , Uint8 b)
{
    textColor.r = r;
    textColor.g = g;
    textColor.b = b;
}

bool SDL_Dictionary::loadFromRenderedText(const string& str , const SDL_Color& color,const Essential& Tools , int i , int j )
{
    //Render text surface
    SDL_Surface* textSurface = TTF_RenderText_Blended( getFont(), str.c_str(), color );
    if( textSurface == NULL )
    {
        printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
    }
    else
    {
        //Create texture from surface pixels
        texture[i][j] = SDL_CreateTextureFromSurface( Tools.getRenderer() , textSurface );
        if( texture[i][j] == nullptr )
        {
            printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
        }

        //Get rid of old surface
        SDL_FreeSurface( textSurface );
    }
    
    //Return success
    return texture != NULL;
}

void SDL_Dictionary::open_TTF()
{
    font = TTF_OpenFont("TTF/RoundedEroded.ttf" , 18);
    if(font == nullptr)
    {
        cerr << " TTF could not be opened ! TTF_Error : " << TTF_GetError() << endl;
        exit(1);
    }
}

TTF_Font* SDL_Dictionary::getFont() const 
{
    return font;
}

SDL_Texture* SDL_Dictionary::getTexture(int i , int j) const
{
    return texture[i][j];
}

void SDL_Dictionary::render( const Essential& Tools , int i )
{
    //Setup the destination rectangle to be at the position we want
	SDL_Rect dst;
	dst.x = 10;
	dst.y = 10;

	//Query the texture to get its width and height to use
    
    for( int j = 0 ; j < 3 ; ++j)
    {
        SDL_QueryTexture(texture[i][j], NULL, NULL, &dst.w, &dst.h);
        SDL_RenderCopy(Tools.getRenderer(), texture[i][j], NULL, &dst);
        dst.y += 100;
    }
}

SDL_Color& SDL_Dictionary::getColor()
{
    return textColor;
}

void SDL_Dictionary::close_TTF()
{
    TTF_CloseFont(font);
}

void SDL_Dictionary::destroyTexture( int k ,int p)
{
    for( int i = 0 ; i < k ; ++i )
        for( int j = 0 ; j < p ; ++j)
            SDL_DestroyTexture(texture[i][j]);
}
