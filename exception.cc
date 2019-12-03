#include "exception.h"

InvalidTradeException::InvalidTradeException(int resourceCount, std::string resourceType, std::string playerColour):
    resourceCount{resourceCount}, resourceType{resourceType}, playerColour{playerColour} {}

std::string InvalidTradeException::getError() {
    std::string error = playerColour + " currently has " + std::to_string(resourceCount) + resourceType + ". Can't proceed with trade.";
    return error;
}
