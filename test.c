#include <libc.h>
#include "get_next_line.h"

int main()
{
   
    int fd = open("get_next_line.h", O_RDONLY);
    int i = 0;
    while (i < 13)
    {
        printf("%s", get_next_line(fd));
        i++;
    }
}