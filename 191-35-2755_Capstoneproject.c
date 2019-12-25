#include <stdio.h>
#include <string.h>
#include<stdlib.h>

struct order
{
    char name[50];
    int order_number;
    int number_of_food;
    int cost;
} p[1000];

int count = 0, served_count = 0, waiting_now = 0;

void items ()
{
    printf("..............................FOOD MENU....................................\n");

    printf("Item Code#----Description-------------------Size--------------------Price(tk)\n");

    printf("[101]---------Burger---------------------Regular/Naga---------------170/290\n");
    printf("[102]---------Chicken Pizza--------------6/8/12inch-----------------600/750/1050\n");
    printf("[103]---------Fried Chicken--------------1/4/10 pcs-----------------85/320/790\n");
    printf("[104]---------Grilled Chicken------------quarter/half/full----------80/160/340\n");
    printf("[105]---------Noodles--------------------Half/Full------------------130/250\n");
    printf("[106]---------Pasta----------------------Half/Full------------------160/320\n");
    printf("[107]---------Oreo Shake-----------------250mg----------------------180\n");
    printf("[108]---------Cold Coffee----------------110mg----------------------110\n");
    printf("[109]---------Cappuccino-----------------150mg----------------------150\n");
    printf("[110]---------Coke-----------------------250/400mg------------------20/35\n\n");

}
int order ()
{
    int n,i, choice,qu;
    FILE *fp;
    fp=fopen("Food.txt","a");

    printf ("\nplease enter your name: ");
    fflush(stdin);
    gets (p[count].name);
    fprintf(fp,"Name: %s",p[count].name);

    p[count].order_number = 1000+count;
    fprintf(fp,"\nOrder no: %d",p[count].order_number);

    items();
    p[count].number_of_food = n;
    p[count].cost = 0;
    p[count].number_of_food = 0;


    printf ("How many items you want to order?-> ");
    scanf ("%d", &n);
    for(i=1; i<=n; i++)
    {
        printf ("\nEnter chosen %d item code: ",i);
        scanf ("%d", &choice);

        switch(choice)
        {
        case 101 :
        {
            int i;
            printf ("Enter the size of burger: 1. Regular  2. Naga\n");
            scanf ("%d", &i);

            printf ("Please enter the quantity: ");
            scanf ("%d", &qu);

            p[count].number_of_food +=qu;

            if (i==1)
                p[count].cost += (170*qu);
            else
                p[count].cost += (290*qu);
            break;
        }
        case 102 :
        {
            int i;
            printf ("Enter the size of Chicken Pizza: 1. 6inch  2. 8inch  3. 12inch\n");
            scanf ("%d", &i);

            printf ("Please enter the quantity: ");
            scanf ("%d", &qu);

            p[count].number_of_food +=qu;

            if (i==1)
                p[count].cost += (600*qu);
            else if (i==2)
                p[count].cost += (750*qu);
            else
                p[count].cost += (1050*qu);
            break;
        }
        case 103 :
        {
            int i;
            printf ("Enter the amount of chicken: 1. 1 pcs  2. 4 pcs  3. 10 pcs\n");
            scanf ("%d", &i);

            printf ("Please enter the quantity: ");
            scanf ("%d", &qu);

            p[count].number_of_food +=qu;

            if (i==1)
                p[count].cost += (85*qu);
            else if (i==2)
                p[count].cost += (320*qu);
            else
                p[count].cost += (790*qu);
            break;
        }
        case 104 :
        {
            int i;
            printf ("Enter the size of grilled chicken: 1. quarter  2. half  3. full\n");
            scanf ("%d", &i);

            printf ("Please enter the quantity: ");
            scanf ("%d", &qu);

            p[count].number_of_food +=qu;

            if (i==1)
                p[count].cost += (80*qu);
            else if (i==2)
                p[count].cost += (160*qu);
            else
                p[count].cost += (340*qu);
            break;
        }
        case 105 :
        {
            int i;
            printf ("Enter the size of Noodles: 1. half  2. full\n");
            scanf ("%d", &i);

            printf ("Please enter the quantity: ");
            scanf ("%d", &qu);

            p[count].number_of_food +=qu;
            if (i==1)
                p[count].cost += (130*qu);
            else
                p[count].cost += (250*qu);
            break;
        }
        case 106 :
        {
            int i;
            printf ("Enter the size of pasta: 1. half  2. full\n");
            scanf ("%d", &i);

            printf ("Please enter the quantity: ");
            scanf ("%d", &qu);

            p[count].number_of_food +=qu;

            if (i==1)
                p[count].cost += (160*qu);
            else
                p[count].cost += (320*qu);
            break;
        }
        case 107 :
        {
            printf ("250 mg of OREO SHAKE\n");

            printf ("Please enter the quantity: ");
            scanf ("%d", &qu);
            p[count].number_of_food +=qu;
            p[count].cost += (180*qu);
            break;
        }
        case 108:
        {
            printf ("250 mg of Cold Coffee\n");

            printf ("Please enter the quantity: ");
            scanf ("%d", &qu);

            p[count].number_of_food +=qu;
            p[count].cost += (110*qu);
            break;
        }
        case 109 :
        {
            printf ("250 mg of Cappuccino\n");

            printf ("Please enter the quantity: ");
            scanf ("%d", &qu);

            p[count].number_of_food +=qu;
            p[count].cost += (150*qu);
            break;
        }
        case 110 :
        {
            int i;
            printf ("Enter the size of Coke: 1. 250mg  2. 400mg\n");
            scanf ("%d", &i);

            printf ("Please enter the quantity: ");
            scanf ("%d", &qu);

            p[count].number_of_food +=qu;

            if (i==1)
                p[count].cost += (20*qu);
            else
                p[count].cost += (35*qu);
            break;
        }
        default :
        {
            printf ("Invalid choice try again\n");
        }
        }
    }

    char ch;
    printf ("Do you want to order anything else? (y/n) --> ");
    fflush(stdin);
    scanf("%c", &ch);
    if (ch == 'y' || ch == 'Y')

        printf ("\nNumber of food ordered %d\n", p[count].number_of_food);
    fprintf(fp,"\nNumber of food: %d",p[count].number_of_food);
    printf ("\nThank you %s for your order. Your bill is %dtk.\nPlease wait while we prepare the food.\n\n", p[count].name, p[count].cost);
    fprintf(fp,"\nTotal cost: %d\n\n",p[count].cost);
    count ++;
    fclose(fp);
}
void receive ()
{
    if (count==0)
    {
        printf ("Please order first\n");
        return;
    }
    else if (served_count ==count)
    {
        printf ("All order served.\n");
        return;
    }

    printf ("Order no. %d by %s is ready.\n", p[served_count].order_number, p[served_count].name);
    printf ("Enjoy your meal!!\n\n");
    served_count++;
}
int display ()
{
    printf ("Total order taken: %d\n", (count));
    printf ("Total number of order served %d\n", served_count);
    printf ("Number of Currently waiting to be served: %d\n", (count-served_count));
    printf ("Currently preparing food for order no. %d\n\n", p[served_count].order_number);
}
void seeorders()
{
    char ch;
    FILE *fp;

    fp = fopen("Food.txt","r");
    if(fp == NULL)
    {
        printf("Previous order doesn't found!\n\n");
    }
    else
    {
        system("cls");
        printf("\t\t    *******************************************\n");
        printf ("\t\t    ! Welcome To Food Order Management System !\n");
        printf("\t\t    *******************************************\n");
        while( ( ch = fgetc(fp) ) != EOF )
            printf("%c",ch);
    }

    fclose(fp);
}
void complain()
{
    char comp[1000];
    FILE *fp;
    fp=fopen("FoodComplain.txt","a");
    if(fp==NULL)
    {
        printf("File doesn't create");
    }
    else
    {
        printf("Enter your complain: ");
        fflush(stdin);
        gets(comp);
        fprintf(fp,"\n%s",comp);
        printf("Your complain has been saved successfully\n");
        fclose(fp);
    }

}



void main ()
{

    while (1)
    {
        printf("\t\t    *******************************************\n");
        printf ("\t\t    ! Welcome To Food Order Management System !\n");
        printf("\t\t    *******************************************\n");

        printf ("   ~~~~~~~~~~~~~~~~~~~~~~~");
        printf ("\n   1. Order              !\n");
        printf ("   2. Serve              !\n");
        printf ("   3. Display            !\n");
        printf ("   4. See all orders     !\n");
        printf ("   5. Complain           !\n");
        printf ("   6. Exit the program   !\n");
        printf ("   ~~~~~~~~~~~~~~~~~~~~~~~\n");

        int choice;
        printf("  Select your option: ");
        scanf ("%d", &choice);
        switch (choice)
        {
        case 1 :
        {
            system("cls");
            order ();
            break;
        }
        case 2 :
        {
            receive();
            break;
        }
        case 3 :
        {
            display();
            break;
        }
        case 4 :
        {
            seeorders();
            break;
        }
        case 5:
        {
            system("cls");
            complain();
            break;
        }
        case 6:
        {
            printf ("We are closed come again!!\n");
            printf ("THANK YOU\n\n");

            return;
        }
        }
        system("pause");
        system("cls");
    }

}
