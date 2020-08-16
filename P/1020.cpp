#include <iostream>

int a[100005], asc[100005], ascLen = 1, desc[100005], descLen = 1;

int main()
{
    int no = 0;
    while (std::cin >> a[no])
    {
        no++;
    }
    asc[0] = desc[0] = a[0];
    // 最长不升子序列
    for (int i = 1; i < no; i++)
    {
        if (a[i] <= asc[ascLen - 1])
        {
            asc[ascLen] = a[i];
            ascLen++;
        }
        else
        {
            int l = 0;
            int r = ascLen - 1;
            int ans = -1;
            while (l <= r)
            {
                int mid = (l + r) / 2;
                if (asc[mid] < a[i])
                {
                    ans = mid;
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            asc[ans] = a[i];
        }

        // 最长上升子序列
        if (a[i] > desc[descLen - 1])
        {
            desc[descLen] = a[i];
            descLen++;
        }
        else
        {
            int l = 0, r = descLen - 1;
            int ans = -1;
            while (l <= r)
            {
                int mid = (l + r) / 2;
                if (desc[mid] >= a[i])
                {
                    ans = mid;
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            desc[ans] = a[i];
        }
    }
    std::cout << ascLen << std::endl
              << descLen << std::endl;

    return 0;
}
