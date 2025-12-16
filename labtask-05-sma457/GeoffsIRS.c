#include <stdio.h>

const double TAX_CAP = 50000.0;
const double TAX_HIGH = 0.25;
const double TAX_MEDIUM = 0.10;
const double TAX_LOW = 0.03;
const double TAX_NONE = 0.00;

void input_income_and_deduction(double *income, double *deduction) {
    *income = 0.0;
    *deduction = 0.0;

    int finished = 0;
    while (!finished) {
        double x = 0.0;
        printf("Enter next amount : ");
        if (scanf("%lf", &x) != 1) {
            printf("Input error.\n");
            return;
        }
        if (x == 0.0) {
            finished = 1;
        } else if (x > 0.0) {
            *income += x;
        } else {
            *deduction += -x;
        }
    }
}

double compute_taxable(double income, double deduction) {
    double t = income - deduction;
    if (t > 0.0) {
        return t;
    } else {
        return 0.0;
    }
}

char compute_tax_group(double taxable) {
    if (taxable >= 500000.0) {
        return 'S';
    } else if (taxable >= 200000.0) {
        return 'Q';
    } else if (taxable >= 100000.0) {
        return 'M';
    } else if (taxable >= 50000.0) {
        return 'A';
    } else if (taxable >= 20000.0) {
        return 'R';
    } else {
        return 'P';
    }
}

double compute_tax(double taxable, char group) {
    double rate;
    if (group == 'S' || group == 'Q') {
        rate = TAX_HIGH;
    } else if (group == 'M') {
        rate = TAX_MEDIUM;
    } else if (group == 'A' || group == 'R') {
        rate = TAX_LOW;
    } else {
        rate = TAX_NONE;
    }

    double tax = taxable * rate;
    if (tax > TAX_CAP) {
        tax = TAX_CAP;
    }
    return tax;
}

void display_tax_info(double income, double deductions,
                      double taxable, char group, double tax) {
    printf("\nIncome         = $%10.2f\n", income);
    printf("Deductions     = $%10.2f\n", deductions);
    printf("Taxable Income = $%10.2f\n", taxable);
    printf("Tax group      = %c\n", group);
    printf("Tax owed       = $%10.2f\n", tax);
}

int main(void) {
    double income, deductions;

    input_income_and_deduction(&income, &deductions);
    double taxable = compute_taxable(income, deductions);
    char group = compute_tax_group(taxable);
    double tax = compute_tax(taxable, group);

    display_tax_info(income, deductions, taxable, group, tax);

    return 0;
}

