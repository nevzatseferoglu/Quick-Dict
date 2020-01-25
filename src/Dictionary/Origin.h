#ifndef _ORIGIN_
#define _ORIGIN_

#include <iostream>
#include <string>

namespace Origins
{
    using std::string;

    class Origin
    {
        public:
            Origin();
            Origin(const string& origin);
            Origin(const Origin& other);
            Origin& operator=(const Origin& other);

            ~Origin();
            
            void set_origin(const string& origin);
            string get_origin() const;

        private:
            string origin;
            int* originAmount;
    };
}

#endif