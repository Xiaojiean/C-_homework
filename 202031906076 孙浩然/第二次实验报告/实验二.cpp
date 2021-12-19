int Min(int* arr)
{
    int mi = arr[0];

    for (int i = 0; i < 5;i++)
    {
        if (mi > arr[i])
        {
            mi = arr[i];
        }
    }

    return mi;
}
//Copyright ©2021-2099 HaoranSun. All rights reserved