#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

enum letter {A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z};

struct post
{
    char npost[1000];
    int like;
    int dislike;
    int love;
    char comment[100];
    struct post *postnext;
};
struct message
{
    char amsg[100][100];
    int visited;
    char aname[40];
    struct message *msgnext;
};
struct node
{
    char alphabet;
    struct node *next;
    //struct node *frinext;
    char name[40];
    int follower;
    int following;
    char sname[100][40];
    char friname[100][40];
    char pname[100][40];
    int password;
    struct post *p;
    struct message *msg;
};
struct graph
{
    int vertexnum;
    int edge;
    struct node **adj;
};

void friend(struct node *temp1,char name1[40],struct graph *g,int a);

struct node* made(char v)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->alphabet=v;
    temp->next=NULL;
    return(temp);
}
struct graph* represent()
{
    int i,x,y,a;
    struct graph *g;
    struct node *temp,*new;
    g=(struct graph*)malloc(sizeof(struct graph));
    g->vertexnum=26;
    g->adj=malloc(g->vertexnum * sizeof(struct node));
//g->adj[0]->vertex=6;
//printf("%d",g->adj[0]->vertex);
    for(i=0; i<g->vertexnum; i++)
        g->adj[i]=NULL;

    for(i=0; i<26; i++)
    {
        char m=i+65;
        g->adj[i]=made(m);
    }
    for(i=0; i<26; i++)
    {
        printf("%c ",g->adj[i]->alphabet);
    }
    return(g);
}

