#pragma once

#include <iostream>
#include <memory>

class City;

class BusLine
{
public:
    typedef std::shared_ptr<BusLine> Ptr;

    BusLine(std::shared_ptr<const City> cityPtr) :
        cityPtr_{cityPtr}
    {
        std::cout << "Construct BusLine" << std::endl;
    }
    ~BusLine() {
        std::cout << "Destruct BusLine" << std::endl;
    }

    void printCityName() const;

private:
#ifdef WEAKPTR
    std::weak_ptr<const City> cityPtr_;
#else
    std::shared_ptr<const City> cityPtr_;
#endif
};