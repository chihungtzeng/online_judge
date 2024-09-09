#include <stdio.h>
#include <stdlib.h>

#define N       1000000000
#define SIZE    47
#define MAXINT  10

int  F[SIZE][MAXINT];    /* F(n) = 4^n */
int  C[SIZE][MAXINT];    /* C(n) = 4 * (2n)!/(n!*n!) */

void mpNum2Str(char *str, int *num);
void mpSub(int *ret, int *a, int *b);
void mpMul(int *ret, int *a, int *b);
int  mpDiv(int *q, int *r, int *za, int *zb);

int main(){
  int  i;
  int  n, n2;
  int  t[2], t1[MAXINT], t2[MAXINT];
  int  ans[MAXINT];
  char buf[100];
  int  cno, cmax;

/*
 * calc F(n), C(n) table
 */
  F[0][0] = 1, F[0][1] = 1;      /* F(0) = 1 */
  t[0] = 1, t[1] = 4;            /* t = 4 */
  for (i = 1; i < SIZE; i++)
    mpMul(F[i], F[i-1], t);      /* F(n) = F(n-1) * t */ 

  C[0][0] = 1, C[0][1] = 4;      /* C(0) = 4 */
  for (i = 1; i < SIZE; i++) {
    t[1] = 2*(2*i-1);            /* t = 2*(2n-1) */
    mpMul(t1, C[i-1], t);        /* t1 = C(n-1) * t */
    t[1] = i;                    /* t = n */
    mpDiv(C[i], t2, t1, t);      /* C(n) = t1/t = C(n-1)*2*(2n-1)/n */
  }

/*
 * OK, let's go
 */
  fgets(buf, 100, stdin);
  cmax = atoi(buf);
  for (cno = 1; cno <= cmax; cno++) {
    printf("Case #%d: ", cno);
    fgets(buf, 100, stdin);
    n2 = atoi(buf);
    if ((n2 & 1) || n2 < 4) { puts("0"); continue; }
    if (n2 == 4) { puts("1"); continue; }
    if (n2 == 6) { puts("2"); continue; }
    n2 -= 8, n = n2/2;           /* n = (n2-8)/2 */
    t[0] = 1, t[1] = n2+11;      /* t = n2+11 */
    mpMul(t1, t, F[n]);          /* t1 = t * F(n) = (n2+11) * F(n) */
    t[1] -= 10;                  /* t = n2+1 */
    mpMul(t2, t, C[n]);          /* t2 = t * C(n) = (n2+1) * C(n) */
    mpSub(ans, t1, t2);          /* answer = t1 - t2                  */
    mpNum2Str(buf, ans);         /*        = (n2+11)*F(n)-(n2+1)*C(n) */
    puts(buf);
  }
  return 0;
}

void mpNum2Str(char *str, int *num)
{
    int  i, j;
    char *ss;
    int  x;

    if (*num == 0 || (*num == 1 && *(num+1) == 0)) {
        *str++ = '0';
        *str = '\0';
        return;
    }

    ss = str - 1;
    for (i = *num; i > 0; i--) {
        x = *++num;
        for (j = 1; j < N; j *= 10) {
            *++ss = x % 10 + '0';
            x /= 10;
        }
    }
    while (*ss == '0') ss--;

    *(ss + 1) = '\0';    
    while (str < ss) {
        x = *str;
        *str++ = *ss;
        *ss-- = x;
    }
}

void mpSub(int *ret, int *a, int *b)
{
    int  i;
    int  la, lb;
    int  *rr;
    int  x;

    la = *a;
    lb = *b;

    rr = ret;
    x = 0;
    for (i = 1; i <= la; i++) {
        x += *++a;
        if (i <= lb) x -= *++b;
        if (x >= 0) {
            *++rr = x;
            x = 0;
        } else {
            *++rr = x + N;
            x = -1;
        }
    }
    while (--i > 0)
        if (*rr-- != 0) break;
    *ret = i;
}

void mpMul(int *ret, int *a, int *b)
{
    int  i, j;
    int  la, lb;
    int  *aa;
    int  ca;
    long long x;

    la = *a;
    lb = *b;

    if (la == 0 || lb == 0) {
        *ret = 0;
        return;
    }

    for (i = la + lb; i > 0; i--) *(ret + i) = 0;

    for (j = 1; j <= lb; j++) {
        ca = 0;
        b++;
        for (i = 1, aa = a; i <= la; i++) {
            x = *++aa;
            x = x * *b + *(ret + i + j - 1) + ca;
            *(ret + i + j - 1) = x % N;
            ca = x / N;
        }
        *(ret + i + j - 1) = ca;
    }
    
    *ret = (ca != 0) ? la + lb : la + lb - 1;
}

