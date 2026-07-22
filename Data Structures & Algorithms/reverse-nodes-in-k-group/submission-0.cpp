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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        int count_k = 0;
        ListNode* temp = head;

        while(count_k < k) {
            if(temp == NULL) {
                return head;
            }

            temp = temp->next;
            count_k++;
        }

        ListNode* prevNode = reverseKGroup(temp, k);

        temp = head;
        count_k = 0;

        while(count_k < k) {
            ListNode* next = temp->next;
            temp->next = prevNode;

            prevNode = temp;

            temp = next;

            count_k++;
        }

        return prevNode;

    }
};
