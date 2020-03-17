#include <bits/stdc++.h>

using namespace std;

// Complete the formingMagicSquare function below.
int formingMagicSquare(vector<vector<int>> s) {
    int mag[]={8,3,4,9,2,7,6,1};
    //mag[0]=s[0][0];
    int cost_min=64;
    int a[]={s[0][0],s[0][1],s[0][2],s[1][2],s[2][2],s[2][1],s[2][0],s[1][0]};
    for(int i=0;i<8;i+=2)
    {
        int cost=0;
        for(int j=0;j<8;j++)
            cost+=abs(mag[j]-a[(j+i)%8]);
        if(cost<cost_min)
            cost_min=cost;
    }

    for(int i=0;i<8;i+=2)
    {
        int cost=0;
        for(int j=0;j<8;j++)
            cost+=abs(mag[(8-j)%8]-a[(j+i)%8]);
        if(cost<cost_min)
            cost_min=cost;
    }
    cost_min+=abs(s[1][1]-5);
    return cost_min;
}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);
    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> s[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = formingMagicSquare(s);

    cout << result << "\n";

    return 0;
}
