#include <iostream>
#include<cmath>

using namespace std;
/*
Write a C++ Program that calculates the roots of a quadratic equation given as
ax^2 + bx + c = 0. Create the following functions:
i. Get_Coefficients function that asks for the coefficient of the equatio using pointers.
ii. Calc_Discriminant function to check if the roots are real, imaginary or same.
If the root is real, imaginary or same, then Calc_discriminant returns "r", "i" or "s" respectively.
Based on the result of Calc_Discriminant function, call a Calc_Root function to calculate the
roots of the quadratic equation. Ask the user if he or she wishes to continue
and loop back if the answer is affirmative.
*/

double x1, x2, y, z;
double a,b,c;
double *pA=&a;
double *pB=&b;
double *pC=&c;

void Get_Coefficients();
char Calc_Discriminant();
double Calc_Root();

int main()
{
    string answer;
    do
    {
        Calc_Root();
        cout << "Do you want to perform this operation again? [Y for Yes, N for No]" << endl;
        cin >> answer;
    }
    while (answer == "Y" || answer == "y");
    if(answer == "N" || answer == "n")
        cout << endl <<"Thank you very much. " << endl;
    return 0;
}

void Get_Coefficients()
{
    cout << endl <<"Enter the coefficient of x^2, a: " << endl;
    cin >> *pA;
    cout << endl << "Enter the coefficient of x, b: " << endl;
    cin >> *pB;
    cout << endl << "Enter the constant, c: " << endl;
    cin >> *pC;
}
char Calc_Discriminant()
{
    Get_Coefficients();

    float discriminant = b*b - 4*a*c;
    if(discriminant > 0)
        return 'r';
    else if(discriminant == 0)
        return 's';
    else
        return 'i';
}

double Calc_Root()
{
    char answer = Calc_Discriminant();

    float discriminant = b*b - 4*a*c;

    if(answer == 'r'){
        x1 = (-b + sqrt(discriminant))/(2*a);
        x2 = (-b - sqrt(discriminant))/(2*a) ;
        cout<<"Roots are real and different"<<endl;
        cout<<"x1 = "<<x1<<endl;
        cout<<"x2 = "<<x2<<endl;
        }

    else if(answer == 's')
    {
        x1 = -b/(2*a);
        cout<<"Roots are real and same"<<endl;
        cout<<"x1=x2= "<<x1<<endl;
    }

    else
    {
        y = (-b)/(2*a);
        z = sqrt(-discriminant)/(2*a);
        cout<<"Roots are complex and Different " << endl;
        cout<<"x1= "<<y<<" +"<<z<<"j"<<endl;
        cout<<"x2= "<<y<<" -"<<z<<"j"<<endl;
    }

}
