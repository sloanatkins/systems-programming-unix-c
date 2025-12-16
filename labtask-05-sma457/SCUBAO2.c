#include <stdio.h>
#include <stdbool.h>

const double FEET_PER_ATM = 33.0;
const double PO2_MAX_RECOMMENDED = 1.4;
const double PO2_MAX_CONTINGENCY = 1.6;

double compute_ambient_pressure(int depth_ft) {
    return (depth_ft / FEET_PER_ATM) + 1.0;
}

double compute_po2(int percent_o2, double ambient_atm) {
    double fO2 = percent_o2 / 100.0;
    return fO2 * ambient_atm;
}

char oxygen_group(double po2) {
    if (po2 < 0.0) {
        po2 = 0.0;
    }
    int idx = (int)(po2 * 10.0);
    if (idx < 0) {
        idx = 0;
    }
    if (idx > 25) {
        idx = 25;
    }
    return (char)('A' + idx);
}

const char *as_bool(bool v) {
    if (v) {
        return "true";
    } else {
        return "false";
    }
}

int main(void) {
    int depth_ft = 0;
    int percent_o2 = 0;

    printf("Enter depth and percentage O2   : ");
    if (scanf("%d %d", &depth_ft, &percent_o2) != 2) {
        printf("Input error.\n");
        return 1;
    }
    if (depth_ft < 0 || percent_o2 < 1 || percent_o2 > 100) {
        printf("Invalid input values.\n");
        return 1;
    }

    double ambient = compute_ambient_pressure(depth_ft);
    double po2 = compute_po2(percent_o2, ambient);
    char   group = oxygen_group(po2);

    bool exceeds_rec = (po2 > PO2_MAX_RECOMMENDED);
    bool exceeds_cont = (po2 > PO2_MAX_CONTINGENCY);

    printf("Ambient pressure                : %.1f\n", ambient);
    printf("O2 pressure                     : %.2f\n", po2);
    printf("O2 group                        : %c\n", group);
    printf("Exceeds maximal O2 pressure     : %s\n", as_bool(exceeds_rec));
    printf("Exceeds contingency O2 pressure : %s\n", as_bool(exceeds_cont));
}

