#include <iostream>
#include <vector>
using namespace std;

#include "MyClass.h"
using namespace af;

// class Class2 {
// public:
//   Class2(MyClass& a)
//     : _m(std::move(a))
//   {
//   }

// private:
//   MyClass _m;

// };

#include <iostream>
#include <string_view>

template <typename T>
constexpr auto type_name() noexcept {
  std::string_view name, prefix, suffix;
#ifdef __clang__
  name = __PRETTY_FUNCTION__;
  prefix = "auto type_name() [T = ";
  suffix = "]";
#elif defined(__GNUC__)
  name = __PRETTY_FUNCTION__;
  prefix = "constexpr auto type_name() [with T = ";
  suffix = "]";
#elif defined(_MSC_VER)
  name = __FUNCSIG__;
  prefix = "auto __cdecl type_name<";
  suffix = ">(void) noexcept";
#endif
  name.remove_prefix(prefix.size());
  name.remove_suffix(suffix.size());
  return name;
}

MyClass f() {
  MyClass c1("Hello Antonio!");
  cout << "[" << &c1 << "]" << endl;
  return c1;
}

int main()
{
  //af::MyClass c1;
  //af::MyClass c2(c1);
  //af::MyClass c3 = c1;
  //c1 = c2;

  //vector<MyClass> v;
  //for (size_t i = 0; i < 2; ++i)
  //{
  //    v.push_back(MyClass());
  //}

  //{
  //  MyClass mc;
  //  Class2 c(mc);
  //}

  //vector<int> v1({1, 2, 3, 4, 5});
  //vector<int> v2 = {1, 2, 3, 4, 5};
  //vector<int> v3{1, 2, 3, 4, 5};

  // for (vector<int>::const_iterator it = begin(v1); it != end(v1); ++it) {
  //   cout << type_name<decltype(it)>() << endl;
  //   cout << *it << endl;
  // }

  // for (auto it = cbegin(v1); it != cend(v1); ++it) {
  //   cout << type_name<decltype(it)>() << endl;
  //   cout << *it << endl;
  // }

  // for (const auto& elem : v1) {
  //   cout << type_name<decltype(elem)>() << endl;
  //   cout << elem << endl;
  // }

  //string str1 = "Antonio";
  //string str2 = "Fuschetto";

  //vector<reference_wrapper<string>> v1 = {ref(str1), ref(str2)};
  //for (const auto& elem : v1) {
  //   cout << type_name<decltype(elem.get())>() << endl;
  //   cout << elem.get() << endl;
  // }

  //cout << "End" << endl;

  cout << "-1-" << endl;
  MyClass c = f();
  cout << c << endl;
  cout << "[" << &c << "]" << endl;
  cout << "-2-" << endl;
}