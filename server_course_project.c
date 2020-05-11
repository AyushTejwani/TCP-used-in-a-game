#include <netdb.h> 
#include <netinet/in.h> 
#include <stdlib.h> 
#include<stdio.h>
#include <string.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#define MAX 80 
#define PORT 8080 
#define SA struct sockaddr 
char buff[MAX];

void func(int sockfd) 
{ 
	 char prev; 
	int n; 
	
	 
	while(1){ 
		bzero(buff, MAX); 

		read(sockfd, buff, sizeof(buff)); 
		
		printf("From client: %s\t To client : %c", buff,prev); 
		prev=buff[0];
	
		n = 0; 

		FILE * fPtr;

    fPtr = fopen("save.txt", "w");

    if(fPtr == NULL)
    {

        printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    }

		
	fprintf(fPtr,"%s",buff);



    fclose(fPtr);

			bzero(buff, MAX); 
		
	} 
} 


int main() 
{ 
	int sockfd, connfd, len; 
	struct sockaddr_in servaddr, cli; 


	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1) { 
		printf("socket creation failed...\n"); 
		exit(0); 
	} 
	else
		printf("Socket successfully created..\n"); 
	bzero(&servaddr, sizeof(servaddr)); 


	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
	servaddr.sin_port = htons(PORT); 


	if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) { 
		printf("socket bind failed...\n"); 
		exit(0); 
	} 
	else
		printf("Socket successfully binded..\n"); 


	if ((listen(sockfd, 5)) != 0) { 
		printf("Listen failed...\n"); 
		exit(0); 
	} 
	else
		printf("Server listening..\n"); 
	len = sizeof(cli); 


	connfd = accept(sockfd, (SA*)&cli, &len); 
	


	while(1)
	func(connfd); 
	

	close(sockfd); 
} 
