#include<unistd.h>
#include<stdio.h>


int fds[2];

void parent_code()
{
char *buf1 = "aaaaaaaaaaaaaaa";
char *buf = "bbbbbbbbbbbbbbb";
close(fds[0]);
write(fds[1],buf1,20);
write(fds[1],buf,20);
printf("End of Parent\n");

}

void child()
{
char buf[100];
int n,i;
close(fds[1]);
n = read(fds[0],buf,100);
printf("no. of char read = %d\n",n);
for(i=0;i<n;i++)
printf("%c",buf[i]);
printf("End of child\n");
}

main()
{
int res, i;
pid_t p;
res = pipe(fds);

p = fork();

if(p == 0)
{
child();
}
else
{
parent_code();
}
}
