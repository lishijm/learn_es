#include"../include/list.h"

int main(){
    list *plist;
    plist=(list *)malloc(sizeof(list));
    memset(plist,0,sizeof(list));

    int i;
    for(i=0;i<5;i++){
        plist->arr[i]=i;
    }

    int sel,pos,flag=1;
    listel posel;
    while(flag){
        scanf("%d",&sel);
        switch(sel){
            case 1:
                output(plist);
                break;
            case 2:
                scanf("%d",&pos);
                scanf("%d",&posel);
                insert(plist,pos,posel);
                break;
            case 3:
                scanf("%d",&pos);
                del(plist,pos);
                break;
            default:
                flag=0;
                break;
        }
        pos=0;
        posel=0;
    }

    return 0;
}