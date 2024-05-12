#include "bus_line.h"

#include "city.h"

void BusLine::printCityName() const
{
    std::cout << "City use count = " << cityPtr_.use_count() << std::endl;
#ifdef WEAKPTR
    if (std::shared_ptr<const City> sptr = cityPtr_.lock())
    {
        sptr->printName();
    }
    else
    {
        std::cout << "City instance has expired" << std::endl;
    }
#else
    cityPtr_->printName();
#endif
}