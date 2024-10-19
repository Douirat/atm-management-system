#include <stdio.h>
#include "header.h" // Include the header file

int main()
{
    User *user1 = NewUser(1, "BenDoe", "Ben123");
    printf("The user's id is: %d, the user name is: %s, and his password is: %s\n", user1->Id, user1->UserName, user1->Password);
    int val = HashedValue("BenDoe");
    printf("The hash value of the string BenDoe is: %d\n", val);
    return 0;
}
