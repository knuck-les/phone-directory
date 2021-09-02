#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct node
{
    long long data;
    char *A;
    struct node *next;
    struct node *prev;
    int p;       //records no of times links are created after head
} ;




struct node *SAVE_NEW_NUMBER(struct node *head,struct node *k)      //returns a pointer to the node attached after the k(passed as argument)
{                                                                     //i.e k->next  contains linker
        char helper;                                                                 //it builds a node and links
    struct node *linker=(struct node *)malloc(sizeof(struct node));
    linker->A=(char*)malloc(20*sizeof(char));

       scanf("%c",&helper);
     printf("ENTER NAME\n");
     fgets(linker->A , 20, stdin);

    printf("ENTER NUMBER\n");
    scanf("%llu",&linker->data);




    linker->prev=k;
    k->next=linker;
    linker->next=NULL;
      head->p= head->p+1;

      return linker;
}

void DELETE_BY_NAME(struct node *head,char *A)      //deletes a node and links previous with next node
{
    struct node *temp,*P;
    P=head;
    int t=0;
    temp=head;
    head=head->next;

    if(P->p>0)
    {

    do
    {

        if(strcmp(head->A,A)==0)
           {

               temp->next=head->next;
               if(head->next!=NULL)
               head->next->prev=temp;
                free(head);
                head=NULL;
                  t++;
                 P->p=P->p-1;

           }



            temp=head;
            if(t==0)
           head=head->next;

    }while(head!=NULL);

        if(t==0)
        printf("\nNO SUCH NUMBER FOUND\n");

    }
    else
        printf("\nDIRECTORY IS EMPTY\n");
}


void DELETE_BY_NUMBER(struct node *head,long long data)              //deletes a node and links previous with next node
{
  struct node *temp,*P;
  P=head;
  int t=0;
  temp=head;
  head=head->next;

  if(P->p >0)
  {

    do
    {
        if(head->data==data)
           {
               temp->next=head->next;
              if(head->next!=NULL)
               head->next->prev=temp;
               free(head);
               head=NULL;
               t++;
                P->p=P->p-1;

           }

          temp=head;

          if(t==0)
         head=head->next;

    } while(head!=NULL);

      if(t==0)
        printf("\nNO SUCH NUMBER FOUND\n");
  }
  else
    printf("\nDIRECTORY IS EMPTY");

}


void SEARCH_BY_NAME(struct node *head,char *A)           //searches and displays if found..takes head as input and pointer to the character array
{
     int t=0;
     struct node *po;
     po=head;
     head=head->next;
 if(po->p>0)
 {
   do
    {
        if(strcmp(head->A,A)==0)
           {
                printf("NAME:%s",head->A);
               printf("NUMBER:%lli\n",head->data);
               head=NULL;
               t++;

           }

       if(t==0)
        head=head->next;

    }while(head!=NULL);

       if(t==0)
        printf("\nNO SUCH NAME FOUND\n");
 }
 else
    printf("\nDIRECTORY IS EMPTY\n");
}

void SEARCH_BY_NUMBER(struct node *head,long long data)       //searches and displays if found takes argument head and  phone number
{
     int t=0;
     struct node *po;
     po=head;
     head=head->next;

  if(po->p>0)
 {

    do
    {
           if(head->data==data)
           {
                printf("NAME:%s",head->A);
               printf("NUMBER:%lli\n",head->data);
               head==NULL;
               t++;
           }
        head=head->next;

    }while(head!=NULL);

      if(t==0)
        printf("\nNO SUCH NUMBER FOUND\n");
}
        else
    printf("\nDIRECTORY IS EMPTY\n");
}


void DELETE_ALL(struct node *head)       //when takes head as argument deletes every node after head
{
    struct node *temp,*P;
    P=head;
    temp=head;
    head=head->next;
    if(P->p >0)
    {
  do
    {
           temp=head;
           head=head->next;
           free(temp);
           P->p=P->p-1;

    }while(head!=NULL);

      printf("\nDIRECTORY IS CLEANED UP\n");
    }
    else
        printf("\nDIRECTORY DON'T CONTAIN ANY CONTACTS TO DELETE\n");
}

