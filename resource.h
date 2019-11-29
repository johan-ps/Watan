#ifndef __RESOURCE_H__
#define __RESOURCE_H__
class Resource {

    public:
        enum resourceType {caffeine, lab, lecture, study, tutorial, netflix};
        std::string getName(int value);

};
#endif