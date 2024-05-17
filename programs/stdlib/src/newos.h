#ifndef NEWOS_H
#define NEWOS_H
#include <stddef.h>
#include <stdbool.h>


struct command_argument
{
    char argument[512];
    struct command_argument* next;
};

struct process_arguments
{
    int argc;
    char** argv;
};


void print(const char* filename);
int newos_getkey();

void* newos_malloc(size_t size);
void newos_free(void* ptr);
void newos_putchar(char c);
int newos_getkeyblock();
void newos_terminal_readline(char* out, int max, bool output_while_typing);
void newos_process_load_start(const char* filename);
struct command_argument* newos_parse_command(const char* command, int max);
void newos_process_get_arguments(struct process_arguments* arguments);
int newos_system(struct command_argument* arguments);
int newos_system_run(const char* command);
void newos_exit();
#endif