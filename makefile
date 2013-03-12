C=gcc
CFLAGS=-I.

hellomake: tcpSocket.c serverTcpSocket.c
	$(CC) -o echoServer serverTcpSocket.c
	$(CC) -o socketClient tcpSocket.c
