#include <stdio.h>
#include "statistics.h"

#define MAX_VALUES 100

int main() {
    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("Fehler beim Öffnen der Datei.\n");
        return 1;
    }

    double values[MAX_VALUES];
    int count = 0;

    while (count < MAX_VALUES && fscanf(file, "%lf", &values[count]) == 1) {
        count++;
    }

    fclose(file);

    double mean = calculate_mean(values, count);
    double std_deviation = calculate_std_deviation(values, count);

    printf("Erwartungswert: %lf\n", mean);
    printf("Standardabweichung: %lf\n", std_deviation);

    return 0;
}

