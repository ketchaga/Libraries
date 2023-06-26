#include "gaussian.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void print_help() {
    printf("Usage: ./program -e <expected_value> -s <std_deviation> -n <amount_of_values>\n");
}

int main(int argc, char *argv[]) {
    int expected_value = 0;
    int std_deviation = 0;
    int amount_of_values = 0;

    int option;
    while ((option = getopt(argc, argv, "he:s:n:")) != -1) {
        switch (option) {
            case 'h':
                print_help();
                return 0;
            case 'e':
                expected_value = atoi(optarg);
                break;
            case 's':
                std_deviation = atoi(optarg);
                break;
            case 'n':
                amount_of_values = atoi(optarg);
                break;
            default:
                printf("Unknown option: %c\n", option);
                return 1;
        }
    }

    if (expected_value == 0 || std_deviation == 0 || amount_of_values == 0) {
        printf("Missing required arguments.\n");
        print_help();
        return 1;
    }

    FILE *output_stream = stdout;  // Verwende Standardausgabe als Standard-Output-Stream

    print_gaussian_dist(expected_value, std_deviation, amount_of_values, output_stream);

    return 0;
}


