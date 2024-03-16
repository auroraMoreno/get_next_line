#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("prueba.txt", O_RDWR);
    
	line = get_next_line(fd);
	printf("%s", line);
	free(line);

	line = get_next_line(fd);
	printf("%s", line);
	free(line);

	line = get_next_line(fd);
	printf("%s", line);
	free(line);


	close(fd);

	return (0);
}