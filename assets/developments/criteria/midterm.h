#ifndef __MIDTERM_H__
#define __MIDETERM_H__
#include "criterion.h"

class Midterm : public Criterion {
    public:
    void improve() override;
    void distributeResources() override;

    Midterm();
};
#endif