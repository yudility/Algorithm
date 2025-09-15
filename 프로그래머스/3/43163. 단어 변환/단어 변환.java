import java.util.*;

class Solution {
    
    static int answer = Integer.MAX_VALUE;
    
    public boolean canChange(String from, String to){
        if(from.equals(to)){
            return false;
        }
        
        int diff = 0;
        for(int i=0; i<from.length() ; i++){
            if(from.charAt(i) != to.charAt(i)){
                diff++;
            }
        }
        return diff == 1;
    }
    
    public void dfs(int now, String target, String[] words, boolean[] visited, int step){
        visited[now] = true;
        
        if(words[now].equals(target)){
            answer = Math.min(answer, step);
            return;
        }
        
        
        for(int i=0; i<words.length ; i++){
            if(!visited[i] && canChange(words[now], words[i])){
                dfs(i, target, words, visited, step+1);
            }
        }
    }
    
    public int solution(String begin, String target, String[] words) {
        
        //1. 변환할 수 없는 경우
        boolean isNotFound = true;
        for(int i=0; i<words.length ; i++){
            if(words[i].equals(target)){
                isNotFound = false;
                break;
            }
        }
        
        if(isNotFound){
            return 0;
        }

        //2. 변환할 수 있는 경우
        for(int i=0; i<words.length ; i++){
            if(canChange(begin, words[i])){
                boolean[] visited = new boolean[words.length];
                dfs(i, target ,words, visited, 1);
            }
        }
        
        return answer;
    }
    

}                        