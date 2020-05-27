package doja;

import java.io.*;
import java.util.*;

public class BOJ1927 {

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
		for(int i=0;i<N;i++) {
			int input= Integer.parseInt(br.readLine());
			if(input==0) {
				if(pq.isEmpty()) {
					System.out.println(0);
				}
				else {
					int cur = pq.poll();
					System.out.println(cur);
				}
			}
			else {
				pq.add(input);
			}
		}
	}

}
