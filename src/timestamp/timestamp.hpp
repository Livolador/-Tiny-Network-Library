#pragma once

#include <iostream>
#include <string>
#include <chrono>

class Timestamp
{
private:
    int64_t microSecondsSinceEpoch;
public:
    Timestamp();
    explicit Timestamp(int64_t _microSecondsSinceEpoch);
    static Timestamp now();
    std::string toString() const;
    ~Timestamp() = default;

};

