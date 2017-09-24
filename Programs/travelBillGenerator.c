#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>


struct bill
{
  int travelTime;
  int waitTime;

  float cost;

};

typedef struct bill BILL;

BILL *bill1;



int BASEFARE = 10; // in Rupees
int TRAVELFARE = 1; //in Rupees
float WAITFARE = 0.1; // in Rupees


int main()
{

    int choice = 1;
    char state;
    int period;
    bill1 = (BILL*)malloc(sizeof(BILL));

    bill1->travelTime = 0;
    bill1->waitTime = 0;

    while(choice)
    {
        printf("Enter  state\n");
        //scanf("%c %d",&state,&period);
        scanf("%c",&state);
        scanf("%d",&period);


        if(state == 's')
        {
            bill1->travelTime = bill1->travelTime + period;
        }
        else if(state == 'w')
        {
            bill1->waitTime = bill1->waitTime + period;
        }
        else if(state == 'e')
        {
            printf("\nTotal TravelTime is %d s ",bill1->travelTime);
            printf("\nTotal WaitTime is %d s", bill1->waitTime);

            bill1->cost = BASEFARE + (bill1->travelTime * TRAVELFARE) + (bill1->waitTime * WAITFARE);

            choice = 0;
        }
        else
        {
            printf("\nError in data format please ReEnter data\n");
            free(bill1);
            choice = 0;
        }
    }

    printf("\nThe Final bill is %f", bill1->cost);

return 0;
}
