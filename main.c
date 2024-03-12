#include <stdio.h>
#include <string.h>

int has_uppercase(const char *password)
{
    for (int i = 0; password[i] != '\0'; i++)
    {
        if (password[i] >= 'A' && password[i] <= 'Z')
        {
            return 1;
        }
    }
    return 0;
}

int has_lowercase(const char *password)
{
    for (int i = 0; password[i] != '\0'; i++)
    {
        if (password[i] >= 'a' && password[i] <= 'z')
        {
            return 1;
        }
    }
    return 0;
}

int has_digit(const char *password)
{
    for (int i = 0; password[i] != '\0'; i++)
    {
        if (password[i] >= '0' && password[i] <= '9')
        {
            return 1;
        }
    }
    return 0;
}

int has_special(const char *password)
{
    const char *specials = "!@#$%^&*()_+-=[]{}|;':\"\\<>,.?/";
    for (int i = 0; password[i] != '\0'; i++)
    {
        for (int j = 0; specials[j] != '\0'; j++)
        {
            if (password[i] == specials[j])
            {
                return 1;
            }
        }
    }
    return 0;
}

int is_valid_password(const char *password, int min_length, int max_length)
{
    int length = strlen(password);
    if (length < min_length || length > max_length)
    {
        return 0;
    }
    return has_uppercase(password) && has_lowercase(password) && has_digit(password) && has_special(password);
}

int main()
{
    int min_length = 8;
    int max_length = 12;

    char password[max_length + 1];

    printf("Enter your password: ");
    fgets(password, max_length + 1, stdin);

    password[strcspn(password, "\n")] = '\0';

    if (is_valid_password(password, min_length, max_length))
    {
        printf("Strong password!\n");
    }
    else
    {
        printf("Password does not meet requirements:\n");
        if (strlen(password) < min_length)
        {
            printf("  - Minimum length is %d characters.\n", min_length);
        }
        else if (strlen(password) > max_length)
        {
            printf("  - Maximum length is %d characters.\n", max_length);
        }
        if (!has_uppercase(password))
        {
            printf("  - Must contain at least one uppercase letter.\n");
        }
        if (!has_lowercase(password))
        {
            printf("  - Must contain at least one lowercase letter.\n");
        }
        if (!has_digit(password))
        {
            printf("  - Must contain at least one digit.\n");
        }
        if (!has_special(password))
        {
            printf("  - Must contain at least one special character.\n");
        }
    }

    return 0;
}
