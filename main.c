#include "monty.h"

globales_t globalvar = {NULL, NULL, NULL};

/**
 * main - entry point for the CLI program
 * @argc: count of arguments passed to the program
 * @argv: pointer to an array of char pointers to arguments
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */

int main(int argc, char **argv)
{
    FILE = *file;
    char *token = NULL;
    size_t line_buf_size = 0;
    int line_number = 0, flag = 0, flag2 = 0;
    ssize_t line_size;
    stack_t *stack = NULL;
/* number of file mute be two*/
    if (argc != 2)
        stderr_usage();

/* to open and check file */
    file = globalvar.fd
    file = fopen(argv[1], "r");
    if (file == NULL)
        stderr_fopen(argv[1]);

    line_size = getline(&globalvar.line_buf, &line_buf_size, file);
    if (globalvar.line_buf[0] == '#')
        line_size = getline(&globalvar.line_buf, &line_buf_size, file);
    while (line_size >= 0)
    {flag = 0;
        flag2 = 0;
        line_number++;
        token = strtok(globalvar.line_buf, DELIM);
        globalvar.token2 = strtok(NULL, DELIM);
        if (token == NULL)
        {flag2 = 1;
            nop(&stack, line_number); }
        if (flag2 == 0)
        {
            if (token[0] == '#')
            {
                line_size = getline(&globalvar.line_buf,
                            &line_buf_size, file);
                flag = 1; }}
        if (flag == 0)
        {get_builtin(token, &stack, line_number);
            line_size = getline(&globalvar.line_buf, &line_buf_size,
                        file); }}
    free_dlistint(stack);
    free(globalvar.line_buf);
    globalvar.line_buf = NULL;
    fclose(file);
    return (EXIT_SUCCESS);
}
