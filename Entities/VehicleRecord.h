#pragma once
#include <string>
#include <utility>

#include "Owner.h"

class VehicleRecord {
private:
    std::string _plateNumber;
    Owner _owner;

public:
    VehicleRecord(const std::string &plateNumber, const Owner &owner){
        _plateNumber = plateNumber;
        _owner = owner;
    }

    std::string ToString() const
    {
        return _plateNumber + " - " + _owner.getFullName();
    }

    bool operator <(const VehicleRecord &other) const {
        return _plateNumber < other._plateNumber;
    };

    bool operator <=(const VehicleRecord &other) const {
        return _plateNumber <= other._plateNumber;
    };

    bool operator >=(const VehicleRecord &other) const {
        return _plateNumber >= other._plateNumber;
    };

    bool operator ==(const VehicleRecord &other) const {
        return _plateNumber == other._plateNumber;
    };

    bool operator !=(const VehicleRecord &other) const {
        return _plateNumber != other._plateNumber;
    };
};
