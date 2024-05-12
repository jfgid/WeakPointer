#include <iostream>
#include <memory>

#include "city.h"

int main()
{
    {
        std::shared_ptr<City> myCityPtr = std::make_shared<City>("Perpignan");

        auto busLinePtr1{ std::make_shared<BusLine>(myCityPtr->getPtr()) };
        myCityPtr->registerBusLine(busLinePtr1);
        auto busLinePtr2{ std::make_shared<BusLine>(myCityPtr->getPtr()) };
        myCityPtr->registerBusLine(busLinePtr2);;

        std::cout << "Nombre de lignes de bus = " << myCityPtr->countBusLines() << std::endl;
        busLinePtr1->printCityName();
        busLinePtr2->printCityName();
    }
    char c;
    std::cout << "Entrez un caractère pour terminer";
    std::cin >> c;
}