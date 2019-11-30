#ifndef __EXAM_H__
#define __EXAM_H__
#include "criterion.h"
#include <vector>

class Exam : public Criterion {
int location;
const std::vector<int> cost = { 3, 2, 2, 1, 2, 0};

    public:
    void improve() override;
    void distributeResources() override;
    int getCriterionType() override;

    Exam();
};
#endif
