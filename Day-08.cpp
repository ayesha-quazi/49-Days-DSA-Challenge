// 1. Linked List Cycle II 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !(head->next))
            return NULL;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                break;
        }
        
        if(fast != slow)
            return NULL;
        
        ListNode* entry = head;
        while(entry != slow) {
            entry = entry->next;
            slow  = slow->next;
        }
        return entry;
    }
};

//T.C : O(n)
//S.C : O(1)


// 2. Copy List with Random Pointer

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

//Approach (Using O(n) space)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return NULL;
        map<Node*, Node*> mp;
        Node* curr = head;
        Node* prev = NULL;
        Node* newHead = NULL;
        while(curr) {
            Node* temp = new Node(curr->val);
            mp[curr] = temp;
            if(newHead == NULL) {
                newHead = temp;
                prev = newHead;
            } else {
                prev->next = temp;
                prev = temp;
            }
            curr = curr->next;
        }
        
        curr = head;
        Node* newCurr = newHead;
        while(curr) {
            if(curr->random == NULL) {
                newCurr->random = NULL;
            } else {
                newCurr->random = mp[curr->random];
            }
            
            newCurr = newCurr->next;
            curr = curr->next;
        }
        return newHead;
    }
};