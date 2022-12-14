#include <stdio.h>
#include <syslog.h>
#include <errno.h>
#include <string.h>

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
    if (f == NULL)
    {
        syslog(LOG_ERR, "Error opening the file %s: Error %d - %s\n", writefile, errno, strerror(errno));
        closelog();
        return 1;
    } else {
        syslog(LOG_DEBUG, "Writing %s to %s\n", writefile, writestr);
        fprintf(f, "%s", writestr);
    }

    fclose(f);

    closelog();
    return 0;
}