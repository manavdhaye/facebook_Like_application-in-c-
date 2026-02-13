#include "../include/social_network.h"

int main()
{
    char name1[40];
    struct graph *p;
    int choice,pass;
    p=represent();

    while(1)
    {
        printf("\n\n1.create account\n2.showdata\n3.login account\n");
        printf("\n\nenter a choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1 :
        {
            printf("\n\nenter a name : ");
            scanf("%s",name1);
            printf("\nenter a password : ");
            scanf("%d",&pass);
            p=addaccount(p,name1,pass);
            break;
        }
        case 2 :
        {
            showdata(p);
            break;
        }
        case 3 :
        {
            p=login(p);
            break;
        }
        default :
            printf("\n Invalid choice print 1 and 2");
        }
    }

    return 0;
}
