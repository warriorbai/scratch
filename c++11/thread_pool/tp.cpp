#include "tp.h"

// the constructor just launches some amount of workers
ThreadPool::ThreadPool(size_t threads):stop(false)
{
   for(size_t i = 0; i < threads; ++i) {
      workers.push_back(std::thread(Worker(*this)));
   }
}
   
// the destructor joins all threads
ThreadPool::~ThreadPool()
{
   // stop all threads
   stop = true;
   condition.notify_all();
    
   // join them
   for(size_t i = 0;i < workers.size(); ++i) {
      workers[i].join();
   }
}

// add new work item to the pool
template<class F>
void ThreadPool::enqueue(F f)
{
   { // acquire lock
      std::unique_lock<std::mutex> lock(queue_mutex);
       
      // add the task
      tasks.push_back(std::function<void()>(f));
   } // release lock
    
   // wake up one thread
   condition.notify_one();
}
