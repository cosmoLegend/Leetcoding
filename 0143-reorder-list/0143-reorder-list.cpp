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
    void reorderList(ListNode* head) {
        vector<ListNode*> vec ;
        ListNode* temp = head ;

        while (temp != nullptr){
            vec.push_back(temp) ;
            temp = temp -> next ;
        }


        int n = vec.size() ;

        int l = 1 , r = n - 1 ;
        temp = head ;
        bool switcher = false ;

        while (l <= r){

            if(!switcher){

            temp -> next = vec[r] ;
            temp = temp -> next ;
            r -- , switcher = true ;

            }

            else {
                temp -> next = vec[l] ;
                temp = temp -> next ;
                l++ , switcher = false ;
            }

        }

        temp -> next = nullptr ;

        return ;
    }
};