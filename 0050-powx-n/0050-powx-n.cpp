class Solution {
public:
    double myPow(double x, int n) {
    // Base case: any number raised to the power of 0 is 1
    if (n == 0) {
        return 1.0;
    }

    // Handle negative powers by converting to positive
    // and returning the reciprocal at the end
    long long N = n;  // Using long long to handle edge cases with large negative n
    if (N < 0) {
        x = 1 / x;
        N = -N;
    }

    // Recursive divide-and-conquer approach
    double result = 1.0;
    while (N > 0) {
        // If N is odd, multiply result by x
        if (N % 2 == 1) {
            result *= x;
        }
        // Square x and reduce N by half
        x *= x;
        N /= 2;
    }

    return result;
}
};