struct graph *addaccount(struct graph *g,char name1[40],int pass)
{
    struct node *temp,*temp1,*ptr;
    temp=(struct node*)malloc(sizeof(struct node));
    strcpy(temp->name,name1);
    temp->password=pass;
    temp->follower=0;
    temp->following=0;
    // temp->frinext=NULL;
    char a=name1[0];
    printf("%c",a);
    for(int i=0; i<g->vertexnum-1; i++)
    {
        if(g->adj[i]->alphabet==a)
        {
            ptr=g->adj[i];
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=temp;
        }
    }
    return(g);
}
void showdata(struct graph *g)
{
//printf("\n%c->",g->adj[0]->alphabet);
//printf("\n%s->",g->adj[0]->next->name);
    int i,flag=1,j;
    struct node *temp1,*ptr;
    for(i=0; i<g->vertexnum; i++)
    {
        printf("\n%c->",g->adj[i]->alphabet);
        temp1=g->adj[i]->next;
        if(temp1!=NULL)
        {
            if(temp1->next==NULL)
            {
                printf("%s->",temp1->name);
                for(j=0; j<100; j++)
                {
                    if(!strlen(temp1->friname[j]))
                        break;
                    printf("friend  name : %s",temp1->friname[j]);
                }
                //  printf("%s->",temp1->sname);
            }
            else
            {
                while(temp1->next!=NULL)
                {
                    printf("%s->",temp1->name);
                    //     printf("%s->",temp1->sname);
                    for(j=0; j<100; j++)
                    {
                        if(!strlen(temp1->friname[j]))
                        {
                            break;
                        }
                        printf("friend  name : %s",temp1->friname[j]);
                    }
                    temp1=temp1->next;
                    flag=0;
                }
                if(flag==0)
                {
                    printf("%s->",temp1->name);
                    for(j=0; j<100; j++)
                    {
                        if(!strlen(temp1->friname[j]))
                        {
                            break;
                        }
                        printf("friend  name : %s",temp1->friname[j]);
                    }
                    // printf("%s->NULL",temp1->sname);
                    flag=1;
                }
            }
        }
    }
}
void friendtwoway(char name2[40],char name1[40],struct graph *g)
{
    int i,j,flag=1,kk=2;
    struct node *temp1;
    for(i=0; i<g->vertexnum; i++)
    {
        temp1=g->adj[i]->next;
        if(temp1!=NULL)
        {
            if(temp1->next==NULL)
            {
                if(!strcmp(temp1->name,name1))
                {
                    friend(temp1,name2,g,kk);
                    break;
                }
            }
            else
            {
                while(temp1->next!=NULL)
                {
                    if(!strcmp(temp1->name,name1))
                    {
                        friend(temp1,name2,g,kk);
                        break;
                    }

                    temp1=temp1->next;
                    flag=0;
                }
                if(flag==0)
                {
                    if(!strcmp(temp1->name,name1))
                    {
                        friend(temp1,name2,g,kk);

                        break;
                    }
                    flag=1;
                }
            }
        }
    }
}
void friend(struct node *temp1,char name1[40],struct graph *g,int a)
{
    static int s;
    s=a;
    int i;
    int flag=0;
    for(i=0; i<100; i++)
    {
        if(!strlen(temp1->friname[i]))
        {
            strcpy(temp1->friname[i],name1);
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        struct message *q,*p;
        q=(struct message*)malloc(sizeof(struct message));
        q->visited=1;
        strcpy(q->aname,name1);
        if(temp1->msg==NULL)
        {
            temp1->msg=q;
        }
        else
        {
            p=temp1->msg;
            while(p->msgnext!=NULL)
            {
                p=p->msgnext;
            }
            p->msgnext=q;
        }
        if(s==1)
        {
            s++;
            friendtwoway(temp1->name,name1,g);
        }
    }
    // return(temp1);
}
void postoperation(struct node *temp)
{
    char napost[100];
    printf("enter a post : ");
    scanf("%s",napost);
    struct post *p1,*p3,*p2;
    p1=(struct post*)malloc(sizeof(struct post));
    strcpy(p1->npost,napost);
    p1->like=0;
    if(temp->p==NULL)
    {
        temp->p=p1;
    }
    else
    {
        p3=temp->p;
        while(p3->postnext!=NULL)
        {
            p3=p3->postnext;
        }
        p3->postnext=p1;
    }

}
void postlogic(struct node *temp,struct graph *g)
{
    int i,j,p=0;
    int flag=1;
    struct node *temp1;
    // struct graph *g;
    //  printf("%s",g->adj[0]->next->name);
    // char fname[40],uname[40];
    //printf("\npost logic function\n");
    for(p=0; p<100; p++)
    {

        for(i=0; i<g->vertexnum; i++)
        {
            temp1=g->adj[i]->next;
            if(temp1!=NULL)
            {
                if(temp1->next==NULL)
                {
                    if(!strcmp(temp1->name,temp->friname[p]))
                    {
                        for(j=0; j<100; j++)
                        {
                            if(!strlen(temp1->pname[j]))
                            {
                                strcpy(temp1->pname[j],temp->name);
                                // printf("friend name  : %s ",temp1->pname[0]);
                                //printf("account name : %s ",temp1->name);
                                break;
                            }

                        }

                        break;
                    }
                }
                else
                {
                    while(temp1->next!=NULL)
                    {
                        if(!strcmp(temp1->name,temp->friname[p]))
                        {
                            for(j=0; j<100; j++)
                            {
                                if(!strlen(temp1->pname[j]))
                                {
                                    strcpy(temp1->pname[j],temp->name);
                                    break;
                                }

                            }

                            break;
                        }

                        temp1=temp1->next;
                        flag=0;
                    }
                    if(flag==0)
                    {
                        if(!strcmp(temp1->name,temp->friname[p]))
                        {
                            for(j=0; j<100; j++)
                            {
                                if(!strlen(temp1->pname[j]))
                                {
                                    strcpy(temp1->pname[j],temp->name);
                                    break;
                                }

                            }

                            break;

                        }
                        flag=1;
                    }
                }
            }
        }
    }
}
void likepost(struct node * temp,struct graph *g)
{
    int count=0,p,l,i,flag=1,lo,li,d,t=0;
    char tname[40];
    struct node *temp1;
    for(p=0; p<100; p++)
    {
        l=strlen(temp->pname[p]);
        if(l==0)
        {
            break;
        }
        else
        {
            // printf("post name : %s",temp->pname[p]);
        }
        count++;
    }
    //  printf("\n%d",count);
    for(p=0; p<count; p++)
    {
        t=0;
        strcpy(tname,temp->pname[p]);
        for(i=0; i<g->vertexnum; i++)
        {
            temp1=g->adj[i]->next;
            if(temp1!=NULL)
            {
                if(temp1->next==NULL)
                {
                    if(!strcmp(temp1->name,tname))
                    {
                        printf("\npost : %s",temp1->p->npost);
                        printf("\nenter a 1 to like : ");
                        scanf("%d",&li);
                        if(li==1)
                        {
                            t=1;
                            temp1->p->like++;
                        }
                        if(t==0)
                        {
                            printf("\nenter a 2 to love : ");
                            scanf("%d",&lo);
                            if(lo==2)
                            {
                                t=1;
                                temp1->p->love++;
                            }
                            if(t==0)
                            {
                                printf("\nenter a 3 to dislike : ");
                                scanf("%d",&d);
                                if(d==3)
                                    temp1->p->dislike++;
                            }
                        }
                        break;
                    }
                }
                else
                {
                    while(temp1->next!=NULL)
                    {
                        if(!strcmp(temp1->name,tname))
                        {
                            printf("\npost : %s",temp1->p->npost);
                            printf("\nenter a 1 to like : ");
                            scanf("%d",&li);
                            if(li==1)
                            {
                                t=1;
                                temp1->p->like++;
                            }
                            if(t==0)
                            {
                                printf("\nenter a 2 to love : ");
                                scanf("%d",&lo);
                                if(lo==2)
                                {
                                    t=1;
                                    temp1->p->love++;
                                }
                                if(t==0)
                                {
                                    printf("\nenter a 3 to dislike : ");
                                    scanf("%d",&d);
                                    if(d==3)
                                        temp1->p->dislike++;
                                }
                            }

                            break;
                        }

                        temp1=temp1->next;
                        flag=0;
                    }
                    if(flag==0)
                    {
                        if(!strcmp(temp1->name,tname))
                        {
                            printf("\npost : %s",temp1->p->npost);
                            printf("\nenter a 1 to like : ");
                            scanf("%d",&li);
                            if(li==1)
                            {
                                t=1;
                                temp1->p->like++;
                            }
                            if(t==0)
                            {
                                printf("\nenter a 2 to love : ");
                                scanf("%d",&lo);
                                if(lo==2)
                                {
                                    t=1;
                                    temp1->p->love++;
                                }
                                if(t==0)
                                {
                                    printf("\nenter a 3 to dislike : ");
                                    scanf("%d",&d);
                                    if(d==3)
                                        temp1->p->dislike++;
                                }
                            }
                            flag=1;
                            break;

                        }
                    }
                }
            }
        }
    }
}
struct message* check(char name1[40],struct graph * g,char name2[40])
{
    int i,flag=1;
    struct node *temp1;
    struct message *ptr;
    for(i=0; i<g->vertexnum; i++)
    {
        temp1=g->adj[i]->next;
        if(temp1!=NULL)
        {
            if(temp1->next==NULL)
            {
                if(!strcmp(temp1->name,name1))
                {
                    ptr=temp1->msg;
                    while(ptr!=NULL)
                    {
                        if(ptr->visited==1&&strcmp(ptr->aname,name2))
                        {
                            return(ptr);
                        }
                        ptr=ptr->msgnext;
                    }
                    break;
                }
            }
            else
            {
                while(temp1->next!=NULL)
                {
                    if(!strcmp(temp1->name,name1))
                    {
                        ptr=temp1->msg;
                        while(ptr!=NULL)
                        {
                            if(ptr->visited==1&&strcmp(ptr->aname,name2))
                            {
                                return(ptr);
                            }
                            ptr=ptr->msgnext;
                        }
                        break;
                    }

                    temp1=temp1->next;
                    flag=0;
                }
                if(flag==0)
                {
                    if(!strcmp(temp1->name,name1))
                    {
                        ptr=temp1->msg;
                        while(ptr!=NULL)
                        {
                            if(ptr->visited==1&&strcmp(ptr->aname,name2))
                            {
                                return(ptr);
                            }
                            ptr=ptr->msgnext;
                        }
                        break;

                    }
                    flag=1;
                }
            }
        }
    }
    return(NULL);
}
struct message *check1(char str[40],struct node *temp)
{
    struct message *ptr;
    ptr=temp->msg;
    while(ptr!=NULL)
    {
        if((!strcmp(ptr->aname,str))&&ptr->visited==1)
        {
            return(ptr);
            break;
        }
        ptr=ptr->msgnext;
    }
    return(NULL);
}
struct graph *login(struct graph *g)
{
    char uname[40],fname[40],napost[100],p,str[40],mes1[40];
    int pass,choice,f,j,index,i,m,l,z,x,mm,t,kk=1;
    printf("\nenter a name : ");
    scanf("%s",uname);
    printf("\nenter a password : ");
    scanf("%d",&pass);
    bool flag=1;
    bool flag1=1;
    struct node *temp1,*ptr;
// enum letter a=uname[0];

    for(i=0; i<g->vertexnum; i++)
    {
        temp1=g->adj[i]->next;
        if(temp1!=NULL)
        {
            if(temp1->next==NULL)
            {
                if(!strcmp(temp1->name,uname)&&temp1->password==pass)
                {
                    flag1=0;

                    printf("login succesfuly\n\n");
                    printf("Id : %s",temp1->name);
                    printf("\nfollower : %d",temp1->follower);
                    printf("\nfollowing : %d",temp1->following);
                    for(j=0; j<100; j++)
                    {
                        if(!strlen(temp1->sname[j]))
                            break;
                        printf("\nfriend request : %s",temp1->sname[j]);
                    }

                    printf("\nenter a 1 to accept friend request : ");
                    scanf("%d",&f);

                    if(f==1)
                    {
                        printf("\nenter a index of friend to accept friend request: ");
                        scanf("%d",&index);
                        for(j=0; j<100; j++)
                        {
                            if(j==index)
                            {
                                friend(temp1,temp1->sname[j],g,kk);
                                break;
                            }
                        }
                    }
                    ptr=temp1;
                    break;
                }
            }
            else
            {
                while(temp1->next!=NULL)
                {
                    if(!strcmp(temp1->name,uname)&&temp1->password==pass)
                    {   // ptr=temp1;
                        flag1=0;
                        printf("login succesfuly\n\n");
                        printf("\nname : %s",temp1->name);
                        printf("\nfollower : %d",temp1->follower);
                        printf("\nfollowing : %d",temp1->following);
                        for(j=0; j<100; j++)
                        {
                            if(!strlen(temp1->sname[j]))
                                break;
                            printf("\nfriend request : %s",temp1->sname[j]);
                        }

                        printf("\nenter a 1 to accept friend request : ");
                        scanf("%d",&f);
                        if(f==1)
                        {
                            printf("\nenter a index of friend to accept friend request: ");
                            scanf("%d",&index);
                            for(j=0; j<100; j++)
                            {
                                if(j==index)
                                {
                                    friend(temp1,temp1->sname[j],g,kk);
                                    break;
                                }
                            }

                        }
                        ptr=temp1;
                        break;
                    }
                    temp1=temp1->next;

                    flag=0;
                }
                if(flag==0)
                {
                    if(!strcmp(temp1->name,uname)&&temp1->password==pass)
                    {
                        //  ptr=temp1;
                        flag1=0;
                        printf("login succesfuly\n\n");
                        printf("name : %s",temp1->name);
                        printf("\nfollower : %d",temp1->follower);
                        printf("\nfollowing : %d",temp1->following);
                        for(j=0; j<100; j++)
                        {
                            if(!strlen(temp1->sname[j]))
                                break;
                            printf("\nfriend request : %s",temp1->sname[j]);
                        }
                        printf("\nenter a 1 to accept friend request : ");
                        scanf("%d",&f);
                        if(f==1)
                        {
                            printf("\nenter a index of friend to accept friend request: ");
                            scanf("%d",&index);
                            for(j=0; j<100; j++)
                            {
                                if(j==index)
                                {
                                    friend(temp1,temp1->sname[j],g,kk);
                                    break;
                                }
                            }

                        }
                        ptr=temp1;
                        break;
                    }
                    flag=1;
                }
            }
        }
    }
    struct graph *g1;
    g1=g;
    if(flag1==0)
    {
        likepost(ptr,g);
        printf("\nenter a 1 to send message : ");
        scanf("%d",&mm);
        if(mm==1)
        {
            printf("\nenter a name : ");
            scanf("%s",str);
            struct message *rmsg,*smsg;
            smsg=check1(str,ptr);
            if(smsg!=NULL)
            {
                rmsg=check(str,g1,smsg->aname);
                if(rmsg!=NULL)
                {
                    printf("\nenter a message : ");
                    scanf("%s",mes1);
                    for(z=0; z<100; z++)
                    {
                        if(!strlen(smsg->amsg[z]))
                        {
                            strcpy(smsg->amsg[z],mes1);
                            for(t=0; t<100; t++)
                            {
                                if(!strlen(smsg->amsg[t]))
                                {
                                    break;
                                }
                                printf("\n%s",smsg->amsg[t]);
                            }
                            break;
                        }
                    }
                    for(x=0; x<100; x++)
                    {
                        if(!strlen(rmsg->amsg[x]))
                        {
                            strcpy(rmsg->amsg[x],mes1);
                         
                            break;
                        }
                    }
                }
            }
        }
        struct post *p2;
        p2=ptr->p;
        if(p2!=NULL)
        {
            while(p2->postnext!=NULL)
            {
                printf("\n post    : %s ",p2->npost);
                printf("\n like    : %d ",p2->like);
                printf("\n dislike : %d",p2->dislike);
                printf("\n love    : %d",p2->love);
                p2=p2->postnext;
            }
            printf("\n post    : %s ",p2->npost);
            printf("\n like    : %d ",p2->like);
            printf("\n dislike : %d ",p2->dislike);
            printf("\n love    : %d ",p2->love);
        }
        printf("\nenter a 1 to share a post : ");
        scanf("%d",&m);
        if(m==1)
        {
            postoperation(ptr);
            postlogic(ptr,g1);

        }

        printf("\nenter a 1 to sent friend request : ");
        scanf("%d",&choice);
    }
    if(choice==1)
    {
        printf("\nenter a name of a user for friend request : ");
        scanf("%s",fname);
        for(i=0; i<g->vertexnum; i++)
        {
            temp1=g->adj[i]->next;
            if(temp1!=NULL)
            {
                if(temp1->next==NULL)
                {
                    if(!strcmp(temp1->name,fname))
                    {
                        for(j=0; j<100; j++)
                        {
                            if(!strlen(temp1->sname[j]))
                            {
                                strcpy(temp1->sname[j],uname);
                                break;
                            }

                        }

                        break;
                    }
                }
                else
                {
                    while(temp1->next!=NULL)
                    {
                        if(!strcmp(temp1->name,fname))
                        {
                            for(j=0; j<100; j++)
                            {
                                if(!strlen(temp1->sname[j]))
                                {
                                    strcpy(temp1->sname[j],uname);
                                    break;
                                }

                            }

                            break;
                        }

                        temp1=temp1->next;
                        flag=0;
                    }
                    if(flag==0)
                    {
                        if(!strcmp(temp1->name,fname))
                        {
                            for(j=0; j<100; j++)
                            {
                                if(!strlen(temp1->sname[j]))
                                {
                                    strcpy(temp1->sname[j],uname);
                                    break;
                                }

                            }

                            break;
                            flag=1;
                        }
                    }
                }
            }
        }
    }
    return(g);

}
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
//friend(p);
            break;
        }
        case 3 :
        {
            p=login(p);
            break;
        }
        default :
            printf("\n Invalid choice pri⁷nt 1 and 2");
        }
    }

    /*
    for(int i=0;i<p->vertexnum-1;i++)
    {
    struct node *temp=p=->adj[i];
    while(temp!=p->adj[i])
    {
    printf(" -> : %d ", temp->vertex);
    temp=temp->next;
    }
    printf("\n");
    }*/
    return 0;
}
