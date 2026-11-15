#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <limits.h>
#include <string.h>

/* Read and validate an integer from the user */
int readInteger(const char prompt[], int min, int max, int *result)
{
    char input[100];
    char *end;
    long value;

    while (1)
    {
        printf("%s", prompt);

        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            return 0;
        }

        errno = 0;
        value = strtol(input, &end, 10);

        /* Reject input that contains no integer */
        if (end == input)
        {
            printf("Please enter a valid number.\n\n");
            continue;
        }

        /* Skip spaces after the number */
        while (*end == ' ' || *end == '\t' || *end == '\n')
        {
            end++;
        }

        /* Reject extra characters, overflow, or values outside the range */
        if (*end != '\0' || errno == ERANGE ||
            value < min || value > max ||
            value < INT_MIN || value > INT_MAX)
        {
            printf("Invalid input. Enter a number from %d to %d.\n\n",
                   min, max);
            continue;
        }

        *result = (int)value;
        return 1;
    }
}

/* Read a full line of text */
int readLine(const char prompt[], char text[], int size)
{
    int ch;
    size_t length;

    printf("%s", prompt);

    if (fgets(text, size, stdin) == NULL)
    {
        return 0;
    }

    length = strlen(text);

    /* Remove the newline, if it was read */
    if (length > 0 && text[length - 1] == '\n')
    {
        text[length - 1] = '\0';
    }
    else
    {
        /* Discard the rest of an overlong input line */
        while ((ch = getchar()) != '\n' && ch != EOF)
        {
            /* Discard characters */
        }
    }

    return 1;
}

/* FEATURE 1: RANDOM PASSWORD GENERATOR */

void shuffle(char password[], int length)
{
    char temp;

    for (int i = length - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);

        temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }
}

void generatePassword(void)
{
    char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
    char digits[] = "0123456789";
    char special[] = "@#$!&*";

    char allCharacters[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789"
        "@#$!&*";

    char password[33];
    int length;
    int totalCharacters = sizeof(allCharacters) - 1;

    if (!readInteger("Enter password length (8-32): ", 8, 32, &length))
    {
        return;
    }

    /* Guarantee at least one character from each category */
    password[0] = uppercase[rand() % 26];
    password[1] = lowercase[rand() % 26];
    password[2] = digits[rand() % 10];
    password[3] = special[rand() % 6];

    /* Fill the remaining positions */
    for (int i = 4; i < length; i++)
    {
        password[i] = allCharacters[rand() % totalCharacters];
    }

    /* Randomize the positions */
    shuffle(password, length);

    /* End the string */
    password[length] = '\0';

    printf("Generated Password: %s\n\n", password);
}

/* FEATURE 2: CAESAR CIPHER TEXT DECODER */

void decodeText(void)
{
    char message[100];
    int shift;

    if (!readLine("\nEnter encoded text (spaces allowed): ",
                  message, sizeof(message)))
    {
        return;
    }

    if (!readInteger("Enter shift value (-100000 to 100000): ",
                     -100000, 100000, &shift))
    {
        return;
    }

    /* Normalize shift to the range 0-25 */
    shift = shift % 26;

    if (shift < 0)
    {
        shift += 26;
    }

    for (int i = 0; message[i] != '\0'; i++)
    {
        /* Decode uppercase letters */
        if (message[i] >= 'A' && message[i] <= 'Z')
        {
            message[i] = message[i] - shift;

            if (message[i] < 'A')
            {
                message[i] += 26;
            }
        }
        /* Decode lowercase letters */
        else if (message[i] >= 'a' && message[i] <= 'z')
        {
            message[i] = message[i] - shift;

            if (message[i] < 'a')
            {
                message[i] += 26;
            }
        }

        /* Spaces, digits, and punctuation remain unchanged */
    }

    printf("Decoded Text: %s\n\n", message);
}

/* MAIN FUNCTION */

int main(void)
{
    int choice;

    srand((unsigned int)time(NULL));

    do
    {
        printf("================================\n");
        printf("       S.Neeraj Reddy-[ECE]\n");
        printf("================================\n");
        printf("\n================================\n");
        printf("        C SECURITY TOOLKIT\n");
        printf("================================\n");
        printf("1. Random Password Generator\n");
        printf("2. Caesar Cipher Text Decoder\n");
        printf("3. Exit\n\n");

        if (!readInteger("Enter your choice: ", 1, 3, &choice))
        {
            printf("Input ended. Exiting program.\n");
            return 0;
        }

        switch (choice)
        {
            case 1:
                generatePassword();
                break;

            case 2:
                decodeText();
                break;

            case 3:
                printf("Thank you for using C Security Toolkit Designed By ECE!\n");
                break;
        }

    } while (choice != 3);

    return 0;
}
