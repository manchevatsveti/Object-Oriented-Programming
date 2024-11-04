#include "Playlist.h"

const Song& Playlist::findSongByName(const char* song) const
{
	for (int i = 0; i < size; i++) {
		if (strcmp(song, playlist[i].getName()) == 0) {
			return playlist[i];
		}
	}
}

Song& Playlist::findSongByName(const char* song)
{
	for (int i = 0; i < size; i++) {
		if (strcmp(song, playlist[i].getName()) == 0) {
			return playlist[i];
		}
	}
}

void Playlist::add(const char* name, int hour, int min, int sec, const char* genre, const char* filename)
{
	playlist[size].createSong(name, hour, min, sec, genre, filename); //copy constr is preferable
	size++;
}

void Playlist::print() const
{
	for (int i = 0; i < size; i++) {
		playlist[i].print();
	}
}

void Playlist::find(const char* songName) const
{
	findSongByName(songName).print();
}

void Playlist::findGenre(char g) const
{
	for (int i = 0; i < size; i++) {
		if (playlist[i].isGenreIn(g)) {
			playlist[i].print();
		}
	}
}

void Playlist::modify(const char* song, int changeRythm)
{
	findSongByName(song).modify(changeRythm);
}

void Playlist::modify(const char* song1, const char* song2)
{
	findSongByName(song1).mix(findSongByName(song2));
}

void Playlist::save(const char* song, const char* filename) const
{
	findSongByName(song).writeToBinaryFile(filename);
}

void Playlist::sort(int (*pred)(const Song& s1, const Song& s2))
{
	for (int i = 0; i < size; i++) {
		int minIndex = i;

		for (int j = i + 1; j < size; j++) {
			if ( pred(playlist[j],playlist[minIndex]) < 0) {
				minIndex = j;
			}
		}

		if (minIndex != i) {
			std::swap(playlist[i], playlist[minIndex]);
		}
	}
}

void Playlist::sortByName()
{
	sort([](const Song& s1, const Song& s2) -> int {
		return strcmp(s1.getName(), s2.getName());
		});
}

void Playlist::sortByDuration()
{
	sort([](const Song& s1, const Song& s2) -> int {
		return s1.compareByTime(s2);
		});
}
