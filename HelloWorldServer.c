#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>
// 2-1. 서버 프로그램이 사용하는 포트를 9000 --> 10000으로 수정 
#define PORT 9000
//#define PORT 10000

// 2-2. 클라이언트가 접속했을 때 보내는 메세지를 변경하려면 buffer을 수정
//char buffer[100] = "hello, world\n";
char buffer[100] = "Hi, I'm server\n";

main( )
{
        int   c_socket, s_socket;
        struct sockaddr_in s_addr, c_addr;
        int   len;
        int   n,a,x;
        int rcvLen;
        char rcvBuffer[100],*jdy1,*jdy2;
        char jdyBuffer[100] = " ";

        s_socket = socket(PF_INET, SOCK_STREAM, 0);

        memset(&s_addr, 0, sizeof(s_addr));
        //s_addr.sin_addr.s_addr = htonl(INADDR_ANY);
        s_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
        s_addr.sin_family = AF_INET;
        s_addr.sin_port = htons(PORT);

        if(bind(s_socket, (struct sockaddr *) &s_addr, sizeof(s_addr)) == -1) {
                printf("Can not Bind\n");
                return -1;
        }

        if(listen(s_socket, 5) == -1) {
                printf("listen Fail\n");
                return -1;
        }

        while(1) {
                len = sizeof(c_addr);
                c_socket = accept(s_socket, (struct sockaddr *) &c_addr, &len);
                //3-3.클라이언트가 접속했을 때 "Client is connected" 출력
                printf("Client is connected\n");
                while(1){
                        rcvLen = read(c_socket, rcvBuffer, sizeof(rcvBuffer));
                        rcvBuffer[rcvLen] = '\0';
                        printf("[%s] received\n", rcvBuffer);
                        if(strncasecmp(rcvBuffer, "quit", 4) == 0 || strncasecmp(rcvBuffer, "kill server", 11) == 0)
                        {
                                break;
                        }
                        else if(!strncmp(rcvBuffer, "안녕하세요",strlen("안녕하세요")))
                          {
                                strcpy(buffer,"안녕하세요 만나서 반가워요 .");
                                n=strlen(buffer);
                                write(c_socket,buffer,n);
                          }
                        else if(!strncmp(rcvBuffer,"이름이 머야?",strlen("이름이 머야?")))
                         {
                                strcpy(buffer,"내이름을 정달영이야");
                                n = strlen(buffer);
                                write(c_socket,buffer,n);
                         }
                        else if(!strncmp(rcvBuffer,"몇 살이야?",strlen("몇 살이야?")))
                         {
                                strcpy(buffer,"나는 100살이야.");
                                n =strlen(buffer);
                                write(c_socket,buffer,n);
                        }

                        else if(!strncasecmp(rcvBuffer,"strlen ",7))
                        {
                         a  = strlen(rcvBuffer)-7;
                         sprintf(buffer,"길이 : %d",a);
                         write(c_socket, buffer,strlen(buffer));
                        }
                        else if (!strncasecmp(rcvBuffer,"strcmp ",7))
                        {
                          strtok(rcvBuffer," ");
                          jdy1=strtok(NULL," ");
                          jdy2=strtok(NULL," ");
                          x=strcmp(jdy1,jdy2);

                          sprintf(buffer,"%d\n",x);
                          write(c_socket,buffer,strlen(buffer));

                        }
                        else{
                        n =strlen(buffer);
                        write(c_socket, jdyBuffer, n);
                        }

                }
                close(c_socket);
                if(!strncasecmp(rcvBuffer, "kill server", 11))
                        break;
        }
        close(s_socket);
}
~                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
~                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
~                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
~                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
~                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
~                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
~                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
~                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
~                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
~                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
~                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
~                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
~                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
~                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
~                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
~                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
~                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
~                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
~                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
                                                                                                                                                                                                                                                                                                                                                                                                                                                                          36,2-9       모두
