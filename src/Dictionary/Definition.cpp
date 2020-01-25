#include <iostream>
#include <string>
#include "Definition.h"

namespace Definitions
{
    using std::string;
    using std::cout;
    using std::cin;

    Definition::Definition() : Definition("Undefined")
    {
        /* Intentioanlly left blank */
        /* File Operation Coming */
    }
    Definition::Definition(const string& definition) : definition(definition)
    {
        /* Intentioanlly left blank */
        /* File Operation Coming */
    }
    Definition::Definition(const Definition& other) : definition(other.definition)
    {
        /* Intentioanlly left blank */
        /* File Operation Coming */
    }
    Definition& Definition::operator=(const Definition& other)
    {
        if(this == &other)
            return *this;
        
        definition = other.definition;

        return *this;
    }

    Definition::~Definition()
    {
        /* File Operation Coming */
    }
    
    void Definition::set_definition(const string& definition)
    {
        this -> definition = definition;
    }
    string Definition::get_definition() const
    {
        return definition;
    }
}