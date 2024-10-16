import java.util.*;

class Solution {
    public int solution(int x, int y, int n) {
        Queue<Integer> queue = new LinkedList<>();
        Set<Integer> visited = new HashSet<>();
        Map<Integer, Integer> steps = new HashMap<>();
        
        queue.offer(x);
        visited.add(x);
        steps.put(x, 0);
        
        while (!queue.isEmpty()) {
            int current = queue.poll();
            
            if (current == y) {
                return steps.get(current);
            }
            
            int[] nextValues = {current + n, current * 2, current * 3};
            
            for (int next : nextValues) {
                if (next <= y && !visited.contains(next)) {
                    queue.offer(next);
                    visited.add(next);
                    steps.put(next, steps.get(current) + 1);
                }
            }
        }
        
        return -1;  // y에 도달할 수 없는 경우
    }
}