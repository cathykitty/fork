#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>

#define TOTALFORK 10
void movehanoi(int num,char from,char temp,char to);
int main(void){
	int num;
	pid_t pids;
	int runProcess = 0;
	printf("How many floors?\n");
	scanf("%d",&num);
	while(runProcess<TOTALFORK){
		pids = fork();
		if(pids<0){
			return -1;
		}else if(pids==0){
			// printf("Child ID:%d\n",getpid());
			// printf("Child\n");
			movehanoi(num,'A','B','C');
			return 0;
		}else{
			printf("Parents ID:%d\n",getpid());
			printf("Parents\n");
		}
		runProcess++;
	}
	return 0;
}
void outputmove(int num,char from,char to){
printf("%d : %dth floor moves from %c to %c.\n", getpid(),num,from,to);
}

void movehanoi(int num,char from,char temp,char to){
	if(num==1){
		outputmove(num,from,to);
	}
	else{
		movehanoi(num-1,from,to,temp);
		outputmove(num,from,to);
		movehanoi(num-1,temp,from,to);
}
}
