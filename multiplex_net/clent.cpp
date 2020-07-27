/*************************************************************************
	> File Name: clent.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2020年07月24日 星期五 14时52分04秒
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <stdlib.h>
#include <arpa/inet.h>
#define IP "127.0.0.1"

#define PORT 8888

int main()
{
        int cli_fd;
        struct sockaddr_in serv_addr;
        
        cli_fd = socket(AF_INET, SOCK_STREAM, 0);
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(PORT);
        serv_addr.sin_addr.s_addr = inet_addr(IP);
        
        if(connect(cli_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr))==-1)
    {
                perror("connect 出现问题");
                exit(-1);
            
    }
        printf("客户端启动成功");
    char pack[1000];
    while(1) {
        scanf("%s", pack);
        printf("pack: %s", pack);
        send(cli_fd, &pack, sizeof(pack),0);
    }
}
