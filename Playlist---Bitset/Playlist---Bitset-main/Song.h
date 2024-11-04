#pragma once
#include <iostream>
#include <fstream>

namespace {
	const int MAX_SONG_NAME_LEN = 64;
	const int MAX_SONG_CONTENT_LEN = 256;
	const int BYTE_SIZE = 8;

	int getFileSize(std::ifstream& ifs) {
		int pos = ifs.tellg();
		
		ifs.seekg(0, std::ios::end);
		int lastPos = ifs.tellg();

		ifs.seekg(pos);

		return lastPos;
	}
}

namespace MusicGenre {
	const char ROCK = 'r';
	const char POP = 'p';
	const char HIPHOP = 'h';
	const char EDM = 'e';
	const char JAZZ = 'j';

	const int ROCK_POS = 0;
	const int POP_POS = 1;
	const int HIPHOP_POS = 2;
	const int EDM_POS = 3;
	const int JAZZ_POS = 4;
}
class Song
{
private:
	struct Time {
	private:
		int hour = 0;
		int min = 0;
		int sec = 0;

	public:
		void setTime(int hour, int min, int sec);
		void print() const;
		void writeToFile(std::ofstream& ofs) const;
		void readFromFile(std::ifstream& ifs);

		int turnToSec() const;

		int compare(const Time& t) const;
	};

	char name[MAX_SONG_NAME_LEN] = "";
	Time duration;
	char genre = 0; //rphej - rock, pop, hip-hop, edm, jazz
	char content[MAX_SONG_CONTENT_LEN] = "";

	void readGenre(const char* genre);
	void addGenre(char g);
	void readContent(const char* filename);
	void readContentFromFile(std::ifstream& ifs);
	int findPosGenre(char ch) const;
	void printGeneres() const;
	void writeToFile(std::ofstream& ofs) const;
	void readFromFile(std::ifstream& ifs);

public:
	Song() = default;
	void createSong(const char* name, int hour, int min, int sec, const char* genre, const char* filename);

	const char* getName() const;
	bool isGenreIn(char g) const;
	int compareByTime(const Song& s) const;

	void modify(int n);
	void mix(const Song& other);
	void print() const;
	void writeToBinaryFile(const char* filename) const;
	void readFromBinaryFile(const char* filename);
};

