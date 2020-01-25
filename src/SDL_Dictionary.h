#if !defined(_CLASS_)
#define _CLASS_

#include "common.h"
#include "Essential.h"

using namespace Dictionarys;

class SDL_Dictionary 
{
    public:

        SDL_Dictionary();
        ~SDL_Dictionary();

        bool loadFromRenderedText(const string& str , const SDL_Color& color,const Essential& Tools , int i , int j );

        void open_TTF();
        void close_TTF(); 

        void setColor(Uint8 r , Uint8 g , Uint8 b);

        TTF_Font* getFont() const;
        SDL_Texture* getTexture(int i , int j) const;
        SDL_Color& getColor();

        void render(const Essential& Tools  , int i);
        void destroyTexture(int k ,int p);

        Dictionary game_dict;

    private:
        TTF_Font* font;
        SDL_Texture*** texture;
        SDL_Color textColor;

};

#endif