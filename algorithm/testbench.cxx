#include"common_header.h"
#include"case.h"
using namespace std;
string case_run = "sort1";

void run_case(string case_run) {
    if(case_run == "sort1") {
        sort1();
    } else { 
        cout<<"No case run!"<<endl;
    }

}

int main() {
    rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    long s_begin = usage.ru_utime.tv_sec;
    long u_begin = usage.ru_utime.tv_usec;
     
    
    run_case(case_run);


    getrusage(RUSAGE_SELF, &usage);

    long s_end = usage.ru_utime.tv_sec;
    long u_end = usage.ru_utime.tv_usec;
    double secs = (s_end - s_begin) + 1.0e-6*(u_end - u_begin);
 
    return 0;
}
