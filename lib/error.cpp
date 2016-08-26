#include "unp.h"
#include <stdarg.h>
#include <syslog.h>

int daemon_proc = 0;        //set nonzero by daemon_init();


/* Print message and return to caller
 * Caller specifies "errorflag" and "level"
*/
static void err_doit(int errorflag,int level,const char *fmt,va_list ap)
{
    int err_save,n;
    char buf[MAX_LINE];
    err_save = errno;
#ifdef HAVE_VSNPRINTF
    vsnprintf(buf,MAX_LINE,fmt,ap);     //save
#else
    vsprintf(buf,fmt,ap);       //not save
#endif
    n = strlen(buf);
    if(errorflag)
        snprintf(buf+n,MAX_LINE-n,": %s",strerror(err_save));
    strcat(buf,"\n");

    if(daemon_proc)
        syslog(level,buf);
    else
    {
        fflush(stdout);
        fputs(buf,stdout);
        fflush(stdout);
    }

}

/* Fatal error related to system call
 * Print message and terminate */

void err_sys(const char *fmt,...)
{
    va_list ap;
    va_start(ap,fmt);
    err_doit(1,LOG_ERR,fmt,ap);
    va_end(ap);
    exit(0);
}

/* Nonfatal error unrelated to system call
 * Print message and return
*/
void err_msg(const char *fmt,...)
{
    va_list ap;
    va_start(ap,fmt);
    err_doit(0,LOG_INFO,fmt,ap);
    va_end(ap);

}
/* Nonfatal error related to system call
 * Print message and return
*/
void err_ret(const char *fmt,...)
{
    va_list ap;
    va_start(ap,fmt);
    err_doit(1,LOG_ERR,fmt,ap);
    va_end(ap);
}
/* Fatal error unrelated to system call
 * Print message and terminate
*/
void err_quit(const char *fmt,...)
{
    va_list ap;
    va_start(ap,fmt);
    err_doit(0,LOG_ERR,fmt,ap);
    va_end(ap);
    exit(0);
}
