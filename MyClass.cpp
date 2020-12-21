#include "MyClass.h"

#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <utility>
using namespace std;

namespace af
{
    MyClass::MyClass()
        : MyClass("No message")
    {
        cout << "[" << this << "] Default ctor()" << endl;
    }

    MyClass::MyClass(const char *msg)
        : mMsg(strdup(msg))
    {
        cout << "[" << this << "] Ctor(\"" << msg << "\")" << endl;
    }

    MyClass::~MyClass()
    {
        cout << "[" << this << "] Dtor" << endl;

        free(mMsg);
    }

    ///////////////////////////////////////////////////////////////////////////

    // Build a new object deeply copying all the member data of the source
    // object (thus including dynamically allocated memory).
    MyClass::MyClass(const MyClass &src)
        : MyClass(src.mMsg)
    {
        cout << "[" << this << "] Copy ctor" << endl;

        // The ctor-initializer shallow copies all member data of "src" object.
        // Instead, the body deeply copies each dynamically allocated object
        // (if any).
    }

    // Deeply copy the status of the object on the right side (rhs) to the left
    // side (this), being careful not to leave the object on the left side in
    // an inconsistent status in case of exceptions.
    MyClass &MyClass::operator=(const MyClass &rhs)
    {
        cout << "[" << this << "] Copy assignment operator" << endl;

        if (this == &rhs)
        {
            return *this;
        }

        // Copy-and-swap idiom: this ensures that the object on the left side
        // (this) remains consistent in case of exceptions.

        MyClass tmp(rhs); // Temporary instance with a full copy of all "rhs" member data (may throw exceptions)
        swap(*this, tmp); // Swap of member data (throw no exceptions)
        return *this;     // Destruction of the previous status of the "lhs" object (throw no exceptions)
    }

    ///////////////////////////////////////////////////////////////////////////

    // Construct a new object shallow copying all the member data of the source
    // object (thus excluding dynamically allocated memory).
    MyClass::MyClass(MyClass &&src) noexcept
        : MyClass()
    {
        cout << "[" << this << "] Move ctor" << endl;

        // The default constructor initializes all member data.
        // The member data of this object is then swapped with the one of the
        // source object.
        swap(*this, src);
    }

    MyClass &MyClass::operator=(MyClass &&rhs) noexcept
    {
        cout << "[" << this << "] Move assignment operator" << endl;

        // Copy-and-swap idiom: this ensures that the object on the left side
        // (this) remains consistent in case of exceptions.

        MyClass tmp(std::move(rhs)); // Temporary instance with a shallow copy of all "rhs" member data (may throw exceptions)
        swap(*this, tmp);            // Swap of member data (throw no exceptions)
        return *this;                // Destruction of the previous status of the "lhs" object (throw no exceptions)
    }

    ///////////////////////////////////////////////////////////////////////////

    // Useful also for some STL algorithms.
    void swap(MyClass &first, MyClass &second) noexcept
    {
        std::swap(first.mMsg, second.mMsg);
    }
} // namespace af