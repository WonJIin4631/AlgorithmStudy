package doja;

import java.io.*;
import java.util.*;

public class BOJ9934 {
	
	static int K;
	static int[] num = new int[1025];
	static int[][] tree = new int[11][513];
	static int[] depth_idx = new int[10];
	
	static void building(int start,int end, int depth) {
	    if (end - start < 0) {
	        return;
	    }
	    int mid = (start + end) / 2;
	    tree[depth][depth_idx[depth]++] = num[mid];
	    building(start, mid-1, depth+1);
	    building(mid+1, end, depth+1);
	}
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int end;
		K = Integer.parseInt(br.readLine());
		end=(int) Math.pow(2, K);
		StringTokenizer tok = new StringTokenizer(br.readLine());
		for(int i=1;i<end;i++) {
			num[i]=Integer.parseInt(tok.nextToken());
		}
		building(1, end-1,0);
		for (int i = 0; i < K; i++) {
	        end = 1;
	        for (int j = 0; j < i; j++)
	            end *= 2;
	        for (int j = 0; j < end; j++) {
	        	System.out.print(tree[i][j]+" ");
	        }
	        System.out.println();
	    }
	}

}
