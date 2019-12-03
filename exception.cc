#include "exception.h"

InvalidTradeException::InvalidTradeException(int resourceCount, std::string resourceType, std::string playerColour):
    resourceCount{resourceCount}, resourceType{resourceType}, playerColour{playerColour} {}

std::string InvalidTradeException::getError() {
    std::string error = "Student " + playerColour + " currently has " + std::to_string(resourceCount) + resourceType + ". Can't proceed with trade.";
    return error;
}

InsufficientResourcesException::InsufficientResourcesException(std::string resourceType, std::string playerColour):
    resourceType{resourceType}, playerColour{playerColour} {}

std::string InsufficientResourcesException::getError() {
    std::string temp = "Student " + playerColour + " doesn't have enough " + resourceType + ".";
    return temp;
}

AlreadyAchievedException::AlreadyAchievedException(int location, std::string playerColour):
    location{location}, playerColour{playerColour} {}

std::string AlreadyAchievedException::getError() {
    std::string temp = "Student " + playerColour + " has already achieved the goal at location: " + std::to_string(location) + ".";
    return temp;
}

AlreadyCompletedException::AlreadyCompletedException(int location, std::string playerColour):
    location{location}, playerColour{playerColour} {}

std::string AlreadyCompletedException::getError() {
    std::string temp = "Student " + playerColour + " has already completed the criteria at location: " + std::to_string(location) + ".";
    return temp;
}

InvalidCriteriaException::InvalidCriteriaException(int location, std::string playerColour):
    location{location}, playerColour{playerColour} {}

std::string InvalidCriteriaException::getError() {
    std::string temp = "Student " + playerColour + " doesn't own the criteria at location: " + std::to_string(location) + ".";
    return temp;
}

CriteriaCannotBeImprovedException::CriteriaCannotBeImprovedException(int location):
    location{location} {}

std::string CriteriaCannotBeImprovedException::getError() {
    std::string temp = "The criteria at location: " + std::to_string(location) + " has already been upgraded to the max level.";
    return temp;
}

std::string InvalidLocationException::getError() {
    std::string temp = "Please enter a valid location.";
    return temp;
}
