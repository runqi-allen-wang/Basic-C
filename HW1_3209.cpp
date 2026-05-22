#include <iostream>
struct ListNode
{
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
int main()
{
    int n, val;
	std::cin >> n;
    std::cin >> val;
    ListNode* head = new ListNode(val);
    ListNode* curr = head;
    for (int i=1; i<n; i++){
        std::cin >> val;
        curr -> next = new ListNode(val);
        curr = curr -> next;
    }
    head = reverseList(head);
    ListNode* p = head;              
    for (int i = 0; i < n; i++) {
        std::cout << p->val << " ";
        p = p->next;
    }
    std::cout << std::endl;
    p = head;                        
    while (p != NULL) {
        ListNode* temp = p;
        p = p->next;
        delete temp;
    }
}   