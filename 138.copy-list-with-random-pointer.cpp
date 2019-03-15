/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 *
 * https://leetcode.com/problems/copy-list-with-random-pointer/description/
 *
 * algorithms
 * Medium (25.62%)
 * Total Accepted:    226K
 * Total Submissions: 873.2K
 * Testcase Example:  '{"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}'
 *
 * A linked list is given such that each node contains an additional random
 * pointer which could point to any node in the list or null.
 * 
 * Return a deep copy of the list.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input:
 * 
 * {"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}
 * 
 * Explanation:
 * Node 1's value is 1, both of its next and random pointer points to Node 2.
 * Node 2's value is 2, its next pointer points to null and its random pointer
 * points to itself.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * You must return the copy of the given head as a reference to the cloned
 * list.
 * 
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/

/*   using hashmap solution 
class Solution {
 public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return NULL;
        Node* res = new Node(head->val);
        Node* cur;
        Node* node = res;
        unordered_map<Node*, Node*> m;
        cur = head->next;
        m[head] = res;
        while (cur) {
            Node * tmp = new Node(cur->val);
            node->next = tmp;
            m[cur] = tmp;
            cur = cur->next;
            node = node->next;
        }
        cur = head;
        node = res;
        while (node) {
            node->random = m[cur->random];
            cur = cur->next;
            node = node->next;
        }
        return res;
    }
};

*/
class Solution {
 public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return NULL;
        Node* iter = head;
        /* insert copy between the two orginal list */
        while (iter) {
            Node * copy = new Node(iter->val);
            copy->next = iter->next;
            iter->next = copy;
            iter = iter->next->next;
        }
        iter = head;
        /* fix the copy random */
        while (iter) {
            if (iter->random)
                iter->next->random = iter->random->next;
            iter = iter->next->next;
        }
        /* break the link */
        iter = head;
        Node * newhead = iter->next;
        while (iter) {
            Node* tmp = iter->next;
            iter->next = tmp->next;
            if (tmp->next) {
                tmp->next = tmp->next->next;
            }
            iter = iter->next;
        }
    return newhead;
    }
};
