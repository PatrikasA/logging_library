#include <stdio.h>
#include <unistd.h>
#include <logger.h>

int main()
{
    int i = 10;
    open_log_file("a");
    while(i>0)
    {
        i--;
        write_to_log("program_that_logs","green is not a creative color\n",1);
    }
    close_log_file();
}