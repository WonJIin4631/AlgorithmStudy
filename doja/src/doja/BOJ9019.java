package doja;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class BOJ9019 {

	static int N;
	static boolean[] visit;

	static class Info {
		String command;
		int cur;

		Info(String command, int cur) {
			this.command = command;
			this.cur = cur;
		}
	}

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine();
		N = Integer.parseInt(s);
		for (int T = 0; T < N; T++) {
			visit = new boolean[10000];
			String[] num = br.readLine().split(" ");
			move(Integer.parseInt(num[0]), Integer.parseInt(num[1]));
		}
	}

	static void move(int st, int end) {

		Queue<Info> q = new LinkedList<>();
		Info info = new Info("", st);
		q.add(info);
		while (!q.isEmpty()) {
			Info c = q.poll();
			int cNum = c.cur;
			String cCom = c.command;
			if (cNum == end) {
				System.out.println(cCom);
				break;
			}
			int temp;
			Info t;
			// D
			temp = (cNum * 2) % 10000;
			if (!visit[temp]) {
				t = new Info(cCom + "D", temp);
				q.add(t);
				visit[temp] = true;
			}
			// S
			temp = cNum - 1;
			if (temp == -1)
				temp = 9999;
			if (!visit[temp]) {
				t = new Info(cCom + "S", temp);
				q.add(t);
				visit[temp] = true;
			}
			// L
			temp = (cNum * 10) % 10000 + (cNum * 10) / 10000;
			if (!visit[temp]) {
				t = new Info(cCom + "L", temp);
				q.add(t);
				visit[temp] = true;
			}
			// R;
			temp = (cNum / 10) + (cNum % 10) * 1000;
			if (!visit[temp]) {
				t = new Info(cCom + "R", temp);
				q.add(t);
				visit[temp] = true;
			}
		}
	}
}
