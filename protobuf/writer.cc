#include <iostream>
#include <fstream>
#include "person.pb.h"
using namespace std;
int main()
{
   tutorial::Person p1;
   p1.set_name("wbai");
   p1.set_age(31);
   p1.set_email("wbai@vmware.com");

  // Write the new address book back to disk. 
  fstream output("./log", ios::out | ios::trunc | ios::binary); 
        
  if (!p1.SerializeToOstream(&output)) { 
      cerr << "Failed to write msg." << endl; 
      return -1; 
  }         
  return 0; 
}
