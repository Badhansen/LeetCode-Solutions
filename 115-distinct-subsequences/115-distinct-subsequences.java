class Solution {
    public int numDistinct(String S, String T) {
        int m = T.length(), n = S.length();
        int[][] mem = new int[m + 1][n + 1];
        for(int j = 0; j <= n; j++) {
            mem[0][j] = 1;
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(T.charAt(i) == S.charAt(j)) {
                    mem[i + 1][j + 1] = mem[i][j] + mem[i + 1][j];
                } else {
                    mem[i + 1][j + 1] = mem[i + 1][j];
                }
            }
        }
        return mem[m][n];
    }
}