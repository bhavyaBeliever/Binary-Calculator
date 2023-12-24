int maximizeSquareArea(int m, int n, int *hFences, int hFencesSize, int *vFences, int vFencesSize)
{
    // int hi = 0, vi = 0;
    // static long long int area = 0;
    // int mod = 1000000000 + 7;
    // if (m == n)
    //     return ((m - 1) * (m - 1)) % mod;
    // if (m == vFences[vFencesSize - 1] || m - 1 == n - vFences[vFencesSize - 1])
    //     if (area < ((m - 1) * (m - 1)))
    //         area = ((m - 1) * (m - 1));
    // if (n == hFences[hFencesSize - 1] || n - 1 == m - hFences[hFencesSize - 1])
    //     if (area < ((n - 1) * (n - 1)))
    //         area = ((n - 1) * (n - 1));
    // while (hFencesSize > 0 && vFencesSize > 0)
    // {
    //     m = hFences[hFencesSize - 1];
    //     n = vFences[vFencesSize - 1];
    //     vFencesSize--;
    //     hFencesSize--;
    //     area = maximizeSquareArea(m, n, hFences, hFencesSize, vFences, vFencesSize);
    // }

    // if (area == 0)
    //     return -1;
    // return area % mod;
    int hi=0, vi=0;
    long long int area=0;
    int mod=1000000000+7;
    if(m==n) return ((m-1)*(n-1))%mod;
    for(int i=hFencesSize-1;i>-1;i--){
        for(int j=vFencesSize-1;j>-1;j--){
            if(n==hFences[i] || n-1==m-hFences[i]) return ((n-1)*(n-1))%mod;
            if(m==vFences[j] || m-1==n-vFences[j]) return ((m-1)*(m-1))%mod;
            if(hFences[i] == vFences[j] || m-hFences[i] == vFences[j]-1) {
                if (area<vFences[j]*vFences[j]) area=(vFences[j]-1)*(vFences[j]-1) ;
            }
            if(vFences[j] == hFences[i] || n-vFences[j] == hFences[i]-1) {
                if (area<hFences[i]*hFences[i]) area=(hFences[i]-1)*(hFences[i]-1) ;
            }
            
        }
    }
    if(area==0) return -1;
    return area%mod;
}
#include <stdio.h>

int main()
{
    int m = 6;
    int n = 7;

    int hFences[] = {2};
    int hFencesSize = 1;

    int vFences[] = {4, 5, 6, 8};
    int vFencesSize = 4;

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
