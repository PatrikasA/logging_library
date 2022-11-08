#include <logger.h>


void print_log()
{
    open_log_file("r");
    char line[3000];
    FILE** log = get_file_pointer();
    if(log != NULL){
        while(1) {
        fgets(line, 300, *log);
        if(line != NULL) 
            if(feof(*log)){
                close_log_file();
                break;
            }
            printf("%s", line);
        }
    }
}

void print_log_of_program(char* program)
{
    open_log_file("r");
    char line[300];
    char templine[300];
    FILE** log = get_file_pointer();
    char* token=malloc(sizeof(char)*300);
    while(!feof(*log)) {
        fgets(line, 300, *log);
        if(line != NULL)
            strcpy(templine, line);
            token = strtok(templine, "|");
            token = strtok(NULL, "|");
            token = strtok(NULL, " ");
            if(token != NULL) {
                if(strcmp(program, token) == 0) {
                    if(!feof(*log))
                        printf("%s", line);
                }
            }
        
    }
    free(token);
    close_log_file();
}

int main(int argc, char* argv[])
{
    if(argc > 2){
        if(strcmp(argv[1],"--program") == 0 || strcmp(argv[1],"-P") == 0)
            print_log_of_program(argv[2]);
    }
    else
        print_log();
}