#include "get_next_line.h"

// junta o buffer e retirada do container
char	*free_container(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

// retira a linha encontrada
char	*container_remove(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	// verifica o tamanhanho da sengunda linha
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	// tamanho do arquivo com o tamanho da primeira linha
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	// verifica se a linha e igual ao buffer
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

// pega a linha para o retorno da line da func get_next_line
char	*extract_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	// caso não encontre a line retorne NULL
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	// line ira receber meu buffer
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*read_container(int fd, char *res)
{
	char	*buffer;
	int		readed;

	// faz o malloc se n existir o res
	if (!res)
		res = ft_calloc(1, 1);
	// malloca o meu buffer
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	readed = 1;
	while (readed > 0)
	{
		if (BUFFER_SIZE < 0)
				return (NULL);
		// enquanto n for lido
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[readed] = 0;
		res = free_container(res, buffer);
		// finaliza meu if se caso encontre meu \n
		if (ft_strrchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_container(fd, buffer);
	if (!buffer)
		return (NULL);
	line = extract_line(buffer);
	buffer = container_next(buffer);
	return (line);

}
