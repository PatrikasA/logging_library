#include <logger.h>
#include <sqlite3.h>


void print_res(sqlite3_stmt *res)
{
    while(sqlite3_step(res) != SQLITE_DONE)
    {
        printf("%d %s %s %s %s",sqlite3_column_int(res,0),
        sqlite3_column_text(res, 1), sqlite3_column_text(res, 2),
        sqlite3_column_text(res, 3), sqlite3_column_text(res, 4));
    }
}

void print_log(char* program)
{
    sqlite3_stmt *res;
    sqlite3** DB = get_database_pointer();
    char* query = NULL;
    
    if(program != NULL){
        char* temp = "SELECT * FROM Logs WHERE program=";
        char query[255];
        snprintf(query, 255,"%s '%s'",temp,program);
    }
    else
        query = "SELECT * FROM Logs";
    
    sqlite3_prepare_v3(*DB, query, -1, 0, &res, 0);
    print_res(res);
}

// void print_log_of_program(char* program)
// {
//     open_log_file("r");
//     char line[300];
//     char templine[300];
//     FILE** log = get_file_pointer();
//     char* token=malloc(sizeof(char)*300);
//     while(!feof(*log)) {
//         fgets(line, 300, *log);
//         if(line != NULL)
//             strcpy(templine, line);
//             token = strtok(templine, "|");
//             token = strtok(NULL, "|");
//             token = strtok(NULL, " ");
//             if(token != NULL) {
//                 if(strcmp(program, token) == 0) {
//                     if(!feof(*log))
//                         printf("%s", line);
//                 }
//             }
        
//     }
//     free(token);
//     close_log_file();
// }

int main(int argc, char* argv[])
{
    if(argc > 2){
        if(strcmp(argv[1],"--program") == 0 || strcmp(argv[1],"-P") == 0)
            print_log(argv[2]);
    }
    else
        print_log(NULL);
}