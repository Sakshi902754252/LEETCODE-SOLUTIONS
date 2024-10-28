class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int n2 = n * n;
        
        // Calculate expected sums
        //formula to calculate first n natural numbers and squares of first n natural numbers
        long long expected_sum = (static_cast<long long>(n2) * (n2 + 1)) / 2;;
        long long expected_sum_of_squares = (static_cast<long long>(n2) * (n2 + 1) * (2 * n2 + 1)) / 6;

        // Calculate actual sums from the grid
        long long actual_sum = 0;
        long long actual_sum_of_squares = 0;

        for (const auto& row : grid) {
            for (int num : row) {
                actual_sum += num;
                actual_sum_of_squares += static_cast<long long>(num) * num;
            }
        }

        // Calculate differences
        long long sum_diff = actual_sum - expected_sum;  // This is a - b
        long long square_sum_diff = actual_sum_of_squares - expected_sum_of_squares;  // This is a^2 - b^2

        // Derive a + b from the difference of squares
        long long sum_ab = square_sum_diff / sum_diff;

        // Calculate a and b
        int a = (sum_diff + sum_ab) / 2;
        int b = sum_ab - a;

        return {a, b};
    }
};