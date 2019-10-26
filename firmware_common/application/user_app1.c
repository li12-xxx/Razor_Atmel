/**********************************************************************************************************************
File: user_app1.c                                                                

----------------------------------------------------------------------------------------------------------------------
To start a new task using this user_app1 as a template:
 1. Copy both user_app1.c and user_app1.h to the Application directory
 2. Rename the files yournewtaskname.c and yournewtaskname.h
 3. Add yournewtaskname.c and yournewtaskname.h to the Application Include and Source groups in the IAR project
 4. Use ctrl-h (make sure "Match Case" is checked) to find and replace all instances of "user_app1" with "yournewtaskname"
 5. Use ctrl-h to find and replace all instances of "UserApp1" with "YourNewTaskName"
 6. Use ctrl-h to find and replace all instances of "USER_APP1" with "YOUR_NEW_TASK_NAME"
 7. Add a call to YourNewTaskNameInitialize() in the init section of main
 8. Add a call to YourNewTaskNameRunActiveState() in the Super Loop section of main
 9. Update yournewtaskname.h per the instructions at the top of yournewtaskname.h
10. Delete this text (between the dashed lines) and update the Description below to describe your task
----------------------------------------------------------------------------------------------------------------------

Description:
This is a user_app1.c file template 

------------------------------------------------------------------------------------------------------------------------
API:

Public functions:


Protected System functions:
void UserApp1Initialize(void)
Runs required initialzation for the task.  Should only be called once in main init section.

void UserApp1RunActiveState(void)
Runs current task state.  Should only be called once in main loop.


**********************************************************************************************************************/

#include "configuration.h"

/***********************************************************************************************************************
Global variable definitions with scope across entire project.
All Global variable names shall start with "G_UserApp1"
***********************************************************************************************************************/
/* New variables */
volatile u32 G_u32UserApp1Flags;                       /* Global state flags */


/*--------------------------------------------------------------------------------------------------------------------*/
/* Existing variables (defined in other files -- should all contain the "extern" keyword) */
extern volatile u32 G_u32SystemFlags;                  /* From main.c */
extern volatile u32 G_u32ApplicationFlags;             /* From main.c */

extern volatile u32 G_u32SystemTime1ms;                /* From board-specific source file */
extern volatile u32 G_u32SystemTime1s;                 /* From board-specific source file */


/***********************************************************************************************************************
Global variable definitions with scope limited to this local application.
Variable names shall start with "UserApp1_" and be declared as static.
***********************************************************************************************************************/
static fnCode_type UserApp1_StateMachine;            /* The state machine function pointer */
//static u32 UserApp1_u32Timeout;                      /* Timeout counter used across states */


/**********************************************************************************************************************
Function Definitions
**********************************************************************************************************************/

/*--------------------------------------------------------------------------------------------------------------------*/
/* Public functions                                                                                                   */
/*--------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------*/
/* Protected functions                                                                                                */
/*--------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------
Function: UserApp1Initialize

Description:
Initializes the State Machine and its variables.

Requires:
  -

Promises:
  - 
*/
void UserApp1Initialize(void)
{
 
  /* If good initialization, set state to Idle */
  if( 1 )
  {
    UserApp1_StateMachine = UserApp1SM_Idle;
  }
  else
  {
    /* The task isn't properly initialized, so shut it down and don't run */
    UserApp1_StateMachine = UserApp1SM_Error;
  }

} /* end UserApp1Initialize() */

  
/*----------------------------------------------------------------------------------------------------------------------
Function UserApp1RunActiveState()

Description:
Selects and runs one iteration of the current state in the state machine.
All state machines have a TOTAL of 1ms to execute, so on average n state machines
may take 1ms / n to execute.

Requires:
  - State machine function pointer points at current state

Promises:
  - Calls the function to pointed by the state machine function pointer
*/
void UserApp1RunActiveState(void)
{
  UserApp1_StateMachine();

} /* end UserApp1RunActiveState */


/*--------------------------------------------------------------------------------------------------------------------*/
/* Private functions                                                                                                  */
/*--------------------------------------------------------------------------------------------------------------------*/


