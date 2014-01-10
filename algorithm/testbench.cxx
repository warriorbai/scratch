#include"common_header.h"
#include"case.h"

void run_case(string case_run) {
    if(case_run == "insert_sort") {
        test_insert_sort();
    } else { 
        cout<<"Error: Can't recognize case name. No case run!"<<endl;
    }
}

int main(int argc, char* argv[]) {
    string case_run = (argc > 1) ? string(argv[1]):string("");
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
