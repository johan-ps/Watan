#include "criterion.h"

class Midterm : public Criterion {
    public:
    void improve() override;
    void distributeResources() override;

    Midterm();
}