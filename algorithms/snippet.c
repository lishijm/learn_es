/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

/**
 * 
 * @param pHead ListNode类 
 * @return ListNode类
 */
struct ListNode* ReverseList(struct ListNode* pHead ) {
    if(pHead==NULL){
        return NULL;
    }
    struct ListNode *ptmp=NULL,*prehead=NULL;
    prehead=(struct ListNode *)malloc(sizeof(struct ListNode));
    memset(prehead,0,sizeof(struct ListNode));
    while(NULL!=pHead->next){
        ptmp=(struct ListNode *)malloc(sizeof(struct ListNode));
        memset(ptmp,0,sizeof(struct ListNode));
        ptmp->val=pHead->val;
        if(NULL!=prehead->next){
            ptmp->next=prehead->next;
        }
        prehead->next=ptmp;
        pHead=pHead->next;
    }
    prehead->val=pHead->val;
    return prehead;
}