#ifndef __ASSIGN_H__
#define __ASSIGN_H__
#include "criterion.h"

class Assignment : public Criterion {
    public:
    void complete(Player&);
    void improve() override;
    void distributeResources() override;

    Assignment();
};
#endif 