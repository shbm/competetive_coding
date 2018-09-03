#include <stdio.h>
#include <queue>
#include <sstream>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <time.h>
#include <bitset>
#include <climits>

using namespace std;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
    os << "[";
    for (int i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i != v.size() - 1)
            os << ", ";
    }
    os << "]\n";
    return os;
}

vector<int> computeLPSArray(string str)
{
    int M = str.length();
    vector<int> lps(M);
    int len = 0;
    lps[0] = 0; // lps[0] is always 0

    int i = 1;
    while (i < M)
    {
        if (str[i] == str[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else // (str[i] != str[len])
        {
            if (len != 0) {
                len = lps[len-1];
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

int getMinCharToAddedToMakeStringPalin(string str)
{
    string revStr = str;
    reverse(revStr.begin(), revStr.end());

    string concat = str + "$" + revStr;

    vector<int> lps = computeLPSArray(concat);


    cout << lps;
    return (str.length() - lps.back());
}

int main()
{
    string str = "aaaaa";
    cout << getMinCharToAddedToMakeStringPalin(str);
    return 0;
}



ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* z = new ListNode(0);
        z->neixt = head;
        ListNode* temp = z;
        int i;
        for(i = 0; i < m-1; i++){
            temp = temp->next;
        }
        ListNode* curr = temp->next;
        ListNode* nex;
        ListNode* prev = NULL;
        for(int j = 0; j < n-m+1; j++){
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        ListNode* tail = temp->next;
        temp->next = prev;
        tail->next = curr;
        return z->next;
    }



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


ListNode* merge(ListNode *a, ListNode* b) {
    if(!a) return b;
    if(!b) return a;
    
    ListNode *head = a;
    a = a->next;
    
    ListNode *p = head;
    bool flip = false;
    
    while(a && b) {
        if(flip) {
            p->next = b;
            b = b->next;
        } else {
            p->next = a;
            a = a->next;
        }
        p = p->next;
        flip = !flip;
    }
    
    if(a) {
        p->next = a;
    } else {
        p->next = b;
    }
    
    return head;
    
}

ListNode *merge(ListNode *l1, ListNode *l2) {
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;

    ListNode* head = l1;    // head of the list to return
    l1 = l1->next;

    ListNode* p = head;     // pointer to form new listp
    // A boolean to track which list we need to extract from. 
    // We alternate between first and second list. 
    bool curListNum = true;

    while(l1 && l2){
        if(curListNum == false) {
            p->next = l1;
            l1 = l1->next;
        } else {
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
        curListNum = !curListNum;
    }

    // add the rest of the tail, done!
    if (l1) {
        p->next = l1;
    } else {
        p->next = l2;
    }

    return head;
}

    ListNode *reverseLinkedList(ListNode *head) {
        if (head->next == NULL) return head;
        ListNode *cur = head, *nextNode = head->next, *tmp;

        while (nextNode != NULL) {
            tmp = nextNode->next;
            nextNode->next = cur;
            cur = nextNode;
            nextNode = tmp;
        }

        head->next = nextNode;
        return cur;
    }


    ListNode *reverseLinkedList(ListNode *head) {
        if (head->next == NULL) return head;
        ListNode *pre = head, *cur = head->next, *n;


        while (cur != NULL) {
            n = cur->next;
            cur->next = pre;
            pre = cur;
            cur = n;
        }

        head->next = cur;
        return pre;
    }


    ListNode* Solution::reorderList(ListNode *head) {
        if(head == NULL || head->next == NULL || head->next->next==NULL)
            return head;

        //find the middle of the list, and split into two lists.    
        ListNode *slow = head,*fast = head;
        while(slow != NULL && fast != NULL && fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *mid = slow->next;
        slow->next = NULL;

        //reverse from the middle to the end
        ListNode* secondHalfReversed = reverseLinkedList(mid);

        //merge these two list
        return head = mergeTwoLists(head, secondHalfReversed);
    }