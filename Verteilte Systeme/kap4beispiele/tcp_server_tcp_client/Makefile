all: tcp_srv tcp_clt

tcp_srv: tcp_server.c
	gcc -o tcp_srv tcp_server.c

tcp_clt: tcp_client.c
	gcc -o tcp_clt tcp_client.c

clean:
	rm tcp_srv tcp_clt

