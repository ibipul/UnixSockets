#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

main()
{
	
	struct sockaddr_in myaddr;
	struct sockaddr_in client;
        int sockid,sendid;
	int bindid;
	int newsockid;
	int clientlen;

	char msg_rcv[100];
	char msg_snd[100];
	int recvid;
	int port_id = 6000;


	sockid = socket(AF_INET, SOCK_STREAM, 0);

	bzero((char*)&myaddr, sizeof(struct sockaddr));
	myaddr.sin_family = AF_INET;
	myaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	myaddr.sin_port = htons(port_id);
	
	bindid = bind(sockid, (struct sockaddr*)&myaddr, sizeof(struct sockaddr_in));
	if(bindid < 0)
		printf("error \n");

	listen(sockid, 5);
	clientlen = sizeof(struct sockaddr_in);

		newsockid = accept(sockid, (struct sockaddr*)&myaddr, &clientlen);
		if(newsockid < 0)
			printf("error accepting\n");

	while(1) {
		
		printf("(you)Server::\n");
		recvid = recvfrom(newsockid, msg_rcv, 100, 0, (struct sockaddr*)&myaddr, &clientlen);
		if(recvid < 0)
			printf("error recieving\n");

		printf("Guest:: %s \n", msg_rcv);
		gets(msg_snd);
		sendid = sendto(newsockid, msg_snd, 100, 0, (struct sockaddr*)&myaddr, sizeof(struct sockaddr_in));
		if(sendid < 0)
		printf("error Sending\n");
		


	}

	return 0;
}
