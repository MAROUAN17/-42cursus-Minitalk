#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "header.h"

void    send_back(siginfo_t *info)
{
    pid_t c_pid;

    c_pid = info->si_pid;
    kill(c_pid, SIGUSR1);
}

int check_null_terminator(char *string)
{
    int i;
    int allZeros;

    i = 0;
    allZeros = 0;
    while(*(string + i) && *(string + i) == '0')
    {
        allZeros++;
        i++;
    }
    return (allZeros);
}

void    display_character(char *string)
{
    int asci_char;

    asci_char = ft_atoi_base(string);
    ft_printf("%c", asci_char);
}

void    decrypt_message(int signum, siginfo_t *info, void *context)
{
    int         allZeros;
    char        *tmp;
    static char byte[9];
    static int  index;

    tmp = context;
    if(index < 8)
    {
        if(signum == SIGUSR1)
            byte[index] = '1';
        else if(signum == SIGUSR2)
            byte[index] = '0';
        index++;
    }
    if(index == 8)    
    {
        byte[index] = '\0';
        allZeros = check_null_terminator(byte);
        if(allZeros == 8)
            send_back(info);
        else
            display_character(byte);
        index = 0;
    }
}

int main()
{
    pid_t               pid;
    struct sigaction    sa;

    pid = getpid();
    ft_printf("PID -> %d\n", pid);
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = decrypt_message;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while(1)
    {
    }
    return (0);
}