#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i))
		i ++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (*(s + i))
	{
		*(str + i) = *(s + i);
		i++;
	}
	*(str + i) = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		range;
	size_t		i;

	if (!s || !(*s))
		return (NULL);
	i = ft_strlen(s);
	range = 0;
	if (start < i)
		range = i - start;
	if (range > len)
		range = len;
	str = (char *)malloc((range + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < range)
	{
		*(str + i) = *(s + start + i);
		i++;
	}
	*(str + i) = '\0';
	return (str);
}

char	*ft_strchr(const char *str, int c)
{
	char	*buf;

	if (!str)
		return (NULL);
	buf = (char *)str;
	while (*buf)
	{
		if (*buf == (unsigned char)(c & 0xFF))
			return (buf);
		buf++;
	}
	if (*buf == c)
		return (buf);
	else
		return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	join = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!join)
		return (NULL);
	ft_strlcpy(join, s1, len1 + 1);
	ft_strlcpy(join + len1, s2, len2 + 1);
	if (s1)
		free(s1);
	return (join);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	const size_t	srclen = ft_strlen(src);

	if (srclen + 1 < n)
	{
		ft_memcpy(dst, src, srclen + 1);
	}
	else if (n != 0)
	{
		ft_memcpy(dst, src, n - 1);
		dst[n - 1] = '\0';
	}
	return (srclen);
}

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    char *destc = (char *)dest;
    const char *srcc = (const char *)src;

    if (dest == NULL || src == NULL)
    {
        return dest;
    }

    if (dest < src)
    {
        while (n-- > 0)
        {
            *destc++ = *srcc++;
        }
    }
    else if (dest > src)
    {
        destc += n;
        srcc += n;
        while (n-- > 0)
        {
            *--destc = *--srcc;
        }
    }

    return dest;
}
