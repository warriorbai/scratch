
Install boost on centos

yum install boost boost-devel boost-doc

version: 1.41


Installed path:
/usr/include/
/usr/lib/




Compile examples:

   Only boost head file:

     g++ main.cc

   Use boost dynamic lib:

     g++ threads.cc  -lboost_thread-mt
