#include <cassert>
#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
    Data dataObj(42, "Test Object");

    uintptr_t serializedPtr = Serializer::serialize(&dataObj);

    Data* deserializedPtr = Serializer::deserialize(serializedPtr);

    assert(deserializedPtr == &dataObj);

    std::cout << "Test successful. Pointers match!" << std::endl;

    return 0;
}