#include <climits>
#include <stdio.h>

int main() {
    printf ("The size of 'byte' in this Impl is: %d 'bits'\n", CHAR_BIT);
    unsigned char age = 65;
    printf ("The size of age in  'age = 65' : %d byte \n", (int)sizeof(age));
    return 0;
}
