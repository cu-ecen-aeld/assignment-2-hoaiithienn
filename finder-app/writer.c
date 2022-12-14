#include <stdio.h>
#include <syslog.h>



int main(int argc, char** argv)
{
    char * writefile;
    char * writestr;

    openlog(NULL, 0, LOG_USER);

    if (argc != 3)
    {
        syslog(LOG_ERR, "Requiring 2 arguments!");
        closelog();
        return 1;
    } else {
        writefile = argv[1];
        writestr  = argv[2];
        syslog(LOG_INFO, "Program Name Is: %s. File Name is: %s. String is: %s\n", argv[0], writefile, writestr);
    }

    FILE * f;
    f = fopen(writefile, "w");
    fprintf(f, "%s", writestr);
    syslog(LOG_DEBUG, "Writing %s to %s\n", writefile, writestr);
    fclose(f);

    closelog();
}