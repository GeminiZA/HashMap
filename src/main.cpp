#include <iostream>
#include <HashMap.h>

int main()
{
    HashMap<int, int> test_map = HashMap<int, int>();
    for (int i = 0; i < 2000; i++)
    {
        test_map.set(i, i + 1);
    }
    // std::cout << ((test_map.get(1) == 2) ? "passed" : "failed") << std::endl;
    std::cout << test_map.toString() << std::endl;
}