#include <stddef.h>
#include <stdlib.h>
void *ft_memset(void *s, int c, size_t n)
{
    unsigned char *dest_ptr = (unsigned char *)s;

    while (n--)
    {
        *dest_ptr++ = (unsigned char)c;
    }
    return s;
}


void *ft_calloc(size_t count, size_t size)
{
    void *ptr;
    int SIZE_MAX = size;

    if (count == 0 || size == 0 || count > SIZE_MAX / size)
    {
        return NULL;
    }

    ptr = malloc(count * size);
    if (ptr == NULL)
    {
        return NULL;
    }

    if (ft_memset(ptr, 0, count * size) == NULL)
    {
        free(ptr);
        return NULL;
    }

    return ptr;
}

