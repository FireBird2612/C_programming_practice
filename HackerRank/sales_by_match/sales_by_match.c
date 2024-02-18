/*
 *  Warmup Challenges:  Sales by match
 *                      Read the question here:
 *                      https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=warmup
 */

#include <stdio.h>

int sock_merchant(int n, int arr[])
{
    int color_count = 1, sock_pair = 1;

    /*  Sort the array in ascending order first */
    for (int count = 0; count < n; count++)
    {
        for (int in_count = count + 1; in_count < n; in_count++)
        {
            if (arr[count] > arr[in_count])
            {
                int t = arr[count];
                arr[count] = arr[in_count];
                arr[in_count] = t;
            }
        }
    }

    for (int count = 0; count < n; count++)
    {
        for (int in_count = count + 1; in_count < n; in_count++)
        {
            if (arr[count] == arr[in_count])
            {
                color_count++;
                if (color_count == 2)
                {
                    sock_pair++;
                    color_count = 1;
                    count = in_count + 1;
                    break;
                }
            }
            else
            {
                count = in_count;
                break;
            }
        }
    }

    /*  Print to check the array    */
    for (int count = 0; count < n; count++)
    {
        printf("%d ", arr[count]);
    }
    printf("\n");

    if (sock_pair == 1)
    {
        return sock_pair - 1;
    }
    return sock_pair;
}

int main()
{
    // declare an array of type int
    int arr[] = {10, 10, 30, 20, 20, 10, 10, 30, 50, 10, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", n);
    printf("Sock pairs of same color: %d\n", sock_merchant(n, arr));
}
