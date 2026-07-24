class Solution {
public:

    int solution(int n){
      if (n == 0) return 1;   // One valid way: do nothing
      if (n < 0) return 0;    // Invalid path


        return solution(n-1) + solution(n-2);
    }



    int climbStairs(int n) {
        return solution(n);

    }
};
