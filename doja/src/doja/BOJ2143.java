package doja;

import java.io.*;
import java.util.*;

public class BOJ2143 {
	static int N, M;
	static long T;
	static long[] list1, list2;
	static long cnt = 0;
	static ArrayList<Long> arrList1 = new ArrayList<>();
	static ArrayList<Long> arrList2 = new ArrayList<>();


	public static int lower_bound(int left, int right, long target) {
		while (left < right) {
			int middle = (left + right) / 2;
			if (arrList2.get(middle) < target) {
				left = middle + 1;
			} else {
				right = middle;
			}
		}
		return right;
	}

	public static int upper_bound(int left, int right, long target) {
		while (left < right) {
			int middle = (left + right) / 2;
			if (arrList2.get(middle) <= target) {
				left = middle + 1;
			} else {
				right = middle;
			}
		}
		return right;
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		T = Long.parseLong(br.readLine());
		N = Integer.parseInt(br.readLine());
		list1 = new long[N];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++)
			list1[i] = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(br.readLine());
		list2 = new long[M];
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < M; i++)
			list2[i] = Integer.parseInt(st.nextToken());

		for (int i = 0; i < N; i++) {
			long sum = 0;
			for (int j = i; j < N; j++) {
				sum += list1[j];
				arrList1.add(sum);
			}
		}
		for (int i = 0; i < M; i++) {
			long sum = 0;
			for (int j = i; j < M; j++) {
				sum += list2[j];
				arrList2.add(sum);
			}
		}
		Collections.sort(arrList1);
		Collections.sort(arrList2);

		for (int i = 0; i < arrList1.size(); i++) {
			long val = T - arrList1.get(i);
			cnt += upper_bound(0, arrList2.size(), val) - lower_bound(0, arrList2.size(), val);
		}

		System.out.println(cnt);
	}

}
