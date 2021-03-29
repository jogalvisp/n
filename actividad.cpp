#include <iostream>
#include <cmath>

double f(double x);
const double m = 1.25; //masa (kg)
const double a = 0;
const double b = 7;
double energ_trap(double x0, double xf, double n);
double energ_simp(double x0, double xf, double n);
double velocidad(double E);

double simpson(double a, double b, int npart);
double trapecio(double a, double b, int npart);

int main (int argc, char *argv[])
{
  std::cout.precision(15);
  //std::cout.setf(std::ios::scientific);

  std::cout << "Velocidad calculada por trapecio (10):"<< "\t" << velocidad(energ_trap(a, b, 10)) << " m/s" << "\n";
  std::cout << "Velocidad calculada por trapecio (1000):" << "\t" << velocidad(energ_trap(a, b, 1000)) << " m/s" << "\n";
  std::cout << "Velocidad calculada por simpson (10):"<< "\t" << velocidad(energ_simp(a, b, 10)) << " m/s" << "\n";
  std::cout << "Velocidad calculada por simpson (1000):" << "\t" << velocidad(energ_simp(a, b, 1000)) << " m/s" << "\n";

  return 0;
}

double f(double x) {
  return 2*x*(std::sin(x));
}

double velocidad(double E) {
  return sqrt((std:: fabs(E))/m);
}

double energ_trap(double x0, double xf, double n) {
  return trapecio(x0, xf, n);
}

double energ_simp(double x0, double xf, double n) {
  return simpson(x0, xf, n);
}

double trapecio(double a, double b, int npart) {
  double h = (b-a)/npart;
  double result = 0.0;
  double x = 0;
  for(int ii = 1; ii <npart; ++ii) {
    x = a +ii*h;
    result += f(x);
  }
  result += 0.5*(f(a)+f(b));
  result *= h;
  return result;
}

double simpson(double a, double b, int npart) {
  double h = (b-a)/npart;
  double result = f(a) + f(b);
  double sum1 = 0.0, sum2 = 0.0;

  for(int ii = 1; ii <=npart/2 - 1; ++ii) {
    double x = a + (2*ii)*h;
    sum1 += f(x);
  }
  for(int ii = 1; ii <=npart/2; ++ii) {
    double x = a + (2*ii-1)*h;
    sum2 += f(x);
  }

  result += 2*sum1 + 4*sum2;
  result *= h/3;

  return result;
}