/**********************************************************************************************************************
State Machine Function Definitions
**********************************************************************************************************************/

/*-------------------------------------------------------------------------------------------------------------------*/
/* Wait for ??? */
static void UserApp1SM_Idle(void)
{
  u8 au8Message1[] = "Press key3 to unlock" ; 
   
  LCDMessage(LINE1_START_ADDR, au8Message1);
 LCDClearChars(LINE2_START_ADDR, 0);
  
 if( WasButtonPressed(BUTTON3) ){
      
  static u8 u8number=0;
  if( IsButtonPressed(BUTTON0) ) {   /* The button is currently pressed, so make sure step over */ 
    u8number=1; } else if( IsButtonPressed(BUTTON1) ) { u8number=2 ; } else if( IsButtonPressed(BUTTON2) ){ u8number=3 ; }
   switch(u8number){
  case 1 : {
    LedOff(WHITE);   LedOff(PURPLE); LedOff(BLUE); LedOff(CYAN);LedOff(GREEN); LedOff(YELLOW);  LedOff(ORANGE); LedOff(RED); 
  
     LedOn(WHITE); 
  LedOn(BLUE); 
  LedOn(GREEN); 
  LedOn(ORANGE); 
  u8 au8Message2[] = "Heart and Soul" ; 
   
  LCDMessage(LINE2_START_ADDR, au8Message2);
 LCDClearChars(LINE2_START_ADDR, 0);
  
  static u16 au16NotesLeft[] = {F5, F5, F5, F5, F5, E5, D5, E5, F5, G5, A5, A5, A5, A5, A5, G5, F5, G5, A5, A5S, C6, F5, F5, D6, C6, A5S, A5, G5, F5, NO, NO};//             NO, NO, E6, G6, D6, D6, C6, B5, G6, D6, D6, C6, B5, E6, C6, C6, B5, A5, E5, E5, C6, C6, B5, B5, G5, G6, D6, D6, C6, B5, G6, D6, D6, C6, B5, E6, C6, C6, B5, A5, A5, G5, A5, E6, A5, A5, G5, A5, D6, C6, B5, G5, E5, D5*/};  
  static u16 au16DurationLeft[] = {QN, QN, HN, EN, EN, EN, EN, EN, EN, QN, QN, QN, HN, EN, EN, EN, EN, EN, EN, QN,  HN, HN, EN, EN, EN, EN,  QN, QN, HN, HN, FN};          //   QN, QN, QN, QN, QN, QN, QN, EN, QN, QN, QN, EN, QN, QN, QN, QN, EN, EN, EN, EN, EN, EN, EN, EN, QN, QN, QN, EN, EN, QN, QN, QN, EN, EN, QN, QN, QN, QN, QN, QN, QN, QN, QN, QN, QN, QN, QN, QN, QN, QN, QN, QN, QN, QN*/};   
  static u16 au16NoteTypeLeft[] = {RT, RT, HT, RT, RT, RT, RT, RT, RT, RT, RT, RT, HT, RT, RT, RT, RT, RT, RT, RT,  RT, HT, RT, RT, RT, RT,  RT, RT, RT, HT, HT};          //     RT, RT, RT, RT, RT, RT, RT, HT, RT, RT, RT, RT, HT, RT, RT, RT, RT, HT, RT, HT, RT, HT, RT, HT, RT, RT, RT, RT, HT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT};  
  static u8 u8IndexLeft = 0;  
  static u32 u32LeftTimer = 0;   
  static u16 u16CurrentDurationLeft = 0;   
  static u16 u16NoteSilentDurationLeft = 0;  
  static u8 u8CurrentIndex = 0;
  static bool bNoteActiveNextLeft = TRUE;
  if(IsTimeUp(&u32LeftTimer, (u32)u16CurrentDurationLeft)) 
  {     u32LeftTimer = G_u32SystemTime1ms;   
  u8CurrentIndex = u8IndexLeft;          /* Set up to play current note */   
  if(bNoteActiveNextLeft)    
  {       if(au16NoteTypeLeft[u8CurrentIndex] == RT)    
     { u16CurrentDurationLeft = au16DurationLeft[u8CurrentIndex] - REGULAR_NOTE_ADJUSTMENT;        
       u16NoteSilentDurationLeft = REGULAR_NOTE_ADJUSTMENT;         
       bNoteActiveNextLeft = FALSE;       }            
  else if(au16NoteTypeLeft[u8CurrentIndex] == ST)  
  {         u16CurrentDurationLeft = STACCATO_NOTE_TIME;  
  u16NoteSilentDurationLeft = au16DurationLeft[u8CurrentIndex] - STACCATO_NOTE_TIME;         bNoteActiveNextLeft = FALSE;       } 
       else if(au16NoteTypeLeft[u8CurrentIndex] == HT)  
       {         u16CurrentDurationLeft = au16DurationLeft[u8CurrentIndex];         u16NoteSilentDurationLeft = 0;         bNoteActiveNextLeft = TRUE; 
         u8IndexLeft++;    
         if(u8IndexLeft == sizeof(au16NotesLeft) / sizeof(u16) )    
         {           u8IndexLeft = 0;         }       } 
       /* Set the buzzer frequency for the note (handle NO special case) */   
         if(au16NotesLeft[u8CurrentIndex] != NO)     
         {         PWMAudioSetFrequency(BUZZER2, au16NotesLeft[u8CurrentIndex]);         PWMAudioOn(BUZZER2);       }       
         else     
         {                         PWMAudioOff(BUZZER2);       }     }  
  else     
  {       PWMAudioOff(BUZZER2);  
  u32LeftTimer = G_u32SystemTime1ms;    
  u16CurrentDurationLeft = u16NoteSilentDurationLeft;  
  bNoteActiveNextLeft = TRUE;            
  u8IndexLeft++;      
  if(u8IndexLeft == sizeof(au16NotesLeft) / sizeof(u16) )   
  {         u8IndexLeft = 0;      }  } }
  break;
  }
case 2 : {
  LedOff(WHITE);   LedOff(PURPLE); LedOff(BLUE); LedOff(CYAN);LedOff(GREEN); LedOff(YELLOW);  LedOff(ORANGE); LedOff(RED); 
 
  
  static u16 au16NotesLeft[] =   {G4,G4,A4,G4,C5,B4,G4,G4,A4,G4,D5,C5,G5,G5,G6,E5,C5,B4,C5,B4,A4,NO,NO,F5,F5,E5,C5,D5,C5,C5  };//NO, NO, E6, G6, D6, D6, C6, B5, G6, D6, D6, C6, B5, E6, C6, C6, B5, A5, E5, E5, C6, C6, B5, B5, G5, G6, D6, D6, C6, B5, G6, D6, D6, C6, B5, E6, C6, C6, B5, A5, A5, G5, A5, E6, A5, A5, G5, A5, D6, C6, B5, G5, E5, D5};  
  static u16 au16DurationLeft[] = {EN,EN,QN,QN,EN,HN,EN,EN,QN,QN,EN,HN,EN,EN,QN,QN,EN,QN,HN,QN,QN,EN,EN,HN,HN,QN,HN,HN };//QN, QN, QN, QN, QN, QN, QN, EN, QN, QN, QN, EN, QN, QN, QN, QN, EN, EN, EN, EN, EN, EN, EN, EN, QN, QN, QN, EN, EN, QN, QN, QN, EN, EN, QN, QN, QN, QN, QN, QN, QN, QN, QN, QN, QN, QN, QN, QN, QN, QN, QN, QN, QN, QN};   
  static u16 au16NoteTypeLeft[] = { RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT};//RT, RT, RT, RT, RT, RT, RT, HT, RT, RT, RT, RT, HT, RT, RT, RT, RT, HT, RT, HT, RT, HT, RT, HT, RT, RT, RT, RT, HT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT, RT};  
  static u8 u8IndexLeft = 0;  
  static u32 u32LeftTimer = 0;   
  static u16 u16CurrentDurationLeft = 0;   
  static u16 u16NoteSilentDurationLeft = 0;  
  static u8 u8CurrentIndex = 0;
  static bool bNoteActiveNextLeft = TRUE;
  if(IsTimeUp(&u32LeftTimer, (u32)u16CurrentDurationLeft)) 
  {     u32LeftTimer = G_u32SystemTime1ms;   
  u8CurrentIndex = u8IndexLeft;           
  if(bNoteActiveNextLeft)    
  {       if(au16NoteTypeLeft[u8CurrentIndex] == RT)    
     {
       LedOn(PURPLE);
        LedOff(WHITE);   LedOff(PURPLE); LedOff(BLUE); LedOff(CYAN);LedOff(GREEN); LedOff(YELLOW);  LedOff(ORANGE); LedOff(RED); 
 
       u16CurrentDurationLeft = au16DurationLeft[u8CurrentIndex] - REGULAR_NOTE_ADJUSTMENT;        
       u16NoteSilentDurationLeft = REGULAR_NOTE_ADJUSTMENT;         
       bNoteActiveNextLeft = FALSE;       }            
  else if(au16NoteTypeLeft[u8CurrentIndex] == ST)  
  {   LedPWM(CYAN,LED_PWM_100);      
    LedOn(CYAN);
     LedOff(WHITE);   LedOff(PURPLE); LedOff(BLUE); LedOff(CYAN);LedOff(GREEN); LedOff(YELLOW);  LedOff(ORANGE); LedOff(RED); 
 
    u16CurrentDurationLeft = STACCATO_NOTE_TIME;  
  u16NoteSilentDurationLeft = au16DurationLeft[u8CurrentIndex] - STACCATO_NOTE_TIME;         bNoteActiveNextLeft = FALSE;       } 
       else if(au16NoteTypeLeft[u8CurrentIndex] == HT)  
       {   LedPWM(YELLOW,LED_PWM_100);       
         LedOn(YELLOW);
          LedOff(WHITE);   LedOff(PURPLE); LedOff(BLUE); LedOff(CYAN);LedOff(GREEN); LedOff(YELLOW);  LedOff(ORANGE); LedOff(RED); 
 
         u16CurrentDurationLeft = au16DurationLeft[u8CurrentIndex];         u16NoteSilentDurationLeft = 0;         bNoteActiveNextLeft = TRUE; 
         u8IndexLeft++;    
         if(u8IndexLeft == sizeof(au16NotesLeft) / sizeof(u16) )    
         {           u8IndexLeft = 0;         }       } 
       /* Set the buzzer frequency for the note (handle NO special case) */   
         if(au16NotesLeft[u8CurrentIndex] != NO)     
         {         PWMAudioSetFrequency(BUZZER2, au16NotesLeft[u8CurrentIndex]);         PWMAudioOn(BUZZER2);       }       
         else     
         {                         PWMAudioOff(BUZZER2);       }     }  
  else     
  {       PWMAudioOff(BUZZER2);  
  u32LeftTimer = G_u32SystemTime1ms;    
  u16CurrentDurationLeft = u16NoteSilentDurationLeft;  
  bNoteActiveNextLeft = TRUE;            
  u8IndexLeft++;      
  if(u8IndexLeft == sizeof(au16NotesLeft) / sizeof(u16) )   
  {         u8IndexLeft = 0;      }  } }
  break;       
   }
case 3: {
     LedOff(WHITE);   LedOff(PURPLE); LedOff(BLUE); LedOff(CYAN);LedOff(GREEN); LedOff(YELLOW);  LedOff(ORANGE); LedOff(RED); 
       
  static u16 au16NotesLeft[] = {C5, D5, E5, C5, C5, D5, E5, C5, E5, F5, G5, E5, F5, G5, G5, A5, G5, F5, E5, C5, G5, A5, G5, F5, E5, C5, D5, G4, C5, D5, G4, C5}; 
static u16 au16DurationLeft[] ={QN, QN, QN, QN, QN, QN, QN, QN, QN, QN, HN, QN, QN, HN, EN, EN, EN, EN, QN, QN, EN, EN, EN, EN, QN, QN, QN, QN, HN, QN, QN, HN};          
static u16 au16NoteTypeLeft[] = {  RT, RT, RT, RT, RT, RT, RT, RT,RT, RT, RT, RT, RT, RT, RT, RT,RT, RT, RT, RT, RT, RT, RT, RT,RT, RT, RT, RT, RT, RT, RT, RT,};     
static u8 u8IndexLeft = 0;  
  static u32 u32LeftTimer = 0;   
  static u16 u16CurrentDurationLeft = 0;   
  static u16 u16NoteSilentDurationLeft = 0;  
  static u8 u8CurrentIndex = 0;
  static bool bNoteActiveNextLeft = TRUE;
  if(IsTimeUp(&u32LeftTimer, (u32)u16CurrentDurationLeft)) 
  {     u32LeftTimer = G_u32SystemTime1ms;   
  u8CurrentIndex = u8IndexLeft;          /* Set up to play current note */   
  if(bNoteActiveNextLeft)    
  {       if(au16NoteTypeLeft[u8CurrentIndex] == RT)    
     {  LedOff(WHITE);   LedOff(PURPLE); LedOff(BLUE); LedOff(CYAN);LedOff(GREEN); LedOff(YELLOW);  LedOff(ORANGE); LedOff(RED); 
   LedOn(BLUE);LedOn(GREEN); LedOn(ORANGE);
      
       u16CurrentDurationLeft = au16DurationLeft[u8CurrentIndex] - REGULAR_NOTE_ADJUSTMENT;        
       u16NoteSilentDurationLeft = REGULAR_NOTE_ADJUSTMENT;         
       bNoteActiveNextLeft = FALSE;       }            
  else if(au16NoteTypeLeft[u8CurrentIndex] == ST)  
  {    
      LedOff(WHITE);   LedOff(PURPLE); LedOff(BLUE); LedOff(CYAN);LedOff(GREEN); LedOff(YELLOW);  LedOff(ORANGE); LedOff(RED); 
   LedOn(WHITE); LedOn(PURPLE);LedOn(YELLOW);
  
    u16CurrentDurationLeft = STACCATO_NOTE_TIME;  
  u16NoteSilentDurationLeft = au16DurationLeft[u8CurrentIndex] - STACCATO_NOTE_TIME;         bNoteActiveNextLeft = FALSE;       } 
       else if(au16NoteTypeLeft[u8CurrentIndex] == HT)  
       {         
         LedOff(WHITE);   LedOff(PURPLE); LedOff(BLUE); LedOff(CYAN);LedOff(GREEN); LedOff(YELLOW);  LedOff(ORANGE); LedOff(RED); 
    LedOn(WHITE);LedOn(RED);
         u16CurrentDurationLeft = au16DurationLeft[u8CurrentIndex];         u16NoteSilentDurationLeft = 0;         bNoteActiveNextLeft = TRUE; 
         u8IndexLeft++;    
         if(u8IndexLeft == sizeof(au16NotesLeft) / sizeof(u16) )    
         {           u8IndexLeft = 0;         }       } 
       /* Set the buzzer frequency for the note (handle NO special case) */   
         if(au16NotesLeft[u8CurrentIndex] != NO)     
         {         PWMAudioSetFrequency(BUZZER2, au16NotesLeft[u8CurrentIndex]);         PWMAudioOn(BUZZER2);       }       
         else     
         {                         PWMAudioOff(BUZZER2);       }     }  
  else     
  {       PWMAudioOff(BUZZER2);  
  u32LeftTimer = G_u32SystemTime1ms;    
  u16CurrentDurationLeft = u16NoteSilentDurationLeft;  
  bNoteActiveNextLeft = TRUE;            
  u8IndexLeft++;      
  if(u8IndexLeft == sizeof(au16NotesLeft) / sizeof(u16) )   
  {         u8IndexLeft = 0;      }  } }
  break;
  }}
 }
} /* end UserApp1SM_Idle() */
    

/*-------------------------------------------------------------------------------------------------------------------*/
/* Handle an error */
static void UserApp1SM_Error(void)          
{
  
} /* end UserApp1SM_Error() */



/*--------------------------------------------------------------------------------------------------------------------*/
/* End of File                                                                                                        */
/*--------------------------------------------------------------------------------------------------------------------*/
