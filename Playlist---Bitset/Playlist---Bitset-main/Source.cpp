#include <iostream>
#include "Playlist.h"

int main() {
	Playlist p;

	p.add("song A", 0, 1, 55, "rp", "Song1.dat");
	p.add("song Z", 2, 3, 45, "p", "Song2.dat");
	p.add("song C", 3, 1, 5, "je", "Song3.dat");
	p.add("song B", 0, 1, 35, "ph", "Song4.dat");

	p.modify("song C", "song B");
	p.save("song C", "song_res.dat"); //','

	p.sortByName();
	p.print();
	std::cout << std::endl;

	p.sortByDuration();
	p.print();
	std::cout << std::endl;

	p.find("song A");
	std::cout << std::endl;

	p.findGenre('p');

}
