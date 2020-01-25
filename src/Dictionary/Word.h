#ifndef _WORD_
#define _WORD_

#include <iostream>
#include <string>

namespace Words
{
    using std::string;

    class Word
    {
        public:
            Word();
            Word(const string& word);
            Word(const Word& other);
            Word& operator=(const Word& other);

            ~Word();
            
            void set_word(const string& word);
            string get_word() const;

        private:
            string word;
    };
}

#endif