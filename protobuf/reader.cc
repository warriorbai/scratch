#include <iostream>
#include <fstream>
#include "person.pb.h"
using namespace std;
int main()
{
   tutorial::Person p1;
 
   fstream input("./log", ios::in | ios::binary); 
   if (!p1.ParseFromIstream(&input)) { 
     cerr << "Failed to parse address book." << endl; 
     return -1; 
   } 

   cout << p1.name() << " " << p1.age() << " " << p1.email() << endl;
   return 0; 
}
