#include<iostream>
#include<string>
using namespace std;
class GameEntry{
public:
	GameEntry(const string& n="", int s =0);
	string getName() const;
	int getScore()const;
private:
	string name;
	int score;
};
GameEntry::GameEntry(const string& n, int s): name(n), score(s){}
string GameEntry::getName()const{
	return name;}
int GameEntry::getScore()const{
	return score;}


class Scores {
public:
	Scores(int maxEnt =10);
	~Scores();
		void add(const GameEntry& e);
		void remove(int i);
private:
	int maxEntries;
	int numEntries;
	GameEntry* entries;
};

Scores::Scores(int maxEnt){
		maxEntries=maxEnt;
		entries=new GameEntry[maxEntries];
		numEntries=0;}

	Scores::~Scores(){
		delete[]entries;}

	void Scores::add(const GameEntry& e){
		int newScore=e.getScore();
		if (numEntries==maxEntries){
			if(newScore<= entries[maxEntries-1].getScore())
				return;
		}
	 else {numEntries++;}
		int i=numEntries-2;
			while (i>=0 &&newScore>entries[i].getScore()){
				entries[i+1]=entries[i];
				i--;
			}

			entries[i+1]=e;}

		void Scores::remove(int i){
			while (i>=0){
entries[i-1]=entries[i];
i--;
			}
			numEntries--;
		}

		int main(){

			return 0;}