#include <stdio.h>
#include <string.h>
#include <cs50.h>
string KnickKnack(int n);
string NumberString(int n);
void SingVerse(int n);

int
main(void)
{
    for (int i = 0; i < 10; i++){
        SingVerse(i);
    }
    return 0;
}

void
SingVerse(int n)
{
    printf("This old man, he played %s\n", NumberString(n));
    printf("He played KnickKnack %s\n", KnickKnack(n));
    printf("With a knickknack paddywack, give a dog a bone\n");
    printf("This old man came rolling home\n");
    printf("\n");
}

string
KnickKnack(int n)
{
    string knickKnack[10] = {
        "on my thumb",
        "on my shoe",
        "on my knee",
        "on my door",
        "on my hive",
        "on my sticks",
        "on my heaven",
        "on my gate",
        "on my spine",
        "once again"
    };
    return knickKnack[n];
}

string
NumberString(int n)
{
    string nums[10] = {
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine",
        "ten"
    };
    return nums[n];
}
