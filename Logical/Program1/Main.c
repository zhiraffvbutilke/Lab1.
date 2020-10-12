
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _INIT ProgramInit(void)
{
	
	FB_Integrator_var.in = 0;
	FB_Integrator_var.out = 0;
	FB_Integrator_var.dt = 0.002;
	FBMotor_var.u = 0;
	FBMotor_var.w = 0 ;
	FBMotor_var.ke = 0.16*FB_Integrator_var.dt*3 ;
	FBMotor_var.Tm = (0.0064*FB_Integrator_var.dt*3)/FBMotor_var.ke;
	FBMotor_var.phi = 0;
	FBMotor_var.dt = FB_Integrator_var.dt;	
	FB_Regulator_var.e = 0;
	FB_Regulator_var.u = 0;
	FB_Regulator_var.k_p = 0.0064 ;
	FB_Regulator_var.k_i = 0.16;
	FB_Regulator_var.dt = FB_Integrator_var.dt;
	FB_Regulator_var.max_abc_value = 240;
	FB_Regulator_var.iyOld = 0;
	speed = 0; 
	enable = 1;
	cnt=0;
}

void _CYCLIC ProgramCyclic(void)
{ 
	if(cnt> 25 && cnt<=85)
	{
		speed = 45;
	}
	else
		speed = 0;
	if(cnt>85)
		cnt=0;
	cnt++;

	FB_Regulator_var.e = speed - FBMotor_var.w;
	FB_Regulator(&FB_Regulator_var);
	FBMotor_var.u = FB_Regulator_var.u;
	FBMotor(&FBMotor_var);	
	/*
	FBMotor_var.u = speed * FBMotor_var.ke;
	FBMotor(&FBMotor_var);*/
	
}

void _EXIT ProgramExit(void)
{

}

