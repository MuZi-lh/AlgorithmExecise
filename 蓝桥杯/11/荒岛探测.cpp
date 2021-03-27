#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int N = 1e5 + 5;
struct point {
    double x, y;
    bool operator<(const point& a) {
        return x < a.x;
    }
    point operator-(const point& a) {
        point k;
        k.x = x - a.x;k.y = y - a.y;
        return k;
    }
    point() { x = 0, y = 0; }
};
point P1, P2, R[3];
double A[3], B[3], a, b, c;
void Rjd(int a, int b, point& m1, point& m2, double x) {//�������ε�y1,y2 
    if (fabs(B[a]) < 1e-6 || fabs(B[b]) < 1e-6) {//��ֱ
        m1.y = min(R[a].y, R[b].y);
        m2.y = max(R[a].y, R[b].y);
        return;
    }
    m1.y = (1 - A[a] * x) / B[a];
    m2.y = (1 - A[b] * x) / B[b];
    if (m1.y > m2.y)swap(m1, m2);
}

void TY(double x, point& m1, point& m2) {//������Ϊxʱ����y1,y2  (x+a^2/c)/p=a/c  p�Ǻ�����Ϊx��ɨ��������Բ�Ľ��㵽��Բ�󽹵�ľ��� y2=sqrt(p^2-(x+c)^2) 
    double p = (x * c / a + a);
    m2.y = sqrt(p * p - (x + c) * (x + c));
    m1.y = -m2.y;
}

int main() { //�������������������Ե��壬��CAD��ͼ�õ��Ĵ�2279.7457�����Ը��Ĵ���2486.14���ҵĴ�����ͼ��һ�¡���ֻ��70%��ʣ���������Ե㻹δ��֤Ӧ��Ҳ�Ǵ����� 
    int L;
    cin >> P1.x >> P1.y >> P2.x >> P2.y >> L;
    cin >> R[0].x >> R[0].y >> R[1].x >> R[1].y >> R[2].x >> R[2].y;//�����ؽ�����ϵ��ʹ������x�� 

    if (P1.x > P2.x)swap(P1, P2);
    c = (P1.x - P2.x) * (P1.x - P2.x) + (P1.y - P2.y) * (P1.y - P2.y);
    c = sqrt(c) / 2;//�뽹�� 
    a = L / 2;
    b = sqrt(a * a - c * c);// x^2/a^2+y^2/b^2=1 

    //double tA1, tB1, tC1 = 1;//������ֱ�� tA1*x+tB1*y=1 
    //tA1 = (P2.y - P1.y) / (P1.x * P2.y - P1.y * P2.x);
    //tB1 = (P1.x - P2.x) / (P1.x * P2.y - P1.y * P2.x);
    point O;//��ԭ�� 
    O.x = (P1.x + P2.x) / 2;O.y = (P1.y + P2.y) / 2;
    for (int i = 0;i < 3;i++)R[i] = R[i] - O;//���������ζ������λ�� 
    P2 = P2 - O;

    double dx = -P2.y;
    double sina = dx / c;//��������ʱ����תa�� ������Ϊ x=Xcosa-Ysina y=Xsina+Ycosa
    double cosa = sqrt(c * c - dx * dx) / c;

    P1.x = -c;P1.y = 0;
    P2.x = c;P2.y = 0;
    for (int i = 0;i < 3;i++) {
        point temp = R[i];
        R[i].x = temp.x * cosa - temp.y * sina;
        R[i].y = temp.x * sina + temp.y * cosa;
    }//���е������� 

    sort(R, R + 3);

    A[2] = (R[2].y - R[1].y) / (R[1].x * R[2].y - R[1].y * R[2].x);//ֱ�߷���A*x+B*y=1; 
    if (fabs(R[1].x - R[2].x) < 1e-6)B[2] = 0;
    else B[2] = (R[1].x - R[2].x) / (R[1].x * R[2].y - R[1].y * R[2].x);
    A[1] = (R[2].y - R[0].y) / (R[0].x * R[2].y - R[0].y * R[2].x);
    if (fabs(R[2].x - R[0].x) < 1e-6)B[1] = 0;
    else B[1] = (R[0].x - R[2].x) / (R[0].x * R[2].y - R[0].y * R[2].x);
    A[0] = (R[0].y - R[1].y) / (R[1].x * R[0].y - R[1].y * R[0].x);
    if (fabs(R[1].x - R[0].x) < 1e-6)B[0] = 0;
    else B[0] = (R[1].x - R[0].x) / (R[1].x * R[0].y - R[1].y * R[0].x);

    double sum = 0;
    double l = max(R[0].x, -a), r = min(R[2].x, a);
    for (double i = l;i < r;i += 0.001) {
        point m1, m2, m3, m4;
        if (i < R[1].x) {
            Rjd(0, 1, m1, m2, i);
        }
        else {
            Rjd(2, 1, m1, m2, i);
        }

        TY(i, m3, m4);
        if (m1.y > m3.y)m3.y = m1.y;
        if (m2.y < m4.y)m4.y = m2.y;
        if (m3.y < m4.y)sum += (m4.y - m3.y) * 0.001;//����ص�������� 

    }
    printf("%.2lf\n", sum);
    return 0;
}
