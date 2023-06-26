#include "gaussian.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>

void print_gaussian_dist(int expected_value, int std_deviation, int amount_of_values, FILE *output_stream) {
    srand(time(NULL));  // Initialisiere den Zufallszahlengenerator

    for (int i = 0; i < amount_of_values; i++) {
        double u1 = ((double)rand() / RAND_MAX);  // Gleichmäßig verteilte Zufallszahl zwischen 0 und 1
        double u2 = ((double)rand() / RAND_MAX);  // Gleichmäßig verteilte Zufallszahl zwischen 0 und 1
        double random_value = sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);  // Berechne Zufallswert

        int gaussian_value = expected_value + std_deviation * random_value;
        fprintf(output_stream, "%d\n", gaussian_value);
    }
}

