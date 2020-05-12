package doja;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class BOJ2075 {
	
	
	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer tok =new StringTokenizer(br.readLine());
		int N = Integer.parseInt(tok.nextToken());
		PriorityQueue<Integer> pq = new PriorityQueue<>();
		for(int i=0;i<N;i++) {
			tok =new StringTokenizer(br.readLine());
			for(int j=0;j<N;j++) {
				int num =Integer.parseInt(tok.nextToken());
				if(pq.isEmpty())
					pq.add(num);
				else if(pq.peek()<(Integer) num) {
					pq.add(num);
					if(pq.size()>N)
						pq.poll();
				}
			}
		}
		System.out.println(pq.peek());
	}

}
