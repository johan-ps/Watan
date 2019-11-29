#ifndef __RESOURCE_H__
#define __RESOURCE_H__
#include <string>

class Resource {

    public:
        enum resourceType {caffeine, lab, lecture, study, tutorial, netflix};
        std::string getName(int);

};
#endif