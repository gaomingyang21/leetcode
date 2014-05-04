/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode(int x) : val(x), next(NULL) {}
 * };
 * 代码来源：http://www.cnblogs.com/TenosDoIt/p/3434550.html
 * 特别说明：通过这个题，我学习了解了归并算法。C++代码和c语言代码还是有许多不同的地方
 * 指针的强大，尤其是在处理链表的时候
 */
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        //链表归并排序
        if(head == NULL || head->next == NULL)return head;
        else
        {
            //快慢指针找到中间节点
            ListNode *fast = head,*slow = head;
            while(fast->next != NULL && fast->next->next != NULL)
            {
                fast = fast->next->next;
                slow = slow->next;
            }
            fast = slow;
            slow = slow->next;
            fast->next = NULL;
            fast = sortList(head);//前半段排序
            slow = sortList(slow);//后半段排序
            return merge(fast,slow);
        }
        
    }
    // merge two sorted list to one
    ListNode *merge(ListNode *head1, ListNode *head2)
    {
        if(head1 == NULL)return head2;
        if(head2 == NULL)return head1;
        ListNode *res , *p ;
        if(head1->val < head2->val)
            {res = head1; head1 = head1->next;}
        else{res = head2; head2 = head2->next;}
        p = res;
        
        while(head1 != NULL && head2 != NULL)
        {
            if(head1->val < head2->val)
            {
                p->next = head1;
                head1 = head1->next;
            }
            else
            {
                p->next = head2;
                head2 = head2->next;
            }
            p = p->next;
        }
        if(head1 != NULL)p->next = head1;
        else if(head2 != NULL)p->next = head2;
        return res;
    }
};
