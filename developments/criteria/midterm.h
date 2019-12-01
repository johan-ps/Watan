#ifndef __MIDTERM_H__
#define __MIDETERM_H__
#include "criterion.h"
#include <vector>

class Midterm : public Criterion {
    int location;
    
    public:
        void improve() override;
        void distributeResources() override;
        int getCriterionType() override;

    Midterm();
};
#endif
