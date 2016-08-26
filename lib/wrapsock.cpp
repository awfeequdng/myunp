#include "unp.h"

int Socket(int family,int type,int protocol)
{
    int n;
    n = socket(family,type,protocol);
    if(n < 0)
        err_sys("socket error");
    return n;
}


void Listen(int fd,int backlog)
{
    char *ptr = NULL;

    if((ptr = getenv("LISTENQ")) != NULL)
        backlog = atoi(ptr);

    if(listen(fd,backlog) < 0)
        err_sys("listen error");

}

void Bind(int fd,const struct sockaddr *addr,socklen_t salen)
{
    if(bind(fd,addr,salen) < 0)
        err_sys("bind error");
}

void Connect(int fd, const sockaddr *addr, socklen_t len)
{
    if(connect(fd,addr,len) < 0)
        err_sys("connect error");
}

int Accept(int fd,struct sockaddr *addr,socklen_t *salenptr)
{
    int connfd ;
again:
    if((connfd = accept(fd,addr,salenptr)) < 0)
    {
#ifdef EPROTO
        if(errno == EPROTO || errno == ECONNABORTED)
#else
        if(errno == ECONNABORTED)
#endif
        {
            goto again;
        }
        else
            err_sys("connect error");
    }
    return connfd;
}
