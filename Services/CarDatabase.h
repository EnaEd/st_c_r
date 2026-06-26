#pragma once

#include <iostream>
#include <optional>
#include <set>

#include "../Entities/VehicleRecord.h"

class CarDatabase {
private:
    std::set<VehicleRecord> database;
public:
    bool Add(const VehicleRecord& record) {
        return database.insert(record).second;
    }
    bool Remove(const VehicleRecord &record) {
        return database.erase(record) != 0;
    }
    std::optional<VehicleRecord> Find(const std::string &plate) {
        const auto record = database.find(VehicleRecord(plate, Owner()));
        if (record == database.end()) {
            return std::nullopt;
        }

        return *record;
    }
    void List() const {
        for (auto &record : database) {
            std::cout << record.ToString() << "\n";
        }
    }
    size_t get_size() const {
        return database.size();
    }
};