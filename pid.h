#ifndef __PID_H
#define __PID_H

#define PRESENT 2
#define LAST	1
#define BEFORE	0

typedef struct
{
	float target;
	float integral;
	float Kp;	
	float Ki;	
	float Kd;	
}PID_ANGLGE;

typedef struct
{
	float kp;//����ϵ��
	float ki;//����ϵ��
	float kd;//΢��ϵ��
	float target;//PIDĿ��
	float lastcontrol;//���µ��������ֵ
	float enote[3];//����¼
	double sumerr;
}PID_SPEED;

void PID_angle_init(PID_ANGLGE *pid, unsigned int Kp, unsigned int Ki, unsigned int Kd, unsigned int target);
int PID_Proc(PID_ANGLGE *pid, float current, float differential);

void PID_speed_init(PID_SPEED *pid,float kp,float ki,float kd,int target);
int PID_Inc(PID_SPEED *pid, int fbv);

#endif