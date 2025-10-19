#include <stdio.h>
#include "./include/taylor_sine.h"

/*
(b)
=== Testing x = 0.0000 radians ===
n = 3  | taylor_sine =  0.000000 | sin =  0.000000 | error = 0.00000000
n = 5  | taylor_sine =  0.000000 | sin =  0.000000 | error = 0.00000000
n = 10 | taylor_sine =  0.000000 | sin =  0.000000 | error = 0.00000000

=== Testing x = 0.5000 radians ===
n = 3  | taylor_sine =  0.479427 | sin =  0.479426 | error = 0.00000154
n = 5  | taylor_sine =  0.479426 | sin =  0.479426 | error = 0.00000000
n = 10 | taylor_sine =  0.479426 | sin =  0.479426 | error = 0.00000000

=== Testing x = 1.0000 radians ===
n = 3  | taylor_sine =  0.841667 | sin =  0.841471 | error = 0.00019568
n = 5  | taylor_sine =  0.841471 | sin =  0.841471 | error = 0.00000002
n = 10 | taylor_sine =  0.841471 | sin =  0.841471 | error = 0.00000000

=== Testing x = 3.1400 radians ===
n = 3  | taylor_sine =  0.523849 | sin =  0.001593 | error = 0.52225648
n = 5  | taylor_sine =  0.008480 | sin =  0.001593 | error = 0.00688718
n = 10 | taylor_sine =  0.001593 | sin =  0.001593 | error = 0.00000000

=== Testing x = 6.2800 radians ===
n = 3  | taylor_sine =  46.399748 | sin = -0.003185 | error = 46.40293362
n = 5  | taylor_sine =  11.832866 | sin = -0.003185 | error = 11.83605137
n = 10 | taylor_sine = -0.004222 | sin = -0.003185 | error = 0.00103716
*/

/*
(c) Observations:

1. The Taylor sine approximation gives accurate results for small |x| values 
   (roughly between -π and π). 
   For x close to 0, even 3–5 terms produce excellent precision.

2. For larger x values (e.g., 6.28 ≈ 2π), the accuracy decreases rapidly 
   if we don't use enough terms - because the Taylor expansion is centered 
   around 0 and doesn’t converge quickly far from 0.

3. Increasing the number of terms (n) improves precision significantly 
   for larger |x| values. For example, at x = 3.14, 3 terms gave large 
   error (~0.52), while 10 terms matched perfectly with sin(x).
*/

int main() {
    double test_values[] = {0.0, 0.5, 1.0, 3.14, 6.28};
    int terms[] = {3, 5, 10};
    int num_values = sizeof(test_values) / sizeof(test_values[0]);
    int num_terms = sizeof(terms) / sizeof(terms[0]);

    for (int i = 0; i < num_values; i++) {
        double x = test_values[i];
        printf("\n=== Testing x = %.4f radians ===\n", x);

        for (int j = 0; j < num_terms; j++) {
            int n = terms[j];
            double approx = taylor_sine(x, n);
            double actual = sin(x);
            double error = fabs(approx - actual);

            printf("n = %-2d | taylor_sine = % .6f | sin = % .6f | error = %.8f\n",
                   n, approx, actual, error);
        }
    }

    return 0;
}

