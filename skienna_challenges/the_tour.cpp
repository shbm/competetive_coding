/*
 * Sai Cheemalapati
 * UVa 10137: The trip
 *
 */
 
#include<cstdio>
 
using namespace std;
 
int n;
double c[1010];
 
int main() {
    for(;;) {
        scanf("%d", &n);
        if(n == 0) break;
        double avg = 0;
        for(int i = 0; i < n; i++) {
            scanf("%lf", &c[i]);
            avg += c[i];
        }
        avg = avg / n;
        double pos = 0, neg = 0;
        for(int i = 0; i < n; i++) {
            double v = (long) ((c[i] - avg) * 100.0) / 100.0;
            printf("%f\n", v);
            if(v > 0) pos += v;
            else neg += v;
        }
        neg = -neg;
        printf("$%.2f\n", neg > pos? neg : pos);
    }
}
