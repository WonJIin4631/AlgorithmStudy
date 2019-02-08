#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct segmentTree

{

	int size;

	vector<long long> tree, collection;

	segmentTree(int N, int M)

	{

		size = N + M;

		collection.resize(N);

		tree.resize(4 * size, 0);

	}

	//세그먼트 트리 초기화

	long long init(int node, int M, int start, int end)

	{

		if (start == end)

		{

			if (start >= M)

			{

				collection[start - M] = start;

				tree[node] = 1;

			}

			return tree[node];

		}



		int mid = (start + end) / 2;

		return tree[node] = init(node * 2, M, start, mid) + init(node * 2 + 1, M, mid + 1, end);

	}

	void init(int M)

	{

		init(1, M, 0, size - 1);

	}

	//구간 합 구하기

	long long query(int node, int start, int end, int nodeLeft, int nodeRight)

	{

		if (end < nodeLeft || nodeRight < start)

			return 0;

		if (start <= nodeLeft && nodeRight <= end)

			return tree[node];



		int mid = (nodeLeft + nodeRight) / 2;

		return query(node * 2, start, end, nodeLeft, mid) + query(node * 2 + 1, start, end, mid + 1, nodeRight);

	}

	long long query(int start, int end)

	{

		return query(1, start, collection[end] - 1, 0, size - 1);

	}

	//세그먼트 트리 업데이트

	long long update(int idx, int node, int val, int nodeLeft, int nodeRight)

	{

		if (idx < nodeLeft || nodeRight < idx)

			return tree[node];

		if (nodeLeft == nodeRight)

			return tree[node] = val;



		int mid = (nodeLeft + nodeRight) / 2;

		return tree[node] = update(idx, node * 2, val, nodeLeft, mid) + update(idx, node * 2 + 1, val, mid + 1, nodeRight);

	}

	long long update(int idx, int val)

	{

		return update(collection[idx], 1, val, 0, size - 1);

	}

	//해당 책 인덱스 업데이트

	void change(int idx, int val)

	{

		collection[idx] = val;

	}

};



int main(void)

{

	ios_base::sync_with_stdio(0);

	cin.tie(0); //cin 속도 향상

	int test_case;

	cin >> test_case;



	for (int i = 0; i < test_case; i++)

	{

		int N, M;

		cin >> N >> M;



		segmentTree segTree(N, M);

		segTree.init(M);



		//idx은 빈 공간 인덱스 표시

		int idx = M - 1;

		for (int j = 0; j < M; j++)

		{

			int num;

			cin >> num;



			cout << segTree.query(0, num - 1) << " ";

			segTree.update(num - 1, 0); //해당 디비디를 꺼내고

			segTree.change(num - 1, idx); //디비디의 위치를 바꾼다

			segTree.update(num - 1, 1); //누적합 업데이트

			idx--; //빈 공간

		}

		cout << "\n";

	}

	return 0;

}