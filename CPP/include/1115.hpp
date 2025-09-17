#ifndef PRINTFOOBARALT_1115_HPP
#define PRINTFOOBARALT_1115_HPP

// 1115. Print FooBar Alternately

// Medium

// Suppose you are given the following code:

// class FooBar {
//   public void foo() {
//     for (int i = 0; i < n; i++) {
//       print("foo");
//     }
//   }

//   public void bar() {
//     for (int i = 0; i < n; i++) {
//       print("bar");
//     }
//   }
// }
// The same instance of FooBar will be passed to two different threads:

// thread A will call foo(), while
// thread B will call bar().
// Modify the given program to output "foobar" n times.

// Example 1:

// Input: n = 1
// Output: "foobar"
// Explanation: There are two threads being fired asynchronously. One of them calls foo(), while the other calls bar().
// "foobar" is being output 1 time.

// Example 2:

// Input: n = 2
// Output: "foobarfoobar"
// Explanation: "foobar" is being output 2 times.
 
// Constraints:
// 1 <= n <= 1000

#include <functional>
#include <iostream>
#include <condition_variable>
#include <mutex>

namespace PrintFooBarAlt {

void printFoo() {
    std::cout << "foo";
}

void printBar() {
    std::cout << "bar";
}

class FooBar {
private:
    int n;
    std::mutex m;
    std::condition_variable cv;
    bool alt;

public:
    FooBar(int n): n(n), alt(false) {}

    void foo(std::function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(m);
            cv.wait(lock, [&] { return !alt; });
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            alt = true;
            cv.notify_all();
        }
    }

    void bar(std::function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(m);
            cv.wait(lock, [&] { return alt; });
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            alt = false;
            cv.notify_all();
        }
    }
};

}

#endif // PRINTFOOBARALT_1115_HPP