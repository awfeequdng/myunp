include ../Make.defines

PROGS = daytimetcpcli daytimetcpcliv6 daytimetcpsrv

all:${PROGS}
	

daytimetcpcli: daytimetcpcli.o
	${CC} ${CFLAGS} -o $@ $^ ${LIBS}
 
daytimetcpcliv6:daytimetcpcliv6.o
	${CC} ${CFLAGS} -o $@ $^ ${LIBS}

daytimetcpsrv: daytimetcpsrv.o
	${CC} ${CFLAGS} -o $@ $^ ${LIBS}

clean:
	rm *.o ${PROGS}
