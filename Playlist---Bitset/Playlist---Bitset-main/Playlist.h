#include <iostream>
#pragma once
#include "Song.h"

namespace {
	const int MAX_PLAYLIST_LEN = 30;
}
class Playlist
{
private:
	Song playlist[MAX_PLAYLIST_LEN];
	int size = 0;

	const Song& findSongByName(const char* song) const;
	Song& findSongByName(const char* song);

public:
	void add(const char* name, int hour, int min, int sec, const char* genre, const char* filename);
	void print()const;
	void find(const char* songName) const;
	void findGenre(char g) const;
	void modify(const char* song, int changeRythm);
	void modify(const char* song1, const char* song2);
	void save(const char* song, const char* filename) const;
	void sort( int (*pred)(const Song& s1, const Song& s2));
	void sortByName();
	void sortByDuration();
};

