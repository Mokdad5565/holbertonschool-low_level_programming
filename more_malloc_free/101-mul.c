#include "holberton.h"

/**
 * print_number - Prints a number.
 * @num: The number to be printed.
 */
void print_number(char *num)
{
    while (*num == '0')  /* Skip leading zeros */
        num++;

    if (*num == '\0')  /* If all digits are zeros, print 0 */
        _putchar('0');
    else
    {
        while (*num != '\0')
        {
            _putchar(*num);
            num++;
        }
    }
    _putchar('\n');
}

/**
 * is_digit - Checks if a character is a digit.
 * @c: The character to be checked.
 * Return: 1 if the character is a digit, 0 otherwise.
 */
int is_digit(char c)
{
    return c >= '0' && c <= '9';
}

/**
 * multiply - Multiplies two positive numbers.
 * @num1: The first number.
 * @num2: The second number.
 * Return: 0 on success, 98 on error.
 */
int multiply(char *num1, char *num2)
{
    int len1 = 0, len2 = 0, i, j, k, carry = 0;
    int *result;

    while (num1[len1] != '\0')
        len1++;
    while (num2[len2] != '\0')
        len2++;

    result = malloc(sizeof(int) * (len1 + len2));
    if (result == NULL)
    {
        _puts("Error");
        exit(98);
    }

    for (i = 0; i < len1 + len2; i++)
        result[i] = 0;

    for (i = len1 - 1; i >= 0; i--)
    {
        carry = 0;
        for (j = len2 - 1; j >= 0; j--)
        {
            k = i + j + 1;
            result[k] += (num1[i] - '0') * (num2[j] - '0') + carry;
            carry = result[k] / 10;
            result[k] %= 10;
        }
        result[i] += carry;
    }

    print_number(result);
    free(result);
    return 0;
}

/**
 * main - Entry point. Multiplies two positive numbers.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 * Return: 0 on success, 98 on error.
 */
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        _puts("Error");
        return 98;
    }

    for (int i = 1; i < 3; i++)
    {
        for (int j = 0; argv[i][j] != '\0'; j++)
        {
            if (!is_digit(argv[i][j]))
            {
                _puts("Error");
                return 98;
            }
        }
    }

    multiply(argv[1], argv[2]);

    return 0;
}
