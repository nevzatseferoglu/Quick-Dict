#include <iostream>
#include "Word.h"

namespace Words
{
    using std::string;
    using std::cout;
    using std::cin;

    Word::Word() : word("Undefined")
    {
        /* Intentionally left blank */
    }
    Word::Word(const string& word) : word(word)
    {
        /* Intentionally left blank */
    }
    Word::Word(const Word& other) : word(other.word)
    {

    }
    Word& Word::operator=(const Word& other)
    {
        if(this == &other)
            return *this;
        
        word = other.word;

        return *this;
    }

    Word::~Word()
    {
        
    }
    
    void Word::set_word(const string& word)
    {
        this -> word = word;
    }
    string Word::get_word() const
    {
        return word;
    }
}