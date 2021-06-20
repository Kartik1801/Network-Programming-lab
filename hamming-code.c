#include<stdio.h>
void main()
{
    //we are using bit 1 0 1 _ 0 _ _ (_ represent the space for parity:p0,p1,p2) 
    int data[10];
    int data_at_rec[10],c,c1,c2,c3,i;
    
    // BITS :  D7  D6  D5  P4  D3  P2  P1 
    // INDEX   0   1   2   3   4   5    6

    printf("enter 4 bit of data one by one \n");
    scanf("%d",&data[0]); //1
    scanf("%d",&data[1]); //0
    scanf("%d",&data[2]); //1
    scanf("%d",&data[4]); //0
    
    // find the values of parity bits
    data[6]=data[0]^data[2]^data[4]; // 110_ for even parity p0 = 0
    data[5]=data[0]^data[1]^data[4]; // 100_ for even parity p1 = 1
    data[3]=data[0]^data[1]^data[2]; // 101_ for even parity p4 = 0
    
    // print encoded data ( data bits + parity bits )
    printf("\nEncoded data:\n");
    for (i=0;i<7;i++)
    { 
        printf("%d",data[i]);
    }
    
    // get the 7 bit of data at reciver's end
    printf("\nenter recived data bit one by one \n"); // for example we will take 1110010
    for ( i = 0; i < 7; i++)
    {
        scanf("%d",&data_at_rec[i]);
    }

printf("\nSent Data: ");   
    for (i=0;i<7;i++)
    { 
        printf("%d",data[i]);
    }
    // print recived data
    printf("\nRecived Data: ");   
    for (i=0;i<7;i++)
    { 
        printf("%d",data_at_rec[i]);
    }

    c1=data_at_rec[6]^data_at_rec[4]^data_at_rec[2]^data_at_rec[0]; // data at d7,d5,d3,p1 check for parity at p1
    c2=data_at_rec[5]^data_at_rec[4]^data_at_rec[1]^data_at_rec[0]; // data at d7,d6,d3,p2 check for parity at p2
    c3=data_at_rec[3]^data_at_rec[2]^data_at_rec[1]^data_at_rec[0]; // data at d7,d6,d5,p4 check for parity at p4
       
    c=c3*4+c2*2+c1*1; // this will give us the decimal position at which error is present  
    
    if(c==0) // NO ERROR 
    printf("\nno error while transmission of data \n");
    else 
    printf("\nerror at position: %d ",c); 
    
//for correction:if  error bit is 0 we complement it otherwise vise versa
   //  CORRECTION 
   if(data_at_rec[7-c]==0)
   data_at_rec[7-c]=1;
   else
   data_at_rec[7-c]=0;
   printf("\nCorrected Data:");   
    for (i=0;i<7;i++)
    { 
        printf("%d",data_at_rec[i]);
    }
}