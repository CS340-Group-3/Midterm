#include <iostream>
#include <string>

#include "Tokenizer.h"

using namespace std;

// A test function to print tokens and sub-tokens from a comma separated line
void PrintCSV(Tokenizer& tokenizer, Tokenizer& subTokenizer, const string& line);

// entry point
int main() {
	Tokenizer tokenizer;
	Tokenizer subTokenizer;

	cout << endl << "-> Emulate line 1" << endl << endl;
	PrintCSV(tokenizer, subTokenizer, R"(Test line.,next token,"seperate,token,sublist",Escape the ""quotes""!,"Test ""A,B""",,Should be an empty line above)");

	cout << endl << "-> Emulate line 2" << endl << endl;
	PrintCSV(tokenizer, subTokenizer, R"(the first token,"a quote, ""within, a, quote"", separated by commas",third token,Empty line below,)");

	cout << endl << "End with an escaped quote (should be one quote char)" << endl;
	PrintCSV(tokenizer, subTokenizer, R"(""")");

	cout << endl << "End with a delimiter (should be two empty lines) " << endl;
	PrintCSV(tokenizer, subTokenizer, ",");

	return 0;
}

void PrintCSV(Tokenizer& tokenizer, Tokenizer& subTokenizer, const string& line) {
	tokenizer.Tokenize(line);

	string token;
	while (tokenizer.HasTokensRemaining()) {
		token = tokenizer.NextToken();
		cout << "-> " << token << endl;
		subTokenizer.Tokenize(token);

		if (subTokenizer.TokenCount() > 1) {
			while (subTokenizer.HasTokensRemaining()) {
				cout << "    -> " << subTokenizer.NextToken() << endl;
			}
		}
	}
}