void DISPLAY_ALL(struct node *k)    //when takes head as argument deletes every node after head
{
    printf("\n\n");
        int temp =k->p;
if(temp!=0)
    {
     k=k->next;

    for(int i=0;i<temp;i++)
    {
           printf("\nNAME:%s",k->A);
          printf("NUMBER:%lli \n",k->data);
             k=k->next;
    }
    }

     else
        printf("\nDIRECTORY IS EMPTY\n");

}

void CREATE( struct node *head)        //initialise the node and takes struct pointer as argument
{
     head->p=0;
    head->next=NULL;
    head->prev=NULL;


}


int NO_OF_CONTACTS(struct node *P)       //displays no of contacts
{
    return P->p;
}


int main()
{


    struct node *head,*creator;
    char address[20];
    char helper;
    int choice,X=0,a;
    long long number;
    head=(struct node *)malloc(sizeof(struct node));
    CREATE(head);
    printf("\t\t\t\tWELCOME TO OUR PHONE DIRECTORY");
     A1:
    printf("\n\nSELECT THE CASE YOU WANT TO PERFORM\n1-SAVE A NUMBER\n2-DELETE \n3-SEARCH\n4-DISPLAY ALL\n5-DISPLAY NO OF CONTACTS SAVED\n6-ERASE ALL\n7-EXIT\n");


    scanf("%d",&choice);


    switch(choice)
    {

        case 1:
                if(X==0)
                {
                    creator=SAVE_NEW_NUMBER(head,head);

                }
                if(X>0)
                creator=SAVE_NEW_NUMBER(head,creator);

                X++;

                goto A1;
                break;


        case 2:
                   printf("\nENTER OPERATION\n1-DELETE BY NAME\n2-DELETE BY NUMBER\n");
                    scanf("%d",&a);

                       switch(a)
                       {
                       case 1:
                           printf("\nENTER NAME:");
                           scanf("%c",&helper);
                            fgets(address , 20, stdin);
                           DELETE_BY_NAME(head,address);
                           X--;
                           break;

                        case 2:
                            printf("\nENTER NUMBER:");
                            scanf("%llu",&number);
                            DELETE_BY_NUMBER(head,number);
                            X--;
                            break;

                        default:
                            printf("\nERROR CHOICE\n");


                       }
                        printf("\n----DELETED----\n");
                     goto A1;
                       break;
        case 3:

                printf("\nENTER OPERATION\n1-SEARCH BY NAME\n2-SEARCH BY NUMBER\n");
                    scanf("%d",&a);

                       switch(a)
                       {
                       case 1:
                           printf("\nENTER NAME:");
                             scanf("%c",&helper);
                            fgets(address , 20, stdin);
                            printf("\n---SEARCHING----\n");
                           SEARCH_BY_NAME(head,address);
                           break;

                        case 2:
                            printf("\nENTER NUMBER:");
                            scanf("%llu",&number);
                            printf("\n-----SEARCHING------\n\n");
                            SEARCH_BY_NUMBER(head,number);
                            break;

                        default:
                            printf("\nERROR CHOICE\n");


                       }

                     goto A1;
                       break;


        case 4:
            printf("\n---DISPLAYING----\n");
            DISPLAY_ALL(head);
             printf("\n---------------\n");
           goto A1;
           break;

        case 5:
                printf("\nNO OF CONTACTS SAVED:%d",NO_OF_CONTACTS(head));
             printf("\n---------------\n");
           goto A1;
                    break;

          case 6:
              printf("\n-------DELETING-------\n");
              DELETE_ALL(head);
              X=0;
               goto A1;
               break;

        case 7:
             printf("\n---------------\n");
                  break;
        default:
             printf("\nERROR CHOICE\n");
              goto A1;



    }


}

