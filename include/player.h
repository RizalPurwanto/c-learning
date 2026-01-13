#define PLAYER_MAXHEALTH (30)
#define PLAYER_DAMAGEVAL (PLAYER_MAXHEALTH-3) //27 damages
// above are macros, used as constants for values

extern int gPlayerHP; //global player HP

//extern is declared here so that it can be accessed by other files, by declaring them.
// if extern already defined here, the value can be accessed by other files
