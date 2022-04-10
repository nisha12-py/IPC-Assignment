#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>

int main(){
int id;
char *r;
struct shmid_ds buf;
id=shmget(48,250,IPC_CREAT|0644);
printf("id= %d\n",id);
r=shmat(id,0,0);
printf("%s\n",r);
shmctl(id,IPC_RMID,&buf);
return 0;
}
