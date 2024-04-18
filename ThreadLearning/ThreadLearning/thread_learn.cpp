//  thread_learn.cpp
//  ThreadLearning
//  Created by Qian on 4/16/24.

#include <mutex>
using namespace::std;

/*使用层次锁来避免死锁*/


/*交换操作中使用lock()和lock_guard解决死锁问题*/
class some_big_object{};
void swap(some_big_object& lhs, some_big_object& rhs);

class X{
private:
    some_big_object some_detail;
    mutex m;
public:
    X(some_big_object const& sd) : some_detail(sd){}
    friend void swap(X& lhs, X& rhs){
        if(&lhs == &rhs) return;
        lock(lhs.m, rhs.m);
        lock_guard<mutex> lock_a(lhs.m, adopt_lock);
        lock_guard<mutex> lock_b(rhs.m, adopt_lock);
        swap(lhs.some_detail, rhs.some_detail);
    }
};

