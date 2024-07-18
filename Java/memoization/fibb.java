package memoization;

import java.util.HashMap;
import java.util.Map;

public class fibb {
    static Integer fibbonacciDP(Integer n, Map<Integer, Integer> memo) {
        if (memo.containsKey(n)) {
            return memo.get(n);
        }

        if (n <= 1)
            return n;

        Integer result = fibbonacciDP(n - 1, memo) + fibbonacciDP(n - 2, memo);

        memo.put(n, result);

        return result;
    }

    static Integer fibbonacci(Integer n) {
        if (n <= 1)
            return n;
        Integer[] dp = new Integer[n + 1];

        dp[0] = 0;
        dp[1] = 1;
        for (Integer i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }

    public static void main(String[] args) {
        Map<Integer, Integer> memo = new HashMap<>();
        Integer res = fibbonacci(30);
        System.out.println(res);
    }

}
