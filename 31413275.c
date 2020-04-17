#include <stdio.h>
#include <stdlib.h>


long decimal_to_binary(long dno)
{
  long bno=0,remainder,f=1;
   while(dno != 0)
   {
        remainder = dno % 2;
        bno = bno + remainder * f;
        f = f * 10;
        dno = dno / 2;
   }
   return bno;
}


int binaryToDecimal(long n)
{
    long num = n;
    long dec_value = 0;
  
    // Initializing base value to 1, i.e 2^0
    long base = 1;
  
    long temp = num;
    while (temp) {
        long last_digit = temp % 10;
        temp = temp / 10;
  
        dec_value += last_digit * base;
  
        base = base * 2;
    }
  
    return dec_value;
}



int main() {
//Linked List
    typedef struct node {
        long val;
        struct node * next;
    }node_t;
    
    int scanned_int_value;
    node_t * head = NULL;
    head=malloc(sizeof(node_t));
    node_t * current = head;
    int count;
    
    while(1){
        
        int result = scanf("%d", &scanned_int_value);
        if(result != 1)
            break;
        
        current->val=scanned_int_value;
        current->next=malloc(sizeof(node_t));
        current = current->next;
        //capture length of linked list
        count++;
    }
    
    current->next=NULL;
    
    node_t * bin = head;
    node_t *binbeg = bin;

    bin->val=decimal_to_binary(bin->val);
    long binVal;
    

    for(int i=0;i<count-1;i++)
    {
        bin=bin->next;
        binVal = decimal_to_binary(bin->val);
        bin->val=binVal;
        

    }

    node_t *hzerobuck;
    node_t *honebuck;
    hzerobuck=malloc(sizeof(node_t));
    honebuck=malloc(sizeof(node_t));
    
    node_t *zerobuck=hzerobuck;
    node_t *onebuck=honebuck;
    
    for(int i=0;i<count;i++)
    {
        if ((binbeg->val) % 10 == 0){
            zerobuck->val = binbeg->val;
           
            zerobuck->next=malloc(sizeof(node_t));
            zerobuck=zerobuck->next;
        }
        else if ((binbeg->val) % 10 == 1)
        {
            onebuck->val = binbeg->val;
            onebuck->next=malloc(sizeof(node_t));
            onebuck=onebuck->next;
        }
        
        binbeg=binbeg->next;

    }
    zerobuck=NULL;
    onebuck=NULL;

   
    node_t *hmerge;
    hmerge=malloc(sizeof(node_t));

    node_t *merge = hmerge;
        while (hzerobuck->val!=0){
            merge->val=hzerobuck->val;
            
            hzerobuck=hzerobuck->next;
            merge->next=malloc(sizeof(node_t));
        
            merge=merge->next;
              
        }
        while(honebuck->val!=0){
            merge->val=honebuck->val;
            honebuck=honebuck->next;
            merge->next=malloc(sizeof(node_t));
            merge=merge->next;

        }
    
    node_t *hzerobuck2;
    node_t *honebuck2;
    hzerobuck2=malloc(sizeof(node_t));
    honebuck2=malloc(sizeof(node_t));
    
    node_t *zerobuck2=hzerobuck2;
    node_t *onebuck2=honebuck2;
    
    
    
    for(int i=0;i<count;i++)
    {
        if ((((hmerge->val)/10) % 10) == 0){
            zerobuck2->val = hmerge->val;
           
            zerobuck2->next=malloc(sizeof(node_t));
            zerobuck2=zerobuck2->next;
        }
        else if ((((hmerge->val)/10) % 10) == 1)
        {
            onebuck2->val = hmerge->val;
            onebuck2->next=malloc(sizeof(node_t));
            onebuck2=onebuck2->next;
        }
        
        hmerge=hmerge->next;

    }
    zerobuck2=NULL;
    onebuck2=NULL;
    
    node_t *hmerge2;
    hmerge2=malloc(sizeof(node_t));

    node_t *merge2 = hmerge2;
    
        while (hzerobuck2->val!=0){
            merge2->val=hzerobuck2->val;
            hzerobuck2=hzerobuck2->next;
            merge2->next=malloc(sizeof(node_t));
            merge2=merge2->next;
              
        }
    
        while(honebuck2->val!=0){
            merge2->val=honebuck2->val;
            honebuck2=honebuck2->next;
            merge2->next=malloc(sizeof(node_t));
            merge2=merge2->next;

        }
    
    node_t *hzerobuck3;
      node_t *honebuck3;
      hzerobuck3=malloc(sizeof(node_t));
      honebuck3=malloc(sizeof(node_t));
      
      node_t *zerobuck3=hzerobuck3;
      node_t *onebuck3=honebuck3;
      
      
      
      for(int i=0;i<count;i++)
      {
          if ((((hmerge2->val)/100) % 10) == 0){
              zerobuck3->val = hmerge2->val;
             
              zerobuck3->next=malloc(sizeof(node_t));
              zerobuck3=zerobuck3->next;
          }
          else if ((((hmerge2->val)/100) % 10) == 1)
          {
              onebuck3->val = hmerge2->val;
              onebuck3->next=malloc(sizeof(node_t));
              onebuck3=onebuck3->next;
          }
          
          hmerge2=hmerge2->next;

      }
      zerobuck3=NULL;
      onebuck3=NULL;
    
    node_t *hmerge3;
    hmerge3=malloc(sizeof(node_t));

       node_t *merge3 = hmerge3;
       
           while (hzerobuck3->val!=0){
               merge3->val=hzerobuck3->val;
               
               hzerobuck3=hzerobuck3->next;
               merge3->next=malloc(sizeof(node_t));
               merge3=merge3->next;
                 
           }
       
           while(honebuck3->val!=0){
               merge3->val=honebuck3->val;
               honebuck3=honebuck3->next;
               merge3->next=malloc(sizeof(node_t));
               merge3=merge3->next;

           }

    node_t *hzerobuck4;
         node_t *honebuck4;
         hzerobuck4=malloc(sizeof(node_t));
         honebuck4=malloc(sizeof(node_t));
         
         node_t *zerobuck4=hzerobuck4;
         node_t *onebuck4=honebuck4;
         
         
         
         for(int i=0;i<count;i++)
         {
             if ((((hmerge3->val)/1000) % 10) == 0){
                 zerobuck4->val = hmerge3->val;
                 zerobuck4->next=malloc(sizeof(node_t));
                 zerobuck4=zerobuck4->next;
             }
             else if ((((hmerge3->val)/1000) % 10) == 1)
             {
                 onebuck4->val = hmerge3->val;
                 onebuck4->next=malloc(sizeof(node_t));
                 onebuck4=onebuck4->next;
             }
             
             hmerge3=hmerge3->next;

         }
         zerobuck4=NULL;
         onebuck4=NULL;

    

    node_t *hmerge4;
    hmerge4=malloc(sizeof(node_t));

    node_t *merge4 = hmerge4;
    
    
    while (hzerobuck4->val != 0){
               merge4->val=hzerobuck4->val;
               hzerobuck4=hzerobuck4->next;
               merge4->next=malloc(sizeof(node_t));
               merge4=merge4->next;
    }
       
    while(honebuck4->val != 0){
               merge4->val=honebuck4->val;
               honebuck4=honebuck4->next;
               merge4->next=malloc(sizeof(node_t));
               merge4=merge4->next;

    }
    
    
    node_t *hzerobuck5;
    node_t *honebuck5;
    hzerobuck5=malloc(sizeof(node_t));
    honebuck5=malloc(sizeof(node_t));
    
    node_t *zerobuck5=hzerobuck5;
    node_t *onebuck5=honebuck5;
    
    
    
    for(int i=0;i<count;i++)
    {
        if ((((hmerge4->val)/10000) % 10) == 0){
            zerobuck5->val = hmerge4->val;
            zerobuck5->next=malloc(sizeof(node_t));
            zerobuck5=zerobuck5->next;
        }
        else if ((((hmerge4->val)/10000) % 10) == 1)
        {
            onebuck5->val = hmerge4->val;
            onebuck5->next=malloc(sizeof(node_t));
            onebuck5=onebuck5->next;
        }
        
        hmerge4=hmerge4->next;

    }
    zerobuck5=NULL;
    onebuck5=NULL;
    
    
    node_t *hmerge5;
    hmerge5=malloc(sizeof(node_t));

    node_t *merge5 = hmerge5;
    
    
    while (hzerobuck5->val != 0){
               merge5->val=hzerobuck5->val;
               hzerobuck5=hzerobuck5->next;
               merge5->next=malloc(sizeof(node_t));
               merge5=merge5->next;
    }
       
    while(honebuck5->val != 0){
               merge5->val=honebuck5->val;
               honebuck5=honebuck5->next;
               merge5->next=malloc(sizeof(node_t));
               merge5=merge5->next;

    }
    
    node_t *hzerobuck6;
    node_t *honebuck6;
    hzerobuck6=malloc(sizeof(node_t));
    honebuck6=malloc(sizeof(node_t));
    
    node_t *zerobuck6=hzerobuck6;
    node_t *onebuck6=honebuck6;
    
    for(int i=0;i<count;i++)
    {
        if ((((hmerge5->val)/100000) % 10) == 0){
            zerobuck6->val = hmerge5->val;
            zerobuck6->next=malloc(sizeof(node_t));
            zerobuck6=zerobuck6->next;
        }
        else if ((((hmerge5->val)/100000) % 10) == 1)
        {
            onebuck6->val = hmerge5->val;
            onebuck6->next=malloc(sizeof(node_t));
            onebuck6=onebuck6->next;
        }
        
        hmerge5=hmerge5->next;

    }
    zerobuck6=NULL;
    onebuck6=NULL;
    
    node_t *hmerge6;
    hmerge6=malloc(sizeof(node_t));

    node_t *merge6 = hmerge6;
    
    
    while (hzerobuck6->val != 0){
               merge6->val=hzerobuck6->val;
               hzerobuck6=hzerobuck6->next;
               merge6->next=malloc(sizeof(node_t));
               merge6=merge6->next;
    }
       
    while(honebuck6->val != 0){
               merge6->val=honebuck6->val;
               honebuck6=honebuck6->next;
               merge6->next=malloc(sizeof(node_t));
               merge6=merge6->next;

    }
    
    node_t *hzerobuck7;
    node_t *honebuck7;
    hzerobuck7=malloc(sizeof(node_t));
    honebuck7=malloc(sizeof(node_t));
    
    node_t *zerobuck7=hzerobuck7;
    node_t *onebuck7=honebuck7;
    
    for(int i=0;i<count;i++)
    {
        if ((((hmerge6->val)/1000000) % 10) == 0){
            zerobuck7->val = hmerge6->val;
            zerobuck7->next=malloc(sizeof(node_t));
            zerobuck7=zerobuck7->next;
        }
        else if ((((hmerge6->val)/1000000) % 10) == 1)
        {
            onebuck7->val = hmerge6->val;
            onebuck7->next=malloc(sizeof(node_t));
            onebuck7=onebuck7->next;
        }
        
        hmerge6=hmerge6->next;

    }
    zerobuck7=NULL;
    onebuck7=NULL;
    
    node_t *hmerge7;
    hmerge7=malloc(sizeof(node_t));

    node_t *merge7 = hmerge7;
    
    
    while (hzerobuck7->val != 0){
               merge7->val=hzerobuck7->val;
               hzerobuck7=hzerobuck7->next;
               merge7->next=malloc(sizeof(node_t));
               merge7=merge7->next;
    }
       
    while(honebuck7->val != 0){
               merge7->val=honebuck7->val;
               honebuck7=honebuck7->next;
               merge7->next=malloc(sizeof(node_t));
               merge7=merge7->next;

    }

    
    node_t *hzerobuck8;
    node_t *honebuck8;
    hzerobuck8=malloc(sizeof(node_t));
    honebuck8=malloc(sizeof(node_t));
    
    node_t *zerobuck8=hzerobuck8;
    node_t *onebuck8=honebuck8;
    
    for(int i=0;i<count;i++)
    {
        if ((((hmerge7->val)/10000000) % 10) == 0){
            zerobuck8->val = hmerge7->val;
            zerobuck8->next=malloc(sizeof(node_t));
            zerobuck8=zerobuck8->next;
        }
        else if ((((hmerge7->val)/10000000) % 10) == 1)
        {
            onebuck8->val = hmerge7->val;
            onebuck8->next=malloc(sizeof(node_t));
            onebuck8=onebuck8->next;
        }
        
        hmerge7=hmerge7->next;

    }
    zerobuck8=NULL;
    onebuck8=NULL;
    
    node_t *hmerge8;
    hmerge8=malloc(sizeof(node_t));

    node_t *merge8 = hmerge8;
    
    
    while (hzerobuck8->val != 0){
               merge8->val=hzerobuck8->val;
               hzerobuck8=hzerobuck8->next;
               merge8->next=malloc(sizeof(node_t));
               merge8=merge8->next;
    }
       
    while(honebuck8->val != 0){
               merge8->val=honebuck8->val;
               honebuck8=honebuck8->next;
               merge8->next=malloc(sizeof(node_t));
               merge8=merge8->next;

    }
    
    node_t *hzerobuck9;
    node_t *honebuck9;
    hzerobuck9=malloc(sizeof(node_t));
    honebuck9=malloc(sizeof(node_t));
    
    node_t *zerobuck9=hzerobuck9;
    node_t *onebuck9=honebuck9;
    
    for(int i=0;i<count;i++)
    {
        if ((((hmerge8->val)/100000000) % 10) == 0){
            zerobuck9->val = hmerge8->val;
            zerobuck9->next=malloc(sizeof(node_t));
            zerobuck9=zerobuck9->next;
        }
        else if ((((hmerge8->val)/100000000) % 10) == 1)
        {
            onebuck9->val = hmerge8->val;
            onebuck9->next=malloc(sizeof(node_t));
            onebuck9=onebuck9->next;
        }
        
        hmerge8=hmerge8->next;

    }
    zerobuck9=NULL;
    onebuck9=NULL;
    
    node_t *hmerge9;
    hmerge9=malloc(sizeof(node_t));

    node_t *merge9 = hmerge9;
    
    
    while (hzerobuck9->val != 0){
               merge9->val=hzerobuck9->val;
               hzerobuck9=hzerobuck9->next;
               merge9->next=malloc(sizeof(node_t));
               merge9=merge9->next;
    }
       
    while(honebuck9->val != 0){
               merge9->val=honebuck9->val;
               honebuck9=honebuck9->next;
               merge9->next=malloc(sizeof(node_t));
               merge9=merge9->next;

    }
    
    node_t *hzerobuck10;
    node_t *honebuck10;
    hzerobuck10=malloc(sizeof(node_t));
    honebuck10=malloc(sizeof(node_t));
    
    node_t *zerobuck10=hzerobuck10;
    node_t *onebuck10=honebuck10;
    
    for(int i=0;i<count;i++)
    {
        if ((((hmerge9->val)/1000000000) % 10) == 0){
            zerobuck10->val = hmerge9->val;
            zerobuck10->next=malloc(sizeof(node_t));
            zerobuck10=zerobuck10->next;
        }
        else if ((((hmerge9->val)/1000000000) % 10) == 1)
        {
            onebuck10->val = hmerge9->val;
            onebuck10->next=malloc(sizeof(node_t));
            onebuck10=onebuck10->next;
        }
        
        hmerge9=hmerge9->next;

    }
    zerobuck10=NULL;
    onebuck10=NULL;
    
    
    node_t *hmerge10;
    hmerge10=malloc(sizeof(node_t));

    node_t *merge10 = hmerge10;
    
    
    while (hzerobuck10->val != 0){
               merge10->val=hzerobuck10->val;
               hzerobuck10=hzerobuck10->next;
               merge10->next=malloc(sizeof(node_t));
               merge10=merge10->next;
    }
       
    while(honebuck10->val != 0){
               merge10->val=honebuck10->val;
               honebuck10=honebuck10->next;
               merge10->next=malloc(sizeof(node_t));
               merge10=merge10->next;

    }
    
    node_t *hzerobuck11;
    node_t *honebuck11;
    hzerobuck11=malloc(sizeof(node_t));
    honebuck11=malloc(sizeof(node_t));

    node_t *zerobuck11=hzerobuck11;
    node_t *onebuck11=honebuck11;

    for(int i=0;i<count;i++)
    {
        if ((((hmerge10->val)/10000000000) % 10) == 0){
            zerobuck11->val = hmerge10->val;
            zerobuck11->next=malloc(sizeof(node_t));
            zerobuck11=zerobuck11->next;
        }
        else if ((((hmerge10->val)/10000000000) % 10) == 1)
        {
            onebuck11->val = hmerge10->val;
            onebuck11->next=malloc(sizeof(node_t));
            onebuck11=onebuck11->next;
        }

        hmerge10=hmerge10->next;

    }
    zerobuck11=NULL;
    onebuck11=NULL;


    node_t *hmerge11;
    hmerge11=malloc(sizeof(node_t));

    node_t *merge11 = hmerge11;


    while (hzerobuck11->val != 0){
               merge11->val=hzerobuck11->val;
               hzerobuck11=hzerobuck11->next;
               merge11->next=malloc(sizeof(node_t));
               merge11=merge11->next;
    }

    while(honebuck11->val != 0){
               merge11->val=honebuck11->val;
               honebuck11=honebuck11->next;
               merge11->next=malloc(sizeof(node_t));
               merge11=merge11->next;

    }

    node_t *hzerobuck12;
    node_t *honebuck12;
    hzerobuck12=malloc(sizeof(node_t));
    honebuck12=malloc(sizeof(node_t));

    node_t *zerobuck12=hzerobuck12;
    node_t *onebuck12=honebuck12;

    for(int i=0;i<count;i++)
    {
        if ((((hmerge11->val)/100000000000) % 10) == 0){
            zerobuck12->val = hmerge11->val;
            zerobuck12->next=malloc(sizeof(node_t));
            zerobuck12=zerobuck12->next;
        }
        else if ((((hmerge11->val)/100000000000) % 10) == 1)
        {
            onebuck12->val = hmerge11->val;
            onebuck12->next=malloc(sizeof(node_t));
            onebuck12=onebuck12->next;
        }

        hmerge11=hmerge11->next;

    }
    zerobuck12=NULL;
    onebuck12=NULL;

    node_t *hmerge12;
    hmerge12=malloc(sizeof(node_t));

    node_t *merge12 = hmerge12;


    while (hzerobuck12->val != 0){
               merge12->val=hzerobuck12->val;
               hzerobuck12=hzerobuck12->next;
               merge12->next=malloc(sizeof(node_t));
               merge12=merge12->next;
    }

    while(honebuck12->val != 0){
               merge12->val=honebuck12->val;
               honebuck12=honebuck12->next;
               merge12->next=malloc(sizeof(node_t));
               merge12=merge12->next;

    }

    node_t *hzerobuck13;
    node_t *honebuck13;
    hzerobuck13=malloc(sizeof(node_t));
    honebuck13=malloc(sizeof(node_t));

    node_t *zerobuck13=hzerobuck13;
    node_t *onebuck13=honebuck13;

    for(int i=0;i<count;i++)
    {
        if ((((hmerge12->val)/1000000000000) % 10) == 0){
            zerobuck13->val = hmerge12->val;
            zerobuck13->next=malloc(sizeof(node_t));
            zerobuck13=zerobuck13->next;
        }
        else if ((((hmerge12->val)/1000000000000) % 10) == 1)
        {
            onebuck13->val = hmerge12->val;
            onebuck13->next=malloc(sizeof(node_t));
            onebuck13=onebuck13->next;
        }

        hmerge12=hmerge12->next;

    }
    zerobuck13=NULL;
    onebuck13=NULL;

    node_t *hmerge13;
    hmerge13=malloc(sizeof(node_t));

    node_t *merge13 = hmerge13;


    while (hzerobuck13->val != 0){
               merge13->val=hzerobuck13->val;
               hzerobuck13=hzerobuck13->next;
               merge13->next=malloc(sizeof(node_t));
               merge13=merge13->next;
    }

    while(honebuck13->val != 0){
               merge13->val=honebuck13->val;
               honebuck13=honebuck13->next;
               merge13->next=malloc(sizeof(node_t));
               merge13=merge13->next;

    }

    node_t *hzerobuck14;
    node_t *honebuck14;
    hzerobuck14=malloc(sizeof(node_t));
    honebuck14=malloc(sizeof(node_t));

    node_t *zerobuck14=hzerobuck14;
    node_t *onebuck14=honebuck14;

    for(int i=0;i<count;i++)
    {
        if ((((hmerge13->val)/10000000000000) % 10) == 0){
            zerobuck14->val = hmerge13->val;
            zerobuck14->next=malloc(sizeof(node_t));
            zerobuck14=zerobuck14->next;
        }
        else if ((((hmerge13->val)/10000000000000) % 10) == 1)
        {
            onebuck14->val = hmerge13->val;
            onebuck14->next=malloc(sizeof(node_t));
            onebuck14=onebuck14->next;
        }

        hmerge13=hmerge13->next;

    }
    zerobuck14=NULL;
    onebuck14=NULL;

    node_t *hmerge14;
    hmerge14=malloc(sizeof(node_t));

    node_t *merge14 = hmerge14;


    while (hzerobuck14->val != 0){
               merge14->val=hzerobuck14->val;
               hzerobuck14=hzerobuck14->next;
               merge14->next=malloc(sizeof(node_t));
               merge14=merge14->next;
    }

    while(honebuck14->val != 0){
               merge14->val=honebuck14->val;
               honebuck14=honebuck14->next;
               merge14->next=malloc(sizeof(node_t));
               merge14=merge14->next;

    }

    node_t *hzerobuck15;
    node_t *honebuck15;
    hzerobuck15=malloc(sizeof(node_t));
    honebuck15=malloc(sizeof(node_t));

    node_t *zerobuck15=hzerobuck15;
    node_t *onebuck15=honebuck15;

    for(int i=0;i<count;i++)
    {
        if ((((hmerge14->val)/100000000000000) % 10) == 0){
            zerobuck15->val = hmerge14->val;
            zerobuck15->next=malloc(sizeof(node_t));
            zerobuck15=zerobuck15->next;
        }
        else if ((((hmerge14->val)/100000000000000) % 10) == 1)
        {
            onebuck15->val = hmerge14->val;
            onebuck15->next=malloc(sizeof(node_t));
            onebuck15=onebuck15->next;
        }

        hmerge14=hmerge14->next;

    }
    zerobuck15=NULL;
    onebuck15=NULL;

    node_t *hmerge15;
    hmerge15=malloc(sizeof(node_t));

    node_t *merge15 = hmerge15;


    while (hzerobuck15->val != 0){
               merge15->val=hzerobuck15->val;
               hzerobuck15=hzerobuck15->next;
               merge15->next=malloc(sizeof(node_t));
               merge15=merge15->next;
    }

    while(honebuck15->val != 0){
               merge15->val=honebuck15->val;
               honebuck15=honebuck15->next;
               merge15->next=malloc(sizeof(node_t));
               merge15=merge15->next;

    }

    node_t *hzerobuck16;
    node_t *honebuck16;
    hzerobuck16=malloc(sizeof(node_t));
    honebuck16=malloc(sizeof(node_t));

    node_t *zerobuck16=hzerobuck16;
    node_t *onebuck16=honebuck16;

    for(int i=0;i<count;i++)
    {
        if ((((hmerge15->val)/1000000000000000) % 10) == 0){
            zerobuck16->val = hmerge15->val;
            zerobuck16->next=malloc(sizeof(node_t));
            zerobuck16=zerobuck16->next;
        }
        else if ((((hmerge15->val)/1000000000000000) % 10) == 1)
        {
            onebuck16->val = hmerge15->val;
            onebuck16->next=malloc(sizeof(node_t));
            onebuck16=onebuck16->next;
        }

        hmerge15=hmerge15->next;

    }
    zerobuck16=NULL;
    onebuck16=NULL;

    node_t *hmerge16;
    hmerge16=malloc(sizeof(node_t));

    node_t *merge16 = hmerge16;


    while (hzerobuck16->val != 0){
               merge16->val=hzerobuck16->val;
               hzerobuck16=hzerobuck16->next;
               merge16->next=malloc(sizeof(node_t));
               merge16=merge16->next;
    }

    while(honebuck16->val != 0){
               merge16->val=honebuck16->val;
               honebuck16=honebuck16->next;
               merge16->next=malloc(sizeof(node_t));
               merge16=merge16->next;

    }

    node_t *hzerobuck17;
    node_t *honebuck17;
    hzerobuck17=malloc(sizeof(node_t));
    honebuck17=malloc(sizeof(node_t));

    node_t *zerobuck17=hzerobuck17;
    node_t *onebuck17=honebuck17;

    for(int i=0;i<count;i++)
    {
        if ((((hmerge16->val)/10000000000000000) % 10) == 0){
            zerobuck17->val = hmerge16->val;
            zerobuck17->next=malloc(sizeof(node_t));
            zerobuck17=zerobuck17->next;
        }
        else if ((((hmerge16->val)/10000000000000000) % 10) == 1)
        {
            onebuck17->val = hmerge16->val;
            onebuck17->next=malloc(sizeof(node_t));
            onebuck17=onebuck17->next;
        }

        hmerge16=hmerge16->next;

    }
    zerobuck17=NULL;
    onebuck17=NULL;

    node_t *hmerge17;
    hmerge17=malloc(sizeof(node_t));

    node_t *merge17 = hmerge17;


    while (hzerobuck17->val != 0){
               merge17->val=hzerobuck17->val;
               hzerobuck17=hzerobuck17->next;
               merge17->next=malloc(sizeof(node_t));
               merge17=merge17->next;
    }

    while(honebuck17->val != 0){
               merge17->val=honebuck17->val;
               honebuck17=honebuck17->next;
               merge17->next=malloc(sizeof(node_t));
               merge17=merge17->next;

    }



    
    long decVal;
    
    printf("Sorted Numbers:\n");

    for(int i=0;i<count;i++)
    {
        decVal = binaryToDecimal(hmerge17->val);
        printf("%ld\n", decVal);
        hmerge17=hmerge17->next;

    }

    return 0;

}

    
    
  
    
    
    
    
    
    
    
    
    

