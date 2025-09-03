import java.util.*;
import java.io.*;

public class Main {
    static int n, m;
    static int[][] map;
    static ArrayList<ArrayList<Integer>> chickenCombi = new ArrayList<>();
    
    static class XY {
        int x;
        int y; 
        
        XY(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
    
    static void getChickenCombis(int idx, int total, ArrayList<Integer> combi) {
        if (combi.size() == m) {
            chickenCombi.add(new ArrayList<>(combi));
            return;
        }
        
        for (int i = idx; i < total; i++) {
            combi.add(i);
            getChickenCombis(i + 1, total, combi);
            combi.remove(combi.size() - 1);
        }
    }
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        ArrayList<XY> chickens = new ArrayList<>();
        ArrayList<XY> homes = new ArrayList<>();
        ArrayList<Integer> combi = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                int now = Integer.parseInt(st.nextToken());
                if (now == 2) {
                    chickens.add(new XY(i, j));
                } else if (now == 1) {
                    homes.add(new XY(i, j));
                }
            }
        }
        
        getChickenCombis(0, chickens.size(), combi);
        
        int result = Integer.MAX_VALUE;
        
        for (int k = 0; k < chickenCombi.size(); k++) {
            int chickDist = 0;
            for (int i = 0; i < homes.size(); i++) {
                XY home = homes.get(i);
                int dist = Integer.MAX_VALUE;
                for (int j = 0; j < chickenCombi.get(k).size(); j++) {
                    int chickenIdx = chickenCombi.get(k).get(j);
                    XY chicken = chickens.get(chickenIdx);
                    dist = Math.min(dist, Math.abs(home.x - chicken.x) + Math.abs(home.y - chicken.y));
                }
                chickDist += dist;
            }
            result = Math.min(result, chickDist);
        }
        
        System.out.println(result);
    }
}