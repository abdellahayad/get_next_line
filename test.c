#include <libc.h>
#include "get_next_line.h"
void gg(void)
{
    system("leaks a.out");
}
int main()
{
   atexit(gg);
    int fd = open("get_next_line.h", O_RDONLY);

 
   
    
        printf("%s", get_next_line(fd));
        printf("%s", get_next_line(fd));
        printf("%s", get_next_line(fd));
        printf("%s", get_next_line(fd));
        printf("%s", get_next_line(fd));
        printf("%s", get_next_line(fd));
        printf("%s", get_next_line(fd));
        printf("%s", get_next_line(fd));
        printf("%s", get_next_line(fd));
        printf("%s", get_next_line(fd));
        printf("%s", get_next_line(fd));
        printf("%s", get_next_line(fd));
        printf("%s", get_next_line(fd));
        printf("%s", get_next_line(fd));
        printf("%s", get_next_line(fd));
        printf("%s", get_next_line(fd));
        printf("%s", get_next_line(fd));
        printf("%s", get_next_line(fd));
       
    
    
    
}