int mpDiv(int *q, int *r, int *za, int *zb)
{
    int  i;
    int  m, n;
    int  *aa, *bb, *qq, *rr, *t;
    int  ca;
    long long x;
    int  k, Q;
    static int atmp[MAXINT], btmp[MAXINT];
    int  *a = atmp, *b = btmp;

    *q = 0, *r = 0;
    if (*zb == 0) return -2;
    if (*za == 0) return 0;

    if (*za < *zb) {
        for (aa = za, rr = r, i = *za; i >= 0; i--) *rr++ = *aa++; 
        return 0;
    }
    
    if (*zb == 1) {
        *q = *za;
        zb++;
        for (ca = 0, aa = za + *za, qq = q + *q, i = *za; i > 0; i--) {
            x = (long long)N * ca + *aa--;
            *qq-- = x / *zb, ca = x % *zb;
        }
        if (*(q + *q) == 0) (*q)--;
        if (ca > 0) {
            *r++ = 1;
            *r = ca;
        } else *r = 0;
        return 0;
    }

    for (aa = a, i = *za; i >= 0; i--) *aa++ = *za++; 
    for (bb = b, i = *zb; i >= 0; i--) *bb++ = *zb++; 

    if ((k = (N/2-1) / *(b + *b) + 1) > 1) {
        for (ca = 0, aa = a, qq = q, i = 0; i < *a; i++) {
            x = (long long)k * *++aa + ca;      /* a = a * k */
            *++qq = x % N, ca = x / N;
        }
        *++qq = ca;
        *q = i + (ca > 0);
        for (qq = q, aa = a, i = *q; i >= 0; i--) *aa++ = *qq++;

        for (ca = 0, bb = b, qq = q, i = 0; i < *b; i++) {
            x = (long long)k * *++bb + ca;      /* b = b * k */
            *++qq = x % N, ca = x / N;
        }
        *++qq = ca;
        *q = i + (ca > 0);
        for (qq = q, bb = b, i = *q; i >= 0; i--) *bb++ = *qq++;
    }

    *q = *a - *b + 1;
    for (qq = q, i = *q; i > 0; i--) *++qq = 0;
    n = *b;
    while ((m = *a) >= n) {
        if (*(a + *a) >= *(b + *b)) {
            for (aa = a + *a, bb = b + *b; bb != b; aa--, bb--) 
                if (*aa != *bb) break;
            if (bb == b) {
                *a -= *b;
                *(q + m - n + 1) = 1;
                continue;
            } else if (*aa > *bb) {
                for (t = bb, ca = 0, aa = a + m - n, bb = b; bb < t; ) {
                    *++aa -= *++bb + ca;
                    ca = 0;
                    if (*aa < 0) *aa += N, ca = 1;
                }
                while (*aa == 0) aa--;
                *a = aa - a;
                *(q + m - n + 1) = 1;
                continue;
            }
            Q = N - 1;
        } else Q = ((long long)N * *(a + *a) + *(a + *a - 1)) / *(b + *b);
        if (m == n) break;
        
        for ( ; ; ) {
            if (Q == 1) {
                *(b + *b + 1) = 0;
                for (ca=0, aa=a+(*a - *b-1), bb=b, i= *b; i >= 0; i--) {
                    *++aa -= *++bb + ca;
                    ca = 0;
                    if (*aa < 0) *aa += N, ca = 1;
                }
                while (*aa == 0) aa--;
                *a = aa - a;
                break;
            }
            for (ca = 0, rr = r, bb = b, i = 0; i < *b; i++) {
                x = (long long)Q * *++bb + ca;
                *++rr = x % N, ca = x / N;
            }
            *++rr = ca;
            *r = i + 1;
            for (aa = a + *a, rr = r + *r; rr != r; aa--, rr--)
                if (*aa != *rr) break;
            if (rr == r) {
                *a -= *r;
                break;
            } else if (*aa > *rr) {
                for (t = rr, ca = 0, aa = a + (*a - *r), rr = r; rr < t; ) {
                    *++aa -= *++rr + ca;
                    ca = 0;
                    if (*aa < 0) *aa += N, ca = 1;
                }
                while (*aa == 0) aa--;
                *a = aa - a;
                break;
            } else Q--;
        }
        *(q + m - n) = Q;
    }
    if (*(q + *q) == 0) (*q)--;
    
    if (k > 1) {
        for (ca = 0, aa = a + *a, rr = r + *a, i = *a; i > 0; i--) {
            x = (long long)N * ca + *aa--;
            *rr-- = x / k, ca = x % k;
        }
        *r = *a - (*(r + *a) == 0);
    } else for (aa = a, rr = r, i = *a; i >= 0; i--) *rr++ = *aa++; 

    return 0;
}
