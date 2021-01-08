#pragma once

#include <ostream>
#include <string>

#define COPY_SEMANTIC 0
#define MOVE_SEMANTIC 0

namespace af
{
    class MyClass
    {
    public:
        MyClass();             // Default constructor
        MyClass(const char *); // Contructor
        ~MyClass();            // Destructor

#if COPY_SEMANTIC
        MyClass(const MyClass &);            // Copy constructor
        MyClass &operator=(const MyClass &); // Copy assignment operator
#else
        MyClass(const MyClass &) = delete;
        MyClass &operator=(const MyClass &) = delete;
#endif

#if MOVE_SEMANTIC
        MyClass(MyClass &&) noexcept;            // Move constructor
        MyClass &operator=(MyClass &&) noexcept; // Move assignment operator
#else
        MyClass(MyClass &&) noexcept = delete;
        MyClass &operator=(MyClass &&) noexcept = delete;
#endif

        friend void swap(MyClass &first, MyClass &second) noexcept;

        std::string getMsg() const;

    private:
        char *mMsg;
    };

    std::ostream& operator<<(std::ostream& os, const MyClass& rhs);
} // namespace af