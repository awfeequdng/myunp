#ifndef __UNP_H_
#define __UNP_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>


#define MAX_LINE 200

#define SA struct sockaddr


#define	LISTENQ		1024	/* 2nd argument to listen() */

//  lib/error.c
void err_sys(const char *fmt,...);
void err_msg(const char *fmt,...);
void err_ret(const char *fmt,...);
void err_quit(const char *fmt,...);

//wrap socket function
int Socket(int family,int type,int protocol);
int Accept(int fd,struct sockaddr *addr,socklen_t *salenptr);
void Connect(int fd, const sockaddr *addr, socklen_t len);
void Bind(int fd,const struct sockaddr *addr,socklen_t salen);
void Listen(int fd,int backlog);

//wrap unix function
void Write(int fd, void *ptr, size_t nbytes);
void Close(int fd);

//daytimetcpcli.cpp
void daytimetcpcli(int argc,char *argv[]);
//daytimetcpcliv6.cpp
void daytimetcpcliv6(int argc,char *argv[]);

#endif //__UNP_H_
