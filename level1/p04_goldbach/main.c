#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
/*
 * 输入一个数来拆分成三个质数之和，输出是所有解（至少我认为）
 * 100以内肯定没问题啦
 * 更大的我不想写优化（就是菜，不会写qaq）
 */
int p[1001],n,pr[1001],cnt=0;
void prime(int a){
    for(int i=a*2;i<=n;i+=a) p[i]=0;
}
int main() {
    scanf("%d",&n);
    for(int i=2;i<=n;i++) p[i]=1;
    for(int i=2;i<=n;i++)
        if(p[i]) {
            prime(i);
            pr[++cnt]=i;
        }
 //   for(int i=1;i<=cnt;i++) printf("%d ",pr[i]);
    int temp=n-4,tmp;
    if(p[temp])
        printf("2+2+%d\n",temp);
    temp=(n-3)/2;
    if(!p[temp])
        while(!p[temp])
            temp++;
    for(int i=2;i<=cnt;i++)
        if(pr[i]==temp){
            temp=i;
            break;
        }
//    printf("%d\n",temp);
    for(int i=cnt;i>=temp;i--){
        tmp=n-pr[i];
        if(tmp<=5) continue;
        for(int j=2;j<=tmp/2;j++) {
            if (tmp-pr[j]<=0) break;
            if (tmp-pr[j]<pr[j]) break;
            if (p[tmp - pr[j]])
                printf("%d+%d+%d\n", pr[i], pr[j], tmp - pr[j]);
        }
    }
    system("pause");
    return 0;
}