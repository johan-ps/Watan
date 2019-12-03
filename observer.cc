#include "observer.h"
#include <string>

class Resource;

class Observer {
    public:
        virtual void notify() = 0;
        virtual void notify(Resource) = 0;
        virtual void notify(int) = 0;
        virtual void notify(int, char, std::string) = 0;
        virtual ~Observer() = 0;
};






