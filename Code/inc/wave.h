#ifndef WAVE_H
#define WAVE_H

#include "ch.h"

#define FORMAT_PCM      1
#define RIFF            0x46464952  // FFIR
#define WAVE            0x45564157  // EVAW 
#define DATA            0x61746164  // atad
#define FMT             0x20746D66  //  tmf

typedef struct _chunk
{
	uint32_t    id;             
	uint32_t    size;
 } chunk;

typedef struct _RIFFHeader
{
	 chunk       descriptor;        // "RIFF"
	 uint32_t    type;              // "WAVE"
} RIFFHeader;

typedef struct _WAVEHeader
{
     chunk       descriptor;        // "fmt "
     uint16_t    audioFormat;	    // 1 - PCM
     uint16_t    numChannels;	    // 1 - mono, 2 - stereo
     uint32_t    sampleRate;
     uint32_t    byteRate;		    // byteRate = SampleRate * BlockAlign
     uint16_t    blockAlign;	    // BlockAlign = bitsPerSample / 8 * NumChannels
     uint16_t    bitsPerSample;
} WAVEHeader;

typedef struct _FILEHeader
{
    RIFFHeader  riff;
    WAVEHeader  wave;
} FILEHeader;

typedef struct _DATAHeader
{
	chunk       descriptor;         // "data"
} DATAHeader;

#endif /* WAVE_H */
