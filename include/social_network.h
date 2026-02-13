#ifndef SOCIAL_NETWORK_H
#define SOCIAL_NETWORK_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

/* ENUM */
enum letter {A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z};

/* STRUCTURES */

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

/* FUNCTION DECLARATIONS */

struct node* made(char v);
struct graph* represent();
struct graph *addaccount(struct graph *g,char name1[40],int pass);
void showdata(struct graph *g);
void friendtwoway(char name2[40],char name1[40],struct graph *g);
void friend(struct node *temp1,char name1[40],struct graph *g,int a);
void postoperation(struct node *temp);
void postlogic(struct node *temp,struct graph *g);
void likepost(struct node * temp,struct graph *g);
struct message* check(char name1[40],struct graph * g,char name2[40]);
struct message *check1(char str[40],struct node *temp);
struct graph *login(struct graph *g);

#endif
