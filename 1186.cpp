#include <iostream>
#include <cstring>
using namespace std;
char test[103];
char test2[103];
char outM[2][4] = {"==", "!="};
char chem[101][3], chem2[101][3];
int chemCount[101], chemCount2[101];
int chemNum = 0, chemNum2;
int i, j, k, t, s, x, y, minusNum, beforeNum, afterNum, tmpNum;
char tmpChem[3];
char tmpF;
int main()
{
    cin >> test;
    t = strlen(test);
    for (i = 0; i < t; i++)
    {
        tmpF = test[i];
        if (tmpF >= 'A' && tmpF <= 'Z')
        {
            tmpChem[0] = tmpF;
            j = 1;
            tmpF = test[i + 1];
            if (tmpF >= 'a' && tmpF <= 'z')
            {
                tmpChem[j] = tmpF;
                j++;
            }
            tmpChem[j] = '\0';
            for (j = 0; j < chemNum; j++)
            {
                if (strcmp(tmpChem, chem[j]) == 0)
                {
                    break;
                }
            }
            if (j == chemNum)
            {
                memcpy(chem[chemNum], tmpChem, strlen(tmpChem) + 1);
                chemCount[chemNum] = 0;
                chemNum++;
            }
            minusNum = 1;
            //4Si->4
            for (k = i - 1; k >= 0; k--)
            {
                if (test[k] == '+')
                {
                    break;
                }
            }
            k++;
            tmpNum = 0;
            while (test[k] >= '0' && test[k] <= '9')
            {
                tmpNum = 10 * tmpNum + (test[k] - '0');
                k++;
            }
            if (tmpNum == 0)
            {
                tmpNum = 1;
            }
            minusNum *= tmpNum;
            //(Si)43->43
            beforeNum = 0;
            afterNum = 0;
            k = i + 1;
            while (test[k] != '+' && test[k] != '\0')
            {
                if (test[k] == '(')
                {
                    beforeNum++;
                    k++;
                }
                else if (test[k] == ')')
                {
                    afterNum++;
                    //cout << tmpChem << " " << beforeNum << " " << afterNum << endl;
                    if (afterNum > beforeNum)
                    {
                        k++;
                        tmpNum = 0;
                        while (test[k] >= '0' && test[k] <= '9')
                        {
                            tmpNum = 10 * tmpNum + (test[k] - '0');
                            k++;
                        }
                        if (tmpNum == 0)
                        {
                            tmpNum = 1;
                        }
                        minusNum *= tmpNum;
                    }
                    else
                    {
                        k++;
                    }
                }
                else
                {
                    k++;
                }
            }
            //Si78->78
            k = i + 1;
            tmpNum = 0;
            while (test[k] >= '0' && test[k] <= '9')
            {
                tmpNum = 10 * tmpNum + (test[k] - '0');
                k++;
            }
            if (tmpNum == 0)
            {
                tmpNum = 1;
            }
            minusNum *= tmpNum;
            //+minusNum
            chemCount[j] += minusNum;
        }
    }
    cin >> s;
    for (x = 0; x < s; x++)
    {
        y = 0; //outM default
        chemNum2 = 0;
        cin >> test2;
        t = strlen(test2);
        for (i = 0; i < t; i++)
        {
            tmpF = test2[i];
            if (tmpF >= 'A' && tmpF <= 'Z')
            {
                tmpChem[0] = tmpF;
                j = 1;
                tmpF = test2[i + 1];
                if (tmpF >= 'a' && tmpF <= 'z')
                {
                    tmpChem[j] = tmpF;
                    j++;
                }
                tmpChem[j] = '\0';
                for (j = 0; j < chemNum2; j++)
                {
                    if (strcmp(tmpChem, chem2[j]) == 0)
                    {
                        break;
                    }
                }
                if (j == chemNum2)
                {
                    memcpy(chem2[chemNum2], tmpChem, strlen(tmpChem) + 1);
                    chemCount2[chemNum2] = 0;
                    chemNum2++;
                }
                minusNum = 1;
                //4Si->4
                for (k = i - 1; k >= 0; k--)
                {
                    if (test2[k] == '+')
                    {
                        break;
                    }
                }
                k++;
                tmpNum = 0;
                while (test2[k] >= '0' && test2[k] <= '9')
                {
                    tmpNum = 10 * tmpNum + (test2[k] - '0');
                    k++;
                }
                if (tmpNum == 0)
                {
                    tmpNum = 1;
                }
                minusNum *= tmpNum;
                //(Si)43->43
                beforeNum = 0;
                afterNum = 0;
                k = i + 1;
                while (test2[k] != '+' && test2[k] != '\0')
                {
                    if (test2[k] == '(')
                    {
                        beforeNum++;
                        k++;
                    }
                    else if (test2[k] == ')')
                    {
                        afterNum++;
                        if (afterNum > beforeNum)
                        {
                            k++;
                            tmpNum = 0;
                            while (test2[k] >= '0' && test2[k] <= '9')
                            {
                                tmpNum = 10 * tmpNum + (test2[k] - '0');
                                k++;
                            }
                            if (tmpNum == 0)
                            {
                                tmpNum = 1;
                            }
                            minusNum *= tmpNum;
                        }
                        else
                        {
                            k++;
                        }
                    }
                    else
                    {
                        k++;
                    }
                }
                //Si78->78
                k = i + 1;
                tmpNum = 0;
                while (test2[k] >= '0' && test2[k] <= '9')
                {
                    tmpNum = 10 * tmpNum + (test2[k] - '0');
                    k++;
                }
                if (tmpNum == 0)
                {
                    tmpNum = 1;
                }
                minusNum *= tmpNum;
                //+minusNum
                chemCount2[j] += minusNum;
            }
        }
        if (chemNum != chemNum2)
        {
            y = 1;
            //cout << "xxx" << endl;
        }
        else
        {
            for (i = 0; i < chemNum2; i++)
            {
                for (j = 0; j < chemNum; j++)
                {
                    if (strcmp(chem2[i], chem[j]) == 0)
                    {
                        //cout << "====" << endl;
                        if (chemCount2[i] != chemCount[j])
                        {
                            y = 1;
                            //cout << "yyy" << endl;
                        }
                        break;
                    }
                }
                if (y == 1)
                {
                    break;
                }
                if (j == chemNum)
                {
                    y = 1;
                    //cout << "zzz" << endl;
                    break;
                }
            }
        }
        cout << test << outM[y] << test2 << endl;
    }
    return 0;
}