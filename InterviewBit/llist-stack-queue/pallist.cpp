/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::lPalin(ListNode *A)
{

    ListNode *p1 = A;
    ListNode *p2 = A;

    vector<int> v;

    int f = 1;

    while (1)
    {
        if (p2 == NULL)
        {
            f = 0;
            break;
        }
        else if (p2->next == NULL)
        {
            f = 1;
            break;
        }
        v.push_back(p1->val);
        p1 = p1->next;
        p2 = (p2->next)->next;
    }

    if (f)
    {
        p1 = p1->next;
    }

    auto it = v.end();
    it--;

    while (p1 != NULL)
    {

        if (v.empty())
        {
            return 0;
        }

        it = v.end();
        it--;

        if (p1->val != *it)
        {
            return 0;
        }

        v.pop_back();

        p1 = p1->next;
    }

    if (!v.empty())
    {
        return 0;
    }

    return 1;
}
