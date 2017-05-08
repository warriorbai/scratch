//Atomit flag to implemente a spinlock 

#include <atomic>
#include <thread>
#include <vector>
#include <iostream>

std::atomic_flag lock_stream = ATOMIC_FLAG_INIT;

void append_number(int x)
{
   while (lock_stream.test_and_set()) {}
   std::cout << "Output from thread " << x << '\n';
   lock_stream.clear();
}

int main()
{
   std::vector<std::thread> threads;
   for (int i=1; i<=10; ++i) {
      threads.push_back(std::thread(append_number,i));   
   }
  
   for(auto& th : threads) {
      th.join();
   }
   return 0;
}
