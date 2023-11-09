#include <stdio.h>
#include <string.h>

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int main ()
{
	char *test = strdup("");
	printf("%lu\n", ft_strlen(""));
	printf("%lu", ft_strlen(test));	
}