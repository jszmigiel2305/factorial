#include <iostream>
#include <array>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <compare>



int main()
{
    srand(time(NULL));
    int comp{0};
    std::vector<int> v;

    for(int i{0}; i<4000000; i++)
        v.push_back(rand());

    std::qsort(&v, v.size(), sizeof(int),
        [&](const void* x, const void* y) {
        const int arg1 = *static_cast<const int*>(x);
        const int arg2 = *static_cast<const int*>(y);
        const auto cmp = arg1 <=> arg2;
        if (cmp < 0) return -1;
        if (cmp > 0) return 1;
        return 0;
    });

    std::for_each(v.begin(), v.end(), [](const int &i){std::cout << i << " asdf " << std::endl;});
    std::cout << comp << std::endl;

  return 0;
}
