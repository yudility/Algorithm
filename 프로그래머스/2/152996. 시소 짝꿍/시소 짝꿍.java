class Solution {
    public long solution(int[] weights) {
        long cnt = 0;
        long[] w = new long[1001];
        
        for (int weight : weights) {
            w[weight]++;
        }
        
        for (int i = 100; i <= 1000; i++) {
            if (w[i] == 0) continue;
            
            // 같은 무게의 짝꿍
            cnt += w[i] * (w[i] - 1) / 2;
            
            // 2:3 비율의 짝꿍
            if (i % 3 == 0 && i / 3 * 2 <= 1000) {
                cnt += w[i] * w[i / 3 * 2];
            }
            
            // 2:4 (1:2) 비율의 짝꿍
            if (i % 2 == 0 && i / 2 <= 1000) {
                cnt += w[i] * w[i / 2];
            }
            
            // 3:4 비율의 짝꿍
            if (i % 4 == 0 && i / 4 * 3 <= 1000) {
                cnt += w[i] * w[i / 4 * 3];
            }
        }
        
        return cnt;
    }
}