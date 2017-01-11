#include <stdio.h>
 
int main() {
    int a[5] = { 1, 2, 2, 5, 1 };
    for( int i:a ) {
        printf( "%d\n",i );
    }
    return 0;
}
