#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>

extern char **getln();

main() {
	int i;
	char **args; 
	int num;
	int tot;
	int t;
	int chick=0;
	int time;
	pid_t pd;
	char * string;



	
	while(1) {
		args = getln();



		for(i = 0; args[i] != NULL; i++) {
			printf("Argument %d: %s\n", i, args[i]);

			if(strcmp(args[i],"exit")==0)
			{
			
				exit(0);
			}

			else if (strcmp(args[i],"add")==0)
			{
				num=0;
				tot=0;
				time=0;
				string=malloc(450);
				while(args[i+1]!=NULL)//add all number
				{
					strcpy(string,args[i+1]); 
					num=strtol(string,NULL,0);
					tot=num+tot;
					
					
					t=args[i+1][0];
					if(isdigit(t) == 0)
					{
						chick=2;
					}
					
					time=time+1;
					i=i+1;	
				}
				if(time==0||chick==2)
				{
					printf("can not use this input");
				}	//when in put do not have any thing		
				else
				{
					printf("%d\n",tot);
				}
				free(string);
			}

			else if(strcmp(args[i], "about") == 0)
			{
				if (i == 0) 
				{
					printf("Name: Haoxiang Dong\n");
					printf("Id 0850990\n");
					printf("School: University of Guelph\n");
					printf("Course: CIS*3110 Operating Systems\n");	
				}
				else
				printf("Invalid command\n");
			}

			else(args[i+1]==NULL)
			{
				
				pd=fork();
				
				if(pd<0)
				{
					printf(" failed\n");
				}
				else if(pd==0)
				{
					execvp(args[0],args);
					exit(0);
				}
				else
				{
					wait(NULL);
				}
			}





		}
	}
}

