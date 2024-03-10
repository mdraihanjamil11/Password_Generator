#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int i, len, uppercase_flag, lowercase_flag, number_flag, special_flag, consecutive_flag;
    char password[13]; // Max length is 12 + 1 for null terminator

    printf("Welcome to the password generator!\n");

    for (i = 0; i < 3; i++)
    { // Allowing 3 attempts
        uppercase_flag = lowercase_flag = number_flag = special_flag = consecutive_flag = 0;

        printf("Enter your password (8-12 characters) with at least one uppercase letter, one lowercase letter, one number, one special character (*,#,@,$,&): ");
        scanf("%s", password);

        len = strlen(password);

        if (len < 8 || len > 12)
        {
            printf("Password length should be between 8 and 12 characters.\n");
            continue;
        }

        for (int j = 0; j < len; j++)
        {
            if (isupper(password[j]))
            {
                uppercase_flag = 1;
            }
            else if (islower(password[j]))
            {
                lowercase_flag = 1;
            }
            else if (isdigit(password[j]))
            {
                number_flag = 1;
            }
            else if (password[j] == '*' || password[j] == '#' || password[j] == '@' || password[j] == '$' || password[j] == '&')
            {
                special_flag = 1;
            }

            if (j > 0 && (isupper(password[j]) && isupper(password[j - 1])) || (islower(password[j]) && islower(password[j - 1])))
            {
                consecutive_flag = 1;
            }
        }

        if (!uppercase_flag || !lowercase_flag || !number_flag || !special_flag || consecutive_flag)
        {
            printf("Failed to generate password.\n");
        }
        else
        {
            printf("Password generated successfully: %s\n", password);
            return 0;
        }
    }

    printf("You have failed to generate a password after 3 attempts.\n");
    return 0;
}
