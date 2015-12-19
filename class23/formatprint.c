#include <stdio.h>
int main(void) {
    int i=32;
    float f=12.3456;
    char str[]="Hello";
    printf("Integer= %5d\n",i);
    printf("Integer= %05d\n",i);
    printf("Integer= %-5d\n",i);
    printf("Integer= %+5d\n",i);
    printf("  Float=%7.2f\n",f);
    printf("  Float=%-7.2f\n",f);
    printf("  Float=%+7.2f\n",f);
    printf(" String=%s\n",str);
    printf(" String=%10s\n",str);
    printf(" String=%-10s\n",str);
}
