#ifndef __MIDTERM_H__
#define __MIDETERM_H__
#include "criterion.h"
#include <vector>

class Midterm : public Criterion {
    int location;
    const std::vector<int> cost = { 0, 0, 2, 0, 3, 0};

    public:
        void improve() override;
        void distributeResources() override;
        int getCriterionType() override;

    Midterm();
};
#endif
