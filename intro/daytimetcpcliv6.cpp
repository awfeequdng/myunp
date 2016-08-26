#include"../lib/unp.h"

void daytimetcpcliv6(int argc,char *argv[])
{
    if(argc != 2)
        err_msg("usage : a.out <IP address>");

    int sockfd = socket(AF_INET6,SOCK_STREAM,0);
    if(sockfd<0)
        err_sys("socket error!");
    struct sockaddr_in6 ser_addr;
    bzero(&ser_addr,sizeof(ser_addr));

    ser_addr.sin6_family = AF_INET6;
    ser_addr.sin6_port = htons(13);
    if(inet_pton(AF_INET6,argv[1],&ser_addr.sin6_addr) <=0 )
    {
        err_quit("inet_pton error for %s ",argv[1]);
    }

    if(connect(sockfd,(SA*)&ser_addr,sizeof(ser_addr)) < 0)
        err_sys("connect error");

    int n ;
    char recvline[MAX_LINE];
    while((n = read(sockfd,recvline,MAX_LINE)) > 0)
    {
        recvline[n] = 0;
        if(fputs(recvline,stdout) == EOF)
            err_sys("fputs error");
    }
    if(n < 0)
        err_sys("read error");

}

int main(int argc,char *argv[])
{
    daytimetcpcliv6(argc,argv);
    return 0;
}
