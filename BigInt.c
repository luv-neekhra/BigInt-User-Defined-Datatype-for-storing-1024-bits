#include <stdio.h>
#include <string.h>
#include <math.h>
void reverseString(char *str) {
    int length = strlen(str);
    int start = 0;
    int end = length - 1;

    while (start < end) {
        // Swap characters at start and end positions
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        // Move the pointers towards each other
        start++;
        end--;
    }
}
long long int reverseLongLong(long long int num) {
  
    char numStr[20];  
    sprintf(numStr, "%lld", num);

    int length = strlen(numStr);
    int start = 0;
    int end = length - 1;

    while (start < end) {
       
        char temp = numStr[start];
        numStr[start] = numStr[end];
        numStr[end] = temp;

     
        start++;
        end--;
    }
    unsigned long long int num1=0;

     for (int j = 0;  numStr[j]!='\0' ; j++) { 
        num1 = num1 * 10 + (numStr[j] - 48); 
       
     }
   
    return num1;
}
void Sum()
{
    unsigned long long int a[18],b[18] ,c[18] ,num =0 ,temp =0;
    char str1[309];
    char str2[309];
    printf("Enter first number: ");
    scanf("%s",str1);
    printf("Enter second number:");
    scanf("%s",str2);
    reverseString(str1);
   // printf("%s\n ",str1);
  
    reverseString(str2);
     // printf("%s\n ",str2);

   
    //storing first number in a[]
    int i =0 ;
    int k1=0;
    int k2 =0;
    int m=0;
    
    while(str1[i]!='\0')
    { 
         for (int j = 0; (j<18 && str1[i]!='\0') ; j++) { 
        num = num * 10 + (str1[i] - 48); 
        i++;
    }
    
    num = reverseLongLong(num);
    a[k1] = num;
    k1++;
    num =0;
    }
    // for(int i = 0 ; i<k1 ;i++)
    // {
    //      printf("%llu ",a[i]);
    // }


    while(str2[m]!='\0')
    {
         for (int j = 0; (j<18 && str2[m]!='\0') ; j++) { 
        num = num * 10 + (str2[m] - 48); 
        m++;
    }
    num = reverseLongLong(num);
    b[k2] = num;
    k2++;
    num =0;
    }
    //  for(int i = 0 ; i<k2 ;i++)
    // {
    //      printf("%llu ",b[i]);
    // }
    int carry =0;
    int num1 = 0;
    int num2 =0;
    int greatnum;
    int ccount;
    if(k1>=k2)
    {
        greatnum =k1;
    }
    else{
        greatnum =k2;
    }
    ccount = greatnum ;
    greatnum =0;
    while(num1<k1 && num2<k2)
    {
        num = a[num1] +b[num2];
        if(num>999999999999999999 &&carry==0 )
        {
            num =   num -1000000000000000000 ;
            c[greatnum] =num;
            carry =1;
        }
       else if(num>999999999999999999 &&carry==1 )
        {
            num =   num -100000000000000000 +1;
            c[greatnum] =num ;
            carry =1;
        }
        else
        {
            if(carry ==0)
            {
                c[greatnum] = num;
            }
            else
            {
                c[greatnum] = num+1;
            }

            
        }
        num1++;
        num2++;
        greatnum++;
        
    }
    
    while(num1<k1)
    {   

        if(a[num1]<999999999999999999  && carry==1)
        {
            c[greatnum] =a[num1] + carry;
            carry =0;
        }
        else if(a[num1]==999999999999999999  && carry==1)
        {
            temp = a[num1] +1;
            c[greatnum] = temp -100000000000000000;
            carry =1;
            
        }
        else{
            c[greatnum] = a[num1];
            carry =0;

        }
        greatnum ++;
        num1++;
    }
    while(num2<k2)
    {   

        if(b[num2]<999999999999999999  && carry==1)
        {
            c[greatnum] =b[num2] + carry;
            carry =0;
        }
        else if(b[num2]==999999999999999999  && carry==1)
        {
            temp = b[num2] +1;
            c[greatnum] = temp -100000000000000000;
            carry =1;
            
        }
        else{
            c[greatnum] = b[num2];
            carry =0;

        }
        greatnum ++;
        num2++;
    }
     
     
        for(int i =greatnum -1; i>=0 ; i--)
        {
            printf("%llu",c[i]);
    

     }
} 

