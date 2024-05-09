#include "inc/AbstractStringOutput.h"

AbstractStringOutput::AbstractStringOutput()
{}

AbstractStringOutput::~AbstractStringOutput()
{
    if(__DEBUG) std::cout << __PRETTY_FUNCTION__ << std::endl;
}
