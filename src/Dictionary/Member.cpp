#include <iostream>
#include <string>
#include "Member.h"

namespace Members
{
    using std::string;
    using std::cout;
    using std::endl;

    Member::Member(const string& word,const string& origin , const string& definition) : Word(word) , Origin(origin) ,Definition(definition) 
    {
        /* Intentionally left blank */
    }
    Member::Member(const Member& other) : Word(other) , Origin(other) ,Definition(other)
    {
        /* Intentionally left blank */
    }
    Member& Member::operator=(const Member& other)
    {
        Word::operator=(other);
        Origin::operator=(other);
        Definition::operator=(other);
        
        return *this;
    }

    Member::~Member()
    {

    }
    
    void Member::printMember() const
    {
        cout << "========================================" << endl;
        cout << get_word() << endl;
        cout << get_origin() << endl;
        cout << get_definition() << endl;
        cout << "========================================" << endl;
    }
}