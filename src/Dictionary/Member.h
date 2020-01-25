#ifndef _MEMBER_
#define _MEMBER_

#include <iostream>
#include <string>

#include "Word.h"
#include "Origin.h"
#include "Definition.h"

namespace Members
{
    using std::string;
    using std::cout;

    class Member : public Words::Word , public Origins::Origin , public Definitions::Definition
    {
        public:
            Member(

                const string& word = Word().get_word(),
                
                const string& origin = Origin().get_origin(),
                
                const string& definition = Definition().get_definition()

            );

            Member(const Member& other);
            Member& operator=(const Member& other);

            void printMember() const;

            ~Member();

        private:
    };
}

#endif