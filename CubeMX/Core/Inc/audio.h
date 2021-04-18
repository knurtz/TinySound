#ifndef AUDIO_H
#define AUDIO_H

void Audio_ReadChunk(void* pbuffer);

void Audio_PlayFile(char* filename);
void Audio_StopPlayback(void);

void Audio_CheckEvents(void);

void cmd_play(char* arg);
void cmd_stop(void);

#endif /* AUDIO_H */
