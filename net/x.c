#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
    char buf[BUFSIZ];
    long int number;
    struct stat statbuf;
    stat("1.jpg",&statbuf);
    printf("%ld\n",statbuf.st_size);
    sprintf(buf,"%ld",statbuf.st_size);
    sscanf(buf,"%ld",&number);
    printf("%ld\n",number);
    return 0;
}