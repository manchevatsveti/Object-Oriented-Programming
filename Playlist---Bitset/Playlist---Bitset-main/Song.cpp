#include "Song.h"
#pragma warning(disable: 4996)

void Song::modify(int n)
{
	int i = 0;
	int lastPos = n - 1;

	while (true) {
		
		if ((lastPos + n) % BYTE_SIZE < lastPos) {
			i++;

			if (i == MAX_SONG_CONTENT_LEN)
				break;
		}
		lastPos = (lastPos + n) % BYTE_SIZE;

		content[i] |= (1 << lastPos);
	}
}

void Song::createSong(const char* name, int hour, int min, int sec, const char* genre, const char* filename)
{
	if (name) strcpy(this->name, name);

	this->duration.setTime(hour, min, sec);

	if (genre) readGenre(genre);

	if (filename) readContent(filename);
}

const char* Song::getName() const
{
	return name;
}

void Song::mix(const Song& other)
{
	int size = strlen(content);
	int sizeOther = strlen(other.content);

	int len = size <= sizeOther ? size : sizeOther;

	for (int i = 0; i < len; i++) {
		content[i] ^= other.content[i];
	}
}

void Song::print() const
{
	std::cout << name<<" ";
	duration.print();
	std::cout << " ";
	printGeneres();
	std::cout << std::endl;
}

void Song::writeToBinaryFile(const char* filename) const
{
	std::ofstream ofs(filename, std::ios::out | std::ios::binary);

	if (!ofs.is_open()) {
		std::cerr << "Invalid filename.";
		return;
	}

	writeToFile(ofs);
}

void Song::readFromBinaryFile(const char* filename)
{
	std::ifstream ifs(filename, std::ios::in | std::ios::binary);

	if (!ifs.is_open()) {
		std::cerr << "Invalid filename.";
		return;
	}
	else
		return readFromFile(ifs);
}

void Song::readGenre(const char* genre)
{
	int len = strlen(genre);

	for (int i = 0; i < len; i++) {
		addGenre(genre[i]);
	}
}

void Song::addGenre(char g)
{
	genre |= (1 << findPosGenre(g));
}

void Song::readContent(const char* filename)
{
	std::ifstream ifs(filename, std::ios::in);

	if (!ifs.is_open()) {
		std::cerr << "Invalid filename.";
		return;
	}
	readContentFromFile(ifs);
}

void Song::readContentFromFile(std::ifstream& ifs)
{
	ifs.getline(content, MAX_SONG_CONTENT_LEN);
}

bool Song::isGenreIn(char g) const
{
	return genre & (1 << findPosGenre(g));
}

int Song::compareByTime(const Song& s) const
{
	return this->duration.compare(s.duration);
}

int Song::findPosGenre(char ch) const
{
	switch (ch) {
		case MusicGenre::POP: {
			return MusicGenre::POP_POS;
		}case MusicGenre::ROCK: {
			return MusicGenre::ROCK_POS;
		}case MusicGenre::HIPHOP: {
			return MusicGenre::HIPHOP_POS;
		}case MusicGenre::EDM: {
			return MusicGenre::EDM_POS;
		}case MusicGenre::JAZZ: {
			return MusicGenre::JAZZ_POS;
		}
	}
}

void Song::printGeneres() const
{
	bool atLeastOne = false;

	if (isGenreIn(MusicGenre::POP)) {
		std::cout << "Pop";
		atLeastOne = true;
	}

	if (isGenreIn(MusicGenre::ROCK)) {
		if (atLeastOne) std::cout << "&";
		std::cout << "Rock";
		atLeastOne = true;
	}

	if (isGenreIn(MusicGenre::HIPHOP)) {
		if (atLeastOne) std::cout << "&";
		std::cout << "Hip Hop";
		atLeastOne = true;
	}

	if (isGenreIn(MusicGenre::EDM)) {
		if (atLeastOne) std::cout << "&";
		std::cout << "EDM";
		atLeastOne = true;
	}

	if (isGenreIn(MusicGenre::JAZZ)) {
		if (atLeastOne) std::cout << "&";
		std::cout << "Jazz";
		atLeastOne = true;
	}
}

void Song::writeToFile(std::ofstream& ofs) const
{
	/*int nameLen = strlen(name);

	ofs.write((const char*)&nameLen, sizeof(nameLen));
	ofs.write((const char*)name, nameLen * sizeof(char));//sizeof(char) depends

	duration.writeToFile(ofs);

	ofs.write((const char*)&genre, sizeof(genre));

	ofs.write((const char*)&contentLen, sizeof(contentLen));*/

	int contentLen = strlen(content);
	ofs.write((const char*)content, contentLen * sizeof(char));
}

void Song::readFromFile(std::ifstream& ifs)
{
	int nameLen;
	ifs.read((char*)&nameLen, sizeof(nameLen));
	ifs.read((char*)name, nameLen * sizeof(char));

	duration.readFromFile(ifs);

	ifs.read((char*)&genre, sizeof(genre));

	int contentLen;

	ifs.read((char*)&contentLen, sizeof(contentLen));
	ifs.read((char*)content, contentLen * sizeof(char));

}

void Song::Time::setTime(int hour, int min, int sec) 
{
	this->hour = hour;
	this->min = min;
	this->sec = sec;
}

void Song::Time::print() const
{
	std::cout << hour << ":" << min << ":" << sec;
}

void Song::Time::writeToFile(std::ofstream& ofs) const
{
	ofs.write((const char*)&hour, sizeof(hour));
	ofs.write((const char*)&min, sizeof(min));
	ofs.write((const char*)&sec, sizeof(sec));
}

void Song::Time::readFromFile(std::ifstream& ifs)
{
	ifs.read((char*)&hour, sizeof(hour));
	ifs.read((char*)&min, sizeof(min));
	ifs.read((char*)&sec, sizeof(sec));
}

int Song::Time::turnToSec() const
{
	return sec + min * 60 + hour * 60 * 60;
}

int Song::Time::compare(const Time& t) const
{
	int time1 = turnToSec();
	int time2 = t.turnToSec();

	if (time1 < time2)
		return -1;
	else if (time1 == time2)
		return 0;
	else if (time1 > time2)
		return 1;

}
