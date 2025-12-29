//------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

//------------------------------------------------------------------------------

#define ROAD_WIDTH_METERS   10.0
#define ROADKILL_CONSTANT    1.47

//------------------------------------------------------------------------------

static double meters_to_km(double meters) {
    return meters / 1000.0;
}

static double kangaroo_density(const double side_km, const int n_roos) {
    const double area_km2 = side_km * side_km;
    return n_roos / area_km2;
}

static double road_surface_area(const double road_len_km, const double width_m) {
    const double width_km = meters_to_km(width_m);
    return road_len_km * width_km;
}

//------------------------------------------------------------------------------

int main(void) {

    double side_km = 0.0;
    double roads_km = 0.0;
    int    n_roos   = 0;

    printf("     Enter side of square in km  : ");
    if (scanf("%lf", &side_km) != 1) return EXIT_FAILURE;

    printf("     Enter roads length in km    : ");
    if (scanf("%lf", &roads_km) != 1) return EXIT_FAILURE;

    printf("     Enter number of 'roos       : ");
    if (scanf("%d", &n_roos) != 1) return EXIT_FAILURE;

    if (side_km <= 0.0 || roads_km < 0.0 || n_roos < 0) {
        fprintf(stderr, "Invalid input\n");
        return EXIT_FAILURE;
    }

    const double density = kangaroo_density(side_km, n_roos);
    const double road_area = road_surface_area(roads_km, ROAD_WIDTH_METERS);
    const double expected_kills = density * road_area * ROADKILL_CONSTANT;

    printf("     Expected number of kills is : %.1f\n", expected_kills);

    return EXIT_SUCCESS;
}

//-----------------------------------------------------------------------------
