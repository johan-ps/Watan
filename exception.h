#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

#include <string>

class InvalidTradeException {
    int resourceCount;
    std::string resourceType;
    std::string playerColour;
    public:
    InvalidTradeException(int resourceCount, std::string resourceType, std::string playerColour);
    std::string getError();
};

#endif
