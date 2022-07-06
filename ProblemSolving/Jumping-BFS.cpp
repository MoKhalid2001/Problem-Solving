#include <vector>
#include <queue>
#include<bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> GRAPH;
int jump, n;

void fast() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
}
void add_reversed_directed_list(GRAPH& adjList, int from, int to) {
	adjList[to].push_back(from);
}

vector<int> BFS(GRAPH& adjList, int start) {
	vector<int> len(adjList.size(), -1);
	queue<int> q;
	q.push(start);
	len[start] = 0;

	for (int level = 0, sz = 1; !q.empty(); level++, sz = q.size()) {
		while (sz--) {
			int cur = q.front();
			q.pop();
			for (int neighbour : adjList[cur]) {
				if (len[neighbour] == -1) {
					q.push(neighbour);
					len[neighbour] = level + 1;
				}
			}
		}
	}
	return len;
}

void solve(GRAPH& graph) {
	int forward, backward;
	for (int i = 0; i < n; i++) {
		cin >> jump;
		forward = i + jump, backward = i - jump;
		if (forward < n) add_reversed_directed_list(graph, i, forward);
		if (backward >= 0) add_reversed_directed_list(graph, i, backward);
	}
	vector<int> results = BFS(graph, n - 1);
	for (int i = 0; i < n; i++)
		cout << results[i] << endl;


}
int main()
{
	fast();
	freopen("jumping.in", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		GRAPH graph(n);
		solve(graph);
	}
	return 0;




}

