#ifndef __EXAM_H__
#define __EXAM_H__
#include "criterion.h"

class Exam : public Criterion {
    public:
    void improve() override;
    void distributeResources() override;
    int getCriterionType() override;

    Exam();
};
#endif
