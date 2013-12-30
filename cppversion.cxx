#include<iostream>
#include<string>
#include<unistd.h>
using namespace std;
int main() {
    int delay          = 0;
    int longdelay      = 99999;      // long value of delay. 
    delay = longdelay;
    string cmd = "ssh localhost date";
    int status;

    //string cmd = "date";
    cout<<"---$cmd---\n";
    int gid = getpgrp();
    cout<<"--group id of parent process is $gid. \n";
    pid_t fid;
    if (fid = fork()) {
    
        cout<< "running in parent process.\n";
        while(1)
        {
                if(waitpid(fid,&status,WNOHANG) == fid)
                {
                        cout<<"running in parent process. waitpid\n";
                        break;
                }
        }

    } else {
        int gidc = getpgrp();
        cout<< "--group id of child process is $gidc. $$\n";
        //setpgrp();
        gidc = getpgrp();
        cout<< "--group id of child process is $gidc. $$\n";
        //Dup standard output to the write side of the pipe, and unbuffer
        cout<<"running in child process.\n";

        //Invoke the child process and capture status
        cout<<"running in child process: system(\"$cmd\").\n";
        //$status = system("$cmd 2>&1");
        int status = system(cmd.c_str());
        cout<<"running in child process: system status: $status.\n";
        //$status = system("rsh linws27 date");
        //Be nice and clean up the pipe
        //Explicitly exit with 1 on failure 0 on success

    }
}
