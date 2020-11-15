#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void){
    long number = get_long("Number: ");

    if(number % 10000000000000 == number){
        int checkvisa = ((number % 10000000000000) - (number % 1000000000000)) / 1000000000000;

        if(checkvisa == 4){
            long mod1 = 100;
            long mod2 = 10;
            long mod3 = 100;

            int sum1 = 0;
            int sum2 = 0;
            int sum3 = 0;

            int tmp;
            int tmp1;
            int tmp2;

            for(int i = 0;mod1 <= 10000000000000;i++){
                tmp = ((((number % mod1) - (number % mod2)) / mod2) * 2);

                if(tmp > 9){
                    tmp1 = (tmp % 100) / 10;
                    tmp2 = tmp % 10;

                    sum1 = sum1 + tmp1 + tmp2;
                }

                else{
                    sum1 = sum1 + tmp;
                }

                mod1 *= 100;
                mod2 *= 100;
            }

            mod2 = 10;

            for(int j = 0;mod2 <= 10000000000000;j++){

                if(mod2 == 10){
                    sum2 = number % mod2;

                    mod2 *= 100;
                }

                else{
                    sum2 = sum2 + (((number % mod2) - (number % mod3)) / mod3);

                    mod2 *= 100;
                    mod3 *= 100;
                }
            }

            sum3 = sum1 + sum2;

            if(sum3 % 10 == 0){
                printf("VISA\n");
            }
            else{
                printf("INVALID\n");
            }
        }

        else{
            printf("INVALID\n");
        }
    }

    else if(number % 1000000000000000 == number){
        int checkamex = ((number % 1000000000000000) - (number % 10000000000000)) / 10000000000000;

        if(checkamex == 34 || checkamex == 37){
            long mod1 = 100;
            long mod2 = 10;
            long mod3 = 100;

            int sum1 = 0;
            int sum2 = 0;
            int sum3 = 0;

            int tmp;
            int tmp1;
            int tmp2;

            for(int i = 0;mod1 <= 1000000000000000;i++){
                tmp = ((((number % mod1) - (number % mod2)) / mod2) * 2);

                if(tmp > 9){
                    tmp1 = (tmp % 100) / 10;
                    tmp2 = tmp % 10;

                    sum1 = sum1 + tmp1 + tmp2;
                }

                else{
                    sum1 = sum1 + tmp;
                }

                mod1 *= 100;
                mod2 *= 100;
            }

            mod2 = 10;

            for(int j = 0;mod2 <= 1000000000000000;j++){

                if(mod2 == 10){
                    sum2 = number % mod2;

                    mod2 *= 100;
                }

                else{
                    sum2 = sum2 + (((number % mod2) - (number % mod3)) / mod3);

                    mod2 *= 100;
                    mod3 *= 100;
                }
            }

            sum3 = sum1 + sum2;

            if(sum3 % 10 == 0){
                printf("AMEX\n");
            }
            else{
                printf("INVALID\n");
            }
        }

        else{
            printf("INVALID\n");
        }
    }

    else if(number % 10000000000000000 == number){
        int checkmaster = ((number % 10000000000000000) - (number % 100000000000000)) / 100000000000000;

        if(checkmaster >= 51 && checkmaster <= 55){
            long mod1 = 100;
            long mod2 = 10;
            long mod3 = 100;

            int sum1 = 0;
            int sum2 = 0;
            int sum3 = 0;

            int tmp;
            int tmp1;
            int tmp2;

            for(int i = 0;mod1 <= 10000000000000000;i++){
                tmp = ((((number % mod1) - (number % mod2)) / mod2) * 2);

                if(tmp > 9){
                    tmp1 = (tmp % 100) / 10;
                    tmp2 = tmp % 10;

                    sum1 = sum1 + tmp1 + tmp2;
                }

                else{
                    sum1 = sum1 + tmp;
                }

                mod1 *= 100;
                mod2 *= 100;
            }

            mod2 = 10;

            for(int j = 0;mod2 <= 10000000000000000;j++){

                if(mod2 == 10){
                    sum2 = number % mod2;

                    mod2 *= 100;
                }

                else{
                    sum2 = sum2 + (((number % mod2) - (number % mod3)) / mod3);

                    mod2 *= 100;
                    mod3 *= 100;
                }
            }

            sum3 = sum1 + sum2;

            if(sum3 % 10 == 0){
                printf("MASTERCARD\n");
            }
            else{
                printf("INVALID\n");
            }
        }

        else if((((checkmaster % 100) - (checkmaster % 10)) / 10) == 4){
            long mod1 = 100;
            long mod2 = 10;
            long mod3 = 100;

            int sum1 = 0;
            int sum2 = 0;
            int sum3 = 0;

            int tmp;
            int tmp1;
            int tmp2;

            for(int i = 0;mod1 <= 10000000000000000;i++){
                tmp = ((((number % mod1) - (number % mod2)) / mod2) * 2);

                if(tmp > 9){
                    tmp1 = (tmp % 100) / 10;
                    tmp2 = tmp % 10;

                    sum1 = sum1 + tmp1 + tmp2;
                }

                else{
                    sum1 = sum1 + tmp;
                }

                mod1 *= 100;
                mod2 *= 100;
            }

            mod2 = 10;

            for(int j = 0;mod2 <= 10000000000000000;j++){

                if(mod2 == 10){
                    sum2 = number % mod2;

                    mod2 *= 100;
                }

                else{
                    sum2 = sum2 + (((number % mod2) - (number % mod3)) / mod3);

                    mod2 *= 100;
                    mod3 *= 100;
                }
            }

            sum3 = sum1 + sum2;

            if(sum3 % 10 == 0){
                printf("VISA\n");
            }
            else{
                printf("INVALID\n");
            }
        }
        else{
            printf("INVALID\n");
        }
    }

    else{
        printf("INVALID\n");
    }
}