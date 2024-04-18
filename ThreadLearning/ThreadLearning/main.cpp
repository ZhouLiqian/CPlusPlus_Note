#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>


// "busy sleep" while suggesting that other threads run
// for a small amount of time
void little_sleep(std::chrono::microseconds us)
{
    auto start = std::chrono::high_resolution_clock::now();
    auto end = start + us;
    do {
        std::this_thread::yield();
    } while (std::chrono::high_resolution_clock::now() < end);
    std::cout << "cout current thread!" << std::endl;
}

//int main()
//{
//    auto start = std::chrono::high_resolution_clock::now();
//    little_sleep(std::chrono::microseconds(100));
//    auto elapsed = std::chrono::high_resolution_clock::now() - start;
//    std::cout << "waited for "
//              << std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count()
//              << " microseconds\n";
//    return 0;
//}


// 实例化互斥锁对象，不要理解为定义变量
std::mutex g_mutex;

// 使用锁保护，创建一个线程安全的打印函数
void safePrint(std::string msg, int val) {
    g_mutex.lock(); // 上锁
    std::cout << msg << val << std::endl;
    g_mutex.unlock(); // 解锁
}

void threadTask()
{
    for (int i = 0; i < 10; i++)
        safePrint("print thread: ", i);
}

int main()
{
    std::thread t(threadTask);
    for (int i = 0; i > -10; i--)
        safePrint("print main: ", i);
    t.join();

    return 0;
}
