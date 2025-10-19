/*
 * Exercise 1: Taylor Series Approximation for Sine Function
 * Assignment 7 - IPFCE 2025
 * 
 * Implement the taylor_sine function that calculates the sine of x
 * using Taylor series approximation with n terms.
 * 
 * Taylor series for sin(x) = x - x^3/3! + x^5/5! - x^7/7! + ...
 */

#include "./include/taylor_sine.h"

/* 
 * Calculate sine using Taylor series approximation
 * x: input value in radians
 * n: number of terms in the series
 * Returns: approximation of sin(x)
 */
double taylor_sine(double x, int n) {
    double result = 0.0;
    double term = x;      // first term is x^(1)/1!
    double sign = 1.0;

    for (int k = 0; k < n; k++) {
        result += sign * term;

        // Prepare next term
        int exp = 2 * k + 1;
        int nextExp = exp + 2;

        sign = -sign;

        term *= (x * x) / ((nextExp - 1) * (nextExp));
    }

    return result;
}
