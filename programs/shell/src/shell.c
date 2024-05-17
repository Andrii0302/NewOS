#include "shell.h"
#include "stdio.h"
#include "stdlib.h"
#include "newos.h"
int main(int argc, char** argv)
{
    print("NewOS v1.0.0\n");
    while(1) 
    {
        print("> ");
        char buf[1024];
        newos_terminal_readline(buf, sizeof(buf), true);
        //newos_process_load_start(buf);
        print("\n");
        newos_system_run(buf);
        print("\n");
    }
    return 0;
} 