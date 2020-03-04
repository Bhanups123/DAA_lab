#include <unistd.h>
#include <stdio.h>         
#include <stdlib.h>       
#include <sys/types.h>  
#include <sys/wait.h>       
#include <errno.h>          
#include <semaphore.h>      
#include <fcntl.h>          
#define PHILO_S "/philo_spoon"
#define PHILO_F "/philo_fork"

int main (){
    int i;                       
    sem_t *sem;                
    pid_t pid;                
    int n=5;              
    int svalue=3, fvalue=3;              

    sem_t *sem_spoon = sem_open(PHILO_S , O_CREAT, 0644, svalue);
    sem_t *sem_fork = sem_open(PHILO_F , O_CREAT, 0644, fvalue);

    for (i = 0; i < n; i++){
        pid = fork ();
        if (pid < 0) {
            sem_unlink (PHILO_S );   
            sem_unlink (PHILO_F );               
            sem_close(sem_spoon);  
            sem_close(sem_fork);   
        }
        else if (pid == 0)
            break;              
    }


    if (pid == 0){
		
        //printf(" Philosopher %d is hungry\n", i);
        //sleep (2);                                          
        sem_wait (sem_spoon);
        printf(" Philosopher %d has picked a spoon\n", i);
        sleep (2);           
        sem_wait (sem_fork);
        printf(" Philosopher %d has picked a fork and is eating\n", i);   
        sleep (2);
        sem_post (sem_spoon); 
        printf(" Philosopher %d has put down the spoon\n", i);                    
        sem_post (sem_fork);                           
        printf(" Philosopher %d has put down the fork and finished eating\n", i); 
    }
    else{
		while (pid = waitpid (-1, NULL, 0)){
            if (errno == ECHILD)
                break;
        }

            sem_unlink (PHILO_S );   
            sem_unlink (PHILO_F );               
            sem_close(sem_spoon);  
            sem_close(sem_fork); 
        
        printf ("\nAll Philosphers have eaten.\n");

    }    

    
    return 0;
}
