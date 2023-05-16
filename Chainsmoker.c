#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t tobacco, paper, matches, agent, tobacco_paper, paper_matches, tobacco_matches;

void *agent_thread(void *arg) {
    while(1) {
        sem_wait(&agent);
        int ingredients = syscall(335);
	ingredients %= 3;
        if(ingredients == 0) {
            sem_post(&tobacco_paper);
            printf("Agent puts tobacco and paper on the table.\n");
        }
        else if(ingredients == 1) {
            sem_post(&paper_matches);
            printf("Agent puts paper and matches on the table.\n");
        }
        else {
            sem_post(&tobacco_matches);
            printf("Agent puts tobacco and matches on the table.\n");
        }
    }
}

void *smoker_thread(void *arg) {
    int smoker_id = *(int *)arg;
    while(1) {
        if(smoker_id == 0) {
            sem_wait(&paper_matches);
            printf("Smoker with tobacco is smoking.\n");
            sem_post(&agent);
        }
        else if(smoker_id == 1) {
            sem_wait(&tobacco_matches);
            printf("Smoker with paper is smoking.\n");
            sem_post(&agent);
        }
        else {
            sem_wait(&tobacco_paper);
            printf("Smoker with matches is smoking.\n");
            sem_post(&agent);
        }
        if(smoker_id == 0) {
            printf("Smoker with tobacco releases ingredients.\n");
        } else if(smoker_id == 1) {
            printf("Smoker with paper releases ingredients.\n");
        } else {
            printf("Smoker with matches releases ingredients.\n");
        }
        usleep(1000000); // smoking time 1 sec
    }
}

int main() {
    pthread_t agent_tid, smoker_tid[3];
    int smoker_id[3] = {0, 1, 2};

    sem_init(&tobacco, 0, 0);
    sem_init(&paper, 0, 0);
    sem_init(&matches, 0, 0);
    sem_init(&agent, 0, 1);
    sem_init(&tobacco_paper, 0, 0);
    sem_init(&paper_matches, 0, 0);
    sem_init(&tobacco_matches, 0, 0);

    pthread_create(&agent_tid, NULL, agent_thread, NULL);
    for(int i=0; i<3; i++) {
        pthread_create(&smoker_tid[i], NULL, smoker_thread, &smoker_id[i]);
    }

    pthread_join(agent_tid, NULL);
    for(int i=0; i<3; i++) {
        pthread_join(smoker_tid[i], NULL);
    }

    sem_destroy(&tobacco);
    sem_destroy(&paper);
    sem_destroy(&matches);
    sem_destroy(&agent);
    sem_destroy(&tobacco_paper);
    sem_destroy(&paper_matches);
    sem_destroy(&tobacco_matches);

    return 0;
}