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
    ListNode* sortList(ListNode* head) {
        if(!head) return NULL ;
        vector<int> ls ;

        ListNode* temp = head ;
        while (temp != nullptr){
            ls.push_back(temp -> val) ;
            temp = temp -> next ;
        }

        delete temp ;
        delete head ;
        //free temp ;

        sort (ls.begin() , ls.end()) ;
        int n = ls.size() ;

        ListNode* root = new ListNode(ls[0]) ;
        temp = root ;
        int i = 1 ;
        while (i < n){
            temp -> next = new ListNode(ls[i]) ;
            if(temp-> next) temp = temp -> next ;
            i++ ;
        }
        return root ;
        
    }
};