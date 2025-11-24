/* tiropar.c -- asks for values such as mass, initial velocity and angle, initial position and plots the parabolic fly */

#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846f
#define G -9.81f // acceleration due to gravity in m/s^2
#define N 1000 // number of points calculated for the trajectory


float flight_time(float v0, float angle_rad, float y0); // returns the time of flight
float max_height(float v0, float angle_rad, float y0); // returns the maximum height and the horizontal possition at that height
float max_distance(float v0, float angle_rad, float t_flight, float x0); // returns the maximum horizontal distance.
float deg_to_rad(float angle_deg); // converts degrees to radians
float t_max_height(float v0, float angle_rad); // returns the time to reach maximum height
void position_at_timex(float v0, float angle_rad, float t, float x0, float posx[]);
void position_at_timey(float v0, float angle_rad, float t, float y0, float posy[]);

int main(void)
{
    float mass, v0, angle_deg, angle_rad,
            x0, y0, t_flight;
    float posx[N], posy[N];

    
    // Get user input
    printf("This is a program to calculate the parabolic trajectory of a projectile. ");
    printf("You will be asked to provide some initial values to calculate the trayectory.\n");
    printf("Let's begin.....\n");
    printf("Enter the mass of the projectile (kg): ");
    scanf("%f", &mass);
    printf("Enter the initial velocity (m/s): ");
    scanf("%f", &v0);
    printf("Enter the launch angle (degrees): ");
    scanf("%f", &angle_deg);
    printf("Enter the initial horizontal position (m): ");
    scanf("%f", &x0);
    printf("Enter the initial vertical position (m): ");
    scanf("%f", &y0);
    angle_rad = deg_to_rad(angle_deg);
    float discriminant = v0*sin(angle_deg) * v0 * sin(angle_deg) - 2.0f * G * y0;
    if (discriminant < 0)
    {
        printf("The projectile does not hit the ground.\n");
        return 0; // No real solution, projectile does not hit the ground
    }

    t_flight = flight_time(v0, angle_rad, discriminant);
    printf("Time of flight: %f seconds\n", t_flight);
    float h_max = max_height(v0, angle_rad, y0);
    float x_max = max_distance(v0, angle_rad, t_flight, x0);
    position_at_timex(v0, angle_rad, t_flight, x0, posx);
    for (int i = 0; i < N; i++) {
        printf("posx[%d] = %f\n", i, posx[i]);
    };
    position_at_timey(v0, angle_rad, t_flight, y0, posy);
    for (int i = 0; i < N; i++) {
        printf("posy[%d] = %f\n", i, posy[i]);
    }
    char * commandsForGnuplot[] = {"set title \"TITLEEEEE\"", "plot 'data.temp'"};

    FILE * temp = fopen("data.temp", "w");
    /*Opens an interface that one can use to send commands as if they were typing into the
     *     gnuplot command line.  "The -persistent" keeps the plot open even after your
     *     C program terminates.
     */
    FILE * gnuplotPipe = popen ("gnuplot -persistent", "w");
    fprintf(gnuplotPipe, "plot '-' \n");
    int i;

    for (int i = 0; i < N; i++)
    {
      fprintf(gnuplotPipe, "%lf %lf\n", posx[i], posy[i]);
    }

    fprintf(gnuplotPipe, "e");
}

float deg_to_rad(float angle_deg)
{
    return angle_deg * PI / 180.0f;
}

float flight_time(float v0, float angle_deg, float discriminant)
{
    float t_flight;
    
    t_flight = (-v0 * sin(angle_deg) - sqrtf(discriminant)) / G;

    return t_flight;
}
float t_max_height(float v0, float angle_deg)
{
    float v0y = v0 * sin(angle_deg);
    return v0y / G;
}
float max_height(float v0, float angle_rad, float y0)
{
    float t_max = t_max_height(v0, angle_rad);
    float h_max = y0 + (v0 * sin(angle_rad)) * t_max + 0.5f * G * t_max * t_max;
    return h_max;
}
float max_distance(float v0, float angle_deg, float t_flight, float x0)
{
    float x_max = x0 + v0 * cos(angle_deg) * t_flight;
    return x_max;
}
void position_at_timex(float v0, float angle_deg, float t, float x0, float posx[])
{
    for (int i = 0; i < N; i++) {
        float ti = t * i / (N - 1);
        printf("ti=%f\n", ti);
        posx[i] = x0 + v0 * cos(angle_deg) * ti;
        ti = ti + ti;

    }

}
void position_at_timey(float v0, float angle_deg, float t, float y0, float posy[])
{
    for (int i = 0; i < N; i++) {
        float ti = t * i / (N - 1);
        posy[i] = y0 + v0 * sin(angle_deg) * ti + 0.5f * G * ti * ti;
        ti = ti + ti;

    }

}


