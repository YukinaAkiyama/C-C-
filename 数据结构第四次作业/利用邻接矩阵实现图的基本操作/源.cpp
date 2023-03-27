#include <iostream>
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

void deleteEdge(Graph& graph, int v, int w) {

    int i = locate(graph, v);
    int j = locate(graph, w);
    if (i != -1 && j != -1) {
        graph.weight[i][j] = 0;
    }
}

void deleteVetex(Graph& graph, int v) {
    int pos = locate(graph, v);
    int lst = graph.size - 1;
    if (pos != -1) {
        //与最后一个顶点交换
        int temp = graph.vertex[pos];
        graph.vertex[pos] = graph.vertex[lst];
        graph.vertex[lst] = temp;
        for (int i = 0; i < graph.size; i++) {
            int t = graph.weight[pos][i];
            graph.weight[pos][i] = graph.weight[lst][i];
            graph.weight[lst][i] = t;
        }
        for (int i = 0; i < graph.size; i++) {
            int t = graph.weight[i][pos];
            graph.weight[i][pos] = graph.weight[i][lst];
            graph.weight[i][lst] = t;
        }
        //删除最后一个顶点
        graph.size--;
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

int main() {
    Graph graph;
    insertVetex(graph, 4);
    insertVetex(graph, 5);
    insertEdge(graph, 5, 4);
    insertVetex(graph, 5);
    insertVetex(graph, 6);
    insertVetex(graph, 7);
    insertVetex(graph, 8);
    insertEdge(graph, 4, 6);
    insertEdge(graph, 3, 6);
    insertEdge(graph, 7, 7);
    insertEdge(graph, 7, 8);
    insertEdge(graph, 8, 7);
    display(graph);
    deleteEdge(graph, 4, 6);
    display(graph);
    deleteVetex(graph, 5);
    display(graph);
    return 0;
}
