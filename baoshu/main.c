#include <stdio.h>
#include <stdlib.h>
struct person {
    int num ;
    struct person * bef ;
    struct person * next ;
};
int main()
{
    int n ,m ,i;
    struct person *p ,*q;
    scanf("%d%d",&n,&m);
    p=(struct person *)malloc(n*sizeof(struct person));
    for (i=0;i<n;i++) {
        p[i].num=i+1;
        p[i].bef=&p[(i+7)%8];
        p[i].next=&p[(i+1)%8];
    }
    q=&p[0];
    printf("the out : ");
    while (n!=1) {
        for(i=1;i<m;i++) {
            q=q->next ;
        }
        printf("%d ",q->num);
        q->bef->next=q->next;
        q->next->bef=q->bef;
        n--;
        q=q->next;
    }
    printf("\n");
    printf("the left : %d ",q->num);

    return 0;


}
