#ifndef _THREAD_POOL_H
#define _THREAD_POOL_H
#include <thread>
#include <mutex>
#include <functional>

class ThreadPool;
  
// our worker thread objects
class Worker {
public:
   Worker(ThreadPool &s) : pool(s) { }
   void operator()();
private:
   ThreadPool &pool;
};


class ThreadPool
{
public:
   ThreadPool(int size);
   template <class F>
   void Enqueue(F f);
   ~ThreadPool();
private:
   friend class Worker;
   std::deque<std::function<void()>> tasks; 
   std::vector<std::thread> workers;

   // synchronization
   std::mutex queue_mutex;
   std::condition_variable condition;
   bool stop;
};
#endif
