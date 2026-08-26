/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)return head;

        int n = 1;
        ListNode* last = head;
        while(last->next!=NULL) {
            n++;
            last = last->next;
        }

        k = k%n;
        if(k==0) return head;

        ListNode* breakNode = head;
        int count = n-k;
        while(--count) {
            breakNode = breakNode->next;
        }
        
        ListNode* res = breakNode->next;

        //Now we got all the Nodes it's time for joining the Links
        last->next = head;
        breakNode->next = NULL;
        head = res;
        return head;
    }
};