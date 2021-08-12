#include "libft.h"

int	clean_up(char **str1, char **str2)
{
	free(*str1);
	*str1 = NULL;
	free(*str2);
	*str2 = NULL;
	return (-1);
}

char	*has_new_line(char **str)
{
	size_t			i;

	i = 0;
	if (*str == NULL)
		return (0);
	while (*(*str + i) != '\0')
	{
		if (*(*str + i) == '\n')
			return ((char *)(*str + i));
		i++;
	}
	return (NULL);
}

int	get_line(char **src, char **dest)
{
	char	*tmp;
	char	*sep;

	sep = has_new_line(src);
	if (!sep)
	{
		*dest = ft_strdup(*src);
		free(*src);
		*src = NULL;
		if (*dest == NULL)
			return (-1);
		return (0);
	}
	*sep = '\0';
	*dest = ft_strdup(*src);
	tmp = ft_strdup(++sep);
	if (tmp == NULL || *dest == NULL)
	{
		free(tmp);
		return (clean_up(src, dest));
	}
	free(*src);
	*src = tmp;
	return (1);
}

int	launch_read (char **rem, char **buf, int fd)
{
	char			*tmp;
	ssize_t			read_res;

	read_res = 1;
	while (!has_new_line(rem) && read_res > 0)
	{
		read_res = read(fd, *buf, BUFFER_SIZE);
		if (read_res < 0)
			return (-1);
		*(*buf + read_res) = '\0';
		tmp = ft_strjoin(*rem, *buf);
		if (!tmp)
			return (-1);
		free(*rem);
		*rem = tmp;
	}
	return (read_res);
}

int	get_next_line(int fd, char **line, int print)
{
	static char		*rem = 0;
	ssize_t			read_res;
	char			*buf;

	if (print)
		ft_putstr_fd("> ", 1);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || !line || !buf)
		return (clean_up(&buf, &rem));
	read_res = launch_read(&rem, &buf, fd);
	if (read_res < 0)
		return (clean_up(&buf, &rem));
	free(buf);
	return (get_line(&rem, line));
}
