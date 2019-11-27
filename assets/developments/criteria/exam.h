#ifndef EXAM_H
#define EXAM_H

#include "criterion.h"

class Exam : public Criterion {
    public:
    void improve() override;
    void distributeResources() override;

    Exam();
}

#endif
