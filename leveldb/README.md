1. Compile leveldb

Entering leveldb, and make



Error: expecting string instruction after 'rep'

Need update bintutils.

wget http://people.centos.org/tru/devtools-2/devtools-2.repo -O /etc/yum.repos.d/devtools-2.repo
yum install devtoolset-2-gcc devtoolset-2-binutils
yum install devtoolset-2-gcc-gfortran


3 folder:
include         
out-shared
out-static


2. Using leveldb

dynamic lib:
g++ main.cc -I/home/wbai/dev/git/leveldb/include -L/home/wbai/dev/git/leveldb/out-shared -lleveldb

static lib:
g++ main.cc -I/home/wbai/dev/git/leveldb/include -L/home/wbai/dev/git/leveldb/out-static -lleveldb -lpthread


3. run 

To make it easy

copy    leveldb/out-shared/libleveldb.so to   /usr/local/lib   or   /usr/lib

Set LD_LIBRARY_PATH
