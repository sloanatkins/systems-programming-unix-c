#include<stdio.h>

// Function to calculate kangaroo density
float kangaroo_density(float square_side, int number_of_kangaroos) {
    float square_area = square_side * square_side;
    return number_of_kangaroos / square_area;
}

// Function to calculate road surface area
float road_surface_area(float road_length, float road_width) {
    return road_length * road_width;
}

int main() {
    float square_side, road_length, road_width, expected_kills;
    int number_of_kangaroos;
    const float road_kill_prob = 1.47;
    const float road_width_avg = 10.0;

    printf("Enter side of square in km: ");
    scanf("%f", &square_side);
    printf("Enter roads length in km: ");
    scanf("%f", &road_length);
    printf("Enter number of 'roos: ");
    scanf("%d", &number_of_kangaroos);

    float kangaroo_den = kangaroo_density(square_side, number_of_kangaroos);
    road_width = road_width_avg / 1000;
    float road_surf_area = road_surface_area(road_length, road_width);
    expected_kills = kangaroo_den * road_surf_area * road_kill_prob;

    printf("Expected number of kills is: %.1f\n", expected_kills);
    return 0;
}
