/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *Solution::reverseList(ListNode *A, int B)
{

    stack<int> s;

    ListNode *p1 = A;
    ListNode *p2 = A;

    int c;

    while (p1 != NULL)
    {
        c = 0;

        while (c < B)
        {
            c++;
            s.push(p2->val);
            p2 = p2->next;
        }

        while (p1 != p2)
        {
            p1->val = s.top();

            s.pop();

            p1 = p1->next;
        }
    }

    return A;
}
