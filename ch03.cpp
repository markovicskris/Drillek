#include "std_lib_facilities.h"

int main() {

    //1
    string first_name;
    cout << "Enter the name of the person you want to write to\n";
    cin >>  first_name;
    cout << "Dear " << first_name << "  \n\n";
    cout << "How are you?\n";
    cout << "I miss you!\n";
    cout << "I'm looking forward to seeing you again.\n";
    
    //2
    string friend_name;
    cout << "Please enter the name of your friend.\n";
    cin >> friend_name;
    cout << "Have you seen " << friend_name << " lately?\n";
    char friend_sex = 0;
	cout << "Enter an m if the friend is male and an f if the friend is female.\n";
    cin >> friend_sex;
    if (friend_sex == 'f') {
        cout << "If you see " << friend_name << " please ask her to call me.\n";
    }
    else {
        cout << "If you see " << friend_name << " please ask him to call me.\n";
    }
    
    //3
    int age;
    cout << "Enter the age of your recipient.\n";
    cin >> age;
     if (0 >= age || 110 <= age)
    {
        simple_error("you're kidding!");
    }
    
        cout << "I hear you just had a birthday and you are " << age << " years old.\n";
    
    if (age < 12) {
        cout << "Next year you will be "<< age + 1 << ".\n";
    }
    else if (age == 17) {
        cout << "Next year you will be able to vote.\n";
    }
    else if (age >= 70) {
        cout << "I hope you are enjoying retirement.\n";
    }
	cout << "\nYours sincerely\n\n " << first_name;

}