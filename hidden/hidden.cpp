/*
ID: aaronli2
TASK: hidden
LANG: C++20
*/
#include<fstream>
#include<iterator>
using namespace std;
int main()
{
	ofstream fout("hidden.out");
	ifstream fin("hidden.in");
	int l;
	fin >> l;
	istream_iterator<char> begin(fin), end;
	string s(begin, end);
	/*unordered_map<string, int> map;
	vector<string> shift(l, s); map[s] = 0;
	for (int i{ 1 }; i < l; i++) {
		s.push_back(s.front());
		s.erase(s.begin());
		shift[i] = s; map[s] = i;
	}
	sort(shift.begin(), shift.end());
	fout << map[shift[0]] << '\n';*/
	int i{ 0 }, j{ 1 }, add;
	/*To whoever reading this, since the possibility of someone reading th
	is actually exists, this is a greedy algorithm that took me a while to
	figure out and I couldn't think of better var names, sorry.*/
	while (i < l && j < l) {
		add = 0;
		while (s[(i + add) % l] == s[(j + add) % l] && add < l)add++;
		if (add == l) break;
		if (s[(i + add) % l] > s[(j + add) % l])i = i + 1 + add;
		else j = j + 1 + add; if (i == j)j++;
	}fout << ((i < j) ? i : j) << '\n';
	return 0;
}