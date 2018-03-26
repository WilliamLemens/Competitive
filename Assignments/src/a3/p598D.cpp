#include <bits/stdc++.h>

#define ALL(x) x.begin(), x.end()
#define MAXX 1005
#define MAXY 1005

using namespace std;

typedef long long int LL;

int n,m,k;
char matrix [MAXY][MAXX];
int sol [MAXY][MAXX];
bool visited [MAXY][MAXX];
vector<pair<int,int> > add;

int dfs(int x, int y)
{
    visited[y][x] = true;
    add.push_back(make_pair(x,y));
    int sum = 0;
    for(int i = -1; i <=1; i +=2){
        if(y+i >= 0 and y+i < n){
            if(matrix[y+i][x] == '*')
                sum++;
            else if(matrix[y+i][x] == '.' and !visited[y+i][x])
                sum += dfs(x,y+i);
        }
        if(x+i >= 0 and x+i < m){
            if(matrix[y][x+i] == '*')
                sum++;
            else if(matrix[y][x+i] == '.' and !visited[y][x+i])
                sum += dfs(x+i,y);
        }
    }
    return sum;
}

void putvalue(int value)
{
    for(int i = 0; i < add.size(); ++i)
        sol[add[i].second][add[i].first] = value;
    add.clear();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;

    for(int n=0; n<N; n++)
        for(int m = 0; m < M; m++) {
            cin >> matrix[n][m];
        }

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            if(matrix[i][j] != '*' and !visited[i][j])
                putvalue(dfs(j,i));




    for(int i = 0; i < k; ++i){
        int a,b;
        cin >> a >> b; a--; b--;
        cout << sol[a][b] << '\n';
    }

    return 0;
}
