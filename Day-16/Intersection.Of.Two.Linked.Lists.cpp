#include <iostream>
using namespace std;
//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        // find length of list A
        int lenA = 0;
        ListNode *currA = headA;
        while (currA)
        {
            lenA++;
            currA = currA->next;
        }

        // find length of list B
        int lenB = 0;
        ListNode *currB = headB;
        while (currB)
        {
            lenB++;
            currB = currB->next;
        }

        // move the longer list by the difference between the two lists’ lengths
        currA = headA;
        currB = headB;
        if (lenA > lenB)
        {
            int diff = lenA - lenB;
            for (int i = 0; i < diff; i++)
            {
                currA = currA->next;
            }
        }
        else
        {
            int diff = lenB - lenA;
            for (int i = 0; i < diff; i++)
            {
                currB = currB->next;
            }
        }

        // traverse both lists until the current nodes in both lists are the same
        while (currA && currB && currA != currB)
        {
            currA = currA->next;
            currB = currB->next;
        }

        return currA;
    }
};

int main()
{
    // Create two linked lists with a common intersection point
    ListNode *common = new ListNode(5);
    common->next = new ListNode(6);
    common->next->next = new ListNode(7);

    ListNode *headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(3);
    headA->next->next->next = common;

    ListNode *headB = new ListNode(4);
    headB->next = common;

    Solution S;

    // Find the intersection node of the two linked lists
    ListNode *intersection = S.getIntersectionNode(headA, headB);

    // Print the value of the intersection node
    cout << intersection->val << endl;

    return 0;
}
