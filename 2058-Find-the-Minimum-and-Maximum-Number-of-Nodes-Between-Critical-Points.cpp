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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector <int> v;
        int nodeNo = 1;
        auto *temp= head->next;
        auto *left= head;
        auto *right= head->next->next;
        if(right== NULL || right -> next == NULL)
        return {-1, -1};

        while(right){
             nodeNo++;
            if((temp -> val) < (right -> val) && (temp -> val) < (left-> val)){
                v.push_back(nodeNo);
            }
            else if((temp -> val) > (right -> val) && (temp -> val) > (left-> val)){
               v.push_back(nodeNo);
            }

            left = temp;
            temp = right;
            right = right -> next;
        }
        //If there are fewer than two critical points, return [-1, -1].(given)
        if(v.size() < 2) return {-1, -1};
       
        int maxdist = v.back() - v.front();
        int mindist = INT_MAX;
        for(int i= 1; i<v.size(); i++){
            mindist = min(mindist, v[i] - v[i-1]);
        }
       return {mindist, maxdist};
    }
};
