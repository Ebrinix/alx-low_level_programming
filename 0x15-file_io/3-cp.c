#include "file.h"

/**
 * main - copies the content of a file to another file
 *
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, exit with code 97-100 on failure
 */
 
#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
	int file_desc_from, file_desc_to, _read, _write;
	char buffer[BUFFER_SIZE];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	file_desc_from = open(argv[1], O_RDONLY);
	if (file_desc_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	file_desc_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (file_desc_to == -1)
	{
		close(file_desc_from);
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}

	while ((_read = read(file_desc_from, buffer, BUFFER_SIZE)))
	{
		if (_read == -1)
		{
			close(file_desc_from);
			close(file_desc_to);
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			exit(98);
		}

		_write = write(file_desc_to, buffer, _read);
		if (_write == -1 || _write != _read)
		{
			close(file_desc_from);
			close(file_desc_to);
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			exit(99);
		}
	}

	if (close(file_desc_from) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_desc_from);
		exit(100);
	}

	if (close(file_desc_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_desc_to);
		exit(100);
	}

	return (0);
}
