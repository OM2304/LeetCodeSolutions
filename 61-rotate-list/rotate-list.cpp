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
        if(head==NULL || k==0) return head;
        ListNode* last = head;
        int n = 1;
        while(last->next!=NULL) {
            n++;
            last = last->next;
        }

        k = k%n;
        if(k==n || k==0) return head;

        ListNode *breakNode = head;
        int times = n-k;
        while(--times) {
            breakNode = breakNode->next;
        }
        ListNode* start = breakNode->next;

        last->next = head;
        breakNode->next = NULL;
        head = start;
        return head;
    }
};