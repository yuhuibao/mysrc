#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_PHI 5

pthread_mutex_t forks[NUM_PHI];
int dinner_time = 1;
pthread_mutex_t locks[NUM_PHI];
void *work(void *threadid) {
  long tid = (long)threadid;
  while (dinner_time) {
    pthread_mutex_lock(&forks[tid]);
    // pthread_mutex_lock(&locks[tid]);
    // printf("phi %ld picks up left fork\n", tid);
    // pthread_mutex_unlock(&locks[tid]);
    pthread_mutex_lock(&forks[(tid + 1) % NUM_PHI]);
    printf("philosopher %ld eating with fork %ld and %ld\n", tid, tid,
           (tid + 1) % NUM_PHI);
    srand(time(0));
    sleep(rand() % 10);
    pthread_mutex_unlock(&forks[tid]);
    // pthread_mutex_lock(&locks[tid]);
    // printf("phi %ld drops left fork\n", tid);
    // pthread_mutex_unlock(&locks[tid]);
    pthread_mutex_unlock(&forks[(tid + 1) % NUM_PHI]);
    printf("philosopher %ld finishes eating and starts thinking\n", tid);
    srand(time(0));
    sleep(rand() % 10);
  }
  pthread_exit((void *)tid);
}
int main() {
  pthread_t philosophers[NUM_PHI];
  int rc;
  void *status;
  long t;
  for (t = 0; t < NUM_PHI; t++) {
    pthread_mutex_init(&forks[t], NULL);
    pthread_mutex_init(&locks[t], NULL);
  }

  for (t = 0; t < NUM_PHI; t++) {
    rc = pthread_create(&philosophers[t], NULL, work, (void *)t);
    if (rc) {
      printf("ERROR; return code from pthread_create() is %d\n", rc);
      exit(-1);
    }
  }
  sleep(30);
  dinner_time = 0;
  for (t = 0; t < NUM_PHI; t++) {
    pthread_join(philosophers[t], &status);
    if (rc) {
      printf("ERROR; return code from pthread_join() is %d\n", rc);
      exit(-1);
    }
    printf("Main: completed join with philosopher %ld having a status of %ld\n",
           t, (long)status);
  }
  for (t = 0; t < NUM_PHI; t++) {
    pthread_mutex_destroy(&forks[t]);
  }
}