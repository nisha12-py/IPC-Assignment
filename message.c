
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/msg.h>
//#define KEY 8979
struct msgbuf{
long mtype;
char data[512];
};

int main(int argc,char *argv[]){
struct msgbuf v;
int id;
struct msqid_ds buf;
id=msgget(49,IPC_CREAT|0644);
printf("id = %d\n",id);
v.mtype=atoi(argv[1]);
strcpy(v.data,argv[2]);
msgsnd(id,&v,strlen(v.data)+1,0);

msgctl(id,IPC_STAT,&buf);
printf(" the details of the queue\n");
printf("number of msgs in queue is %hi\n",buf.msg_qnum);
printf("max no of bytes in q %hi\n",buf.msg_qbytes);
return 0;
}
