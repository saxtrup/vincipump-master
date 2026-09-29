//3. Leak detection
//Leak detection is a potentially useful software feature that will alert the user if a leak forms anywhere in the system. Such a leak could cause 
//hazardous pooling of oil and, once enough oil has been lost a resultant loss of pressure in the system, which could compromise the neutron 
//measurement. 

//The algorithm shall require knowledge of the pressure set point Pset (modbus 34), the current actual pressure Pact (modbus 10) and the current flow F 
//(modbus 6). In addition, a stabilization time Tstable, an acceptable pressure differential Pdiff and a flow threshold Fthresh shall be defined.

//The condition that the system is at the requested set point shall be:

//|Pset – Pact|<=Pdiff

//When this condition is met, a timer shall initiate and, after an elapsed time of Tstable the current flow F is queried and compared with the flow threshold. Under the condition that 

//F >= Fthresh

#include <aSubRecord.h>
#include <registryFunction.h>
#include <epicsExport.h>
#include <stdio.h>
#include <stdlib.h>
//=============================================================================
static long asub_timer(aSubRecord *precord) {
    
    static int counter = 5;

    int   timer_init  = *(int*)precord->a;
    float p_set       = *(float*)precord->b;
    float p_act       = *(float*)precord->c;
    float flow        = *(float*)precord->d;
    float threshold   = *(float*)precord->e;
    float p_diff      = *(float*)precord->f;         

    int   leak_error = 0;

    float a = abs(p_set - p_act);
    //printf("p_diff:%f abs(p_set-p_act): %f, counter: %u\n", p_diff, a, counter );
    if( p_diff >= abs(p_set - p_act) ){
       if(counter > 0)
          counter--;
    }
    else
        counter = timer_init;


    *(int *)precord->vala = counter;

    //printf("counter:%d \n", counter);
    
    if(counter == 0) {
        if( flow >= threshold ){
           leak_error = 1; // there is a leak
           printf("error:%i \n", leak_error);
        }
        else{ 
           leak_error = 0; // no leak
        }
    }
    *(int *)precord->valb = leak_error;
return 0;
}


epicsRegisterFunction(asub_timer);
