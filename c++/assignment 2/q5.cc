#include <iostream>
#include<cstring>
#include <stdlib.h>
using namespace std;
class CustomString
{
    char *str;

public:
    CustomString(char *str)
    {
        int length = 0;
        while (str[length] != '\0')
        {
            ++length;
        }
        this->str = new char[length + 1];
        for (int i = 0; i <= length; i++)
        {
            this->str[i] = str[i];
        }
    }
    
    CustomString operator+ (const CustomString& other) const {
        char* temp = new char[strlen(str) + strlen(other.str) + 1];
        strcpy(temp, str);
        strcat(temp, other.str);
        CustomString result(temp);
        delete[] temp;
        return result;
    }
    void copyTo(CustomString& destination) const {
        int i = 0;
        while (str[i] != '\0') {
            destination.str[i] = str[i];
            ++i;
        }
        destination.str[i] = '\0';
    }
    int IsLessThanOrEqual(const CustomString& otr) {
        int i = 0;
        while (str[i] != '\0' && str[i] == otr.str[i])
        {
            i++;
        }
        // return (str[i] <= otr.str[i]);

        if(str[i] <= otr.str[i]) {
            return true;
        }else {
            return false;
        }
    }
    void reverse()
    {
        int length = 0;
        while (str[length] != '\0')
        {
            ++length;
        }
        for (int i = 0, j = length - 1; i < j; i++, --j)
        {
            char temp = str[i];
            str[i] = str[j];
            str[j] = temp;
        }
    }
    void Display()
    {
        cout << (string)str << endl;
    }

};
int main()
{
    char name[] = "a1";
    char name1[] = "a2";
    CustomString a1("Urjit");
    CustomString a2("dabhi");
    CustomString a3 (a1 + " " +a2);

    a3.Display();
    return 0;
    // skid#_#_#_#_#_#_#_#
    // skidr_o_w_#_#_#_#_#
    // skidr_l_i_e_s_o_f_p
    // skidrow
    // skidrow12345
}