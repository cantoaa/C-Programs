#include <stdio.h>
#include <math.h>

int main(){
    float temp;
    char type;

    printf("Temperature: ");
    scanf("%f", temp);
    printf("\n F(Fahrenheit) or C(Celsius): ");
    scanf(" %c", &type);
    if(type == 'F'){
        printf("\n In Celsius: %f", (temp - 32) * 5 / 9.0);
    }
    else if(type == 'C'){
        printf("\n In Fahrenheit: %f", ((temp / 5.0)    * 9 + 32));
    }

    return 0;
}
