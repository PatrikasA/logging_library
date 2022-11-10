#include <logger.h>
#include <sqlite3.h>

int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    NotUsed=0;
    for (int i = 0; i < argc; i++) {

        printf("%s ", argv[i] ? argv[i] : "NULL");
    }
    return 0;
}

void print_log(char* program)
{
    char* err_msg=NULL;
    sqlite3_stmt *res;
    sqlite3** DB = get_database_pointer();
    char query[255];
    
    if(program != NULL){
        char* temp = "SELECT * FROM Logs WHERE program=";
        snprintf(query, 255,"%s'%s'",temp,program);
    }
    else
        strcpy(query, "SELECT * FROM Logs");
    int rc = sqlite3_exec(*DB, query, callback,0,&err_msg);
    sqlite3_free(err_msg);
}


int main(int argc, char* argv[])
{
    open_log_file();
    if(argc > 2){
        if(strcmp(argv[1],"--program") == 0 || strcmp(argv[1],"-P") == 0)
            print_log(argv[2]);
    }
    else
        print_log(NULL);
    close_log_file();
}