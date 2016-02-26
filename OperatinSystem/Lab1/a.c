#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include  <sys/types.h>

char command[512];
char *argv[256];

void execute(char** command)
{
    pid_t  pid;
    int status = 0;
    if ((pid = fork()) < 0)
    {
        printf("*** ERROR forking child process failed ***\n");
        exit(1);
    }
    if (pid == 0)
    {
        if (execvp(*command, command) < 0)
        {
            printf("*** ERROR exec failed ***\n");
            exit(1);
        }
    }
    else
    {
        while (pid != wait(&status));
    }
}

void parse(char *command, char **argv)
{
    while (*command != '\0')
    {
        while (*command == ' ' || *command == '\n')
        {
            *command = '\0';
            command++;
        }
        *argv = command;
        argv++;
        while (*command != '\0' && *command != ' ' && *command != '\t')
            command++;
    }
    *argv = '\0';
}

int main(int argc, char** args)
{
    if (argc > 1)
        freopen(args[1], "r", stdin);
    while ("DO")
    {
        printf("Prompt >> ");
        gets(command);
        printf("\n");

        parse(command, argv);
        if (strcmp("exit", argv[0]) == 0)
            exit(0);
        execute(argv);
    }
    return 0;
}
