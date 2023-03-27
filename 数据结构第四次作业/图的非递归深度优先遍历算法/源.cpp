#include <iostream>
#include <stack>
#include <set>
using namespace std;

struct Graph {
	static const int MAX_V = 100;
	int weight[MAX_V][MAX_V];
	int vertex[MAX_V];
	int size = 0;
	Graph() {

	}
};

int locate(Graph& graph, int v) { //查找顶点位置
	for (int i = 0; i < graph.size; i++) {
		if (graph.vertex[i] == v) {
			return i;
		}
	}
	return -1;
}


void insertVetex(Graph& graph, int v) {
	if (graph.size + 1 > graph.MAX_V) {    ///如果顶点个数已满
		return;
	}

	if (locate(graph, v) != -1) {  //如果已经存在相同的顶点
		return;
	}

	graph.vertex[graph.size] = v;
	for (int i = 0; i <= graph.size; i++) {
		graph.weight[i][graph.size] = graph.weight[graph.size][i] = 0;
	}
	graph.size++;
}

void insertEdge(Graph& graph, int v, int w) {
	int i = locate(graph, v);
	int j = locate(graph, w);
	if (i != -1 && j != -1) {
		graph.weight[i][j] = 1;
	}
}

void display(Graph& graph) {
	cout << "vetices: ";
	for (int i = 0; i < graph.size; i++) {
		cout << graph.vertex[i] << " ";
	}
	cout << endl;
	cout << "edges: " << endl;
	for (int i = 0; i < graph.size; i++) {
		for (int j = 0; j < graph.size; j++) {
			cout << graph.weight[i][j] << " ";
		}
		cout << endl;
	}
}

void DFS(Graph& graph, int v) {
	int pos = locate(graph, v);
	if (pos != -1) {
		stack<int> opened;
		set<int> closed;
		opened.push(pos);
		while (!opened.empty())
		{
			int index = opened.top(); opened.pop();
			if (closed.find(index) == closed.end()) {  //！注意判断的位置
				cout << graph.vertex[index] << " ";
				//添加子结点
				for (int i = 0; i < graph.size; i++) {
					if (graph.weight[index][i] != 0) {
						opened.push(i);
					}
				}
				closed.insert(index);
			}
		}
	}
}


int main() {
	Graph graph;
	insertVetex(graph, 0);
	insertVetex(graph, 1);
	insertVetex(graph, 2);
	insertVetex(graph, 3);
	insertVetex(graph, 4);
	insertEdge(graph, 0, 1);
	insertEdge(graph, 0, 2);
	insertEdge(graph, 1, 0);
	insertEdge(graph, 1, 3);
	insertEdge(graph, 1, 4);
	insertEdge(graph, 2, 0);
	insertEdge(graph, 2, 3);
	insertEdge(graph, 3, 1);
	insertEdge(graph, 3, 2);
	insertEdge(graph, 3, 4);
	insertEdge(graph, 4, 1);
	insertEdge(graph, 4, 3);
	display(graph);
	cout << "search result: ";
	DFS(graph, 1);
	return 0;
}
