#ifndef PRINTZEROEVENODD_1116_HPP
#define PRINTZEROEVENODD_1116_HPP

// 1116. Print Zero Even Odd

// Medium

// You have a function printNumber that can be called with an integer parameter and prints it to the console.

// For example, calling printNumber(7) prints 7 to the console.
// You are given an instance of the class ZeroEvenOdd that has three functions: zero, even, and odd. The same instance of ZeroEvenOdd will be passed to three different threads:

// Thread A: calls zero() that should only output 0's.
// Thread B: calls even() that should only output even numbers.
// Thread C: calls odd() that should only output odd numbers.
// Modify the given class to output the series "010203040506..." where the length of the series must be 2n.

// Implement the ZeroEvenOdd class:

// ZeroEvenOdd(int n) Initializes the object with the number n that represents the numbers that should be printed.
// void zero(printNumber) Calls printNumber to output one zero.
// void even(printNumber) Calls printNumber to output one even number.
// void odd(printNumber) Calls printNumber to output one odd number. 

// Example 1:

// Input: n = 2
// Output: "0102"
// Explanation: There are three threads being fired asynchronously.
// One of them calls zero(), the other calls even(), and the last one calls odd().
// "0102" is the correct output.

// Example 2:

// Input: n = 5
// Output: "0102030405"
 
// Constraints:
// 1 <= n <= 1000

#include <iostream>
#include <functional>
#include <semaphore.h>

namespace PrintZeroEvenOdd {

void printNumber(int num) {
    std::cout << num;
}

class ZeroEvenOdd {
private:
    int n;
    unsigned count;
    unsigned num;
    std::mutex m;
    std::condition_variable cv;    

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        this->count = 0;
        this->num = 1;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(std::function<void(int)> printNumber) {
        const unsigned lim = n * 2;
        while (count < lim) {
            std::unique_lock<std::mutex> lock(m);
            cv.wait(lock, [&] { return (count % 2) == 0; });
            if (count < lim) {
                printNumber(0);
            }
            ++count;
            cv.notify_all();
        }
    }

    void even(std::function<void(int)> printNumber) {
        const unsigned lim = ((n % 2) == 0) ? n : n - 1;
        while (num <= lim) {
            std::unique_lock<std::mutex> lock(m);
            cv.wait(lock, [&] { return (count % 2) == 1 && (num % 2) == 0; });
            printNumber(num);
            ++count;
            ++num;
            cv.notify_all();
        }
    }

    void odd(std::function<void(int)> printNumber) {
        const unsigned lim = ((n % 2) == 0) ? n - 1 : n;
        while (num <= lim) {
            std::unique_lock<std::mutex> lock(m);
            cv.wait(lock, [&] { return (count % 2) == 1 && (num % 2) == 1; });
            printNumber(num);
            ++count;
            ++num;
            cv.notify_all();
        }
    }
};

class ZeroEvenOddTE {
private:
    int n;
    int count;
    bool is_zero;
    std::mutex m;
    std::condition_variable cv;

public:
    ZeroEvenOddTE(int n) {
        this->n = n;
        this->count = 1;
        this->is_zero = true;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(std::function<void(int)> printNumber) {
        while (count <= n) {
            std::unique_lock<std::mutex> lock(m);
            cv.wait(lock, [&] { return is_zero; });
            if (count <= n) {
                printNumber(0);
            }
            is_zero = false;
            cv.notify_all();
        }
    }

    void even(std::function<void(int)> printNumber) {
        while (count <= n) {
            std::unique_lock<std::mutex> lock(m);
            cv.wait(lock, [&] { return !is_zero && (count % 2) == 0; });
            if (count <= n) {
                printNumber(count);
                ++count;                
            }
            is_zero = true;
            cv.notify_all();
        }
    }

    void odd(std::function<void(int)> printNumber) {
        while (count <= n) {
            std::unique_lock<std::mutex> lock(m);
            cv.wait(lock, [&] { return !is_zero && (count % 2) == 1; });
            if (count <= n) {
                printNumber(count);
                ++count;
            }
            is_zero = true;
            cv.notify_all();
        }
    }
};

}

#endif // PRINTZEROEVENODD_1116_HPP