#include <iostream>
#include <vector>
#include <list>

using namespace std;

void print_num(vector<int> &vec);
void print_num(list<int> &vec);

void
num_add(list<int> &n1,
        list<int> &n2)
{
   list<int>::reverse_iterator rit1;
   list<int>::reverse_iterator rit2;
   int carry = 0;
   int val = 0;

   for(rit2 = n2.rbegin(),rit1 = n1.rbegin(); rit2 != n2.rend(); rit2++, rit1++) {
      if(rit1 == n1.rend()) {
         n1.push_front(0); 
         rit1 = n1.rend();
         rit1--;
      }
      val = *rit1 + *rit2 + carry;
      carry = val/10;
      val = val%10;
      *rit1 = val;
   }

   if (carry != 0) {
      n1.push_front(carry);
   }
}


void
vec_x_num_add(vector<int> &n1,
              int num,
              int pos,
              list<int> &res)
{
   int carry = 0;
   int i = 0;
   list<int> temp;
   int val = 0;

   print_num(n1);
   cout << "*" << endl;
   cout << num << endl;

   if (num == 0) {
      return;
   }

   for(vector<int>::reverse_iterator rit = n1.rbegin(); rit != n1.rend(); rit++) {
      val = (*rit) * num + carry;   
      carry = val / 10;
      temp.push_front(val % 10);
   }

   if(carry != 0) {
      temp.push_front(carry);
   }

   for(int i = 0; i < pos; i++) {
      temp.push_back(0);
   }

   cout << "temp:";
   print_num(temp);
   num_add(res, temp);
   print_num(res);
}


void 
multiply(vector<int> &n1,
         vector<int> &n2,
         vector<int> &mult)
{
   int n2_size = n2.size();
   list<int> res;

   for (int i = 0; i < n2_size; i++) {
      cout << "iter " << i << "  " << endl;
      vec_x_num_add(n1, n2[n2_size - i - 1], i, res);
   }

   for(list<int>::iterator it = res.begin(); it != res.end(); it++) {
      mult.push_back(*it);
   }
}


bool
str_to_vec(string &str,
           vector<int> &vec)
{
   bool valid = false;
   for(string::iterator it = str.begin(); it != str.end(); it++) {
      char c = *it;
      if (c < '0' || c > '9') {
         cerr << "Invalid input!" << endl;
         return false;
      }
      
      if (c == '0' && !valid) {
         continue;
      }

      vec.push_back(c - '0');
      valid = true;
   }
   return true;
}


void
get_input(vector<int> &n)
{
   string str;
   do {
      cout << "input number:";
      cin >> str;
   } while (!str_to_vec(str, n));

   
}


void
print_num(vector<int> &vec)
{
   for(int i = 0; i < vec.size(); i++) {
      cout << vec[i];
   }
   cout << endl;
}


void
print_num(list<int> &l)
{
   for(list<int>::iterator it = l.begin(); it != l.end(); it++) {
      cout << *it;
   }
   cout << endl;
}


int main()
{
   vector<int> n1;
   vector<int> n2;
   vector<int> mult;
   string a;
   string b;

   cout << "a * b" << endl;

   get_input(n1);
   get_input(n2);

   multiply(n1, n2, mult);

   cout << "Result is: ";
   print_num(mult);
   
   return 0;
}
