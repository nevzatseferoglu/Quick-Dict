#ifndef _DICTIONARY_
#define _DICTIONARY_

#include <iostream>
#include <string>

#include "Member.h"

namespace Dictionarys
{
    using std::string;
    using std::cout;
    using namespace Members;

    class Dictionary : Members::Member
    {
        public:
            Dictionary();
            Dictionary(const string& filename);
            
            Dictionary(const Dictionary& other);
            Dictionary& operator=(const Dictionary& other);
            ~Dictionary();

            Member& operator[]( int index );
            const Member& operator[]( int index ) const;
            
            int size() const;

            void set_filename(const string& filename);
            void read_from_file();
            void write_to_file();
            
            void add_word_to_dictionary();
            void remove_word(const string& word);
            void release_dictionary();
            
            void printDictionary() const;

        private:
            int is_in_dictionary( const string& word );
            Members::Member* Phase;
            int capacity;
            int used;
            string filename;
    };
}

#endif