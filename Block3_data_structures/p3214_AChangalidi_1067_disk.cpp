#include <iostream>
#include <map>

using namespace std;

struct Node {
    Node(string name) {
        this->name = name;
        this->children = {};
    }

    string name;
    map<string, Node *> children;
};

void print_answer(Node *cur_node, int depth) {
    for (int i = 0; i < depth - 1; i++)
        cout << " ";
    depth++;
    if (!cur_node->name.empty()) {
        cout << cur_node->name << endl;
    }
    for (auto &child :cur_node->children)
        print_answer(child.second, depth);
}


int main() {
    int n;
    cin >> n;

    Node *root = new Node("");
    for (int i = 0; i < n; i++) {
        string path;
        cin >> path;
        string dir_name;
        Node *cur_node = root;
        for (int j = 0; j <= path.size(); j++) {

            if (path[j] == '\\' || path[j] == '\0') {
                auto new_dir = cur_node->children.find(dir_name);
                if (new_dir == cur_node->children.end()) {
                    Node *new_node = new Node(dir_name);
                    cur_node->children[dir_name] = new_node;
                    cur_node = cur_node->children.find(dir_name)->second;
                } else {
                    cur_node = new_dir->second;
                }
                dir_name = "";
            } else {
                dir_name += path[j];
            }
        }
    }
    print_answer(root, 0);
}