void Subtraction() {
    unsigned long long int a[18], b[18], c[18], num = 0, temp = 0;
    char str1[309];
    char str2[309];

    printf("Enter first number: ");
    scanf("%s", str1);
    printf("Enter second number: ");
    scanf("%s", str2);

    int length1 = strlen(str1);
    int length2 = strlen(str2);

    // Ensure the greater number is entered first
    while (length1 < length2) {
        printf("Enter greater number first!\n");
        printf("Enter first number: ");
        scanf("%s", str1);
        printf("Enter second number: ");
        scanf("%s", str2);
        length1 = strlen(str1);
        length2 = strlen(str2);
    }

    reverseString(str1);
    reverseString(str2);

    // Storing the first number in a[]
    int i = 0;
    int k1 = 0;
    int k2 = 0;
    int m = 0;

    while (str1[i] != '\0') {
        num = 0;
        for (int j = 0; (j < 18 && str1[i] != '\0'); j++) {
            num = num * 10 + (str1[i] - 48);
            i++;
        }
        num = reverseLongLong(num);
        a[k1] = num;
        k1++;
    }

    while (str2[m] != '\0') {
        num = 0;
        for (int j = 0; (j < 18 && str2[m] != '\0'); j++) {
            num = num * 10 + (str2[m] - 48);
            m++;
        }
        num = reverseLongLong(num);
        b[k2] = num;
        k2++;
    }

    int borrow = 0;
    int num1 = 0;
    int num2 = 0;
    int greatnum = 0;

    while (num1 < k1) {
        num = a[num1] - borrow;

        if (num2 < k2) {
            num -= b[num2];
        }

        if (num < 0) {
            num += 1000000000000000000;
            borrow = 1;
        } else {
            borrow = 0;
        }

        c[greatnum] = num;
        greatnum++;
        num1++;
        num2++;
    }

    // Ignore leading zeros
    while (greatnum > 1 && c[greatnum - 1] == 0) {
        greatnum--;
    }

    for (int i = greatnum - 1; i >= 0; i--) {
        printf("%llu", c[i]);
    }
}
void Multiply() {
    unsigned long long int a[18], b[18], c[36] = {0}, num = 0, temp = 0;
    char str1[309];
    char str2[309];

    printf("Enter first number: ");
    scanf("%s", str1);
    printf("Enter second number: ");
    scanf("%s", str2);

    int length1 = strlen(str1);
    int length2 = strlen(str2);

    reverseString(str1);
    reverseString(str2);

    int k1 = 0, k2 = 0;
    int num1 = 0, num2 = 0;

    while (str1[num1] != '\0') {
        num = 0;
        for (int j = 0; (j < 18 && str1[num1] != '\0'); j++) {
            num = num * 10 + (str1[num1] - 48);
            num1++;
        }
        num = reverseLongLong(num);
        a[k1] = num;
        k1++;
    }

    while (str2[num2] != '\0') {
        num = 0;
        for (int j = 0; (j < 18 && str2[num2] != '\0'); j++) {
            num = num * 10 + (str2[num2] - 48);
            num2++;
        }
        num = reverseLongLong(num);
        b[k2] = num;
        k2++;
    }

    int carry = 0;
    int ccount;
    int greatnum = 0;

    for (int i = 0; i < k1; i++) {
        for (int j = 0; j < k2; j++) {
            num = a[i] * b[j] + c[i + j] + carry;
            c[i + j] = num % 1000000000000000000;
            carry = num / 1000000000000000000;
        }

        if (carry > 0) {
            c[i + k2] += carry;
            carry = 0;
        }
    }

    // Finding the actual count of c array
    for (ccount = 35; ccount >= 0; ccount--) {
        if (c[ccount] != 0) {
            break;
        }
    }

    for (int i = ccount; i >= 0; i--) {
        printf("%llu", c[i]);
    }
}


int main()
{   
    int ans =0;
    while(ans!=4)
    {
        printf("\nEnter the operation that you want to perform with large numbers:\n");
        printf("1=> Addition\n");
        printf("2=>Subtraction\n");
        printf("3=>Multiplication\n");
        printf("4=>Exit\n");
        scanf("%d",&ans);
        if(ans ==1)
        {
            Sum();

        }
        else if(ans==2)
        {
            Subtraction();
        }
        else if(ans==3)
        {
            Multiply();
        }

    }
   
}