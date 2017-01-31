#define N 5 /* or any other number of points */


void Spline(double x[N+1],double y[N+1], // input
            double A[N],double B[N],     // output
            double C[N],double D[N])     // output
{
    double w[N];
    double h[N];
    double ftt[N+1];

    for (int i=0; i<N; i++)
    {
        w[i] = (x[i+1]-x[i]);
        h[i] = (y[i+1]-y[i])/w[i];
    }

    ftt[0] = 0;
    for (int i=0; i<N-1; i++)
        ftt[i+1] = 3*(h[i+1]-h[i])/(w[i+1]+w[i]);
    ftt[N] = 0;

    for (int i=0; i<N; i++)
    {
        A[i] = (ftt[i+1]-ftt[i])/(6*w[i]);
        B[i] = ftt[i]/2;
        C[i] = h[i]-w[i]*(ftt[i+1]+2*ftt[i])/6;
        D[i] = y[i];
    }
}


void PrintSpline(double x[N+1],           // input
                 double A[N],double B[N], // input
                 double C[N],double D[N]) // input
{
    for (int i=0; i<N; i++)
    {
        printf("%f <= x <= %f : f(x) = ",x[i],x[i+1]);
        printf("%f(x-%f)^3 + ",A[i],x[i]);
        printf("%f(x-%f)^2 + ",B[i],x[i]);
        printf("%f(x-%f) + "  ,C[i],x[i]);
        printf("%f\n"         ,D[i]);
    }
}
