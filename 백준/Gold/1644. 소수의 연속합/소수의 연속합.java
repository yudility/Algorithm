import java.util.*;
import java.io.*;

public class Main
{
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        
        if( n < 2){ //2보다 작은 경우에는 0을 출력하고 종료
            System.out.println(0);
            return;
        }
        
        //0 ~ n까지의 수가 소수인지 판별할 배열
        boolean[] isNotPrime = new boolean[n+1]; 
                
        isNotPrime[0] = true; // 소수가 아님
        isNotPrime[1] = true;
        
        for(int i=2; i<=Math.sqrt(n); i++){
            if(!isNotPrime[i]){ //소수라면
                for(int j= i*i; j<= n; j+=i){ // 소수의 배수는 모두 소수가 아님 
                    isNotPrime[j] = true;
                } 
            }
        }
        
        //소수들만 담을 리스트
        ArrayList<Integer> primes = new ArrayList<>(); 
        
        for(int i=2; i<=n; i++){
            if(!isNotPrime[i]){
                primes.add(i);
            }
        }
        
        int i=0;
        int j=0;
        int result = 0; //(결과)경우의 수
        int sum = 0; // 슬라이딩 윈도우 도중 저장할 합
        while(j < primes.size() ){
            
            sum += primes.get(j); //j번째 소수를 넣고 j를 하나 증가시킴
            j++;
            
            while (sum > n && i < j) { 
                sum -= primes.get(i); // sum이 n보다 크다면 i를 sum에서 뺀 후, i를 하나 증가시킴.
                i++;
            }
            
            if (sum == n) { // 같다면 경우의 수 +1
                result++;
            }
        }
        
        System.out.println(result);
	}
}
