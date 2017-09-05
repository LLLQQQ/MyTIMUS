#include <iostream>
using namespace std;
int n, m, q;
int groupNum = 0; //the num of groups;
int countRealNum[100010];
int toNodes[200010];
int color[100010];
int startPoint[100010];
int group[100010];			//a list to save the nodes with the same color
int groupConfig[100010][3]; //0:where to start;1:where to end;2:the num of one group;
int isRead[100010];
int thds[100010][3];
int tear[100010];
int changeGroup[100010];
int countFromNode[100010];
int addToGroup(int fa)
{
	int i, j, k = color[fa];
	for (i = 0; i < countRealNum[fa]; i++)
	{
		j = toNodes[startPoint[fa] + i];
		if (isRead[j] == 0)
		{
			color[j] = k;
			isRead[j] = 1;
			group[groupConfig[k][1]] = j;
			groupConfig[k][1] = j;
			groupConfig[k][2]++;
			addToGroup(j);
		}
	}
	return 0;
}
int changeAll(int a, int b)
{
	//change a'color to b'color;b'num>=a'num
	int i = color[a], j = color[b];
	int k = groupConfig[i][0];
	color[k] = j;
	while (group[k] != 0)
	{
		k = group[k];
		color[k] = j;
	}
	groupConfig[j][2] += groupConfig[i][2];
	k = groupConfig[j][1];
	group[k] = groupConfig[i][0];
	groupConfig[j][1] = groupConfig[i][1];
	return 0;
}
int main()
{
	int i, j, x, y;
	for (i = 1; i <= n; i++)
	{
		countFromNode[i] = 0;
		countRealNum[i] = 0;
		group[i] = 0;
		isRead[i] = 0;
	}
	cin >> n >> m;
	for (i = 1; i <= m; i++)
	{
		cin >> thds[i][0] >> thds[i][1];
		thds[i][2] = 1;
		countFromNode[thds[i][0]]++;
		countFromNode[thds[i][1]]++;
	}
	j = 0;
	for (i = 1; i <= n; i++)
	{
		startPoint[i] = j;
		j += countFromNode[i];
	} //toNodes[startPoint[i]]
	cin >> q;
	for (i = 0; i < q; i++)
	{
		cin >> tear[i];
		thds[tear[i]][2] = 0;
	}
	for (i = 1; i <= m; i++)
	{
		if (thds[i][2] == 1)
		{
			toNodes[startPoint[thds[i][0]] + countRealNum[thds[i][0]]] = thds[i][1];
			countRealNum[thds[i][0]]++;
			toNodes[startPoint[thds[i][1]] + countRealNum[thds[i][1]]] = thds[i][0];
			countRealNum[thds[i][1]]++;
		}
	}
	for (i = 1; i <= n; i++)
	{
		if (isRead[i] == 0)
		{
			groupNum++;
			color[i] = groupNum;
			isRead[i] = 1;
			groupConfig[groupNum][0] = i;
			groupConfig[groupNum][1] = i;
			groupConfig[groupNum][2] = 1;
			addToGroup(i);
		}
	}
	changeGroup[q] = groupNum;
	for (i = q - 1; i >= 0; i--)
	{
		j = tear[i];
		x = thds[j][0];
		y = thds[j][1];
		if (color[x] == color[y])
		{
			changeGroup[i] = changeGroup[i + 1];
		}
		else
		{
			if (groupConfig[color[x]][2] < groupConfig[color[y]][2])
			{
				changeAll(x, y);
			}
			else
			{
				changeAll(y, x);
			}
			changeGroup[i] = changeGroup[i + 1] - 1;
		}
	}
	for (i = 1; i <= q; i++)
	{
		cout << changeGroup[i] << " ";
	}
	return 0;
}