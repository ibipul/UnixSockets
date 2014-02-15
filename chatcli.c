#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

main()
{
	
	struct sockaddr_in servaddr, myaddr;
	struct sockaddr_in client;
        int sockid;
	int connectid;
	int newsockid;
	int clientlen;

	char msg_snd[100];//="Indian Statistical Institute";
	char msg_rcv[100];
	int sendid,recvid;
	int port_id = 6000;


	sockid = socket(AF_INET, SOCK_STREAM, 0);

	bzero((char*)&servaddr, sizeof(struct sockaddr_in));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");// 192.168.23.44
	servaddr.sin_port = htons(port_id);
	
	connectid = connect(sockid, (struct sockaddr*)&servaddr, sizeof(struct sockaddr_in));
	if(connectid < 0)
	 printf("error connecting \n");
	while(1){
	
		printf("(you)Guest::\n");

		gets(msg_snd);
		sendid = sendto(sockid, msg_snd, 100, 0, (struct sockaddr*)&servaddr, sizeof(struct sockaddr_in));
		if(sendid < 0)
		printf("error sending\n");

		recvid = recvfrom(sockid, msg_rcv, 100, 0, (struct sockaddr*)&servaddr, &clientlen);
		if(recvid < 0)
			printf("error recieving\n");

		printf("server:: %s \n", msg_rcv);

	}
	return 0;
}
