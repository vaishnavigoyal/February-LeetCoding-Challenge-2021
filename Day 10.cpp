// Day 10
// Question : Copy List with Random Pointer

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
	Node *copyRandomList(Node *head)
	{
		if (head == NULL)
			return NULL;

		unordered_map<Node *, Node *> mp;

		Node *B = head;
		while (B != NULL)
		{
			Node *temp = new Node(B->val);
			mp[B] = temp;
			B = B->next;
		}
		mp[NULL] = NULL;
		B = head;
		while (B != NULL)
		{
			mp[B]->next = mp[B->next];
			mp[B]->random = mp[B->random];
			B = B->next;
		}
		return mp[head];
	}
};