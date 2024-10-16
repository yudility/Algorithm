import java.util.Stack;

class Solution {
    public int[] solution(int[] numbers) {
        int n = numbers.length;
        int[] result = new int[n];
        Stack<Integer> stack = new Stack<>();
        
        // 배열을 뒤에서부터 순회
        for (int i = n - 1; i >= 0; i--) {
            // 현재 숫자보다 작거나 같은 숫자는 스택에서 제거
            while (!stack.isEmpty() && stack.peek() <= numbers[i]) {
                stack.pop();
            }
            
            // 스택이 비어있으면 뒷 큰수가 없으므로 -1, 아니면 스택의 top이 뒷 큰수
            result[i] = stack.isEmpty() ? -1 : stack.peek();
            
            // 현재 숫자를 스택에 push
            stack.push(numbers[i]);
        }
        
        return result;
    }
}