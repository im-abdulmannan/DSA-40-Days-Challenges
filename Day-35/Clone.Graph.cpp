#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

// Definition for a Node.
class Node
{
public:
    int val;
    std::vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = std::vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = std::vector<Node *>();
    }
    Node(int _val, std::vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (node == nullptr)
            return nullptr;

        std::unordered_map<Node *, Node *> visited;

        std::queue<Node *> q;
        q.push(node);

        Node *clone_node = new Node(node->val);
        visited[node] = clone_node;

        while (!q.empty())
        {
            Node *curr_node = q.front();
            q.pop();

            for (Node *neighbor : curr_node->neighbors)
            {
                if (!visited.count(neighbor))
                {
                    visited[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }

                visited[curr_node]->neighbors.push_back(visited[neighbor]);
            }
        }

        return clone_node;
    }
};

int main(void)
{
    Solution sol;

    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    node1->neighbors.push_back(node2);
    node1->neighbors.push_back(node4);
    node2->neighbors.push_back(node1);
    node2->neighbors.push_back(node3);
    node3->neighbors.push_back(node2);
    node3->neighbors.push_back(node4);
    node4->neighbors.push_back(node1);
    node4->neighbors.push_back(node3);

    Node *clone = sol.cloneGraph(node1);

    std::cout << "Original Graph: " << std::endl;
    std::cout << "Node 1: ";
    for (Node *neighbor : node1->neighbors)
        std::cout << neighbor->val << " ";
    std::cout << std::endl;
    std::cout << "Node 2: ";
    for (Node *neighbor : node2->neighbors)
        std::cout << neighbor->val << " ";
    std::cout << std::endl;
    std::cout << "Node 3: ";
    for (Node *neighbor : node3->neighbors)
        std::cout << neighbor->val << " ";
    std::cout << std::endl;
    std::cout << "Node 4: ";
    for (Node *neighbor : node4->neighbors)
        std::cout << neighbor->val << " ";
    std::cout << std::endl;

    std::cout << "Cloned Graph: " << std::endl;
    std::cout << "Node 1: ";
    for (Node *neighbor : clone->neighbors)
        std::cout << neighbor->val << " ";
    std::cout << std::endl;
    std::cout << "Node 2: ";
    for (Node *neighbor : clone->neighbors[0]->neighbors)
        std::cout << neighbor->val << " ";
    std::cout << std::endl;
    std::cout << "Node 3: ";
    for (Node *neighbor : clone->neighbors[1]->neighbors)
        std::cout << neighbor->val << " ";
    std::cout << std::endl;
    std::cout << "Node 4: ";
    for (Node *neighbor : clone->neighbors[0]->neighbors[1]->neighbors)
        std::cout << neighbor->val << " ";
    std::cout << std::endl;

    return 0;
}