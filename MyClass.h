#pragma once

namespace af
{
    class MyClass
    {
    public:
        MyClass();             // Default constructor
        MyClass(const char *); // Contructor
        ~MyClass();            // Destructor

        MyClass(const MyClass &);            // Copy constructor
        MyClass &operator=(const MyClass &); // Copy assignment operator

        MyClass(MyClass &&) noexcept;            // Move constructor
        MyClass &operator=(MyClass &&) noexcept; // Move assignment operator

        friend void swap(MyClass &first, MyClass &second) noexcept;

    private:
        char *mMsg;
    };
} // namespace af