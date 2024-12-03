#ifndef GET_NEXT_LINA_H
# define GET_NEXT_LINA_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
#include <libc.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

char *get_next_line(int fd);
size_t ft_strlen(const char *str);
char    *ft_strdup(char *s1);
char *ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

# endif
