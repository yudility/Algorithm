import java.util.Arrays;
import java.util.Collections;

class Solution {
    public String solution(String s) {
        String[] str = s.split(" ");
        int min = Integer.parseInt(str[0]);
        int max = min;
        
        for(int i=0; i<str.length; i++){
            int t = Integer.parseInt(str[i]);
            min = Math.min(min, t);
            max = Math.max(max, t);
        }
        
        return min + " " + max ;
    }
}