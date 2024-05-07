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
    ListNode* reverseList(ListNode* head)
    {
        ListNode* temp = NULL;
        while(head){
            ListNode* nex = head->next;
            head->next = temp;
            temp=head;
            head=nex;
        }
        return temp;
    }
    void insert(ListNode* &head, int d)
    {
        ListNode* n= new ListNode(d);
        if(head==NULL)
        {
            head=n;
            return;
        }
        ListNode* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=n;
    }
    ListNode* doubleIt(ListNode* head) {
        ListNode* temp = reverseList(head);
        ListNode* dummy=NULL;
        int sum=0,carry=0;
        while(temp){
            sum=2*temp->val + carry;
            insert(dummy,sum%10);
            carry = sum/10;
            temp=temp->next;
        }
        if(carry) insert(dummy,carry);
        return reverseList(dummy);
    }
};
