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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> s(nums.begin(), nums.end());

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* curr = head;
        ListNode* prev = dummy;

        while (curr) {
            if (s.count(curr->val)) {
                prev->next = curr->next;

                curr = curr->next;

            }

            else {
                curr = curr->next;
                prev = prev->next;
            }
        }

        head = dummy->next;
        delete dummy;

        return head;
    }
};