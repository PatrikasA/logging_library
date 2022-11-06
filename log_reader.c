#include "logger.h"


void print_log()
{
    open_log_file("r");
    char line[300];
    FILE** log = get_file_pointer();
    while(!feof(*log)) {
        fgets(line, 300, *log);
        if(line != NULL) 
            printf("%s", line);
        }
}

void print_log_of_program(char* program)
{
    char line[300];
    char templine[300];
    open_log_file("r");
    FILE** log = get_file_pointer();
    char* token=malloc(sizeof(char)*300);
    while(!feof(*log)) {
        fgets(line, 300, *log);
        if(line != NULL)
            strcpy(templine, line);
            printf("\n%s\n",templine);
            token = strtok(line, " ");
            token = strtok(NULL, " ");
            token = strtok(NULL, " ");
            printf("\n%s\n",token);
            if(token != NULL) {
                if(strcmp(program, token) == 0) {
                    printf("%s", line);
                }
            }
        }
}

int main(int argc, char* argv[])
{
    open_log_file("w");
    write_to_log("program1","We do be logging though", 1);
    close_log_file();
    open_log_file("r");
    print_log();
    //print_log_of_program("program1");
}