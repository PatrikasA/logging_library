#include "logger.h"

int main(int argc, char* argv[])
{
    char* log_message="This is a test, yo\n";
    write_to_log("test_prog",log_message,1);
    printf("%s\n",argv[0]);
}