#include <libc.h>
#include "get_next_line.h"
void gg(void)
{
    system("leaks a.out");
}
int main()
{
   //atexit(gg);
    int fd = open("get_next_line.h", O_RDONLY);

 
   
    
        int i = 0;
        while (i < 23)
        {
            char *s =  get_next_line(fd);
            printf("%s", s);
            free(s);
            i++;
        } 
}




