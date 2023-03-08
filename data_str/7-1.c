/**
 * 名称: 归并算法的实现
 * 作者: mz21g
 * 日期: 2019.8.29
 * */

#include <stdio.h>
#include <stdlib.h>

typedef struct CELL *LIST;
struct CELL{
    int element;
    LIST next;
};

LIST merge(LIST list1, LIST list2);
LIST split(LIST list);
LIST MergeSort(LIST list);
LIST MakeList();
void PrintList(LIST list);

int main(){
    LIST list;

    printf("排序前: ");
    list = MakeList();

    PrintList(MergeSort(list));
}

LIST MakeList(){
    int x;
    LIST pNewCell;

    if (scanf("%d", &x) == EOF){
        printf("\n");
        return NULL;
    }
    else {
        printf("%d ", x);
        pNewCell = (LIST) malloc(sizeof(struct CELL));
        pNewCell -> next = MakeList();
        pNewCell -> element = x;
        return pNewCell;
    }
}

void PrintList(LIST list){
    printf("排序后: ");
    while (list != NULL)
    {   
        /**
         * 向下遍历整个已排序表
         * */
        printf("%d ", list->element);
        list = list->next;
    }
    printf("\n");
    
}

LIST MergeSort(LIST list){
    LIST SecondList;

    if (list == NULL) return NULL;
    else if (list->next == NULL) return list;
    else {
        /**
         * 表中至少有两个元素，这样做的副作用是有一半元素会从表中删除然后
         * 赋值到SecondList
         * */
        SecondList = split(list);
        return merge(MergeSort(list), MergeSort(SecondList));
    }
}

/**
 * 用两个已排序表生成一个只包含这两个表中所有元素的已排序表
 * 从表头开始分析他们，在每一步中，我们找出两个表当前开头位置中较小的那个，
 * 选择该元素作为合并后的表的下一个元素，并将该元素从他原来所在的表中删除，使得
 * 该表具有一个新的“首位”元素，两个表开头元素相同时会选取第一个表开头的元素
 * args: 指向两个给定表的指针
 * return: 指向合并后的表的指针
 * */
LIST merge(LIST list1, LIST list2){
    if (list1 == NULL) return list2;
    else if (list2 == NULL)return list1;
    else if (list1->element <= list2->element){
        /**
         * 在这里，两个表都不为空，
         * 而且第一个表的首个元素更小，
         * 得到的结果就是第一个表的第一个元素，
         * 后面跟上其余元素的合并
         * */
        list1->next = merge(list1->next, list2);
        return list1;
    } else{ // list2的首个元素更小
        list2->next = merge(list1, list2->next);
        return list2;
    }
}

/**
 * 将这些元素“处理”进两个表，其中一个表由第一个、第三个、第五个等元素组成，
 * 而另一个表则由偶数位置的元素组成。更确切地说，split函数会将偶数编号的
 * 元素从作为参数给出的表中删除，并返回一个由这些偶数编号元素组成的新表。
 * split是个具有副作用的函数，它会从作为参数给出的表中删除偶数位置的单元，
 * 而且它会将这些单元组合成一个作为该函数返回值的新表
 * */
LIST split(LIST list){
    /**
     * 局部变量pSecondCell被定义为LIST类型，这里是将pSecondCell用作
     * 指向表第二个单元（而不是指向表本身）的指针
     * */
    LIST pSecondCell;

    if (list == NULL) return NULL;
    else if (list->next == NULL) return NULL;
    else {
        // pSecondCell中存放了指向表第二个单元的指针
        pSecondCell = list->next;
        // 使第一个单元的next字段跳过第二个单元，直接指向第三个单元，或者
        // 如果表中只有两个单元，就变为NBLL
        list->next = pSecondCell->next;
        /**
         * 对除前两个元素之外的整个表递归的调用split函数
         * */
        pSecondCell->next = split(pSecondCell->next);
        /**
         * 返回一个指向第二个单元的指针，该指针让我们可以访问由原表中所有偶数
         * 编号的元素组成的链表
         * */
        return pSecondCell;
    }
}