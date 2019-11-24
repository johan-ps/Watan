#include "criterion.h"

class Assignment : public Criterion {
    public:
    void complete(Player&) override;
    void improve() override;
    void distributeResources() override;

    Assignment();
}