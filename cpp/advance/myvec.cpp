#include "myvec.h"

void vectest()
{
    const int TESTS = 1000;
    const int ITEMS = 10000;
    auto dur = high_resolution_clock::duration();
    auto mydur = high_resolution_clock::duration();
    
    typedef int type;
    type obj;
    
    for(int i = 0; i < TESTS; ++i) {
        std::vector<type> vec;
        myvec<type> myvec;
        // myvec<int>::iterator it = vec.begin();
        
        high_resolution_clock::time_point tp0 = high_resolution_clock::now();
        for(int i = 0; i < ITEMS; ++i) {
            vec.push_back(obj);
        }
        high_resolution_clock::time_point tp1 = high_resolution_clock::now();
        dur += tp1 - tp0;
        
        tp0 = high_resolution_clock::now();
        for(int i = 0; i < ITEMS; ++i) {
            myvec.push_back(obj);
        }
        tp1 = high_resolution_clock::now();
        mydur += tp1 - tp0;
    }
    dur /= TESTS;
    mydur /= TESTS;
    
    std::cout << std::setw(15) << "std::vector: " << dur.count() << std::endl;
    std::cout << std::setw(15) << "myvec: " << mydur.count() << std::endl;
    
    std::cout << "\n" << std::endl;
}

int main(void)
{
    vectest();
    
    return 0;
}
