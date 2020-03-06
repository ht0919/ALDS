#include<cstdio>
#include<string>
#include<queue>
using namespace std;

int main() {
    char com[20];
    // 標準ライブラリの priority_queue を使用
    priority_queue<int> PQ;

    while ( 1 ) {
        scanf("%s", com);
        if ( com[0] == 'i' ) {
            int key; scanf("%d", &key); // cin より高速な scanf を使用
            PQ.push(key);
        } else if ( com[1] == 'x' ) {
            printf("%d\n", PQ.top());
            PQ.pop();
        } else if ( com[0] == 'e' ) {
            break;
        }
    }

    return 0;
}