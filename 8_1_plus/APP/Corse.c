#include "Corse.h"
#include "math.h"
float test_p = 15.0f;
PidTypeDef Corse_pid = {10.0f, 0.0f, 0.0f, 
						300.0f, 200.0f, 0.0f,
						0.0f, 0.0f, 0.0f, 0.0f, 
						0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };
PidTypeDef Corse_pid_issue2= {9.0f, 0.0f, 0.0f, 
						300.0f, 200.0f, 0.0f,
						0.0f, 0.0f, 0.0f, 0.0f, 
						0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };
PidTypeDef Corse_pid_issue3= {9.0f, 0.0f, 0.0f, 
						300.0f, 200.0f, 0.0f,
						0.0f, 0.0f, 0.0f, 0.0f, 
						0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };
PidTypeDef Corse_pid_issue4 = {9.0f, 0.0f, 0.0f, 
						300.0f, 200.0f, 0.0f,
						0.0f, 0.0f, 0.0f, 0.0f, 
						0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };
PidTypeDef Corse_pid_issue5 = {10.5f, 0.0f, 0.0f, 
						300.0f, 200.0f, 0.0f,
						0.0f, 0.0f, 0.0f, 0.0f, 
						0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };

#define LimitMax(input, max)   \
    {                          \
        if (input > max)       \
        {                      \
            input = max;       \
        }                      \
        else if (input < -max) \
        {                      \
            input = -max;      \
        }                      \
    }

void PID_init(PidTypeDef *pid,  const float PID[3],float deadband,float max_out, float max_iout)
{
   
	pid->deadband = deadband;
	
    pid->Kp = PID[0];
    pid->Ki = PID[1];
    pid->Kd = PID[2];
    pid->max_out = max_out;
    pid->max_iout = max_iout;
    pid->Dbuf[0] = pid->Dbuf[1] = pid->Dbuf[2] = 0.0f;
    pid->error[0] = pid->error[1] = pid->error[2] = pid->Pout = pid->Iout = pid->Dout = pid->out = 0.0f;
}

float PID_Calc(PidTypeDef *pid, float ref, float set)
{
   
    pid->error[2] = pid->error[1];
    pid->error[1] = pid->error[0];
    pid->set = set;
    pid->fdb = ref;
    pid->error[0] = set - ref;
   
	if(pid->error[0] < -180.0f)
		pid->error[0] = pid->error[0] + 360.0f;
	else if(pid->error[0] >180.0f)
		pid->error[0] = pid->error[0] - 360.0f;
	
	if(fabs(pid->error[0])< pid->deadband ) //ËÀÇø
			pid->error[0]=0;
	
    pid->Pout = pid->Kp * pid->error[0];
    pid->Iout += pid->Ki * pid->error[0];
    pid->Dbuf[2] = pid->Dbuf[1];
    pid->Dbuf[1] = pid->Dbuf[0];
    pid->Dbuf[0] = (pid->error[0] - pid->error[1]);
    pid->Dout = pid->Kd * pid->Dbuf[0];
    LimitMax(pid->Iout, pid->max_iout);
    pid->out = pid->Pout + pid->Iout + pid->Dout;
    LimitMax(pid->out, pid->max_out);
   
    return pid->out;
}



