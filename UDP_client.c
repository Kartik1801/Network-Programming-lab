#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
int main(){
    int clientSocket , port_number, nBytes;
    char buffer[1024];
    struct sockaddr_in serverAddr;
    socklen_t addr_size;

    //Creating UDP Socket 
    clientSocket=socket(PF_INET, SOCK_DGRAM, 0);

    //Configure Settings in Address Stuct 
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(7891);
    serverAddr.sin_addr.s_addr=inet_addr("127.0.0.1");
    memset(serverAddr.sin_Zero,'\0',sizeof serverAddr.sin_Zero);

    //Initialize size variable 
    addr_size =sizeof serverAddr;
    
    while(1){
        printf("Write Your Message: ");
        fgets(buffer,1024,stdin);
        printf("Your Message: %s",buffer);

        nBytes= strlen(buffer);

        // Send message to server: 
        sendto(clientSocket,buffer,nBytes,0,(struct sockaddr *)&serverAddr,addr_size);

        //Recieving message from sever 
        nBytes=recvfrom(clientSocket,buffer,1024,0,NULL,NULL);
        printf("Recieved: %s\n",buffer);
    }
    return 0;
}