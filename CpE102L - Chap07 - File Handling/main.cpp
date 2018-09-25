#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;

int main()
{
    std::string name;
    std::string payRate;
    std::string hoursWorked;
    int x = 0;
    std::string space(" ");
    char nStr[50];
    char hStr[50];
    char pStr[50];
    int num[50];
    char dol = '$';
    int nlen = 0;
    int hlen = 0;
    int plen = 0;
    int n = 0;

    std::ifstream employeeData;
    employeeData.open("EmployeeData.bat");

    //std::cout << employeeData.is_open();

    printf("Name\t\t\t    Hours Worked\t\tPayrate\n");
    printf("===============================\n");

    while(!employeeData.eof()){
        employeeData.getline(nStr,50,';');
        name = nStr;
        employeeData.getline(hStr,50,';');
        hoursWorked = hStr;
        employeeData.getline(pStr,50,';');
        payRate = pStr;
        employeeData.ignore(50, '\n');

        nlen = strlen(nStr);
        hlen = strlen(hStr);

        nlen = 30 - nlen;
        hlen = 10 - hlen;

        printf("%s", name.c_str());
        while(n<=nlen){
            printf(" ");
            n++;
        }
        n = 0;
        printf("%4s", hoursWorked.c_str());
        /*while(n<=hlen){
            printf(" ");
            n++;
        }
        n = 0; */
        payRate = dol + payRate;
        printf("%28s\n", payRate.c_str());
        /*printf("%20s", hoursWorked.c_str());
        printf("%40c%s\n", dol,payRate.c_str()); */
    }

    return 0;
}
