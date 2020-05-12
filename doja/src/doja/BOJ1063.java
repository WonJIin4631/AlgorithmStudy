package doja;

import java.util.*;
import java.io.*;

public class BOJ1063 {
	static class Info {
		int x;
		int y;

		Info(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
	static int[] dx= {1,-1,0,0,1,-1,1,-1};
	static int[] dy= {0,0,1,-1,-1,-1,1,1};
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer tok = new StringTokenizer(br.readLine());
		String s = tok.nextToken();

		Info king = new Info(s.charAt(0) - 'A','8'-s.charAt(1));
		s = tok.nextToken();
		Info stone = new Info(s.charAt(0) - 'A','8'-s.charAt(1));
		int N = Integer.valueOf(tok.nextToken());
		while (N != 0) {
			N--;
			s = br.readLine();
			int dir= chan(s);
			int nx=king.x+dx[dir];
			int ny =king.y+dy[dir];
			if(nx<0||nx>=8||ny<0||ny>=8)
				continue;
			if(nx==stone.x&&ny==stone.y) {
				int snx=stone.x+dx[dir];
				int sny=stone.y+dy[dir];
				if(snx<0||snx>=8||sny<0||sny>=8)
					continue;
				king.x+=dx[dir];
				king.y+=dy[dir];
				stone.x+=dx[dir];
				stone.y+=dy[dir];
			}
			else {
				king.x+=dx[dir];
				king.y+=dy[dir];
			}
		}
		char c=(char) ('A'+king.x);
		System.out.println(c+""+(8-king.y));
		c=(char) ('A'+stone.x);
		System.out.println(c+""+(8-stone.y));
	}
	static int chan(String s) {
		if (s.equals("R")) {
			return 0;
		} else if (s.equals("L")) {
			return 1;
		} else if (s.equals("B")) {
			return 2;
		} else if (s.equals("T")) {
			return 3;
		} else if (s.equals("RT")) {
			return 4;
		} else if (s.equals("LT")) {
			return 5;
		} else if (s.equals("RB")) {
			return 6;
		} else if (s.equals("LB")) {
			return 7;
		}
		return -1;
	}
}
