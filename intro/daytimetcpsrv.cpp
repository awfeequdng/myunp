#include "../lib/unp.h"
#include <time.h>

void daytimetcpsrv()
{
    int listenfd,connfd;
    listenfd = Socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in server_addr;
    bzero(&server_addr,sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(13);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    Bind(listenfd,(SA *)&server_addr,sizeof(server_addr));

    Listen(listenfd,LISTENQ);
    time_t ticks;
    char buf[MAX_LINE];
    while(true)
    {
        connfd = Accept(listenfd,(SA*)NULL,NULL);
        ticks = time(NULL);
        snprintf(buf,MAX_LINE,"%s\r\n",ctime(&ticks));
        Write(connfd,buf,strlen(buf));
        Close(connfd);
    }

}

int main()
{
    daytimetcpsrv();
    return 0;
}
