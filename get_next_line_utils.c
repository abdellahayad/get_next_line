#include "get_next_line.h"

size_t ft_strlen(const char *str)
{
    size_t i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char    *ft_strdup(char *s1)
{
    char    *ptr;
    int     i;

    ptr = malloc(ft_strlen(s1) + 1);
    if (!ptr)
        return (NULL);
    i = 0;
    while (ptr[i])
    {
        ptr[i] = s1[i];
        i++;
    }
    ptr[i] = '\0';
    return (ptr);
}

char *ft_strjoin(char *s1, char *s2)
{
    char    *dest;
    int     i;
    int     j;

    dest = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
    if (!dest)
        return (NULL);
    i = 0;
    j = 0;
    while (s1[j])
        dest[i++] = s1[j++];
    j = 0;
    while (s2[j])
        dest[i++] = s2[j++];
    dest[i] = '\0';
    return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t  i;
    char *str;

    if (!s)
        return (NULL);
    if (start > ft_strlen(s))
        return (ft_strdup(""));
    if (len > ft_strlen(s + start))
        len = ft_strlen(s + start);
    str = malloc((len + 1) * sizeof(char));
    if (!str)
        return (NULL);
    i  = 0;
    while (str[i])
    {
        str[i] = s[start + i];
        i++;
    }
    str[i] = '\0';
    return (str);
}