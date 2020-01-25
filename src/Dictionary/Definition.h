#ifndef _DEFINITION_
#define _DEFINITION_

#include <iostream>
#include <string>

namespace Definitions
{
    using std::string;

    class Definition
    {
        public:
            Definition();
            Definition(const string& Definition);
            Definition(const Definition& other);
            Definition& operator=(const Definition& other);

            ~Definition();
            
            void set_definition(const string& Definition);
            string get_definition() const;

        private:
            string definition;
    };
}

#endif