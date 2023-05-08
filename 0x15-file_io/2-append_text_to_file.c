#include "file.h"

/**
 * append_text_to_file - appends text to a file
 * @filename: the name of the file to append text to
 * @text_content: the content to append to the file
 *
 * Return: 1 on success, -1 on failure
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int file_desc, _write;

	file_desc = open(filename, O_WRONLY | O_APPEND);
	if (file_desc == -1)
		return (-1);

	if (!text_content)
	{
		close(file_desc);
		return (1);
	}

	_write = write(file_desc, text_content, slen(text_content));
	if (_write == -1 || _write != slen(text_content))
	{
		close(file_desc);
		return (-1);
	}

	close(file_desc);
	return (1);
}
