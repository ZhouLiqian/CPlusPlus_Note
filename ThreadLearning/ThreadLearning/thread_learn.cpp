//  thread_learn.cpp
//  ThreadLearning
//  Created by Qian on 4/16/24.

#include <mutex>
using namespace::std;

/*使用层次锁来避免死锁*/
class hierarchical_mutex{
    mutex internal_mutex;
    unsigned long const hierarchy_value;
    unsigned long previous_hierarchy_value;
    static thread_local unsigned long this_thread_hierarchy_value;
    void check_for_hierarchy_violation(){
        if(this_thread_hierarchy_value <= hierarchy_value){
            throw logic_error("mutex hierarchy violated");
        }
    }
    void update_hierarchy_value(){
        previous_hierarchy_value = this_thread_hierarchy_value;
        this_thread_hierarchy_value = hierarchy_value;
    }
    
public:
    explicit hierarchical_mutex(unsigned long value) : hierarchy_value(value), previous_hierarchy_value(0){}
    void lock(){
        check_for_hierarchy_violation();
        internal_mutex.lock();
        update_hierarchy_value();
    }
    void unlock(){
        if(this_thread_hierarchy_value != hierarchy_value) throw logic_error("mutex hierarchy violated");
        this_thread_hierarchy_value = previous_hierarchy_value;
        internal_mutex.unlock();
    }
    bool try_lock(){
        check_for_hierarchy_violation();
        if(!internal_mutex.try_lock()) return false;
        update_hierarchy_value();
        return true;
    }
};
thread_local unsigned long hierarchical_mutex::this_thread_hierarchy_value(ULONG_MAX);

hierarchical_mutex high_level_mutex(10000);
hierarchical_mutex low_level_mutex(5000);
hierarchical_mutex other_mutex(6000);
int do_low_level_stuff();
int low_level_func(){
    lock_guard<hierarchical_mutex> lk(low_level_mutex);
    return do_low_level_stuff();
}
void high_level_stuff(int some_param);
void high_level_func(){
    lock_guard<hierarchical_mutex> lk(high_level_mutex);
    high_level_stuff(low_level_func());
}
void thread_a(){
    high_level_func();//高层级锁可以对低层级互斥量上锁
}
void do_other_stuff();
void other_stuff(){
    high_level_func();
    do_other_stuff();
}
void thread_b(){
    lock_guard<hierarchical_mutex> lk(other_mutex);
    other_stuff();//违反层级结构
}

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

