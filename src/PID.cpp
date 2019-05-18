#include "PID.h"
#include <vector>
#include <numeric>

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

 double arraySum(std::vector<double> &v) {
     double initial_sum  = 0.0;
     return std::accumulate(v.begin(), v.end(), initial_sum);
 }


PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */

    PID::Kp = Kp_;
    PID::Ki = Ki_;
    PID::Kd = Kd_;

    PID::p_err = 0.0;
    PID::i_err = 0.0;
    PID::d_err = 0.0;
    PID::prev_cte = 0.0;

}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */

     // Proportional part
     PID::p_err = cte;

     // Integral part
     PID::i_err += cte;

     // Differential part
     PID::d_err = cte - PID::prev_cte;

     PID::prev_cte = cte;
}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */

  return PID::p_err * PID::Kp + PID::i_err * PID::Ki + PID::d_err * PID::Kd;

}
