int maximizeSquareArea(int m, int n, int *hFences, int hFencesSize, int *vFences, int vFencesSize)
{
    int hi = 0, vi = 0;
    static long long int area = 0;
    int mod = 1000000000 + 7;
    if (m == n)
        return ((m - 1) * (m - 1)) % mod;
    if (m == vFences[vFencesSize - 1] || m - 1 == n - vFences[vFencesSize - 1])
        if (area < ((m - 1) * (m - 1)))
            area = ((m - 1) * (m - 1));
    if (n == hFences[hFencesSize - 1] || n - 1 == m - hFences[hFencesSize - 1])
        if (area < ((n - 1) * (n - 1)))
            area = ((n - 1) * (n - 1));
    while (hFencesSize > 0 && vFencesSize > 0)
    {
        m = hFences[hFencesSize - 1];
        n = vFences[vFencesSize - 1];
        vFencesSize--;
        hFencesSize--;
        area = maximizeSquareArea(m, n, hFences, hFencesSize, vFences, vFencesSize);
    }

    if (area == 0)
        return -1;
    return area % mod;
}
#include <stdio.h>

int main()
{
    int m = 4;
    int n = 3;

    int hFences[] = {2, 3};
    int hFencesSize = 2;

    int vFences[] = {2};
    int vFencesSize = 1;

    int result = maximizeSquareArea(m, n, hFences, hFencesSize, vFences, vFencesSize);

    if (result == -1)
    {
        printf("No valid square can be formed.\n");
    }
    else
    {
        printf("Maximum square area: %d\n", result);
    }

    return 0;
}
