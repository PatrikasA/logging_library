#include <stdio.h>
#include <unistd.h>
#include <logger.h>

int main()
{
    printf("I am alive");
    open_log_file("a");
    while(1)
    {
        sleep(5);
        printf("5 seconds have passed!");
        write_to_log("program_that_logs","5 seconds have passed!",1);
    }
}