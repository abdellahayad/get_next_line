#include <libc.h>
#include "get_next_line.h"
// void gg(void)
// {
//     system("leaks a.out");
// }
int main()
{
//    atexit(gg);
    int fd = open("r.txt", O_RDONLY);

    int i = 0;
    while (i < 2)
    {
        printf("%s", get_next_line(fd));
        i++;
    }
    
    
}