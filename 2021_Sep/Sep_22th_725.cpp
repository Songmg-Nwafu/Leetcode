//
// Created by smg_nwafu on 2021/9/22.
//
#include <vector>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution{
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int list_length = 0;
        ListNode* tmp = head;
        while (tmp != nullptr){
            list_length++;
            tmp = tmp -> next;
        }
        int n = list_length / k, re = list_length % k;
        vector<ListNode*> part(k, nullptr);
        ListNode* cur = head;
        for (int i = 0; i < k && cur != nullptr; ++i) {
            part[i] = cur;
            int part_size = n + (i < re ? 1 : 0);
            for (int j = 1; j < part_size; ++j) {
                cur = cur -> next;
            }
            ListNode* ptr = cur -> next;
            cur -> next = nullptr;
            cur = ptr;
        }

        return part;
    }
};