#include <stdio.h>
#include <unistd.h>
#include <logger.h>

int main()
{
    open_log_file();
    create_database();
    write_to_log("program_that_logs","green is not a creative color\n",1);
    close_log_file();
}