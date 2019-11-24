#include "../development.h"

class Criterion : public Development {
    public:
    virtual void improve() = 0;
    virtual void distributeResources() = 0;
}