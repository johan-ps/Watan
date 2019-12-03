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

class InsufficientResourcesException {
    std::string resourceType;
    std::string playerColour;
    public:
    InsufficientResourcesException(std::string resourceType, std::string playerColour);
    std::string getError();
};

class AlreadyAchievedException {
    int location;
    std::string playerColour;
    public:
    AlreadyAchievedException(int location, std::string playerColour);
    std::string getError();
};

class AlreadyCompletedException {
    int location;
    std::string playerColour;
    public:
    AlreadyCompletedException(int location, std::string playerColour);
    std::string getError();
};

class InvalidCriteriaException {
    int location;
    std::string playerColour;
    public:
    InvalidCriteriaException(int location, std::string playerColour);
    std::string getError();
};

class CriteriaCannotBeImprovedException {
    int location;
    public:
    CriteriaCannotBeImprovedException(int location);
    std::string getError();
};

class InvalidLocationException {
    public:
    std::string getError();
};

class GameOverException {};

#endif
