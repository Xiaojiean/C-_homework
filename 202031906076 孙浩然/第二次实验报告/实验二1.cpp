int Max(int* arr)
{
    int ma = arr[0];

    for (int i = 0; i < 5;i++)
    {
        if (ma < arr[i])
        {
            ma = arr[i];
        }
    }

    return ma;
}
//Copyright ©2021-2099 HaoranSun. All rights reserved