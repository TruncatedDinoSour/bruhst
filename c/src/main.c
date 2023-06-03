#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <pthread.h>

#define G           6.6743e-11
#define N           10000
#define BODIES_N    20
#define DT          0.1
#define NUM_THREADS 6

#ifndef M_PI
#define M_PI 3.141592653589793
#endif

/* io */

static void io(const int data[N]) {
    unsigned idx;
    FILE *const fp = fopen("/tmp/.tmpfile", "wb");

    for (idx = 0; idx < N; ++idx)
        fwrite(&data[idx], 1, 1, fp);

    fclose(fp);
    remove("/tmp/.tmpfile");
}

/* fib */

static int fib(const int n) { return n <= 1 ? n : fib(n - 1) + fib(n - 2); }

/* bubblesort */

static void swap(int *const a, int *const b) {
    int t = *a;
    *a    = *b;
    *b    = t;
}

static void bubble_sort(int arr[N]) {
    unsigned idx, jdx;

    for (idx = 0; idx < N - 1; ++idx)
        for (jdx = 0; jdx < N - idx - 1; ++jdx)
            if (arr[jdx] > arr[jdx + 1])
                swap(&arr[jdx], &arr[jdx + 1]);
}

/* n-body sim */

struct Body {
    double x, y, mass, vx, vy;
};

static void compute_gravity(const struct Body *const body1,
                            const struct Body *const body2,
                            double *fx,
                            double *fy) {
    const double dx = body2->x - body1->x, dy = body2->y - body1->y;
    const double distance = sqrt(dx * dx + dy * dy);
    const double force = G * body1->mass * body2->mass / (distance * distance);
    const double angle = atan2(dy, dx);

    *fx = force * cos(angle);
    *fy = force * sin(angle);
}

static void simulate_bodies(struct Body *const bodies) {
    double fx, fy, ax, ay;
    unsigned idx, jdx;
    struct Body *body;

    double force_x[BODIES_N] = {0}, force_y[BODIES_N] = {0};

    for (idx = 0; idx < BODIES_N; ++idx) {
        for (jdx = idx + 1; jdx < BODIES_N; ++jdx) {
            compute_gravity(&bodies[idx], &bodies[jdx], &fx, &fy);

            force_x[idx] += fx;
            force_y[idx] += fy;

            force_x[jdx] -= fx;
            force_y[jdx] -= fy;
        }
    }

    for (idx = 0; idx < BODIES_N; ++idx) {
        body = &bodies[idx];
        ax   = force_x[idx] / body->mass;
        ay   = force_y[idx] / body->mass;

        body->vx += ax * DT;
        body->vy += ay * DT;
        body->x += body->vx * DT;
        body->y += body->vy * DT;
    }
}

/* threads */

static void *threading(void *thread_arg) {
    unsigned long thread_id;
    long double sum = 0.0;
    unsigned idx;

    thread_id = (unsigned long)thread_arg;

    for (idx = 0; idx < N * 100; ++idx)
        sum += sin(sqrt(M_PI / (idx + 1)) - thread_id);

    sum = (unsigned int)sum - 1;
    (void)sum;

    pthread_exit(NULL);
}

int main(void) {
    double mass, distance, angle, speed;
    unsigned long idx;
    clock_t start_time;

    static pthread_t threads[NUM_THREADS];

    static int barr[N];

    static struct Body bodies[BODIES_N] = {{0}};
    bodies[0].mass                      = 5.972e24;

    srand(time(NULL));

    for (idx = 1; idx < BODIES_N; ++idx) {
        mass     = (double)rand() / RAND_MAX * 1e20;
        distance = (double)rand() / RAND_MAX * 1e9;
        angle    = (double)rand() / RAND_MAX * 2.0 * M_PI;

        bodies[idx].x  = distance * cos(angle);
        bodies[idx].y  = distance * sin(angle);
        speed          = sqrt(G * bodies[0].mass / distance);
        bodies[idx].vx = -speed * sin(angle);
        bodies[idx].vy = speed * cos(angle);

        bodies[idx].mass = mass;
    }

    for (idx = 0; idx < N; ++idx)
        barr[idx] = rand();

    start_time = clock();

    /* io */

    io(barr);

    /* fib */

    fib(42);

    /* bubblesort */

    bubble_sort(barr);

    /* n-bodies sim */

    for (idx = 0; idx < N; ++idx)
        simulate_bodies(bodies);

    /* threads */

    for (idx = 0; idx < NUM_THREADS; ++idx)
        pthread_create(&threads[idx], NULL, threading, (void *)idx);

    for (idx = 0; idx < NUM_THREADS; ++idx)
        pthread_join(threads[idx], NULL);

    printf("%f\n", (double)(clock() - start_time) / CLOCKS_PER_SEC);

    pthread_exit(NULL);
    return 0;
}
