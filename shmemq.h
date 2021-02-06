#include <stdbool.h>

#ifndef SHMEMQ_H
#define SHMEMQ_H

typedef struct _shmemq shmemq_t;

#define SHMQUEUE_MAX_COUNT 500u
#define SHMQUEUE_MSG_LEN   7u

#define ADAPTIVE_MUTEX 1

typedef char shm404_msg_t[SHMQUEUE_MSG_LEN];

#define SHM_CLEAR {'C',0,0,0,0,0,0}

#define SHM_ADD_MOTOR       {'A','M',0,0,0,0,0}
#define SHM_SET_MOTOR_ID    {'M','0','L',0,0,0,0}
#define SHM_SET_MOTOR_SIMPLE {'M','0','S',0,0,0,0}
#define SHM_SET_MOTOR_USTEPS {'M','0','U',0,0,0,0}
#define SHM_SET_MOTOR_MSTEPS {'M','0','X',0,0,0,0}
#define SHM_SET_MOTOR_SPOS  {'M','0','P',0,0,0,0}
#define SHM_SET_MOTOR_EN  {'M','0','E',0,0,0,0}

#define SHM_ADD_INDICATOR   {'A','I',0,0,0,0,0}
#define SHM_SET_INDICATOR   {'I','0','V',0,0,0,0}
#define SHM_SET_IND_COLOUR  {'I','0','C',0,0,0,0}


// Creates the new queue for the "consumer" side
shmemq_t* shmemq_create(char const* name);
// Only opens an existing queue, does not create it. 
shmemq_t* shmemq_open(char const* name);

bool shmemq_try_enqueue(shmemq_t* self, shm404_msg_t* element);
bool shmemq_try_dequeue(shmemq_t* self, shm404_msg_t* element);
void shmemq_destroy(shmemq_t* self, int unlink); 

#endif
