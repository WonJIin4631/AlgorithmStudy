package doja;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class BOJ2660 {
	static int N;
	static int[][] visit=new int[52][52];
	static int ans=987654321;
	static ArrayList<Integer> ansList =new ArrayList<>();
	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		for(int i=1;i<=N;i++)
			for(int j=1;j<=N;j++)
				visit[i][j]=987654321;
		while(true) {
			StringTokenizer tok = new StringTokenizer(br.readLine());
			int from,to;
			from = Integer.parseInt(tok.nextToken());
			to = Integer.parseInt(tok.nextToken());
			if((from==-1)&&(to==-1))
				break;
			visit[from][to]=1;
			visit[to][from]=1;
		}
		for(int i=1;i<=N;i++) {
			visit[i][i]=1;
			for(int j=1;j<=N;j++) {
				for(int k=1;k<=N;k++) {
					if(visit[j][k]>visit[j][i]+visit[i][k])	
						visit[j][k]=visit[j][i]+visit[i][k];
				}
			}
		}
		for(int i=1;i<=N;i++) {
			for(int j=1;j<=N;j++) {
				System.out.print(visit[i][j]+" ");
			}
			System.out.println();
		}
		for(int i=1;i<=N;i++) {
			int temp =0;
			for(int j=1;j<=N;j++) {
				if(temp<visit[i][j])
					temp=visit[i][j];
			}
			if(ans>temp) {
				ans=temp;
				ansList.clear();
				ansList.add(i);
			}
			else if(ans==temp) {
				ansList.add(i);
			}
		}
		System.out.println(ans+" "+ansList.size());
		for(int i=0;i<ansList.size();i++) {
			System.out.print(ansList.get(i)+" ");
		}
	}

}
