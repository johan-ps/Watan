#ifndef MIDTERM_H
#define MIDTERM_H

#include "criterion.h"

class Midterm : public Criterion {
    public:
    void improve() override;
    void distributeResources() override;
    int getCriterionType() override;

    Midterm();
}

#endif
