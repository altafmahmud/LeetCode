#ifndef PRINTINORDER_1114_HPP
#define PRINTINORDER_1114_HPP

// 1114. Print in Order

// Easy

// Suppose we have a class:

// public class Foo {
//   public void first() { print("first"); }
//   public void second() { print("second"); }
//   public void third() { print("third"); }
// }

// The same instance of Foo will be passed to three different threads. Thread A will call first(), thread B will call second(), 
// and thread C will call third(). Design a mechanism and modify the program to ensure that second() is executed after first(), and third() is executed after second().

// Note:
// We do not know how the threads will be scheduled in the operating system, even though the numbers in the input seem to imply the ordering. The input format you see is mainly to ensure our tests' comprehensiveness.

// Example 1:
// Input: nums = [1,2,3]
// Output: "firstsecondthird"
// Explanation: There are three threads being fired asynchronously. The input [1,2,3] means thread A calls first(), thread B calls second(), and thread C calls third(). "firstsecondthird" is the correct output.

// Example 2:
// Input: nums = [1,3,2]
// Output: "firstsecondthird"
// Explanation: The input [1,3,2] means thread A calls first(), thread B calls third(), and thread C calls second(). "firstsecondthird" is the correct output. 

// Constraints:
// nums is a permutation of [1, 2, 3].

#include <functional>
#include <iostream>
#include <condition_variable>
#include <mutex>
#include <thread>

namespace PrintInOrder {

void printFirst() {
    std::cout << "first";
}

void printSecond() {
    std::cout << "second";
}

void printThird() {
    std::cout << "third";
}

class Foo {
public:
    Foo(): state(0) {}

    void first(std::function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        std::lock_guard<std::mutex> lock(m);
        printFirst();
        state = 1;
        cv.notify_all();
    }

    void second(std::function<void()> printSecond) {
        // printSecond() outputs "second". Do not change or remove this line.
        std::unique_lock<std::mutex> lock(m);
        cv.wait(lock, [this] { return this->state == 1; });
        printSecond();
        state = 2;
        cv.notify_all();
    }

    void third(std::function<void()> printThird) {
        // printThird() outputs "third". Do not change or remove this line.
        std::unique_lock<std::mutex> lock(m);
        cv.wait(lock, [this] { return this->state == 2; });
        printThird();
    }

private:
std::condition_variable cv;
std::mutex m;
unsigned short state;
};

std::thread createThread(const unsigned short val, Foo &foo) {
    std::thread t;
    switch (val)
    {
    case 1:
    {
        t = std::thread(&Foo::first, std::ref(foo), PrintInOrder::printFirst);
        break;
    }
    case 2:
    {
        t = std::thread(&Foo::second, std::ref(foo), PrintInOrder::printSecond);
        break;
    }
    case 3:
    {
        t = std::thread(&Foo::third, std::ref(foo), PrintInOrder::printThird);
        break;
    }        
    default:
    {
        break;
    }
    }
    return t;
}

} // PrintInOrder

#endif // PRINTINORDER_1114_HPP