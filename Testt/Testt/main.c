#include <stdio.h>
#include <string.h>
#define PRAISE "NowCoder is benefit to everyone concerned."

int main(int argc, const char * argv[]) {
    // insert code here...
    char color = 'B';
    int color_byte = sizeof(color);
    unsigned B_byte = sizeof('B');
    printf("color_byte = %d\n", color_byte);
    printf("B_byte = %d\n", B_byte);
    printf("The phrase of PRAISE has %zd letters " , strlen(PRAISE));
    printf("and occupies %zd memory cells.\n", sizeof(PRAISE));
    return 0;
}
