#include "omp.h"
#include <stdio.h>
#include <stdlib.h>
int total = 0;
void work(int num_darts, int interval) {
  int tid, start, end, x, y;
  tid = omp_get_num_threads();
  int circle_points = 0;
  printf("Thread %d performs %d darts\n", tid, num_darts);
  unsigned int seed = (unsigned)time(NULL) + tid;
  srand(seed);
  for (int i = 0; i < num_darts; i++) {
    x = rand() % (interval + 1);
    y = rand() % (interval + 1);
    if (x * x + y * y < interval * interval) {
      circle_points++;
    }
  }
#pragma omp critical
  total += circle_points;
}
int main(int argc, char **argv) {
  int num_threads = atoi(argv[1]);
  int interval = atoi(argv[2]);
  int num_darts = interval * interval, darts_per_thread, darts_extra;
  float pi;
  int circle_points = 0, tid;
  int darts[num_threads];
  double t1, t2;
  darts_extra = num_darts % num_threads;
  darts_per_thread = num_darts / num_threads;
  for (int t = 0; t < num_threads; t++) {
    if (darts_extra == 0) {
      darts[t] = darts_per_thread;
    } else {
      if (t < darts_extra) {
        darts[t] = darts_per_thread + 1;
      } else {
        darts[t] = darts_per_thread;
      }
    }
  }
#pragma omp parallel num_threads(num_threads)
  {
    t1 = omp_get_wtime();
    tid = omp_get_thread_num();
    work(darts[tid], interval);
    t2 = omp_get_wtime();
  }

  pi = (float)(4 * total) / num_darts;
  printf("final estimation of pi=%g\n", pi);
  printf("time: %g\n", t2 - t1);
  return 0;
}
