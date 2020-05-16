package doja;

import java.io.*;
import java.util.*;

public class BOJ2630 {
	static int[][] map =new int[129][129];
	static int N;
	static boolean[][] visit = new boolean[129][129];
	static int ansWhite=0;
	static int ansBlue=0;
	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer tok = new StringTokenizer(br.readLine());
		N= Integer.parseInt(tok.nextToken());
		for(int i=0;i<N;i++) {
			 tok = new StringTokenizer(br.readLine());
			 for(int j=0;j<N;j++) {
				 map[i][j]=Integer.parseInt(tok.nextToken());
			 }
		}
		solve(N,0,0);
		System.out.println(ansWhite+"\n"+ansBlue);
	}
	static void solve(int n,int x,int y) {
		int color= map[y][x];
		for(int i=y;i<y+n;i++) {
			for(int j=x;j<x+n;j++) {
				if(map[i][j]!=color) {
					solve(n/2,x,y);
					solve(n/2,x+n/2,y);
					solve(n/2, x, y+n/2);
					solve(n/2,x+n/2,y+n/2);
					return;
				}
			}
		}
		if(color==1) {
			ansBlue++;
		}
		else {
			ansWhite++;
		}
	}
	
}
