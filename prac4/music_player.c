#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct song_struct
{
	char *name;
	int id;
} song_struct;

typedef struct node
{
	song_struct song;
	struct node *next;
	struct node *prev;
} node;

typedef struct dll
{
	node *start;
} dll;

node *get_node(song_struct song)
{
	node *n = (node *)malloc(sizeof(node));
	n->next = NULL;
	n->prev = NULL;
	n->song = song;
	return n;
}

void insert_at_start(dll *list, song_struct song)
{
	if (list->start == NULL)
	{
		list->start = get_node(song);
	}
	else
	{
		node *temp = list->start;
		list->start = get_node(song);
		list->start->next = temp;
		temp->prev = list->start;
	}
}

void insert_at_end(dll *list, song_struct song)
{
	if (list->start == NULL)
	{
		list->start = get_node(song);
	}
	else
	{
		node *temp = list->start;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		temp->next = get_node(song);
		temp->next->prev = temp;
	}
}

song_struct delete_at_start(dll *list)
{
	if (list->start == NULL)
	{
		printf("\nNo song in playlist to play.\n");
		exit(1);
	}
	else
	{
		song_struct song = list->start->song;
		list->start = list->start->next;
		free(list->start->prev);
		list->start->prev = NULL;
		return song;
	}
}

song_struct delete_at_end(dll *list)
{
	if (list->start == NULL)
	{
		printf("\nNo song in playlist to play.\n");
		exit(1);
	}
	else
	{
		node *temp = list->start;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		song_struct song = temp->song;
		temp = temp->prev;
		free(temp->next);
		temp->next = NULL;
	}
}

song_struct delete_last_node(dll *list)
{
	if (list->start == NULL)
	{
		printf("\nNo song in playlist to play.\n");
		exit(1);
	}
	else
	{
		song_struct song = list->start->song;
		free(list->start);
		list->start = NULL;
		return song;
	}
}

void play(song_struct s) { printf("\n\tNow playing -> %s. \n", s.name); }

void traverse(dll *list)
{
	if (list->start == NULL)
	{
		printf("\nNo song in playlist to play.\n");
	}
	else
	{
		node *temp = list->start;
		int c = 0;
		while (temp->next != NULL)
		{
			play(temp->song);
			temp = temp->next;
		}
		play(temp->song);
	}
}

song_struct get_song()
{

	song_struct song;

	char s[100];
	printf("\nEnter Song name : ");
	scanf("%s", s);

	int id = 0;
	printf("Enter Song id : ");
	scanf("%d", &id);

	song.id = id;
	char *name = (char *)calloc(strlen(s) + 2, sizeof(char));
	name = strcpy(name, s);
	song.name = name;

	return song;
}

int get_length(dll *l)
{

	node *temp = l->start;
	int c = 0;
	while (temp->next != NULL)
	{
		temp = temp->next;
		c += 1;
	}
	c += 1;
	return c;
}

void shuffle_playlist(dll *l)
{

	int length = get_length(l);
	song_struct *playlist = (song_struct *)calloc(length, sizeof(song_struct));

	// loading into p
	for (int i = 0; i < length; i++)
	{
		if (get_length(l) != 1)
		{
			playlist[i] = delete_at_start(l);
		}
		else
		{
			playlist[i] = delete_last_node(l);
		}
	}

	l->start = NULL;

	for (int i = 0; i < length; i += 2)
	{
		insert_at_end(l, playlist[i]);
	}

	for (int i = 1; i < length; i += 2)
	{
		insert_at_end(l, playlist[i]);
	}
}

int main()
{

	dll playlist = {.start = NULL};

	while (1)
	{

		printf("\nMusic Player Menu:\n");
		printf("1. Add Song to Playlist\n");
		printf("2. Shuffle Playlist\n");
		printf("3. Play Playlist\n");
		printf("4. Quit\n");

		int choice;
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			insert_at_end(&playlist, get_song());
			break;

		case 2:
			shuffle_playlist(&playlist);
			break;

		case 3:
			traverse(&playlist);
			break;

		case 4:
			printf("Exiting the Music Player.\n");
			exit(0);

		default:
			printf("Invalid choice. Please try again.\n");
		}
	}

	return 0;
}