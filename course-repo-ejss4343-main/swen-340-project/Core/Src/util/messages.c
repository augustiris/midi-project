/*
 * messages.c
 *
 *  Created on: Dec 6, 2023
 *      Author: ahlsj
 */

#include <util/messages.h>
#include <util/endian_conversions.h>
#include "printf.h"
#include "menu.h"

/*
 * This function prints the current mode.
 */
void printMode(){
	switch (getMode()){
		case MANUAL:{
			printf("***MANUAL OVERRIDE MODE ACTIVE***\n\r");
			break;
		}
		case REMOTE:{
			printf("***REMOTE MODE ACTIVE***\n\r");
			break;
		}
	}
}

/*
 * This function prints Available User Commands.
 */
void printPrompt(){
	printf("%s\n\r", "***REMOTE LED CONTROL MENU***");
	printf("%s\n\r", "Available User Commands");
	printf("%s\n\r", "NEXT - Show the next song info");
	printf("%s\n\r", "PLAY - Play the song (LED on)");
	printf("%s\n\r", "PAUSE - Pause the song (LED flash)");
	printf("%s\n\r", "STOP - Stop the song (LED off)");
}

/*
 * This function prints the invalid command message.
 */
void printInvalidCmd(){
	printf("Invalid command, try using 'HELP'\n\r");
}

/*
 * This function parses the current song for meta-events
 * the type is passed in as a parameter. It prints out the
 * info associated with the type.
 */
int printMetaEvent(song piece, unsigned char type) {
	int i = 0;
	int song_length = piece.size / sizeof(unsigned char);

	while(i < song_length){
		unsigned char byte = piece.p_song[i];
		if(byte == 0xff && piece.p_song[i+1] == type){ // If the matching type is found
			i += 2; // Skip the next two bytes (type)
			unsigned char length = piece.p_song[i];
			i++; // Skip the next byte (length)
			if(type == 0x51){// If the type is tempo it cannot be displayed by printing out byte by byte.
				uint32_t tempo = convert_to_uint24 (piece.p_song + i);
				printf("%ld (\xE6sec/quarter note)", tempo);
			}
			else{
				for(int j = 0; j < length; j++) // Print out each byte in the meta event.
					putchar(piece.p_song[i + j]);
			}
			printf("\n\r");
			return 1;
		}
		i++;
	}
	printf("none\n\r");
	return 0;
}

/*
 * This function prints out the current song's title, copyright, and tempo.
 */
void printSong(){
	uint8_t curr_song = getCurrentSong();
	song piece = get_song(curr_song);
	printf("Song %d\n\rtitle: ", curr_song);
	printMetaEvent(piece, 0x03);
	printf("copyright: ");
	printMetaEvent(piece, 0x02);
	printf("tempo: ");
	printMetaEvent(piece, 0x51);
}
