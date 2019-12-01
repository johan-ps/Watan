#ifndef __EXAM_H__
#define __EXAM_H__
#include "criterion.h"
#include <vector>

class Exam : public Criterion {
int location;

    public:
    void improve() override;
    //void distributeResources() override;
    //int getCriterionType() override;

    Exam();
};
#endif
