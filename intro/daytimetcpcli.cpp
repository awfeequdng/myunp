#include "../lib/unp.h"

void daytimetcpcli(int argc,char *argv[])
{
    int sockfd;
    if((sockfd = socket(AF_INET,SOCK_STREAM,0)) < 0)
        err_sys("socket error");

    if(argc != 2)
        err_quit("usage : a.out <IP address>");

    sockaddr_in server_addr;
    bzero(&server_addr,sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(13);
    if(inet_pton(AF_INET,argv[1],&server_addr.sin_addr) <= 0)
        err_sys("inet_pton error for %s",argv[1]);

    if(connect(sockfd,(sockaddr *)&server_addr,sizeof(server_addr)) < 0)
        err_sys("connect error");
    int n ;
    char bufline[MAX_LINE];
    while( (n = read(sockfd,bufline,MAX_LINE)) > 0)
    {
        bufline[n] = 0;
        if(fputs(bufline,stdout) == EOF)
            err_sys("fputs error");

    }

    if(n<0)
        err_sys("read error");
}


int main(int argc,char *argv[])
{
    daytimetcpcli(argc,argv);
    return 0;
}
