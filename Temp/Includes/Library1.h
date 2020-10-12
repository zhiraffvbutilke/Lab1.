/* Automation Studio generated header file */
/* Do not edit ! */
/* Library1  */

#ifndef _LIBRARY1_
#define _LIBRARY1_
#ifdef __cplusplus
extern "C" 
{
#endif

#include <bur/plctypes.h>

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif
/* Datatypes and datatypes of function blocks */
typedef struct FB_Integrator
{
	/* VAR_INPUT (analog) */
	float in;
	/* VAR_OUTPUT (analog) */
	float out;
	/* VAR (analog) */
	float dt;
} FB_Integrator_typ;

typedef struct FBMotor
{
	/* VAR_INPUT (analog) */
	float u;
	/* VAR_OUTPUT (analog) */
	float w;
	float phi;
	/* VAR (analog) */
	struct FB_Integrator integrator;
	float Tm;
	float ke;
	float dt;
} FBMotor_typ;

typedef struct FB_Regulator
{
	/* VAR_INPUT (analog) */
	float e;
	/* VAR_OUTPUT (analog) */
	float u;
	/* VAR (analog) */
	float k_p;
	float k_i;
	struct FB_Integrator integrator;
	float iyOld;
	float max_abc_value;
	float dt;
	float x;
} FB_Regulator_typ;



/* Prototyping of functions and function blocks */
_BUR_PUBLIC void FB_Integrator(struct FB_Integrator* inst);
_BUR_PUBLIC void FBMotor(struct FBMotor* inst);
_BUR_PUBLIC void FB_Regulator(struct FB_Regulator* inst);


#ifdef __cplusplus
};
#endif
#endif /* _LIBRARY1_ */

