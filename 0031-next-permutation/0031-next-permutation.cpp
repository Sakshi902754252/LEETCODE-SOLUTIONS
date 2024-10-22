class Solution {
public:
     //TC : 3*O(N) which is approximately O(3N).
    void nextPermutation(vector<int>& A) {
       
        int idx =-1;
        int n = A.size();
          // Step 1: Find the break point: where i is smaller than next element
        for(int i = n-2 ; i>=0; i--){
            if(A[i] < A[i+1]){
                idx = i;
                break;
            }
        }
         // If no such index exists, the current permutation is the largest. Reverse to get the   //smallest permutation.
        if(idx  == -1){
            reverse(A.begin(), A.end());
            return;
        }
        // Step 2: Find the next greater element
        // and swap it with arr[ind]:
        for(int i = n-1; i>idx ; i--){
            if(A[i]> A[idx]){
                swap(A[i], A[idx]);
                break;
            }
        }

        reverse(A.begin() + idx + 1, A.end());


    }
};