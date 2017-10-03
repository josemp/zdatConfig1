
/******************************************/
/*  Estructuras de la tabla motFaltas  */ 
/******************************************/

/* Tabla ped */

typedef struct {  
 char ip[20+1]; 
 char puerto[6+1]; 
 char timeutConexion[6+1]; 
 char timeoutRespuesta[6+1];
} ped_t; 

/* Tabla cons */

typedef struct {  
 char ip[20+1]; 
 char puerto[6+1];
} cons_t; 

/*  Estructura de la tabla motFaltas  */ 

typedef struct { 
 char hostias[3][10+1];   
 char name[50+1];  
 ped_t ped;   
 cons_t cons;   
 char reinicio[3][7+1]; 
} motFaltas_t;

