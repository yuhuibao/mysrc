#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
struct thread_data {
  int thread_id;
  int darts;
  int circle_points;
  int interval;
};
void *work(void *threadarg) {
  struct thread_data *data;
  data = (struct thread_data *)threadarg;
  int tid, x, y;
  tid = data->thread_id;
  int darts = data->darts;
  int interval = data->interval;
  printf("Thread %d performs %d darts\n", tid, darts);
  unsigned int seed = (unsigned)time(NULL) + tid;
  srand(seed);
  for (int i = 0; i < darts; i++) {
    x = rand() % (interval + 1);
    y = rand() % (interval + 1);
    if (x * x + y * y < interval * interval) {
      data->circle_points++;
    }
  }
  pthread_exit(NULL);
}
int main(int argc, char **argv) {
  int num_threads = atoi(argv[1]);
  int interval = atoi(argv[2]);
  int num_darts = interval * interval, darts_per_thread, darts_extra;
  float pi;
  int circle_points = 0, rc;
  pthread_t threads[num_threads];
  struct thread_data thread_data_array[num_threads];

  darts_extra = num_darts % num_threads;
  darts_per_thread = num_darts / num_threads;
  for (int t = 0; t < num_threads; t++) {
    thread_data_array[t].thread_id = t;
    thread_data_array[t].interval = interval;
    thread_data_array[t].circle_points = 0;
    if (darts_extra == 0) {
      thread_data_array[t].darts = darts_per_thread;
    } else {
      if (t < darts_extra) {
        thread_data_array[t].darts = darts_per_thread + 1;
      } else {
        thread_data_array[t].darts = darts_per_thread;
      }
    }
    rc = pthread_create(&threads[t], NULL, work, (void *)&thread_data_array[t]);
    if (rc) {
      printf("ERROR: return code from pthread_create() is %d\n", rc);
      exit(-1);
    }
  }
  for (int t = 0; t < num_threads; t++) {
    rc = pthread_join(threads[t], NULL);
    if (rc) {
      printf("ERROR: return code from pthread_join() is %d\n", rc);
      exit(-1);
    }
    int p = thread_data_array[t].circle_points;
    printf("circle_points from thread %d is %d\n", t, p);
    circle_points = circle_points + p;
  }

  pi = (float)(4 * circle_points) / num_darts;
  printf("final estimation of pi=%g\n", pi);
  return 0;
}
