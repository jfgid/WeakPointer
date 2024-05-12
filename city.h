#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <string>

#include "bus_line.h"

class City : public std::enable_shared_from_this<City>
{
public:
    City(const std::string& name) : name_{name} {
        std::cout << "Construct City" << std::endl;
    }
    ~City() {
        std::cout << "Destruct City" << std::endl;
    }

    std::shared_ptr<const City> getPtr() const {
//        return std::shared_ptr<const Engine>(this);
        return shared_from_this();
    }

    void registerBusLine(BusLine::Ptr busLinePtr) {
        busLines_.push_back(busLinePtr);
    }

    int countBusLines() const {
        return busLines_.size();
    }

    void printName() const {
        std::cout << "Name: " << name_ << std::endl;
    }

private:
    std::vector<BusLine::Ptr> busLines_;
    std::string name_;
};