class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<
            ListNode*,
            vector<ListNode*>,
            decltype([](ListNode* a, ListNode* b) {
                return a->val > b->val;
            })
        > pq;

        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != NULL) {
                pq.push(lists[i]);
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();

            current->next = node;
            current = current->next;

            if (node->next != NULL) {
                pq.push(node->next);
            }
        }

        current->next = NULL;

        ListNode* result = dummy->next;
        delete dummy;

        return result;
    }
};
