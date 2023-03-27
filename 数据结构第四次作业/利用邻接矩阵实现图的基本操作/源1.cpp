#include <iostream>
using namespace std;

struct Node {
    int name;            //结点的id, 其实可以用string替代
    int weight;          //边或结点的权重，在此例用没有用到
    Node* next_e;        //下一条边
    Node* next_v;        //下一个顶点
    Node(int name = 0, int weight = 0, Node* next_e = 0, Node* next_v = 0) :
        name(name),
        weight(weight),
        next_e(next_e),
        next_v(next_v)
    {

    }
};

Node* locate(Node& graph, int v) {   //根据id查找顶点
    Node* pos = graph.next_v;
    while (pos != 0)
    {
        if (pos->name == v) {
            return pos;
        }
        pos = pos->next_v;
    }
    return 0;
}

void insertVertex(Node& graph, int v) {
    if (locate(graph, v) == 0) {
        Node* node = &graph;
        while (node->next_v != 0)         //这里使用后插法
        {
            node = node->next_v;
        }
        node->next_v = new Node(v);
    }
}

void deleteVertex(Node& graph, int v) {
    Node* node = &graph;
    while (node->next_v != 0)
    {
        if (node->next_v->name == v) {
            Node* n = node->next_v;
            while (n->next_e != 0)
            {
                Node* t = n->next_e;
                n->next_e = n->next_e->next_e;
                delete t;
            }
            Node* temp = node->next_v;;
            node->next_v = node->next_v->next_v;
            delete temp;
            return;
        }
        node = node->next_v;
    }
}

void insertEdge(Node& graph, int v, int w) {
    Node* node_v = locate(graph, v);
    Node* node_w = locate(graph, w);
    if (node_v != 0 && node_w != 0) {
        Node* node = node_v;
        while (node->next_e != 0) {
            if (node->next_e->next_v->name == w) {
                return;
            }
            node = node->next_e;
        }
        node->next_e = new Node(0, 0, 0, node_w);
    }
}

void deleteEdge(Node& graph, int v, int w) {
    Node* node_v = locate(graph, v);
    Node* node_w = locate(graph, w);
    if (node_v != 0 && node_w != 0) {
        Node* node = node_v;
        while (node->next_e != 0)
        {
            if (node->next_e->next_v == node_w) {
                Node* temp = node->next_e;
                node->next_e = node->next_e->next_e;
                delete temp;
            }
            node = node->next_e;
        }
    }
}

void release(Node& graph) {
    Node* node = &graph;
    while (node->next_v != 0)
    {
        Node* n = node->next_v;
        while (n->next_e != 0)
        {
            Node* t = n->next_e;
            n->next_e = n->next_e->next_e;
            delete t;
        }
        Node* temp = node->next_v;;
        node->next_v = node->next_v->next_v;
        delete temp;
    }
    graph.next_v = 0;
}


void display(Node& graph) {
    Node* node = graph.next_v;
    while (node != 0)
    {
        cout << node->name << ": ";
        Node* n = node->next_e;
        while (n != 0)
        {
            cout << n->next_v->name << " ";
            n = n->next_e;
        }
        cout << endl;
        node = node->next_v;
    }
}

/*int size(Node& graph) {
    Node* node = graph.next_v;
    int count = 0;
    while (node != 0)
    {
        count++;
        node = node->next_v;
    }
    return count;
}
*/
/*int getEdgeWeight(Node& graph, int v, int w) {
    Node* node_v = locate(graph, v);
    Node* node_w = locate(graph, w);
    if (node_v != 0 && node_w != 0) {
        Node* node = node_v->next_e;
        while (node != 0) {
            if (node->next_v == node_w) {
                return node->weight;
            }
            node = node->next_e;
        }
    }
    return 0;
}*/

int main() {
    Node graph;
    insertVertex(graph, 5);
    insertVertex(graph, 4);
    insertVertex(graph, 3);
    insertVertex(graph, 2);
    insertVertex(graph, 1);
    insertEdge(graph, 1, 2);
    insertEdge(graph, 1, 3);
    insertEdge(graph, 4, 5);
    insertEdge(graph, 4, 1);
    insertEdge(graph, 4, 3);
    display(graph);
    deleteEdge(graph, 4, 1);
    deleteEdge(graph, 4, 1);
    cout << "-----------" << endl;
    display(graph);
    deleteVertex(graph, 4);
    cout << "-----------" << endl;
    display(graph);
    release(graph);
    return 0;
}
