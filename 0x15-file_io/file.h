#ifndef _FILE_H
#define _FILE_H

#include "main.h"

/**
 * slen - Calculates the length of a string recursively
 * @s: String to measure
 *
 * Return: Length of string
 */
__home int slen(char *s)
{
	if (!*s)
		return (0);
	s++;
	return (1 + slen(s));
}

/**
 * create_buffer - Allocates memory for a buffer
 * @file: File being worked on
 *
 * Return: Pointer to buffer
 */
__home char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (!buffer)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}
	return (buffer);
}

/**
 * close_file - Closes a file descriptor
 * @file_desc: File descriptor to close
 *
 * Return: Nothing
 */
__home void close_file(int file_desc)
{
	int c;

	c = close(file_desc);

	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_desc);
		exit(100);
	}
}

#endif /* _FILE_H */

