#include "libft.h"

/* Function copies up to (dstsize - 1) characters from the string 'src' to
'dst', NUL-terminating the result if dstsize is not 0. */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;

	if (!src || !dst)
		return (0);
	srclen = ft_strlen(src);
	if (dstsize == 0)
		return (srclen);
	if (dstsize <= srclen)
	{
		ft_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = '\0';
	}
	else
	{
		ft_memcpy(dst, src, srclen);
		dst[srclen] = '\0';
	}
	return (srclen);
}

/* Function allocates memory for a copy of the string 's1', does the copy,
and returns a pointer to it. */
char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	len;

	len = ft_strlen(s1);
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (dup)
		ft_strlcpy(dup, s1, len + 1);
	return (dup);
}

/* Allocates memory and returns a new string, which is the result of the
concatenation of ’s1’ and ’s2’ */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*new_str;
	unsigned int	s1_len;
	unsigned int	s2_len;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (new_str == NULL)
		return (new_str);
	new_str = (char *)ft_memcpy(new_str, s1, s1_len);
	ft_memcpy((new_str + s1_len), s2, s2_len);
	new_str[s1_len + s2_len] = '\0';
	return (new_str);
}
