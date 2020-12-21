#include <vector>
using namespace std;

#include "MyClass.h"
using namespace af;

int main()
{
    af::MyClass c1;
    af::MyClass c2(c1);
    af::MyClass c3 = c1;
    //c3 = c2;

    //vector<MyClass> v;
    //for (size_t i = 0; i < 2; ++i) {
    //    v.push_back(MyClass("Class_" + to_string(i)));
    //}

    return 0;
}