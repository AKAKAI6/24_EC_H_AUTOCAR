#ifndef __CORSE_H
#define __CORSE_H
typedef struct
{
    //PID ������
    float Kp;
    float Ki;
    float Kd;

    float max_out;  //������
    float max_iout; //���������
	float deadband;
	
	float set;
    float ref;
    float fdb;
	float lastfdb;

    float out;
    float Pout;
    float Iout;
    float Dout;
    float Dbuf[3];  //΢���� 0���� 1��һ�� 2���ϴ�
    float error[3]; //����� 0���� 1��һ�� 2���ϴ�

} PidTypeDef;
extern PidTypeDef Corse_pid;
extern PidTypeDef Corse_pid_issue2;
extern PidTypeDef Corse_pid_issue3;
extern PidTypeDef Corse_pid_issue4;
extern PidTypeDef Corse_pid_issue5;
extern void PID_init(PidTypeDef *pid,  const float PID[3],float deadband,float max_out, float max_iout);

extern float PID_Calc(PidTypeDef *pid,  float ref,float fdb);

#endif
