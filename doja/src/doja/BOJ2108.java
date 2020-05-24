package doja;

import java.io.*;
import java.util.*;

public class BOJ2108 {
	static int[] numList ;
    static int[] check = new int[8001];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        numList = new int[n];
        double avg = 0;
        for (int i = 0; i < n; i++) {
        	numList[i] = Integer.parseInt(br.readLine());
        	check[numList[i]+4000]++;
            avg += numList[i];
        }
        int maxIndex = 0;
        int maxVal=-1;
        ArrayList<Integer> list = new ArrayList<>();
        for (int i = 0; i <8001; i++) {
            if(maxVal<check[i]){
                maxIndex = i;
                maxVal=check[i];
                list.clear();
            }
            else if(check[i]!= 0 &&check[i] == maxVal)
            {
                list.add(i-4000); 
            }
        }
        Arrays.sort(numList);
        System.out.println((int)Math.round((double)(avg/n)));
        System.out.println(numList[n/2]);
        if(list.size()!= 0)
            System.out.println(list.get(0));
        else
            System.out.println(maxIndex-4000);
        System.out.println(numList[n-1]-numList[0]);
    }
}
