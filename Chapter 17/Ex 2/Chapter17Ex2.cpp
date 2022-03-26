int main(int argc, char* argv[])
{
    using namespace std;

	char ch;
	ofstream fout;
	fout.open(argv[1]);
	if (!fout.is_open()) {
		cerr << "Could not open " << argv[1] << ". Closing";
		exit(EXIT_FAILURE);
	}
	while (cin.get(ch)) {
		fout.put(ch);
	}
}
