//Bit Stuffing :
// 011111111000 => 0111110111000
//      ^                ^
#include<string.h>
#include<stdio.h>
void main()
{
    int i=0,j=0,count=0;
    char databits[80],databitwithStuffing[80];
    printf("Enter Data Bit: ");
    scanf("%s",&databits);

    for(i=0;i<strlen(databits);i++)
    {
        
        if(databits[i]=='1')
        count++;
        else
        count=0;
        databitwithStuffing[j]=databits[i];
        j++;        
        if (count>=5)
        {
           count=0;
           databitwithStuffing[j]='0';
           j++;
        }
    }
    databitwithStuffing[j]='\0';
    printf("%s\n",databits); 
    printf("%s\n",databitwithStuffing);
   
}
