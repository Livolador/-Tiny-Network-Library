#include "timestamp.hpp"

int main(int argc, const char** argv) {
    std::cout << Timestamp::now().toString() << std::endl;
    return 0;
}