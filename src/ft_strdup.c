#include "libft.h"

int main()
{
    char source[] = "GeeksForGeeks";
    char *target = ft_strdup(source); 

    printf("Duplicate :%s\n", target);
    return 0;
}

char    *ft_strdup(const char *src)
{
    char    *dup;
    size_t  len;

    if (!src)
        return NULL;

    len = ft_strlen(src);
    dup = (char *)malloc((len + 1) * sizeof(char));
    if (!dup)
        return NULL;

    ft_strcpy(dup, src);
    return dup;
}