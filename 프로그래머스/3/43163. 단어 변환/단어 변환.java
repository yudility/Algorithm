import java.util.*;

class Solution {
    
    // BFS에서 사용할 노드 클래스
    class Node {
        int index;  // words 배열에서의 인덱스
        int steps;  // 변환 횟수
        
        Node(int index, int steps) {
            this.index = index;
            this.steps = steps;
        }
    }
    
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
        
        //2. BFS로 변환 경로 찾기
        boolean[] visited = new boolean[words.length];
        Queue<Node> q = new LinkedList<>();
        
        // begin에서 한 번에 변환 가능한 단어들을 큐에 추가
        for(int i=0; i<words.length ; i++){
            if(canChange(begin, words[i])){
                q.offer(new Node(i, 1));
                visited[i] = true;
                
                // target에 바로 도달한 경우
                if(words[i].equals(target)){
                    return 1;
                }
            }
        }
        
        while(!q.isEmpty()){
            Node current = q.poll();
            
            // 현재 단어에서 변환 가능한 단어들 탐색
            for(int i=0; i<words.length ; i++){
                if(!visited[i] && canChange(words[current.index], words[i])){
                    visited[i] = true;
                    
                    // target에 도달한 경우
                    if(words[i].equals(target)){
                        return current.steps + 1;
                    }
                    
                    q.offer(new Node(i, current.steps + 1));
                }
            }
        }
        
        return 0; // 변환 불가능한 경우
    }
}