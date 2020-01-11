// Kate Radford
// PA 2
// Due: 1.31.2018

#include "PA 2.h"	

int main(void)
{

	int menu = 0, index = 0, totalSongs = 0;
	FILE *infile = NULL, *outfile = NULL;
	char line[100] = "", copyLine[100] = "";
	Node *pList = NULL;
	char *pTokens[100] = { NULL };

	srand((unsigned) 1);

	printf("WELCOME TO DIGITAL MUSIC MANAGER\n\n");
	
	do {

		printf("MAIN MENU\n");
		printf("(1) load\n(2) store\n(3) display\n(4) insert\n(5) delete\n(6) edit\n(7) sort\n(8) rate\n(9) play\n(10) shuffle\n(11) exit\n\n");
		scanf("%d", &menu); //obtain menu selection

		if (menu == 1)
		{
			// The “load” command must read all records from a file called musicPlayList.csv (you may find a sample file here) into a 
			// dynamic doubly linked list. The doubly linked list is considered the main playlist. As each record is read from the file, 
			// it must be inserted at the front of the list. Each record consists of the following attributes:

			//  *		Artist – a string
			//	*       Album title – a string
			//	*       Song title – a string
			//	*       Genre – a string
			//	*       Song length - a struct Duration type consisting of seconds and minutes, both integers
			//	*       Number times played – an integer
			//	*       Rating – an integer(1 – 5)

			// Each attribute, in a single record, will be separated by a comma in the.csv(comma separated values) file. This means that 
			// you will need to design an algorithm to extract the required attributes for each record.  Each field in each record will have 
			// a value. You do not need to check for null or empty values.

			printf("LOAD MODE\n");
			infile = fopen("musicPlayList.csv", "r");
			
			if (infile != NULL)
			{
				int i = 0;
				while ((fgets(line, 100, infile)) != NULL && (i < 20)) //having trouble making this loop
				{
					fgets(line, 100, infile);
					puts(line);
					pTokens[index] = strtok(line, ","); // first token
					while (pTokens[index] != NULL)
					{
						pTokens[index+1] = strtok(NULL, ",");
						pTokens[index+2] = strtok(NULL, ",");
						pTokens[index+3] = strtok(NULL, ",");
						pTokens[index+4] = strtok(NULL, ":");
						pTokens[index+5] = strtok(NULL, ":");
						pTokens[index+6] = strtok(NULL, ",");

					}

					strcpy(mainPlaylist[i].artist, pTokens[0]);
					puts(mainPlaylist[i].artist);

					strcpy(mainPlaylist[i].album, pTokens[1]);
					puts(mainPlaylist[i].album);

					strcpy(mainPlaylist[i].song, pTokens[2]);
					puts(mainPlaylist[i].song);

					strcpy(mainPlaylist[i].genre, pTokens[3]);
					puts(mainPlaylist[i].genre);

					strcpy(mainPlaylist[i].songLength.minutes, pTokens[4]);
					strcpy(mainPlaylist[i].songLength.seconds, pTokens[5]);
					puts(mainPlaylist[i].songLength.minutes);
					puts(mainPlaylist[i].songLength.seconds);

					strcpy(mainPlaylist[i].timesPlayed, pTokens[6]);
					puts(mainPlaylist[i].timesPlayed);

					strcpy(mainPlaylist[i].rating, pTokens[7]);
					puts(mainPlaylist[i].rating);

					insertFront(&pList, mainPlaylist[i]); //insert at front of doubly linked list

					i++;
				}
			
				int totalSongs = i;
				
			}
			
			fclose(infile);
		}
		if (menu == 2)
		{
			// The “store” command writes the current records, in the dynamic doubly linked list, to the musicPlayList.csv file. 
			// The store will completely overwrite the previous contents in the file.
			printf("STORE MODE\n");
			outfile = fopen("musicPlayList2.csv", "w"); //made this a different file for testing purposes in case I f*** up

			while ((fgets(outfile, 100, &mainPlaylist)) != NULL) //fputs??
			{
				printf("Storing...\n");

			}

		}
		if (menu == 3)
		{
			int display = 0;
			// The “display” command prints records to the screen.
			printf("DISPLAY MODE\n");
			printf("1. Print all records.\n2. Print all records that match an artist.\n");
			scanf("%d", &display);
			if (display == 1) // 1.Print all records.
			{
				int num = 0;
				while (mainPlaylist[num].artist != NULL)
				{
					puts(mainPlaylist[num].artist);
					puts(mainPlaylist[num].album);
					puts(mainPlaylist[num].song);
					puts(mainPlaylist[num].genre);
					puts(mainPlaylist[num].songLength.minutes);
					puts(mainPlaylist[num].songLength.seconds);
					puts(mainPlaylist[num].timesPlayed);
					puts(mainPlaylist[num].rating);
					num += 1;

				}
			}
			else if (display == 2) // 2.Print all records that match an artist.
			{
				char str[20];
				printf("What artist would you like to play?");
				gets(str);
				while (mainPlaylist[index].artist != NULL)
				{
					if (strcmp(str, mainPlaylist[index].artist) == 0)
					{
						while (mainPlaylist[index].artist != NULL)
						{
							printf("Playing...\n");
							puts(mainPlaylist[index].song);
							index++;
							Sleep(3000);
						}
					}
					else
						index += 1;
				}

			}
			else
				printf("something went wrong");
		}
		if (menu == 4)
		{
			// The “insert” command must prompt the user for the details of a new record. The prompt must request the artist name, 
			// album title, song title, genre, song length, number of times played, and rating. The new record must be inserted at the 
			// front of the list.
			char artist, album, title, genre, length, played, rating;
			printf("INSERT NEW RECORD\n");
			printf("Please enter the artist: \n");
			gets(artist);
			printf("Album: \n");
			gets(album);
			printf("Song: \n");
			gets(title);
			printf("Genre: \n");
			gets(genre);
			printf("Song length: \n");
			gets(length);
			printf("Times played: \n");
			gets(played);
			printf("Rating (1-5); \n");
			gets(rating);

			while (index != 100)
			{
				if (mainPlaylist[index] == NULL)
				{
					mainPlaylist[index].artist = artist;


				}
				index++;
			}
			
			// wont work until i fix above
			insertFront(&pList, mainPlaylist[index]);


		}
		if (menu == 5)
		{
			// The “delete” command must prompt the user for a song title, and remove the matching record from the list. If the song title 
			// does not exist, then the list remains unchanged.
			printf("DELETE MODE\n");
			char song;
			printf("Please enter the song title: \n");
			gets(song);
			deleteRecord(&pList, song);
		}
		if (menu == 6)
		{
			// The “edit” command must allow the user to find a record in the list by artist. If there are multiple records with the 
			// same artist, then your program must prompt the user which one to edit. The user may modify all of the attributes in the record.
			printf("EDIT MODE\n");
		}
		if (menu == 7)
		{
			// The “sort” command must prompt the user for 4 different methods to sort the records in the list. These include:
			// 1.    Sort based on artist(A - Z)
			// 2.    Sort based on album title(A - Z)
			// 3.    Sort based on rating(1 - 5)
			// 4.    Sort based on times played(largest - smallest)
			// Once a sort method is selected by the user, the sort must be performed on the records in the list.Consider using bubble sort, 
			// insertion sort, or selection sort.
			printf("SORT MODE\n");
			int sortmethod = 0;
			printf("Would you like to sort based on 1) artist 2) album title 3) rating or 4) times played \n");
			scanf("%d", &sortmethod);
			if (sortmethod == 1) //artist
			{


			}
			else if (sortmethod == 2) //album
			{


			}
			else if (sortmethod == 3) //rating
			{


			}
			else if (sortmethod == 4) //times played
			{


			}
			else
				printf("That wasnt an option!\n");
		}
		if (menu == 8)
		{
			// The “rate” command must allow the user to assign a value of 1 – 5 to a song; 1 is the lowest rating and 5 is the 
			// highest rating. The rating will replace the previous rating.
			printf("Which song would you like to rate?\n");
			int song = 0, rating = 0;
			while (mainPlaylist[index].song != NULL)
			{
				printf("%d: %s\n", index, mainPlaylist[index].song);
			}
			scanf("%d", &song);
			printf("What rating would you like to give? 1-5 with 5 being the best\n");
			scanf("%d", &rating);
			mainPlaylist[index].rating = rating;
		}
		if (menu == 9)
		{
			// The “play” command must allow the user to select a song, and must start “playing” each song in order from the current song. 
			// “Playing” the song for this assignment means displaying the contents of the record that represents the song for a short period
			// of time, clearing the screen and showing the next record in the list, etc. This continues until all songs have been played.
			printf("PLAY MODE\n");
			printf("Which song would you like to play?");
			while (mainPlaylist[index].song != NULL)
			{
				printf("%d: %s\n", index, mainPlaylist[index].song);
				index++;
			}
			int song = 0;
			index = song;
			scanf("%d", &song);
			while (mainPlaylist[song].song != NULL)
			{
				printf("Playing...  ");
				puts(mainPlaylist[index].song);
				index++;
				Sleep(3000);
			}

		}
		if (menu == 10)
		{
			// The “shuffle” command must provide a random order in which the songs are played. This command must not modify the links in 
			// the list. It must just specify the order in which songs are played, based on the position of the song in the list. 
			// For example, let’s say we have a list with 5 songs at positions 1 – 5 in the list, shuffle must generate an order 1 – 5 in 
			// which the songs are played. An order 2, 5, 3, 1, 4 would require that the second song in the list is played first, the fifth 
			// song in the list is played second, the third song in the list is played third, the first song in the list is played fourth, 
			// and the fourth song in the list is played fifth. The songs are accessed by traversing the list both forwards and backwards to 
			// satisfy the order. Hence, the need for a doubly linked list!
			printf("SHUFFLE MODE\n");
			printRandom(pList);
			Sleep(3000);
			printRandom(pList);
			Sleep(3000);
		}
		if (menu == 11)
		{
			// The “exit” command saves the most recent list to the musicPlayList.csv file. This command will completely overwrite the 
			// previous contents in the file.
			printf("now exiting\n");

			fclose(outfile);
			break;
		}
		else if (menu == 0 || menu > 11)
		{
			printf("invalid menu option\n");
		}


	} while (menu != 11);

	printf("Thank you for using DMM, Goodbye\n");
	return 0;
}