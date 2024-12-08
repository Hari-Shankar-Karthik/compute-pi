#include <iostream>
#include <float.h>
#include <algorithm>
#include <cmath>
#include <iomanip>

int main() {
    const double m1 = 1;
    const double m2 = 10000000000; // pi = 3.14159
    double u1 = 0;
    double u2 = -1;
    double x1 = 1;
    double x2 = 1; // assuming both masses are infinitely thin
    double t = 0;
    double dt = 0;
    int num_collisions = 0;
    while(u1 < 0 || u2 < 0 || u1 > u2) {
        num_collisions++;
        std::cout << "Collision " << num_collisions << ": t = " << std::setprecision(15) << t << "s" << std::endl;
        if(std::abs(x1) <= DBL_EPSILON) {
            // Collision between m1 and the wall, assuming infinitely massive wall
            u1 *= -1;
        } else { // x1 == x2
            // Perfectly elasic collision between m1 and m2
            double v1 = ((m1 - m2) * u1 + 2 * m2 * u2) / (m1 + m2);
            double v2 = ((m2 - m1) * u2 + 2 * m1 * u1) / (m1 + m2);
            u1 = v1;
            u2 = v2;
        }
        dt = DBL_MAX;
        if(u1 < 0) {
            dt = std::min(dt, x1 / -u1);
        }
        if(u1 > u2) {
            dt = std::min(dt, (x2 - x1) / (u1 - u2));
        }
        t += dt;
        x1 += u1 * dt;
        x2 += u2 * dt;
    }
    double approx_pi = num_collisions / std::sqrt(m2);
    std::cout << "pi ~ " << std::setprecision(15) << approx_pi << std::endl;
}