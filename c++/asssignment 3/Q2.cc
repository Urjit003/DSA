// Staff
// code
// name

// Teacher
// subject
// publicat.

// Officer
// grade

// typist
// speed

// regular

// casual
//  daily
//  wages
#include <iostream>
#include <stdlib.h>
using namespace std;
class Staff
{
protected:
    int code;
    string name;

public:
    Staff(int code =000, string name=NULL) : code(code) , name(name) {}
    void SetName(string name)
    {
        this->name = name;
    }
    void SetCode(int code)
    {
        this->code = code;
    }
    int GetCode()
    {
        return this->code;
    }
    string GetName()
    {
        return this->name;
    }
};
class Teacher : public Staff
{
    string subject , publicat;
    public:
    Teacher (int code =000, string name =NULL, string subject =NULL, string publicat=NULL) : Staff(code, name),
    subject(subject) , publicat(publicat){}
    
    void setPublicat(const std::string& newPublicat) {
        publicat = newPublicat;
    }

    string getPublicat() const {
        return publicat;
    }
    void setSubject(const std::string& newSubject) {
        subject = newSubject;
    }

    string getSubject() const {
        return subject;
    }
};
class typist : public Staff
{
    int speed;
    public :
    typist (int code =000, string name =NULL, int speed=0) : Staff(code,name) , speed(speed){}
    void setSpeed(int newSpeed) {
        speed = newSpeed;
    }

    int getSpeed() const {
        return speed;
    }
};
class Officer : public Staff
{
    char Grade ;
    Officer(int code =000, string name =NULL, int speed=0,char grade='N') : Staff(code,name) , Grade(grade) {}
    void setGrade(char newGrade) {
        Grade = newGrade;
    }

    char getGrade() const {
        return Grade;
    }

};
class regular : public typist
{

};
class casual : public typist
{
    float daily_wages;
    public:
    casual(int code =000, string name =NULL, float DW=0.0): typist(code,name) , daily_wages(DW) {}
    void setDailyWages(float newDailyWages) {
        daily_wages = newDailyWages;
    }

    float getDailyWages() const {
        return daily_wages;
    }
};
int main()
{
    Staff *t1 = new Teacher(101,"Urjit","DSA");
    cout << t1->GetName();
    return 0;
}