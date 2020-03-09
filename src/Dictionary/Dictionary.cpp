#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

#include "Dictionary.h"

namespace
{
    using std::string;

    bool isWord(const string& phase)
    {
        return phase == "Word";
    }

    bool isOrigin(const string& phase)
    {
        return phase == "Origin";
    }

    bool isDefinition(const string& phase)
    {
        return phase == "Definition";
    }
}
namespace Dictionarys
{
    using std::cout;
    using std::cin;
    using std::cerr;
    using std::endl;

    using std::ifstream;
    using std::ofstream;

    Dictionary::Dictionary() : Phase(nullptr) , capacity(50) , used(0)
    {
        Phase = new Member [capacity];
        filename.clear();
    }
    Dictionary::Dictionary(const string& filename) : Phase(nullptr) , capacity(0) , used(0) , filename(filename)
    {
        read_from_file();
    }

    Dictionary::Dictionary(const Dictionary& other)
    {
        capacity = other.capacity;
        used = other.used;
        filename = other.filename;
        
        Phase = new Member [capacity];
        
        for(int i = 0 ; i < used ; ++i)
            Phase[i] = other.Phase[i];
    }
    
    Dictionary& Dictionary::operator=(const Dictionary& other)
    {
        if( this == &other )
            return *this;
        
        if(capacity != other.capacity )
        {
            release_dictionary();
            capacity = other.capacity;
            
            Phase = new Member [capacity];
        }

        used = other.used;

        for(int i = 0 ; i < used ; ++i)
            Phase[i] = other.Phase[i];

        filename = other.filename;

        return *this;
    }

    Dictionary::~Dictionary()
    {
        release_dictionary();
    }

    Member& Dictionary::operator[]( int index )
    {
        if( index >= used || index < 0 )
            std::cerr << "Invalid Index !" << endl;
        return Phase[ index ];
    }

    const Member& Dictionary::operator[]( int index ) const
    {
        if( index >= used || index < 0 )
            std::cerr << "Invalid Index !" << endl;
        return Phase[ index ];
    }

    int Dictionary::size() const
    {
        return used;
    }

    void Dictionary::set_filename(const string& filename)
    {
        this -> filename = filename;
    }

    void Dictionary::read_from_file()
    {
        int i = 0;
        string WordSentece , OriginSentece , DefinitionSentece;
        string lastSentence;
        string fromFile;


        release_dictionary();

        ifstream inStream;
        inStream.open(filename,std::ios_base::in);
        if(inStream.fail())
        {
            cout << "Error : File could not be opened !" << endl;
            exit(1);
        }

        while(!inStream.eof())
        {
            inStream >> fromFile;
            if( isWord(fromFile) )
                ++used;
        }

        inStream.clear();
        inStream.seekg(std::ios_base::beg);

        capacity = used * 2;
        Phase = new Member [capacity];
        
        while(!inStream.eof())
        {
            inStream >> fromFile;
            
            if( fromFile == "-" )
            {
                Phase[i].set_word(WordSentece);
                Phase[i].set_origin(OriginSentece);
                Phase[i].set_definition(DefinitionSentece);
                ++i;
                
                WordSentece.clear();
                OriginSentece.clear();
                DefinitionSentece.clear();

                continue;
            }
            else
            {
                if( isWord(fromFile) )
                    lastSentence = "Word";
                
                if( isOrigin(fromFile) )
                    lastSentence = "Origin";
                
                if( isDefinition(fromFile) )
                    lastSentence = "Definition";


                if( isWord(lastSentence) )
                    WordSentece +=  " " + fromFile;

                if( isOrigin(lastSentence) )
                    OriginSentece +=  " " + fromFile;
                
                if( isDefinition(lastSentence) )
                    DefinitionSentece +=  " " + fromFile ;
            }
        }
        
        inStream.close();
    }

    void Dictionary::write_to_file()
    {

    }

    void Dictionary::add_word_to_dictionary()
    {
        Members::Member* newList = nullptr;
        string newWord , newOrigin ,newDefinition;

        cout << "Enter the word : ";
        cin >> newWord;

        cout << "Enter the origin : ";
        cin >> newOrigin;

        cout << "Enter the definition of the word : ";
        cin >> newDefinition;

        if( used > capacity )
        {
            capacity = used * 2;
            newList = new Member [ capacity ];

            for(int i = 0 ; i < used ; ++i)
                    newList[i] = Phase[i];

            Phase = newList;
        }

        Phase[used].set_word("Word : " + newWord);
        Phase[used].set_origin("Origin : " + newOrigin);
        Phase[used].set_definition("Definition : " + newDefinition);

        ++used;
    }

    void Dictionary::remove_word(const string& word)
    {
        int index = is_in_dictionary(word);

        if( index != -1 )
        {
            for( int i = index ; i < size() ; ++i )
                Phase[i] = Phase[i+1];
            --used;
        }
        else
        {
            cout << " Removing word was not completed successfully! \n" << endl;
        }
    }
    
    int Dictionary::is_in_dictionary( const string& word )
    {
        int index = -1;

        for( int i = 0 ; i < size() ; ++ i)
            if( word == Phase[i].get_word() )
                index = i;
        
        return ( index );
    }

    void Dictionary::release_dictionary()
    {
        if(Phase == nullptr)
            return;
        
        delete [] Phase;
        Phase = nullptr;

        used = 0;
    }

    void Dictionary::printDictionary() const
    {
        if( used == 0 )
        {
            cout << "Dictionary is empty " << endl;
            return;
        }
        
        for(int i = 0 ; i < used ; ++i)
        {
            Phase[i].printMember();
            cout << endl;
        }
    }
}