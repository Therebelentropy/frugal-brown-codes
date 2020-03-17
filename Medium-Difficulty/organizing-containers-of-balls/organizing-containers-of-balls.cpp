#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> container(n);
        vector<long int> bucket_size(n,0);
        vector<long int> ball_count(n,0);

        for (int i = 0; i < n; i++) {
            container[i].resize(n);

            for (int j = 0; j < n; j++) {
                cin >> container[i][j];
                bucket_size[i]+=container[i][j];
                ball_count[j]+=container[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        sort(bucket_size.begin(), bucket_size.end());
        sort(ball_count.begin(), ball_count.end());
        if(bucket_size==ball_count)
            printf("Possible\n");
        else 
            printf("Impossible\n");

        
    }
    return 0;
}