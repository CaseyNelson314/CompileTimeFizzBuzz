#include <iostream>


template <int N, int, int>
struct FizzBazzImpl
{
    static void Print() { std::cout << N << std::endl; }
};

template <int N>
struct FizzBazzImpl<N, 0, 0>
{
    static void Print() { std::cout << "FizzBuzz" << std::endl; }
};

template <int N, int Mod5>
struct FizzBazzImpl<N, 0, Mod5>
{
    static void Print() { std::cout << "Fizz" << std::endl; }
};

template <int N, int Mod3>
struct FizzBazzImpl<N, Mod3, 0>
{
    static void Print() { std::cout << "Buzz" << std::endl; }
};


template <int N, int Count = 1>
struct FizzBazz
{
    static void Print()
    {
        FizzBazzImpl<Count, Count % 3, Count % 5>::Print();
        FizzBazz<N, Count + 1>::Print();
    }
};

template <int N>
struct FizzBazz<N, N>
{
    static void Print() { }
};


int main()
{
    FizzBazz<100>::Print();
}
