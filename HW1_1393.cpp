#include<iostream>
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};
ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;
    while(curr != NULL)
    {
        ListNode* nexttemp = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = nexttemp;
    }
    return prev;
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* head = new ListNode(0);
    ListNode* curr = head;
    int carry = 0;
    while(l1 || l2 || carry)
    {
        int sum = carry;
        if(l1)
        {
            sum += l1 -> val;
            l1 = l1 ->next;
        }
        if(l2)
        {
            sum += l2 -> val;
            l2 = l2 ->next;
        }
        carry = sum / 10;
        curr -> next = new ListNode(sum % 10);
        curr = curr -> next;
    }
    return head -> next;
}


int main(){
    int m,n,val;
    std::cin >> m >> n;
    std::cin >> val;
    ListNode* head = new ListNode(val);
    ListNode* curr = head;
    for (int i=1; i<m; i++){
        std::cin >> val;
        curr -> next = new ListNode(val);
        curr = curr -> next;
    }
    std::cin >> val;
    ListNode* head2 = new ListNode(val);
    ListNode* curr2 = head2;
    for (int i=1; i<n; i++){
        std::cin >> val;
        curr2 -> next = new ListNode(val);
        curr2 = curr2 -> next;
    }
    head = reverseList(head);
    head2 = reverseList(head2);
    ListNode* merged = mergeTwoLists(head, head2);
    ListNode* result = reverseList(merged);
    ListNode* p = result;
    while (p) {
        std::cout << p->val;
        if (p->next) std::cout << " ";
        p = p->next;
    }
    std::cout << std::endl;
    p = head;                        
    while (p != NULL) {
        ListNode* temp = p;
        p = p->next;
        delete temp;
    }
    p = head2;                        
    while (p != NULL) {
        ListNode* temp = p;
        p = p->next;
        delete temp;
    }
    p = merged;                        
    while (p != NULL) {
        ListNode* temp = p;
        p = p->next;
        delete temp;
    }
    return 0;
}