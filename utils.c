#include "monty.h"

/**
 * is_comment_line - checks if a line is a comment or empty
 * @line: input line
 * Return: 1 if comment or empty, 0 otherwise
 */
int is_comment_line(char *line)
{
    int i = 0;

    if (!line)
        return (1);

    /* skip spaces and tabs */
    while (line[i] == ' ' || line[i] == '\t')
        i++;

    /* empty line */
    if (line[i] == '\0' || line[i] == '\n')
        return (1);

    /* comment line */
    if (line[i] == '#')
        return (1);

    return (0);
}
