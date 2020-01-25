#include <iostream>
#include <string>
#include "Origin.h"

namespace Origins
{
    using std::string;
    using std::cout;
    using std::cin;

    Origin::Origin() : origin("Undefined")
    {
        /* Intentioanlly left blank */
        /* File Operation Coming */
    }
    Origin::Origin(const string& origin) : origin(origin)
    {
        /* Intentioanlly left blank */
        /* File Operation Coming */
    }
    Origin::Origin(const Origin& other) : origin(other.origin)
    {
        /* Intentioanlly left blank */
        /* File Operation Coming */
    }
    Origin& Origin::operator=(const Origin& other)
    {
        if(this == &other)
            return *this;
        
        origin = other.origin;

        return *this;
    }

    Origin::~Origin()
    {
        /* File Operation Coming */
    }
    
    void Origin::set_origin(const string& origin)
    {
        this -> origin = origin;
    }
    string Origin::get_origin() const
    {
        return origin;
    }
}