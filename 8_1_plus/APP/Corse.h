#ifndef __CORSE_H
#define __CORSE_H
typedef struct
{
    //PID 三参数
    float Kp;
    float Ki;
    float Kd;

    float max_out;  //最大输出
    float max_iout; //最大积分输出
	float deadband;
	
	float set;
    float ref;
    float fdb;
	float lastfdb;

    float out;
    float Pout;
    float Iout;
    float Dout;
    float Dbuf[3];  //微分项 0最新 1上一次 2上上次
    float error[3]; //误差项 0最新 1上一次 2上上次

} PidTypeDef;
extern PidTypeDef Corse_pid;
extern PidTypeDef Corse_pid_issue2;
extern PidTypeDef Corse_pid_issue3;
extern PidTypeDef Corse_pid_issue4;
extern PidTypeDef Corse_pid_issue5;
extern void PID_init(PidTypeDef *pid,  const float PID[3],float deadband,float max_out, float max_iout);

extern float PID_Calc(PidTypeDef *pid,  float ref,float fdb);

#endif
